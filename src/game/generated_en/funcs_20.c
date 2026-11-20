#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006BC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BC78: jal         0x8005F064
    // 0x8006BC7C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BC7C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x8006BC80: b           L_8006BC90
    // 0x8006BC84: nop

        goto L_8006BC90;
    // 0x8006BC84: nop

    // 0x8006BC88: b           L_8006BC90
    // 0x8006BC8C: nop

        goto L_8006BC90;
    // 0x8006BC8C: nop

L_8006BC90:
    // 0x8006BC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BC94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC98: jr          $ra
    // 0x8006BC9C: nop

    return;
    // 0x8006BC9C: nop

;}
RECOMP_FUNC void func_8006BCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BCA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BCA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BCA8: jal         0x8005F064
    // 0x8006BCAC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BCAC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_0:
    // 0x8006BCB0: b           L_8006BCC0
    // 0x8006BCB4: nop

        goto L_8006BCC0;
    // 0x8006BCB4: nop

    // 0x8006BCB8: b           L_8006BCC0
    // 0x8006BCBC: nop

        goto L_8006BCC0;
    // 0x8006BCBC: nop

L_8006BCC0:
    // 0x8006BCC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BCC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BCC8: jr          $ra
    // 0x8006BCCC: nop

    return;
    // 0x8006BCCC: nop

;}
RECOMP_FUNC void func_8006BCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BCD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BCD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BCD8: jal         0x8005F064
    // 0x8006BCDC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BCDC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_0:
    // 0x8006BCE0: b           L_8006BCF0
    // 0x8006BCE4: nop

        goto L_8006BCF0;
    // 0x8006BCE4: nop

    // 0x8006BCE8: b           L_8006BCF0
    // 0x8006BCEC: nop

        goto L_8006BCF0;
    // 0x8006BCEC: nop

L_8006BCF0:
    // 0x8006BCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BCF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BCF8: jr          $ra
    // 0x8006BCFC: nop

    return;
    // 0x8006BCFC: nop

;}
RECOMP_FUNC void func_8006BD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD08: jal         0x8005F064
    // 0x8006BD0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8006BD10: b           L_8006BD20
    // 0x8006BD14: nop

        goto L_8006BD20;
    // 0x8006BD14: nop

    // 0x8006BD18: b           L_8006BD20
    // 0x8006BD1C: nop

        goto L_8006BD20;
    // 0x8006BD1C: nop

L_8006BD20:
    // 0x8006BD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD28: jr          $ra
    // 0x8006BD2C: nop

    return;
    // 0x8006BD2C: nop

;}
RECOMP_FUNC void func_8006BD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD38: jal         0x8005F064
    // 0x8006BD3C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD3C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
    // 0x8006BD40: b           L_8006BD50
    // 0x8006BD44: nop

        goto L_8006BD50;
    // 0x8006BD44: nop

    // 0x8006BD48: b           L_8006BD50
    // 0x8006BD4C: nop

        goto L_8006BD50;
    // 0x8006BD4C: nop

L_8006BD50:
    // 0x8006BD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD58: jr          $ra
    // 0x8006BD5C: nop

    return;
    // 0x8006BD5C: nop

;}
RECOMP_FUNC void func_8006BD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD68: jal         0x8005F064
    // 0x8006BD6C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD6C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x8006BD70: b           L_8006BD80
    // 0x8006BD74: nop

        goto L_8006BD80;
    // 0x8006BD74: nop

    // 0x8006BD78: b           L_8006BD80
    // 0x8006BD7C: nop

        goto L_8006BD80;
    // 0x8006BD7C: nop

L_8006BD80:
    // 0x8006BD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD88: jr          $ra
    // 0x8006BD8C: nop

    return;
    // 0x8006BD8C: nop

;}
RECOMP_FUNC void func_8006BD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD98: jal         0x8005F064
    // 0x8006BD9C: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD9C: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x8006BDA0: b           L_8006BDB0
    // 0x8006BDA4: nop

        goto L_8006BDB0;
    // 0x8006BDA4: nop

    // 0x8006BDA8: b           L_8006BDB0
    // 0x8006BDAC: nop

        goto L_8006BDB0;
    // 0x8006BDAC: nop

L_8006BDB0:
    // 0x8006BDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BDB8: jr          $ra
    // 0x8006BDBC: nop

    return;
    // 0x8006BDBC: nop

