/*
 * WPJ2 Recomp - Controller Pak (MPK) implementation
 *
 * Implements a full Controller Pak filesystem backed by a 32KB file on disk.
 * The Controller Pak has 32KB of battery-backed RAM organized as 128 pages
 * of 256 bytes each.
 *
 * Page layout:
 *   0     - Bad sector table (unused in emulation)
 *   1-2   - Reserved
 *   3     - Inode table (128 × 2-byte entries tracking page allocation)
 *   4     - Mirror of inode table (backup)
 *   5-6   - Directory table (16 entries × 32 bytes)
 *   7-121 - File data pages (115 pages = 29,440 bytes)
 *   122-127 - ID area
 *
 * Inode entry values:
 *   0x0001 = free page
 *   0x0003 = last page of a file
 *   other  = next page number in file chain
 *
 * Directory entry (32 bytes):
 *   0x00: company_code (2 bytes)
 *   0x02: game_code (2 bytes)
 *   0x04: note_name (5 bytes, space-padded)
 *   0x09: ext_name (1 byte)
 *   0x0A: reserved (1 byte)
 *   0x0B: num_blocks (1 byte)
 *   0x0C: first_page (2 bytes)
 *   0x0E: reserved (2 bytes)
 *   0x10: status (4 bytes, bit 4 = validated)
 *   0x14: copy_flag (1 byte)
 *   0x15: checksum (2 bytes, XOR of bytes 0x00-0x14)
 *   0x17: padding (15 bytes)
 */

#include "recomp.h"
#include "shims.h"
#include "ultramodern/ultra64.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <mutex>

// Controller Pak constants
#define PAK_RAM_SIZE     (32 * 1024)       // 32KB
#define PAK_PAGE_SIZE    256               // bytes per page
#define PAK_NUM_PAGES    (PAK_RAM_SIZE / PAK_PAGE_SIZE)  // 128 pages
#define PAK_DIR_PAGE     5                 // directory starts at page 5
#define PAK_DIR_PAGES    2                 // 2 pages for directory
#define PAK_INODE_PAGE   3                 // inode table at page 3
#define PAK_MINODE_PAGE  4                 // mirror inode at page 4
#define PAK_DATA_START   7                 // first data page
#define PAK_DATA_PAGES   (PAK_NUM_PAGES - PAK_DATA_START - 6)  // 115 pages
#define PFS_MAX_FILES    16
#define PFS_DIR_ENTRY_SIZE 32
#define PFS_ERR_NOPACK   1
#define PFS_ERR_INVALID  2
#define PFS_ERR_EXIST    4
#define PFS_ERR_FULL     8

// OSPfs struct offsets (from ultra64.h)
#define OSPFS_STATUS     0    // int
#define OSPFS_QUEUE      4    // PTR(OSMesgQueue)
#define OSPFS_CHANNEL    8    // int
#define OSPFS_ID         12   // u8[32]
#define OSPFS_LABEL      44   // u8[32]
#define OSPFS_VERSION    76   // int
#define OSPFS_DIR_SIZE   80   // int
#define OSPFS_INODE_TBL  84   // int (page number)
#define OSPFS_MINODE_TBL 88   // int (page number)
#define OSPFS_DIR_TBL    92   // int (page number)
#define OSPFS_INODE_SP   96   // int (inode start page)
#define OSPFS_ACTIVEBANK 102  // u8

// Inode values
#define INODE_FREE       0x0001
#define INODE_LAST       0x0003

