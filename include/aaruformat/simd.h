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

#ifndef LIBAARUFORMAT_SIMD_H
#define LIBAARUFORMAT_SIMD_H

#ifdef _MSC_VER
#define ALIGNED_(n) __declspec(align(n))
#else
#define ALIGNED_(n) __attribute__((aligned(n)))
#endif

#if defined(__x86_64__) || defined(__amd64) || defined(_M_AMD64) || defined(_M_X64) || defined(__I386__) || \
    defined(__i386__) || defined(__THW_INTEL) || defined(_M_IX86)

#ifdef _MSC_VER
#define AVX2
#define SSSE3
#define CLMUL
#else
#define AVX2  __attribute__((target("avx2")))
#define SSSE3 __attribute__((target("ssse3")))
#define CLMUL __attribute__((target("pclmul,sse4.1")))
#endif
#endif

#if(defined(__arm__) || defined(_M_ARM)) && !defined(_WIN32)
#define HWCAP_NEON   (1 << 12)
#define HWCAP2_AES   (1 << 0)
#define HWCAP2_CRC32 (1 << 4)
#endif

#if(defined(__aarch64__) || defined(_M_ARM64)) && !defined(_WIN32)
#define HWCAP_NEON  (1 << 1)
#define HWCAP_AES   (1 << 3)
#define HWCAP_CRC32 (1 << 7)
#endif

#if defined(__aarch64__) || defined(_M_ARM64) || defined(__arm__) || defined(_M_ARM)

#ifndef __ARM_FEATURE_CRC32
#define __ARM_FEATURE_CRC32 1
#endif

#ifdef _MSC_VER

#define TARGET_ARMV8_WITH_CRC
#define TARGET_WITH_CRYPTO
#define TARGET_WITH_SIMD

#else  // _MSC_VER

#if defined(__aarch64__) || defined(_M_ARM64)

#ifdef __clang__
#define TARGET_ARMV8_WITH_CRC __attribute__((target("crc")))
#else
#define TARGET_ARMV8_WITH_CRC __attribute__((target("+crc")))
#endif

#ifdef __clang__
#define TARGET_WITH_CRYPTO __attribute__((target("crypto")))
#else
#define TARGET_WITH_CRYPTO __attribute__((target("+crypto")))
#endif

#define TARGET_WITH_SIMD
#else

#if __ARM_ARCH >= 8

#ifdef __clang__
#define TARGET_ARMV8_WITH_CRC __attribute__((target("armv8-a,crc")))
#define TARGET_WITH_CRYPTO    __attribute__((target("armv8-a,crypto")))
#else
#define TARGET_ARMV8_WITH_CRC __attribute__((target("arch=armv8-a+crc")))
#define TARGET_WITH_CRYPTO    __attribute__((target("fpu=crypto-neon-fp-armv8")))
#endif

#endif  // __ARM_ARCH >= 8

#ifdef __clang__
#define TARGET_WITH_SIMD __attribute__((target("neon")))
#else
#define TARGET_WITH_SIMD __attribute__((target("fpu=neon")))
#endif

#endif  // __aarch64__ || _M_ARM64

#endif  // _MSC_VER

#endif  // __aarch64__ || _M_ARM64 || __arm__ || _M_ARM

#endif  // LIBAARUFORMAT_SIMD_H