;}
RECOMP_FUNC void func_8006BDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BDC8: jal         0x8005F064
    // 0x8006BDCC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BDCC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_0:
    // 0x8006BDD0: b           L_8006BDE0
    // 0x8006BDD4: nop

        goto L_8006BDE0;
    // 0x8006BDD4: nop

    // 0x8006BDD8: b           L_8006BDE0
    // 0x8006BDDC: nop

        goto L_8006BDE0;
    // 0x8006BDDC: nop

L_8006BDE0:
    // 0x8006BDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BDE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BDE8: jr          $ra
    // 0x8006BDEC: nop

    return;
    // 0x8006BDEC: nop

;}
RECOMP_FUNC void func_8006BDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BDF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BDF8: jal         0x8005F064
    // 0x8006BDFC: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BDFC: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_0:
    // 0x8006BE00: b           L_8006BE10
    // 0x8006BE04: nop

        goto L_8006BE10;
    // 0x8006BE04: nop

    // 0x8006BE08: b           L_8006BE10
    // 0x8006BE0C: nop

        goto L_8006BE10;
    // 0x8006BE0C: nop

L_8006BE10:
    // 0x8006BE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BE18: jr          $ra
    // 0x8006BE1C: nop

    return;
    // 0x8006BE1C: nop

;}
RECOMP_FUNC void func_8006BE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BE28: jal         0x8005F064
    // 0x8006BE2C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BE2C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x8006BE30: b           L_8006BE40
    // 0x8006BE34: nop

        goto L_8006BE40;
    // 0x8006BE34: nop

    // 0x8006BE38: b           L_8006BE40
    // 0x8006BE3C: nop

        goto L_8006BE40;
    // 0x8006BE3C: nop

L_8006BE40:
    // 0x8006BE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BE44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BE48: jr          $ra
    // 0x8006BE4C: nop

    return;
    // 0x8006BE4C: nop

;}
RECOMP_FUNC void func_8006BE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BE58: jal         0x8005F064
    // 0x8006BE5C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BE5C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_0:
    // 0x8006BE60: b           L_8006BE70
    // 0x8006BE64: nop

        goto L_8006BE70;
    // 0x8006BE64: nop

    // 0x8006BE68: b           L_8006BE70
    // 0x8006BE6C: nop

        goto L_8006BE70;
    // 0x8006BE6C: nop

L_8006BE70:
    // 0x8006BE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BE78: jr          $ra
    // 0x8006BE7C: nop

    return;
    // 0x8006BE7C: nop

;}
RECOMP_FUNC void func_8006BE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BE88: jal         0x8005F064
    // 0x8006BE8C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BE8C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x8006BE90: b           L_8006BEA0
    // 0x8006BE94: nop

        goto L_8006BEA0;
    // 0x8006BE94: nop

    // 0x8006BE98: b           L_8006BEA0
    // 0x8006BE9C: nop

        goto L_8006BEA0;
    // 0x8006BE9C: nop

L_8006BEA0:
    // 0x8006BEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BEA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BEA8: jr          $ra
    // 0x8006BEAC: nop

    return;
    // 0x8006BEAC: nop

;}
RECOMP_FUNC void func_8006BEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BEB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BEB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BEB8: jal         0x8005F064
    // 0x8006BEBC: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BEBC: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    after_0:
    // 0x8006BEC0: b           L_8006BED0
    // 0x8006BEC4: nop

        goto L_8006BED0;
    // 0x8006BEC4: nop

    // 0x8006BEC8: b           L_8006BED0
    // 0x8006BECC: nop

        goto L_8006BED0;
    // 0x8006BECC: nop

L_8006BED0:
    // 0x8006BED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BED8: jr          $ra
    // 0x8006BEDC: nop

    return;
    // 0x8006BEDC: nop

;}
RECOMP_FUNC void func_8006BEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BEE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BEE8: jal         0x8005F064
    // 0x8006BEEC: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BEEC: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_0:
    // 0x8006BEF0: b           L_8006BF00
    // 0x8006BEF4: nop

        goto L_8006BF00;
    // 0x8006BEF4: nop

    // 0x8006BEF8: b           L_8006BF00
    // 0x8006BEFC: nop

        goto L_8006BF00;
    // 0x8006BEFC: nop