namespace {

std::mutex g_pak_mutex;

// Get the path for the pak file
std::filesystem::path pak_path(int channel) {
    const char* home = getenv("HOME");
    if (!home) home = "/tmp";
    auto dir = std::filesystem::path(home) / ".config" / "wpj2-recomp";
    std::filesystem::create_directories(dir);
    return dir / ("controller_pak_" + std::to_string(channel) + ".bin");
}

// Load the pak RAM from file (or initialize if it doesn't exist)
void load_pak(int channel, uint8_t* ram) {
    auto path = pak_path(channel);
    std::ifstream f(path, std::ios::binary);
    if (f.is_open() && f.read(reinterpret_cast<char*>(ram), PAK_RAM_SIZE)) {
        return; // loaded successfully
    }

    // Initialize a fresh pak
    memset(ram, 0, PAK_RAM_SIZE);

    // Initialize inode table: all data pages are free
    // Pages 0-6 are system pages (mark as used/last)
    uint8_t* inode = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;
    for (int i = 0; i < PAK_NUM_PAGES; i++) {
        if (i < PAK_DATA_START) {
            inode[i * 2] = 0;
            inode[i * 2 + 1] = 0;
        } else {
            inode[i * 2] = INODE_FREE & 0xFF;
            inode[i * 2 + 1] = (INODE_FREE >> 8) & 0xFF;
        }
    }

    // Mirror inode table
    memcpy(ram + PAK_MINODE_PAGE * PAK_PAGE_SIZE, inode, PAK_PAGE_SIZE);

    // Clear directory (all zeros = empty entries)
    memset(ram + PAK_DIR_PAGE * PAK_PAGE_SIZE, 0, PAK_DIR_PAGES * PAK_PAGE_SIZE);

    // Write to file
    std::ofstream out(path, std::ios::binary);
    if (out.is_open()) {
        out.write(reinterpret_cast<const char*>(ram), PAK_RAM_SIZE);
    }
}

// Save the pak RAM to file
void save_pak(int channel, const uint8_t* ram) {
    auto path = pak_path(channel);
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (out.is_open()) {
        out.write(reinterpret_cast<const char*>(ram), PAK_RAM_SIZE);
    }
}

// Per-channel pak RAM cache
uint8_t g_pak_ram[4][PAK_RAM_SIZE];
bool g_pak_loaded[4] = {false, false, false, false};

// Ensure pak is loaded for a channel
uint8_t* ensure_pak(int channel) {
    if (channel < 0 || channel >= 4) return nullptr;
    if (!g_pak_loaded[channel]) {
        load_pak(channel, g_pak_ram[channel]);
        g_pak_loaded[channel] = true;
    }
    return g_pak_ram[channel];
}

// Read the OSPfs channel from RDRAM
int get_pfs_channel(uint8_t* rdram, gpr pfs_ptr) {
    if (pfs_ptr == 0) return 0;
    return MEM_W(OSPFS_CHANNEL, pfs_ptr);
}

// Set the OSPfs fields for a initialized pak
void init_pfs_struct(uint8_t* rdram, gpr pfs_ptr, int channel) {
    if (pfs_ptr == 0) return;
    // status: PFS_INITIALIZED (0x1) | PFS_CORRUPTED (0x2 if needed)
    MEM_W(OSPFS_STATUS, pfs_ptr) = 1; // PFS_INITIALIZED
    MEM_W(OSPFS_CHANNEL, pfs_ptr) = channel;
    MEM_W(OSPFS_DIR_SIZE, pfs_ptr) = PFS_MAX_FILES;
    MEM_W(OSPFS_INODE_TBL, pfs_ptr) = PAK_INODE_PAGE;
    MEM_W(OSPFS_MINODE_TBL, pfs_ptr) = PAK_MINODE_PAGE;
    MEM_W(OSPFS_DIR_TBL, pfs_ptr) = PAK_DIR_PAGE;
    MEM_W(OSPFS_INODE_SP, pfs_ptr) = PAK_DATA_START;
    // activebank
    MEM_BU(OSPFS_ACTIVEBANK, pfs_ptr) = 0;
}

// Find a free directory entry (returns index 0-15, or -1 if full)
int find_free_dir_slot(const uint8_t* ram) {
    const uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
    for (int i = 0; i < PFS_MAX_FILES; i++) {
        // An entry is free if company_code and game_code are both 0
        const uint8_t* entry = dir + i * PFS_DIR_ENTRY_SIZE;
        if (entry[0] == 0 && entry[1] == 0 && entry[2] == 0 && entry[3] == 0) {
            return i;
        }
    }
    return -1;
}

// Find a file by company/game/name/ext (returns index 0-15, or -1 if not found)
int find_file(const uint8_t* ram, u16 company, u32 gamecode,
              const uint8_t* note_name, const uint8_t* ext_name) {
    const uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
    for (int i = 0; i < PFS_MAX_FILES; i++) {
        const uint8_t* entry = dir + i * PFS_DIR_ENTRY_SIZE;
        if (entry[0] == 0 && entry[1] == 0) continue; // empty slot

        u16 entry_company = (entry[0] << 8) | entry[1];
        u32 entry_game = (entry[2] << 24) | (entry[3] << 16) | (entry[4] << 8) | entry[5];

        if (entry_company != company) continue;
        if (entry_game != gamecode) continue;

        // Compare note name (5 bytes)
        if (note_name && memcmp(entry + 6, note_name, 5) != 0) continue;

        // Compare extension (1 byte)
        if (ext_name && entry[11] != *ext_name) continue;

        return i;
    }
    return -1;
}

// Count free pages
int count_free_pages(const uint8_t* ram) {
    const uint8_t* inode = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;
    int count = 0;
    for (int i = PAK_DATA_START; i < PAK_NUM_PAGES - 6; i++) {
        u16 val = (inode[i * 2]) | (inode[i * 2 + 1] << 8);
        if (val == INODE_FREE) count++;
    }
    return count;
}

// Allocate `count` pages and return the first page number (or -1 if not enough)
int allocate_pages(uint8_t* ram, int count) {
    uint8_t* inode = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;
    int first = -1;
    int prev = -1;
    int found = 0;

    for (int i = PAK_DATA_START; i < PAK_NUM_PAGES - 6 && found < count; i++) {
        u16 val = (inode[i * 2]) | (inode[i * 2 + 1] << 8);
        if (val == INODE_FREE) {
            if (first == -1) first = i;
            if (prev != -1) {
                // Link previous page to this one
                inode[prev * 2] = i & 0xFF;
                inode[prev * 2 + 1] = (i >> 8) & 0xFF;
            }
            prev = i;
            found++;
        }
    }

    if (found < count) return -1; // not enough space

    // Mark last page as end-of-file
    inode[prev * 2] = INODE_LAST & 0xFF;
    inode[prev * 2 + 1] = (INODE_LAST >> 8) & 0xFF;

    // Mirror inode
    memcpy(ram + PAK_MINODE_PAGE * PAK_PAGE_SIZE, inode, PAK_PAGE_SIZE);

    return first;
}

// Free all pages in a file chain starting from first_page
void free_pages(uint8_t* ram, int first_page) {
    uint8_t* inode = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;
    int page = first_page;
    while (page >= PAK_DATA_START && page < PAK_NUM_PAGES - 6) {
        u16 val = (inode[page * 2]) | (inode[page * 2 + 1] << 8);
        // Mark as free
        inode[page * 2] = INODE_FREE & 0xFF;
        inode[page * 2 + 1] = (INODE_FREE >> 8) & 0xFF;

        if (val == INODE_LAST || val == INODE_FREE) break;
        page = val;
    }

    // Mirror inode
    memcpy(ram + PAK_MINODE_PAGE * PAK_PAGE_SIZE, inode, PAK_PAGE_SIZE);
}

// Follow the page chain from first_page, reading/writing data
void access_file_data(uint8_t* ram, int first_page, int offset, int size,
                      uint8_t* rdram, gpr buffer_ptr, bool is_write) {
    int page = first_page;
    int bytes_done = 0;
    int page_offset = offset; // offset within the file

    // Skip to the right page
    while (page_offset >= PAK_PAGE_SIZE && page >= PAK_DATA_START) {
        uint8_t* inode = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;
        u16 val = (inode[page * 2]) | (inode[page * 2 + 1] << 8);
        if (val == INODE_LAST || val == INODE_FREE) break;
        page = val;
        page_offset -= PAK_PAGE_SIZE;
    }

    // Read/write data
    while (bytes_done < size && page >= PAK_DATA_START && page < PAK_NUM_PAGES - 6) {
        uint8_t* page_data = ram + page * PAK_PAGE_SIZE;
        int to_copy = std::min(size - bytes_done, PAK_PAGE_SIZE - page_offset);

        for (int i = 0; i < to_copy; i++) {
            if (is_write) {
                page_data[page_offset + i] = MEM_BU(0, buffer_ptr + bytes_done + i);
            } else {
                MEM_BU(0, buffer_ptr + bytes_done + i) = page_data[page_offset + i];
            }
        }

        bytes_done += to_copy;
        page_offset = 0;

        if (bytes_done < size) {
            uint8_t* inode = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;
            u16 val = (inode[page * 2]) | (inode[page * 2 + 1] << 8);
            if (val == INODE_LAST || val == INODE_FREE) break;
            page = val;
        }
    }
}

// Calculate the number of pages needed for a given byte size
int bytes_to_pages(int size) {
    return (size + PAK_PAGE_SIZE - 1) / PAK_PAGE_SIZE;
}

} // anonymous namespace

