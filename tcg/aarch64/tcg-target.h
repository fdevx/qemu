/*
 * Initial TCG Implementation for aarch64
 *
 * Copyright (c) 2013 Huawei Technologies Duesseldorf GmbH
 * Written by Claudio Fontana
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or
 * (at your option) any later version.
 *
 * See the COPYING file in the top-level directory for details.
 */

#ifndef AARCH64_TCG_TARGET_H
#define AARCH64_TCG_TARGET_H

// just for testing - TODO remove
//#define FENCES_CONST
// fence type: 0 - none; 1 - normal; 2 - tso (without fences)
#define FENCE_TYPE 0


#define TCG_TARGET_INSN_UNIT_SIZE  4
#define TCG_TARGET_TLB_DISPLACEMENT_BITS 24
#define MAX_CODE_GEN_BUFFER_SIZE  (2 * GiB)
#undef TCG_TARGET_STACK_GROWSUP

typedef enum {
    TCG_REG_X0, TCG_REG_X1, TCG_REG_X2, TCG_REG_X3,
    TCG_REG_X4, TCG_REG_X5, TCG_REG_X6, TCG_REG_X7,
    TCG_REG_X8, TCG_REG_X9, TCG_REG_X10, TCG_REG_X11,
    TCG_REG_X12, TCG_REG_X13, TCG_REG_X14, TCG_REG_X15,
    TCG_REG_X16, TCG_REG_X17, TCG_REG_X18, TCG_REG_X19,
    TCG_REG_X20, TCG_REG_X21, TCG_REG_X22, TCG_REG_X23,
    TCG_REG_X24, TCG_REG_X25, TCG_REG_X26, TCG_REG_X27,
    TCG_REG_X28, TCG_REG_X29, TCG_REG_X30,

    /* X31 is either the stack pointer or zero, depending on context.  */
    TCG_REG_SP = 31,
    TCG_REG_XZR = 31,

    TCG_REG_V0 = 32, TCG_REG_V1, TCG_REG_V2, TCG_REG_V3,
    TCG_REG_V4, TCG_REG_V5, TCG_REG_V6, TCG_REG_V7,
    TCG_REG_V8, TCG_REG_V9, TCG_REG_V10, TCG_REG_V11,
    TCG_REG_V12, TCG_REG_V13, TCG_REG_V14, TCG_REG_V15,
    TCG_REG_V16, TCG_REG_V17, TCG_REG_V18, TCG_REG_V19,
    TCG_REG_V20, TCG_REG_V21, TCG_REG_V22, TCG_REG_V23,
    TCG_REG_V24, TCG_REG_V25, TCG_REG_V26, TCG_REG_V27,
    TCG_REG_V28, TCG_REG_V29, TCG_REG_V30, TCG_REG_V31,

    /* Aliases.  */
    TCG_REG_FP = TCG_REG_X29,
    TCG_REG_LR = TCG_REG_X30,
    TCG_AREG0  = TCG_REG_X19,
} TCGReg;

#define TCG_TARGET_NB_REGS 64

/* used for function call generation */
#define TCG_REG_CALL_STACK              TCG_REG_SP
#define TCG_TARGET_STACK_ALIGN          16
#define TCG_TARGET_CALL_ALIGN_ARGS      1
#define TCG_TARGET_CALL_STACK_OFFSET    0

/* optional instructions */
#define TCG_TARGET_HAS_div_i32          1
#define TCG_TARGET_HAS_rem_i32          1
#define TCG_TARGET_HAS_ext8s_i32        1
#define TCG_TARGET_HAS_ext16s_i32       1
#define TCG_TARGET_HAS_ext8u_i32        1
#define TCG_TARGET_HAS_ext16u_i32       1
#define TCG_TARGET_HAS_bswap16_i32      1
#define TCG_TARGET_HAS_bswap32_i32      1
#define TCG_TARGET_HAS_not_i32          1
#define TCG_TARGET_HAS_neg_i32          1
#define TCG_TARGET_HAS_rot_i32          1
#define TCG_TARGET_HAS_andc_i32         1
#define TCG_TARGET_HAS_orc_i32          1
#define TCG_TARGET_HAS_eqv_i32          1
#define TCG_TARGET_HAS_nand_i32         0
#define TCG_TARGET_HAS_nor_i32          0
#define TCG_TARGET_HAS_clz_i32          1
#define TCG_TARGET_HAS_ctz_i32          1
#define TCG_TARGET_HAS_ctpop_i32        0
#define TCG_TARGET_HAS_deposit_i32      1
#define TCG_TARGET_HAS_extract_i32      1
#define TCG_TARGET_HAS_sextract_i32     1
#define TCG_TARGET_HAS_extract2_i32     1
#define TCG_TARGET_HAS_movcond_i32      1
#define TCG_TARGET_HAS_add2_i32         1
#define TCG_TARGET_HAS_sub2_i32         1
#define TCG_TARGET_HAS_mulu2_i32        0
#define TCG_TARGET_HAS_muls2_i32        0
#define TCG_TARGET_HAS_muluh_i32        0
#define TCG_TARGET_HAS_mulsh_i32        0
#define TCG_TARGET_HAS_extrl_i64_i32    0
#define TCG_TARGET_HAS_extrh_i64_i32    0
#define TCG_TARGET_HAS_qemu_st8_i32     0