L_8006BF00:
    // 0x8006BF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF08: jr          $ra
    // 0x8006BF0C: nop

    return;
    // 0x8006BF0C: nop

;}
RECOMP_FUNC void func_8006BF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF18: jal         0x8005F064
    // 0x8006BF1C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BF1C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x8006BF20: b           L_8006BF30
    // 0x8006BF24: nop

        goto L_8006BF30;
    // 0x8006BF24: nop

    // 0x8006BF28: b           L_8006BF30
    // 0x8006BF2C: nop

        goto L_8006BF30;
    // 0x8006BF2C: nop

L_8006BF30:
    // 0x8006BF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF38: jr          $ra
    // 0x8006BF3C: nop

    return;
    // 0x8006BF3C: nop

;}
RECOMP_FUNC void func_8006BF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF48: jal         0x8005F064
    // 0x8006BF4C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BF4C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    after_0:
    // 0x8006BF50: b           L_8006BF60
    // 0x8006BF54: nop

        goto L_8006BF60;
    // 0x8006BF54: nop

    // 0x8006BF58: b           L_8006BF60
    // 0x8006BF5C: nop

        goto L_8006BF60;
    // 0x8006BF5C: nop

L_8006BF60:
    // 0x8006BF60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF68: jr          $ra
    // 0x8006BF6C: nop

    return;
    // 0x8006BF6C: nop

;}
RECOMP_FUNC void func_8006BF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF78: jal         0x8005F064
    // 0x8006BF7C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BF7C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x8006BF80: b           L_8006BF90
    // 0x8006BF84: nop

        goto L_8006BF90;
    // 0x8006BF84: nop

    // 0x8006BF88: b           L_8006BF90
    // 0x8006BF8C: nop

        goto L_8006BF90;
    // 0x8006BF8C: nop

L_8006BF90:
    // 0x8006BF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF98: jr          $ra
    // 0x8006BF9C: nop

    return;
    // 0x8006BF9C: nop

;}
RECOMP_FUNC void func_8006BFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BFA8: jal         0x8005F064
    // 0x8006BFAC: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BFAC: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x8006BFB0: b           L_8006BFC0
    // 0x8006BFB4: nop

        goto L_8006BFC0;
    // 0x8006BFB4: nop

    // 0x8006BFB8: b           L_8006BFC0
    // 0x8006BFBC: nop

        goto L_8006BFC0;
    // 0x8006BFBC: nop

L_8006BFC0:
    // 0x8006BFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFC8: jr          $ra
    // 0x8006BFCC: nop

    return;
    // 0x8006BFCC: nop

;}
RECOMP_FUNC void func_8006BFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BFD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BFD8: jal         0x8005F064
    // 0x8006BFDC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BFDC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_0:
    // 0x8006BFE0: b           L_8006BFF0
    // 0x8006BFE4: nop

        goto L_8006BFF0;
    // 0x8006BFE4: nop

    // 0x8006BFE8: b           L_8006BFF0
    // 0x8006BFEC: nop

        goto L_8006BFF0;
    // 0x8006BFEC: nop

L_8006BFF0:
    // 0x8006BFF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BFF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFF8: jr          $ra
    // 0x8006BFFC: nop

    return;
    // 0x8006BFFC: nop

;}
RECOMP_FUNC void func_8006C000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C008: jal         0x8005F064
    // 0x8006C00C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C00C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_0:
    // 0x8006C010: b           L_8006C020
    // 0x8006C014: nop

        goto L_8006C020;
    // 0x8006C014: nop

    // 0x8006C018: b           L_8006C020
    // 0x8006C01C: nop

        goto L_8006C020;
    // 0x8006C01C: nop

L_8006C020:
    // 0x8006C020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C028: jr          $ra
    // 0x8006C02C: nop

    return;
    // 0x8006C02C: nop

;}
RECOMP_FUNC void func_8006C030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C038: jal         0x8005F064
    // 0x8006C03C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C03C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_0:
    // 0x8006C040: b           L_8006C050
    // 0x8006C044: nop

        goto L_8006C050;
    // 0x8006C044: nop

    // 0x8006C048: b           L_8006C050
    // 0x8006C04C: nop

        goto L_8006C050;
    // 0x8006C04C: nop

L_8006C050:
    // 0x8006C050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C058: jr          $ra
    // 0x8006C05C: nop

    return;
    // 0x8006C05C: nop

