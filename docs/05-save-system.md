# 05 — Save System: Controller Pak (MPK)

> Implementation spec for Controller Pak save. NOT EEPROM. NOT SRAM.

## Hardware Specs

| Property | Value |
|---|---|
| **Device** | Controller Pak (NUS-004) / Mempak |
| **Capacity** | 32 KB = 32,768 bytes |
| **Pages** | 123 pages × 256 bytes = 31,488 bytes usable (rest is directory) |
| **Page size** | 256 bytes (0x100) |
| **Directory** | 16 entries × 32 bytes = 512 bytes at page 0 |
| **File ID** | Game-specific (WPJ2 likely uses unique ID) |
| **Access** | SI bus, command 0x00 (status), 0x04 (read), 0x05 (write) |

## MPK File Format (Host Side)

Host stores save as single file: `controller_pak.mpk` (32,768 bytes exact).

```
MPK Layout (32 KB):
├── Page 0 (0x0000-0x00FF): Directory (16 entries × 32 bytes)
│   ├── Entry 0: Filename (20 bytes) + Extension (4) + Game ID (2) + Company (2) + ...
│   ├── Entry 1-15: Additional files (WPJ2 may only use 1)
├── Pages 1-122: File data (page-aligned)
└── Page 123: Unused / checksum?
```

### Directory Entry (32 bytes)

```c
typedef struct {
    char filename[20];      // "WPJ2SAVE" + padding
    char extension[4];      // "SAV" + padding
    u16 game_id;            // WPJ2-specific (e.g., 0x4A32 = 'J2')
    u16 company_code;       // Enix = 0x00? (verify)
    u8  start_page;         // First data page (1-122)
    u8  page_count;         // Number of pages
    u8  offset;             // Offset within start page
    u8  flags;              // 0x80 = valid, 0x40 = last block
    u16 crc16;              // CRC16 of file data
    u8  reserved[2];
} MPKDirEntry;
```

## SI Commands (N64 → Pak)

| Command | Code | Description |
|---|---|---|
| **Read Status** | 0x00 | Returns device type, capacity, CRC |
| **Read Page** | 0x04 | Read 256 bytes from page N |
| **Write Page** | 0x05 | Write 256 bytes to page N |
| **Read ID** | 0x02 | Manufacturer ID (optional) |

### Command Format (SI)

```
TX: [CMD] [PAGE_HI] [PAGE_LO] [DATA...] (write)
TX: [CMD] [PAGE_HI] [PAGE_LO]          (read)
RX: [DATA...] (256 bytes for read)
```

## N64ModernRuntime Integration

Check if N64ModernRuntime has MPK support:

```bash
grep -r "controller_pak\|mempak\|MPK" lib/N64ModernRuntime/
```

If missing, implement in `src/audio_input/controller_pak.cpp`:

```cpp
// Public API (called by recompiled game via osMotorInit/osPfsInitPak etc.)
extern "C" {
    s32 osPfsInitPak(OSMesgQueue* mq, u8* id, s32* result);
    s32 osPfsReadWriteFile(OSPfs* pfs, s32 file_no, u8* buffer, s32 mode);
    // ... other osPfs* functions
}

// Host implementation:
class ControllerPak {
    std::string mpk_path_;
    std::array<u8, 32768> data_;
    bool dirty_ = false;
    
    // SI command handlers
    s32 HandleStatus(u8* response);
    s32 HandleReadPage(u8 page, u8* response);
    s32 HandleWritePage(u8 page, const u8* data);
    
    // MPK file ops
    void LoadMPK();
    void SaveMPK();  // On dirty + periodic
    u8* GetPagePtr(u8 page);
    bool FindFile(u8 file_no, u8& start_page, u8& page_count);
};
```

## Game-Expected Behavior

From parallel-n64 reports:

1. **Boot check:** Game calls `osPfsInitPak` early. If fails → "Insert Controller Pak" screen → infinite loop.
2. **Save:** Player selects save → game writes via `osPfsReadWriteFile`.
3. **Load:** Game reads on boot/continue.

**Our implementation must:**
- Return success on init (Pak "present")
- Persist MPK file across sessions
- Handle CRC verification (game may check)

## Testing Checklist

| Test | Expected |
|---|---|
| Fresh boot, no MPK file | Creates empty MPK, game sees Pak, proceeds |
| Save in-game | MPK file updated, CRC valid |
| Load save | Data reads correctly, game state restored |
| Multiple saves | Directory handles multiple files (if game uses) |
| Corrupt MPK | Game handles gracefully (reformat?) |
| Concurrent read/write | Thread-safe (SI is single-threaded in game) |

## Reference Implementations

- **N64ModernRuntime** — check for existing `osPfs*` stubs
- **Mupen64Plus** — `src/mempak.c` (GPL, reference only)
- **ParaLLEl-RDP** — SI device emulation
- **libdragon** — `src/mempak.c` (BSD, can adapt)

## File Location

| Platform | Path |
|---|---|
| Linux | `~/.local/share/wpj2-recomp/controller_pak.mpk` |
| Windows | `%APPDATA%\wpj2-recomp\controller_pak.mpk` |
| macOS | `~/Library/Application Support/wpj2-recomp/controller_pak.mpk` |

## Future: EEPROM/SRAM Support

If we later recomp a game with on-cart save, add factory:
```cpp
std::unique_ptr<SaveDevice> CreateSaveDevice(SaveType type);
```
For WPJ2: `SaveType::ControllerPak` only.