// ============================================================================
// Low-level RAM access
// ============================================================================

extern "C" void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = channel, r5 = address (page), r6 = buffer ptr
    // The original signature is __osContRamRead(mq, channel, address, buffer)
    // but the recompiled code passes: r4 = mq, r5 = channel, r6 = address, r7 = buffer
    // Let's handle both cases — check if r4 looks like a channel (0-3) or a pointer
    int channel;
    int page_addr;
    gpr buffer_ptr;

    // Based on the generated code analysis:
    // r4 = mq (from OSPfs.queue), r5 = channel (from OSPfs.channel),
    // r6 = address, r7 = buffer
    // But some callers might use: r4 = channel, r5 = address, r6 = buffer
    // We'll detect based on r7 being non-zero (4-arg variant)
    if (ctx->r7 != 0) {
        // 4-arg variant: (mq, channel, address, buffer)
        channel = (int)ctx->r5;
        page_addr = (int)ctx->r6;
        buffer_ptr = ctx->r7;
    } else {
        // 3-arg variant: (channel, address, buffer)
        channel = (int)ctx->r4;
        page_addr = (int)ctx->r5;
        buffer_ptr = ctx->r6;
    }

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram || page_addr < 0 || page_addr >= PAK_NUM_PAGES) {
        ctx->r2 = PFS_ERR_INVALID;
        return;
    }

    const uint8_t* page_data = ram + page_addr * PAK_PAGE_SIZE;
    for (int i = 0; i < PAK_PAGE_SIZE; i++) {
        MEM_BU(0, buffer_ptr + i) = page_data[i];
    }

    ctx->r2 = 0; // success
}

