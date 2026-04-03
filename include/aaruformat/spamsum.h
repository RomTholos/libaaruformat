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

#ifndef LIBAARUFORMAT_SPAMSUM_H_
#define LIBAARUFORMAT_SPAMSUM_H_

#include <stdint.h>

#define SPAMSUM_LENGTH   64
#define NUM_BLOCKHASHES  31
#define ROLLING_WINDOW   7
#define HASH_INIT        0x28021967
#define HASH_PRIME       0x01000193
#define MIN_BLOCKSIZE    3
#define FUZZY_MAX_RESULT ((2 * SPAMSUM_LENGTH) + 20)

typedef struct
{
    uint32_t h;
    uint32_t half_h;
    uint8_t  digest[SPAMSUM_LENGTH];
    uint8_t  half_digest;
    uint32_t d_len;
} blockhash_ctx;

typedef struct
{
    uint8_t  window[ROLLING_WINDOW];
    uint32_t h1;
    uint32_t h2;
    uint32_t h3;
    uint32_t n;
} roll_state;

typedef struct
{
    uint32_t      bh_start;
    uint32_t      bh_end;
    blockhash_ctx bh[NUM_BLOCKHASHES];
    uint64_t      total_size;
    roll_state    roll;
} spamsum_ctx;

#endif  // LIBAARUFORMAT_SPAMSUM_H_