#define TCG_TARGET_HAS_div_i64          1
#define TCG_TARGET_HAS_rem_i64          1
#define TCG_TARGET_HAS_ext8s_i64        1
#define TCG_TARGET_HAS_ext16s_i64       1
#define TCG_TARGET_HAS_ext32s_i64       1
#define TCG_TARGET_HAS_ext8u_i64        1
#define TCG_TARGET_HAS_ext16u_i64       1
#define TCG_TARGET_HAS_ext32u_i64       1
#define TCG_TARGET_HAS_bswap16_i64      1
#define TCG_TARGET_HAS_bswap32_i64      1
#define TCG_TARGET_HAS_bswap64_i64      1
#define TCG_TARGET_HAS_not_i64          1
#define TCG_TARGET_HAS_neg_i64          1
#define TCG_TARGET_HAS_rot_i64          1
#define TCG_TARGET_HAS_andc_i64         1
#define TCG_TARGET_HAS_orc_i64          1
#define TCG_TARGET_HAS_eqv_i64          1
#define TCG_TARGET_HAS_nand_i64         0
#define TCG_TARGET_HAS_nor_i64          0
#define TCG_TARGET_HAS_clz_i64          1
#define TCG_TARGET_HAS_ctz_i64          1
#define TCG_TARGET_HAS_ctpop_i64        0
#define TCG_TARGET_HAS_deposit_i64      1
#define TCG_TARGET_HAS_extract_i64      1
#define TCG_TARGET_HAS_sextract_i64     1
#define TCG_TARGET_HAS_extract2_i64     1
#define TCG_TARGET_HAS_movcond_i64      1
#define TCG_TARGET_HAS_add2_i64         1
#define TCG_TARGET_HAS_sub2_i64         1
#define TCG_TARGET_HAS_mulu2_i64        0
#define TCG_TARGET_HAS_muls2_i64        0
#define TCG_TARGET_HAS_muluh_i64        1
#define TCG_TARGET_HAS_mulsh_i64        1
#define TCG_TARGET_HAS_direct_jump      1

#define TCG_TARGET_HAS_v64              1
#define TCG_TARGET_HAS_v128             1
#define TCG_TARGET_HAS_v256             0

#define TCG_TARGET_HAS_andc_vec         1
#define TCG_TARGET_HAS_orc_vec          1
#define TCG_TARGET_HAS_nand_vec         0
#define TCG_TARGET_HAS_nor_vec          0
#define TCG_TARGET_HAS_eqv_vec          0
#define TCG_TARGET_HAS_not_vec          1
#define TCG_TARGET_HAS_neg_vec          1
#define TCG_TARGET_HAS_abs_vec          1
#define TCG_TARGET_HAS_roti_vec         0
#define TCG_TARGET_HAS_rots_vec         0
#define TCG_TARGET_HAS_rotv_vec         0
#define TCG_TARGET_HAS_shi_vec          1
#define TCG_TARGET_HAS_shs_vec          0
#define TCG_TARGET_HAS_shv_vec          1
#define TCG_TARGET_HAS_mul_vec          1
#define TCG_TARGET_HAS_sat_vec          1
#define TCG_TARGET_HAS_minmax_vec       1
#define TCG_TARGET_HAS_bitsel_vec       1
#define TCG_TARGET_HAS_cmpsel_vec       0

/*
 * This defines the natural memory order supported by this
 * architecture before guarantees made by various barrier
 * instructions.
 *
 * The aarch64 has a pretty weak memory ordering by default which
 * allows any reordering for stores and loads.
 *
 * However, the M1 Mac Processor has a switch to enable x86's
 * stronger memory ordering in hardware which should
 * speed up the execution.
 */
#include "tcg/tcg-mo.h"

extern TCGBar target_memory_ordering;

#ifndef FENCES_CONST
#define TCG_TARGET_DEFAULT_MO target_memory_ordering

#else

#if FENCE_TYPE == 1
  #define TCG_TARGET_DEFAULT_MO 0
#else
  #define TCG_TARGET_DEFAULT_MO (TCG_MO_ALL & ~TCG_MO_ST_LD)
#endif

#endif

#define TCG_TARGET_HAS_MEMORY_BSWAP     0

void tb_target_set_jmp_target(uintptr_t, uintptr_t, uintptr_t, uintptr_t);

#define TCG_TARGET_NEED_LDST_LABELS
#define TCG_TARGET_NEED_POOL_LABELS

#endif /* AARCH64_TCG_TARGET_H */