extern "C" void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Same arg layout as __osContRamRead, plus an extra force flag
    int channel;
    int page_addr;
    gpr buffer_ptr;

    if (ctx->r7 != 0) {
        // 5-arg variant: (mq, channel, address, buffer, force)
        // r7 is buffer, force is on stack — but r7 being non-zero means it's a pointer
        // Actually: r4=mq, r5=channel, r6=address, r7=buffer, stack=force
        channel = (int)ctx->r5;
        page_addr = (int)ctx->r6;
        buffer_ptr = ctx->r7;
    } else {
        // 3-arg variant: (channel, address, buffer)
        channel = (int)ctx->r4;
        page_addr = (int)ctx->r5;
        buffer_ptr = ctx->r6;
    }

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram || page_addr < 0 || page_addr >= PAK_NUM_PAGES) {
        ctx->r2 = PFS_ERR_INVALID;
        return;
    }

    uint8_t* page_data = ram + page_addr * PAK_PAGE_SIZE;
    for (int i = 0; i < PAK_PAGE_SIZE; i++) {
        page_data[i] = MEM_BU(0, buffer_ptr + i);
    }

    save_pak(channel, ram);
    ctx->r2 = 0; // success
}

// ============================================================================
// Bank selection (no-op — we only have one bank)
// ============================================================================

extern "C" void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs*, r5 = bank
    // Just update the activebank field in OSPfs
    if (ctx->r4 != 0) {
        MEM_BU(OSPFS_ACTIVEBANK, ctx->r4) = (uint8_t)ctx->r5;
    }
    ctx->r2 = 0;
}

// ============================================================================
// PFS initialization
// ============================================================================

