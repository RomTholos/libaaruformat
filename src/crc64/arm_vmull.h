/*
 * This file is part of the Aaru Data Preservation Suite.
 * Copyright (c) 2019-2026 Natalia Portillo.
 *
 * SPDX-License-Identifier: MIT OR LGPL-2.1-or-later
 *
 * This file is dual-licensed. You may use, modify, and distribute it under
 * either the terms of the MIT license (see LICENSE-MIT) or the GNU Lesser
 * General Public License v2.1 or later (see LICENSE), at your option.
 */

#ifndef LIBAARUFORMAT_NATIVE_ARM_VMULL_H
#define LIBAARUFORMAT_NATIVE_ARM_VMULL_H

#if defined(__aarch64__) || defined(_M_ARM64) || defined(__arm__) || defined(_M_ARM)

#ifdef TARGET_WITH_CRYPTO
TARGET_WITH_CRYPTO static uint64x2_t sse2neon_vmull_p64_crypto(uint64x1_t _a, uint64x1_t _b);
#endif
TARGET_WITH_SIMD uint64x2_t          sse2neon_vmull_p64(uint64x1_t _a, uint64x1_t _b);
TARGET_WITH_SIMD uint64x2_t          mm_shuffle_epi8(uint64x2_t a, uint64x2_t b);
TARGET_WITH_SIMD uint64x2_t          mm_srli_si128(uint64x2_t a, int imm);
TARGET_WITH_SIMD uint64x2_t          mm_slli_si128(uint64x2_t a, int imm);

#endif

#endif  // LIBAARUFORMAT_NATIVE_ARM_VMULL_H
