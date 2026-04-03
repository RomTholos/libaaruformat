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

#ifndef LIBAARUFORMAT_FLAC_H
#define LIBAARUFORMAT_FLAC_H

typedef struct
{
    const uint8_t *src_buffer;
    size_t         src_len;
    size_t         src_pos;
    uint8_t       *dst_buffer;
    size_t         dst_len;
    size_t         dst_pos;
    uint8_t        error;
} aaru_flac_ctx;

#endif  // LIBAARUFORMAT_FLAC_H