extern "C" void osPfsInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs*, r5 = OSMesgQueue* (or channel), r6 = channel (if 3-arg)
    // Based on generated code: r4 = OSPfs*, r5 = mq, r6 = channel
    gpr pfs_ptr = ctx->r4;
    int channel = (int)ctx->r6;

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    // Set up OSPfs struct
    if (pfs_ptr != 0) {
        MEM_W(OSPFS_STATUS, pfs_ptr) = 1; // PFS_INITIALIZED
        MEM_W(OSPFS_QUEUE, pfs_ptr) = ctx->r5; // store mq
        MEM_W(OSPFS_CHANNEL, pfs_ptr) = channel;
        MEM_W(OSPFS_DIR_SIZE, pfs_ptr) = PFS_MAX_FILES;
        MEM_W(OSPFS_INODE_TBL, pfs_ptr) = PAK_INODE_PAGE;
        MEM_W(OSPFS_MINODE_TBL, pfs_ptr) = PAK_MINODE_PAGE;
        MEM_W(OSPFS_DIR_TBL, pfs_ptr) = PAK_DIR_PAGE;
        MEM_W(OSPFS_INODE_SP, pfs_ptr) = PAK_DATA_START;
        MEM_BU(OSPFS_ACTIVEBANK, pfs_ptr) = 0;
    }

    // Count used blocks
    int free_pages = count_free_pages(ram);
    int used_pages = PAK_DATA_PAGES - free_pages;

    ctx->r2 = 0; // success
    fprintf(stderr, "[WPJ2/PFS] osPfsInit: channel=%d, free_pages=%d, used_pages=%d\n",
            channel, free_pages, used_pages);
}

extern "C" void osPfsIsPlug_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs* or OSMesgQueue*, r5 = pattern ptr
    // Set bit pattern: bit 0 = controller 0 has pak
    if (ctx->r5 != 0) {
        MEM_BU(0, ctx->r5) = 0x01; // controller 0 has pak
    }
    ctx->r2 = 0; // success
}

// ============================================================================
// File operations
// ============================================================================

extern "C" void osPfsFindFile_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs*, r5 = company, r6 = gamecode, r7 = note_name ptr
    //       stack[0x10] = ext_name ptr, stack[0x14] = file_no ptr
    gpr pfs_ptr = ctx->r4;
    u16 company = (u16)ctx->r5;
    u32 gamecode = (u32)ctx->r6;
    gpr note_ptr = ctx->r7;
    gpr ext_ptr = MEM_W(ctx->r29, 0x10);
    gpr file_no_ptr = MEM_W(ctx->r29, 0x14);

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    // Read note_name and ext_name from RDRAM
    uint8_t note[5] = {0};
    uint8_t ext = 0;
    if (note_ptr) {
        for (int i = 0; i < 5; i++) note[i] = MEM_BU(0, note_ptr + i);
    }
    if (ext_ptr) {
        ext = MEM_BU(0, ext_ptr);
    }

    int idx = find_file(ram, company, gamecode, note_ptr ? note : nullptr, ext_ptr ? &ext : nullptr);
    if (idx >= 0) {
        if (file_no_ptr) MEM_W(0, file_no_ptr) = idx;
        ctx->r2 = 0; // found
    } else {
        if (file_no_ptr) MEM_W(0, file_no_ptr) = -1;
        ctx->r2 = PFS_ERR_INVALID; // not found
    }
}