;}
RECOMP_FUNC void func_8006C060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C068: jal         0x8005F064
    // 0x8006C06C: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C06C: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    after_0:
    // 0x8006C070: b           L_8006C080
    // 0x8006C074: nop

        goto L_8006C080;
    // 0x8006C074: nop

    // 0x8006C078: b           L_8006C080
    // 0x8006C07C: nop

        goto L_8006C080;
    // 0x8006C07C: nop

L_8006C080:
    // 0x8006C080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C088: jr          $ra
    // 0x8006C08C: nop

    return;
    // 0x8006C08C: nop

;}
RECOMP_FUNC void func_8006C090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C098: jal         0x8005F064
    // 0x8006C09C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C09C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x8006C0A0: b           L_8006C0B0
    // 0x8006C0A4: nop

        goto L_8006C0B0;
    // 0x8006C0A4: nop

    // 0x8006C0A8: b           L_8006C0B0
    // 0x8006C0AC: nop

        goto L_8006C0B0;
    // 0x8006C0AC: nop

L_8006C0B0:
    // 0x8006C0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C0B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C0B8: jr          $ra
    // 0x8006C0BC: nop

    return;
    // 0x8006C0BC: nop

;}
RECOMP_FUNC void func_8006C0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C0C8: jal         0x8005F064
    // 0x8006C0CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C0CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x8006C0D0: b           L_8006C0E0
    // 0x8006C0D4: nop

        goto L_8006C0E0;
    // 0x8006C0D4: nop

    // 0x8006C0D8: b           L_8006C0E0
    // 0x8006C0DC: nop

        goto L_8006C0E0;
    // 0x8006C0DC: nop

L_8006C0E0:
    // 0x8006C0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C0E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C0E8: jr          $ra
    // 0x8006C0EC: nop

    return;
    // 0x8006C0EC: nop

;}
RECOMP_FUNC void func_8006C0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C0F8: jal         0x8005F064
    // 0x8006C0FC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C0FC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_0:
    // 0x8006C100: b           L_8006C110
    // 0x8006C104: nop

        goto L_8006C110;
    // 0x8006C104: nop

    // 0x8006C108: b           L_8006C110
    // 0x8006C10C: nop

        goto L_8006C110;
    // 0x8006C10C: nop

L_8006C110:
    // 0x8006C110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C118: jr          $ra
    // 0x8006C11C: nop

    return;
    // 0x8006C11C: nop

;}
RECOMP_FUNC void func_8006C120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C128: jal         0x8005F064
    // 0x8006C12C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C12C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x8006C130: b           L_8006C140
    // 0x8006C134: nop

        goto L_8006C140;
    // 0x8006C134: nop

    // 0x8006C138: b           L_8006C140
    // 0x8006C13C: nop

        goto L_8006C140;
    // 0x8006C13C: nop

L_8006C140:
    // 0x8006C140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C148: jr          $ra
    // 0x8006C14C: nop

    return;
    // 0x8006C14C: nop

;}
RECOMP_FUNC void func_8006C150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C158: jal         0x8005F064
    // 0x8006C15C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C15C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_0:
    // 0x8006C160: b           L_8006C170
    // 0x8006C164: nop

        goto L_8006C170;
    // 0x8006C164: nop

    // 0x8006C168: b           L_8006C170
    // 0x8006C16C: nop

        goto L_8006C170;
    // 0x8006C16C: nop

L_8006C170:
    // 0x8006C170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C178: jr          $ra
    // 0x8006C17C: nop

    return;
    // 0x8006C17C: nop

;}
RECOMP_FUNC void func_8006C180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C188: jal         0x8005F064
    // 0x8006C18C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C18C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x8006C190: b           L_8006C1A0
    // 0x8006C194: nop

        goto L_8006C1A0;
    // 0x8006C194: nop

    // 0x8006C198: b           L_8006C1A0
    // 0x8006C19C: nop

        goto L_8006C1A0;
    // 0x8006C19C: nop

L_8006C1A0:
    // 0x8006C1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C1A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C1A8: jr          $ra
    // 0x8006C1AC: nop

    return;
    // 0x8006C1AC: nop

;}
RECOMP_FUNC void func_8006C1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C1B8: jal         0x8005F064
    // 0x8006C1BC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C1BC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_0:
    // 0x8006C1C0: b           L_8006C1D0
    // 0x8006C1C4: nop

        goto L_8006C1D0;
    // 0x8006C1C4: nop

    // 0x8006C1C8: b           L_8006C1D0
    // 0x8006C1CC: nop

        goto L_8006C1D0;
    // 0x8006C1CC: nop