extern "C" void osPfsAllocateFile_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs*, r5 = company, r6 = gamecode, r7 = note_name ptr
    //       stack args: ext_name ptr, file_size, file_no ptr
    gpr pfs_ptr = ctx->r4;
    u16 company = (u16)ctx->r5;
    u32 gamecode = (u32)ctx->r6;
    gpr note_ptr = ctx->r7;
    gpr ext_ptr = MEM_W(ctx->r29, 0x10);
    int file_size = (int)MEM_W(ctx->r29, 0x14);
    gpr file_no_ptr = MEM_W(ctx->r29, 0x18);

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    int num_pages = bytes_to_pages(file_size);
    int free_pages = count_free_pages(ram);
    if (free_pages < num_pages) {
        ctx->r2 = PFS_ERR_FULL;
        return;
    }

    // Check if file already exists
    uint8_t note[5] = {0};
    uint8_t ext = 0;
    if (note_ptr) for (int i = 0; i < 5; i++) note[i] = MEM_BU(0, note_ptr + i);
    if (ext_ptr) ext = MEM_BU(0, ext_ptr);

    int existing = find_file(ram, company, gamecode, note_ptr ? note : nullptr, ext_ptr ? &ext : nullptr);
    if (existing >= 0) {
        ctx->r2 = PFS_ERR_EXIST;
        return;
    }

    // Find a free directory slot
    int slot = find_free_dir_slot(ram);
    if (slot < 0) {
        ctx->r2 = PFS_ERR_FULL;
        return;
    }

    // Allocate pages
    int first_page = allocate_pages(ram, num_pages);
    if (first_page < 0) {
        ctx->r2 = PFS_ERR_FULL;
        return;
    }

    // Create directory entry
    uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
    uint8_t* entry = dir + slot * PFS_DIR_ENTRY_SIZE;
    memset(entry, 0, PFS_DIR_ENTRY_SIZE);

    // Company code (big-endian 2 bytes)
    entry[0] = (company >> 8) & 0xFF;
    entry[1] = company & 0xFF;
    // Game code (big-endian 4 bytes)
    entry[2] = (gamecode >> 24) & 0xFF;
    entry[3] = (gamecode >> 16) & 0xFF;
    entry[4] = (gamecode >> 8) & 0xFF;
    entry[5] = gamecode & 0xFF;
    // Note name (5 bytes, space-padded)
    if (note_ptr) {
        for (int i = 0; i < 5; i++) entry[6 + i] = MEM_BU(0, note_ptr + i);
    } else {
        memset(entry + 6, ' ', 5);
    }
    // Extension (1 byte)
    entry[11] = ext_ptr ? MEM_BU(0, ext_ptr) : ' ';
    // Number of blocks (pages)
    entry[12] = (uint8_t)num_pages;
    // First page (big-endian 2 bytes)
    entry[13] = (first_page >> 8) & 0xFF;
    entry[14] = first_page & 0xFF;
    // Status (bit 4 = validated)
    entry[16] = 0x10; // validated
    // Copy flag
    entry[20] = 0; // original

    // Calculate checksum (XOR of bytes 0-20)
    uint8_t checksum = 0;
    for (int i = 0; i < 21; i++) checksum ^= entry[i];
    entry[21] = checksum;

    save_pak(channel, ram);

    if (file_no_ptr) MEM_W(0, file_no_ptr) = slot;
    ctx->r2 = 0; // success

    fprintf(stderr, "[WPJ2/PFS] osPfsAllocateFile: slot=%d, first_page=%d, pages=%d, size=%d\n",
            slot, first_page, num_pages, file_size);
}

extern "C" void osPfsReadWriteFile_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs*, r5 = file_no, r6 = mode (0=read, 1=write),
    //       r7 = offset, stack[0x10] = size, stack[0x14] = buffer ptr
    gpr pfs_ptr = ctx->r4;
    int file_no = (int)ctx->r5;
    int mode = (int)ctx->r6;
    int offset = (int)ctx->r7;
    int size = (int)MEM_W(ctx->r29, 0x10);
    gpr buffer_ptr = MEM_W(ctx->r29, 0x14);

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    if (file_no < 0 || file_no >= PFS_MAX_FILES) {
        ctx->r2 = PFS_ERR_INVALID;
        return;
    }

    // Get directory entry
    uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
    uint8_t* entry = dir + file_no * PFS_DIR_ENTRY_SIZE;
    if (entry[0] == 0 && entry[1] == 0) {
        ctx->r2 = PFS_ERR_INVALID; // empty slot
        return;
    }

    // Get first page (big-endian)
    int first_page = (entry[13] << 8) | entry[14];

    // Read/write data
    access_file_data(ram, first_page, offset, size, rdram, buffer_ptr, mode == 1);

    if (mode == 1) {
        save_pak(channel, ram);
    }

    ctx->r2 = 0; // success
}

extern "C" void osPfsDeleteFile_recomp(uint8_t* rdram, recomp_context* ctx) {
    gpr pfs_ptr = ctx->r4;
    u16 company = (u16)ctx->r5;
    u32 gamecode = (u32)ctx->r6;
    gpr note_ptr = ctx->r7;
    gpr ext_ptr = MEM_W(ctx->r29, 0x10);

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    uint8_t note[5] = {0};
    uint8_t ext = 0;
    if (note_ptr) for (int i = 0; i < 5; i++) note[i] = MEM_BU(0, note_ptr + i);
    if (ext_ptr) ext = MEM_BU(0, ext_ptr);

    int idx = find_file(ram, company, gamecode, note_ptr ? note : nullptr, ext_ptr ? &ext : nullptr);
    if (idx < 0) {
        ctx->r2 = PFS_ERR_INVALID;
        return;
    }

    // Get first page and free the chain
    uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
    uint8_t* entry = dir + idx * PFS_DIR_ENTRY_SIZE;
    int first_page = (entry[13] << 8) | entry[14];
    free_pages(ram, first_page);

    // Clear directory entry
    memset(entry, 0, PFS_DIR_ENTRY_SIZE);

    save_pak(channel, ram);
    ctx->r2 = 0; // success
}

// ============================================================================
// Filesystem info
// ============================================================================

extern "C" void osPfsNumFiles_recomp(uint8_t* rdram, recomp_context* ctx) {
    gpr pfs_ptr = ctx->r4;
    gpr max_ptr = ctx->r5;
    gpr used_ptr = ctx->r6;

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);

    int used = 0;
    if (ram) {
        const uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
        for (int i = 0; i < PFS_MAX_FILES; i++) {
            const uint8_t* entry = dir + i * PFS_DIR_ENTRY_SIZE;
            if (!(entry[0] == 0 && entry[1] == 0)) used++;
        }
    }

    if (max_ptr) MEM_W(0, max_ptr) = PFS_MAX_FILES;
    if (used_ptr) MEM_W(0, used_ptr) = used;
    ctx->r2 = 0;
}

extern "C" void osPfsFileState_recomp(uint8_t* rdram, recomp_context* ctx) {
    gpr pfs_ptr = ctx->r4;
    int file_no = (int)ctx->r5;
    gpr state_ptr = ctx->r6;

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    if (file_no < 0 || file_no >= PFS_MAX_FILES) {
        ctx->r2 = PFS_ERR_INVALID;
        return;
    }

    const uint8_t* dir = ram + PAK_DIR_PAGE * PAK_PAGE_SIZE;
    const uint8_t* entry = dir + file_no * PFS_DIR_ENTRY_SIZE;
    if (entry[0] == 0 && entry[1] == 0) {
        ctx->r2 = PFS_ERR_INVALID;
        return;
    }

    // Write file state to RDRAM (OSPfsState struct)
    if (state_ptr) {
        // company (2 bytes at offset 0)
        MEM_W(0, state_ptr) = (entry[0] << 24) | (entry[1] << 16);
        // game_code (4 bytes at offset 4)
        MEM_W(4, state_ptr) = (entry[2] << 24) | (entry[3] << 16) | (entry[4] << 8) | entry[5];
        // note_name (5 bytes at offset 8)
        for (int i = 0; i < 5; i++) MEM_BU(8 + i, state_ptr) = entry[6 + i];
        // ext (1 byte at offset 13)
        MEM_BU(13, state_ptr) = entry[11];
        // num_bytes (4 bytes at offset 16) = pages * 256
        int num_pages = entry[12];
        MEM_W(16, state_ptr) = num_pages * PAK_PAGE_SIZE;
    }

    ctx->r2 = 0;
}

extern "C" void osPfsFreeBlocks_recomp(uint8_t* rdram, recomp_context* ctx) {
    gpr pfs_ptr = ctx->r4;
    gpr bytes_ptr = ctx->r5;

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);

    int free_bytes = 0;
    if (ram) {
        free_bytes = count_free_pages(ram) * PAK_PAGE_SIZE;
    }

    if (bytes_ptr) MEM_W(0, bytes_ptr) = free_bytes;
    ctx->r2 = 0;
}