L_8006C1D0:
    // 0x8006C1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C1D8: jr          $ra
    // 0x8006C1DC: nop

    return;
    // 0x8006C1DC: nop

;}
RECOMP_FUNC void func_8006C1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C1E8: jal         0x8005F064
    // 0x8006C1EC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C1EC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x8006C1F0: b           L_8006C200
    // 0x8006C1F4: nop

        goto L_8006C200;
    // 0x8006C1F4: nop

    // 0x8006C1F8: b           L_8006C200
    // 0x8006C1FC: nop

        goto L_8006C200;
    // 0x8006C1FC: nop

L_8006C200:
    // 0x8006C200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C208: jr          $ra
    // 0x8006C20C: nop

    return;
    // 0x8006C20C: nop

;}
RECOMP_FUNC void func_8006C210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C218: jal         0x8005F064
    // 0x8006C21C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C21C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x8006C220: b           L_8006C230
    // 0x8006C224: nop

        goto L_8006C230;
    // 0x8006C224: nop

    // 0x8006C228: b           L_8006C230
    // 0x8006C22C: nop

        goto L_8006C230;
    // 0x8006C22C: nop

L_8006C230:
    // 0x8006C230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C238: jr          $ra
    // 0x8006C23C: nop

    return;
    // 0x8006C23C: nop

;}
RECOMP_FUNC void func_8006C240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C248: jal         0x8005F064
    // 0x8006C24C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C24C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_0:
    // 0x8006C250: b           L_8006C260
    // 0x8006C254: nop

        goto L_8006C260;
    // 0x8006C254: nop

    // 0x8006C258: b           L_8006C260
    // 0x8006C25C: nop

        goto L_8006C260;
    // 0x8006C25C: nop

L_8006C260:
    // 0x8006C260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C268: jr          $ra
    // 0x8006C26C: nop

    return;
    // 0x8006C26C: nop

;}
RECOMP_FUNC void func_8006C270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C278: jal         0x8005F064
    // 0x8006C27C: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C27C: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x8006C280: b           L_8006C290
    // 0x8006C284: nop

        goto L_8006C290;
    // 0x8006C284: nop

    // 0x8006C288: b           L_8006C290
    // 0x8006C28C: nop

        goto L_8006C290;
    // 0x8006C28C: nop

L_8006C290:
    // 0x8006C290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C298: jr          $ra
    // 0x8006C29C: nop

    return;
    // 0x8006C29C: nop

;}
RECOMP_FUNC void func_8006C2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C2A8: jal         0x8005F064
    // 0x8006C2AC: addiu       $a0, $zero, 0xB7
    ctx->r4 = ADD32(0, 0XB7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C2AC: addiu       $a0, $zero, 0xB7
    ctx->r4 = ADD32(0, 0XB7);
    after_0:
    // 0x8006C2B0: b           L_8006C2C0
    // 0x8006C2B4: nop

        goto L_8006C2C0;
    // 0x8006C2B4: nop

    // 0x8006C2B8: b           L_8006C2C0
    // 0x8006C2BC: nop

        goto L_8006C2C0;
    // 0x8006C2BC: nop

L_8006C2C0:
    // 0x8006C2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C2C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C2C8: jr          $ra
    // 0x8006C2CC: nop

    return;
    // 0x8006C2CC: nop

;}
RECOMP_FUNC void func_8006C2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C2D8: jal         0x8005F064
    // 0x8006C2DC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C2DC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8006C2E0: b           L_8006C2F0
    // 0x8006C2E4: nop

        goto L_8006C2F0;
    // 0x8006C2E4: nop

    // 0x8006C2E8: b           L_8006C2F0
    // 0x8006C2EC: nop

        goto L_8006C2F0;
    // 0x8006C2EC: nop

L_8006C2F0:
    // 0x8006C2F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C2F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C2F8: jr          $ra
    // 0x8006C2FC: nop

    return;
    // 0x8006C2FC: nop