// ============================================================================
// Filesystem checker (no-op — our implementation is always consistent)
// ============================================================================

extern "C" void osPfsChecker_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Just return success — our file-backed implementation is always consistent
    ctx->r2 = 0;
}

// ============================================================================
// Inode read/write (called by game's PFS code)
// ============================================================================

extern "C" void __osPfsRWInode_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = OSPfs*, r5 = inode ptr, r6 = mode (0=read, 1=write), r7 = bank
    gpr pfs_ptr = ctx->r4;
    gpr inode_ptr = ctx->r5;
    int mode = (int)ctx->r6;

    int channel = get_pfs_channel(rdram, pfs_ptr);

    std::lock_guard<std::mutex> lock(g_pak_mutex);
    uint8_t* ram = ensure_pak(channel);
    if (!ram) {
        ctx->r2 = PFS_ERR_NOPACK;
        return;
    }

    // The inode table is at page PAK_INODE_PAGE (128 entries × 2 bytes = 256 bytes)
    uint8_t* inode_ram = ram + PAK_INODE_PAGE * PAK_PAGE_SIZE;

    if (mode == 0) {
        // Read: copy from RAM to RDRAM
        for (int i = 0; i < PAK_NUM_PAGES * 2; i++) {
            MEM_BU(0, inode_ptr + i) = inode_ram[i];
        }
    } else {
        // Write: copy from RDRAM to RAM
        for (int i = 0; i < PAK_NUM_PAGES * 2; i++) {
            inode_ram[i] = MEM_BU(0, inode_ptr + i);
        }
        // Mirror
        memcpy(ram + PAK_MINODE_PAGE * PAK_PAGE_SIZE, inode_ram, PAK_PAGE_SIZE);
        save_pak(channel, ram);
    }

    ctx->r2 = 0;
}

// ============================================================================
// CRC functions (used by the game's PFS code for data integrity)
// ============================================================================

extern "C" void __osContAddressCrc_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = address (11-bit)
    // CRC is 5 bits, computed over the address
    uint32_t address = (uint32_t)ctx->r4 & 0x7FF;
    uint8_t crc = 0;
    uint8_t data = address >> 3;

    for (int i = 0; i < 8; i++) {
        if ((data >> (7 - i)) & 1) {
            crc ^= 0x17 >> i;
        }
    }
    // Include the lower 3 bits
    data = address & 0x7;
    for (int i = 0; i < 3; i++) {
        if ((data >> (2 - i)) & 1) {
            crc ^= 0x07 >> i;
        }
    }

    ctx->r2 = crc & 0x1F;
}

extern "C" void __osContDataCrc_recomp(uint8_t* rdram, recomp_context* ctx) {
    // Args: r4 = data ptr (in RDRAM)
    gpr data_ptr = ctx->r4;
    uint8_t crc = 0;
    for (int i = 0; i < 32; i++) {
        uint8_t byte = MEM_BU(0, data_ptr + i);
        for (int bit = 7; bit >= 0; bit--) {
            uint8_t temp = (crc << 1) | ((byte >> bit) & 1);
            if (crc & 0x80) {
                crc = temp ^ 0x85;
            } else {
                crc = temp;
            }
        }
    }
    // Final 8 bits of 0
    for (int i = 0; i < 8; i++) {
        uint8_t temp = crc << 1;
        if (crc & 0x80) {
            crc = temp ^ 0x85;
        } else {
            crc = temp;
        }
    }
    ctx->r2 = crc;
}

// ============================================================================
// Other stubs (not PFS-related, but needed for compilation)
// ============================================================================

// osContReset_recomp is provided by librecomp's cont.cpp — do NOT redefine.

extern "C" void osPfsGetLabel_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;
}

extern "C" void osPfsSetLabel_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;
}

extern "C" void osCreateMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
}

extern "C" void osLockMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
}

extern "C" void osUnlockMutex_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
}

extern "C" void __osViGetCurrentContext_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;
}

extern "C" void __osViSwapContext_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
}

extern "C" void __osTimerInterrupt_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
}