;}
RECOMP_FUNC void func_8006C300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C308: jal         0x8005F064
    // 0x8006C30C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C30C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_0:
    // 0x8006C310: b           L_8006C320
    // 0x8006C314: nop

        goto L_8006C320;
    // 0x8006C314: nop

    // 0x8006C318: b           L_8006C320
    // 0x8006C31C: nop

        goto L_8006C320;
    // 0x8006C31C: nop

L_8006C320:
    // 0x8006C320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C328: jr          $ra
    // 0x8006C32C: nop

    return;
    // 0x8006C32C: nop

;}
RECOMP_FUNC void func_8006C330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C338: jal         0x8005F064
    // 0x8006C33C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C33C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x8006C340: b           L_8006C350
    // 0x8006C344: nop

        goto L_8006C350;
    // 0x8006C344: nop

    // 0x8006C348: b           L_8006C350
    // 0x8006C34C: nop

        goto L_8006C350;
    // 0x8006C34C: nop

L_8006C350:
    // 0x8006C350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C358: jr          $ra
    // 0x8006C35C: nop

    return;
    // 0x8006C35C: nop

;}
RECOMP_FUNC void func_8006C360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C368: jal         0x8005F064
    // 0x8006C36C: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C36C: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_0:
    // 0x8006C370: b           L_8006C380
    // 0x8006C374: nop

        goto L_8006C380;
    // 0x8006C374: nop

    // 0x8006C378: b           L_8006C380
    // 0x8006C37C: nop

        goto L_8006C380;
    // 0x8006C37C: nop

L_8006C380:
    // 0x8006C380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C388: jr          $ra
    // 0x8006C38C: nop

    return;
    // 0x8006C38C: nop

;}
RECOMP_FUNC void func_8006C390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C398: jal         0x8005F064
    // 0x8006C39C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C39C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x8006C3A0: b           L_8006C3B0
    // 0x8006C3A4: nop

        goto L_8006C3B0;
    // 0x8006C3A4: nop

    // 0x8006C3A8: b           L_8006C3B0
    // 0x8006C3AC: nop

        goto L_8006C3B0;
    // 0x8006C3AC: nop

L_8006C3B0:
    // 0x8006C3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3B8: jr          $ra
    // 0x8006C3BC: nop

    return;
    // 0x8006C3BC: nop

;}
RECOMP_FUNC void func_8006C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C3C8: jal         0x8005F064
    // 0x8006C3CC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C3CC: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_0:
    // 0x8006C3D0: b           L_8006C3E0
    // 0x8006C3D4: nop

        goto L_8006C3E0;
    // 0x8006C3D4: nop

    // 0x8006C3D8: b           L_8006C3E0
    // 0x8006C3DC: nop

        goto L_8006C3E0;
    // 0x8006C3DC: nop

L_8006C3E0:
    // 0x8006C3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3E8: jr          $ra
    // 0x8006C3EC: nop

    return;
    // 0x8006C3EC: nop

;}
RECOMP_FUNC void func_8006C3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C3F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C3F8: jal         0x8005F064
    // 0x8006C3FC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C3FC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x8006C400: b           L_8006C410
    // 0x8006C404: nop

        goto L_8006C410;
    // 0x8006C404: nop

    // 0x8006C408: b           L_8006C410
    // 0x8006C40C: nop

        goto L_8006C410;
    // 0x8006C40C: nop

L_8006C410:
    // 0x8006C410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C418: jr          $ra
    // 0x8006C41C: nop

    return;
    // 0x8006C41C: nop

;}
RECOMP_FUNC void func_8006C420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C428: jal         0x8005F064
    // 0x8006C42C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C42C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_0:
    // 0x8006C430: b           L_8006C440
    // 0x8006C434: nop

        goto L_8006C440;
    // 0x8006C434: nop

    // 0x8006C438: b           L_8006C440
    // 0x8006C43C: nop

        goto L_8006C440;
    // 0x8006C43C: nop

L_8006C440:
    // 0x8006C440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C448: jr          $ra
    // 0x8006C44C: nop

    return;
    // 0x8006C44C: nop

;}
RECOMP_FUNC void func_8006C450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C458: jal         0x8005F064
    // 0x8006C45C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C45C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x8006C460: b           L_8006C470
    // 0x8006C464: nop

        goto L_8006C470;
    // 0x8006C464: nop

    // 0x8006C468: b           L_8006C470
    // 0x8006C46C: nop

        goto L_8006C470;
    // 0x8006C46C: nop

L_8006C470:
    // 0x8006C470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C478: jr          $ra
    // 0x8006C47C: nop

    return;
    // 0x8006C47C: nop

;}
RECOMP_FUNC void func_8006C480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C488: jal         0x8005F064
    // 0x8006C48C: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C48C: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_0:
    // 0x8006C490: b           L_8006C4A0
    // 0x8006C494: nop

        goto L_8006C4A0;
    // 0x8006C494: nop

    // 0x8006C498: b           L_8006C4A0
    // 0x8006C49C: nop

        goto L_8006C4A0;
    // 0x8006C49C: nop

L_8006C4A0:
    // 0x8006C4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C4A8: jr          $ra
    // 0x8006C4AC: nop

    return;
    // 0x8006C4AC: nop

;}
RECOMP_FUNC void func_8006C4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C4B8: jal         0x8005F064
    // 0x8006C4BC: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C4BC: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_0:
    // 0x8006C4C0: b           L_8006C4D0
    // 0x8006C4C4: nop

        goto L_8006C4D0;
    // 0x8006C4C4: nop

    // 0x8006C4C8: b           L_8006C4D0
    // 0x8006C4CC: nop

        goto L_8006C4D0;
    // 0x8006C4CC: nop

L_8006C4D0:
    // 0x8006C4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C4D8: jr          $ra
    // 0x8006C4DC: nop

    return;
    // 0x8006C4DC: nop

;}
RECOMP_FUNC void func_8006C4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C4E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C4E8: jal         0x8005F064
    // 0x8006C4EC: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C4EC: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_0:
    // 0x8006C4F0: b           L_8006C500
    // 0x8006C4F4: nop

        goto L_8006C500;
    // 0x8006C4F4: nop

    // 0x8006C4F8: b           L_8006C500
    // 0x8006C4FC: nop

        goto L_8006C500;
    // 0x8006C4FC: nop

L_8006C500:
    // 0x8006C500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C508: jr          $ra
    // 0x8006C50C: nop

    return;
    // 0x8006C50C: nop

;}
RECOMP_FUNC void func_8006C510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C518: jal         0x8005F064
    // 0x8006C51C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C51C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_0:
    // 0x8006C520: b           L_8006C530
    // 0x8006C524: nop

        goto L_8006C530;
    // 0x8006C524: nop

    // 0x8006C528: b           L_8006C530
    // 0x8006C52C: nop

        goto L_8006C530;
    // 0x8006C52C: nop

L_8006C530:
    // 0x8006C530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C538: jr          $ra
    // 0x8006C53C: nop

    return;
    // 0x8006C53C: nop

;}
RECOMP_FUNC void func_8006C540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C548: jal         0x8005F064
    // 0x8006C54C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C54C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x8006C550: b           L_8006C560
    // 0x8006C554: nop

        goto L_8006C560;
    // 0x8006C554: nop

    // 0x8006C558: b           L_8006C560
    // 0x8006C55C: nop

        goto L_8006C560;
    // 0x8006C55C: nop

L_8006C560:
    // 0x8006C560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C568: jr          $ra
    // 0x8006C56C: nop

    return;
    // 0x8006C56C: nop

;}
RECOMP_FUNC void func_8006C570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C578: jal         0x8005F064
    // 0x8006C57C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C57C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x8006C580: b           L_8006C590
    // 0x8006C584: nop

        goto L_8006C590;
    // 0x8006C584: nop

    // 0x8006C588: b           L_8006C590
    // 0x8006C58C: nop

        goto L_8006C590;
    // 0x8006C58C: nop

L_8006C590:
    // 0x8006C590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C598: jr          $ra
    // 0x8006C59C: nop

    return;
    // 0x8006C59C: nop

;}
RECOMP_FUNC void func_8006C5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C5A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C5A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C5A8: jal         0x8005F064
    // 0x8006C5AC: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C5AC: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_0:
    // 0x8006C5B0: b           L_8006C5C0
    // 0x8006C5B4: nop

        goto L_8006C5C0;
    // 0x8006C5B4: nop

    // 0x8006C5B8: b           L_8006C5C0
    // 0x8006C5BC: nop

        goto L_8006C5C0;
    // 0x8006C5BC: nop

L_8006C5C0:
    // 0x8006C5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C5C8: jr          $ra
    // 0x8006C5CC: nop

    return;
    // 0x8006C5CC: nop

;}
