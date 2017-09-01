/*
 * MIT License
 *
 * Copyright (c) 2017 Joel Freeman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdint.h>
#include <stdlib.h>

#include "boxes.h"

// forward declarations
typedef struct BMFFContext BMFFContext;
typedef enum BMFFEventId BMFFEventId;

/**
 * Memory Allocator.
 * Allocate memory block.
 * See malloc C90 (C++98) definition.
 */
typedef void * (*bmff_malloc) (size_t size);

/**
 * Memory Allocator.
 * Allocate and zero initialize array.
 * See calloc C90 (C++98) definition.
 */
typedef void * (*bmff_calloc) (size_t num, size_t size);

/**
 * Memory Allocator.
 * Changes the size of the memory block pointed at by ptr.
 * See realloc C90 (C++98) definition.
 */
typedef void * (*bmff_realloc) (void *ptr, size_t size);

/**
 * Parse Callback.
 */
typedef void * (bmff_on_event) (BMFFContext *ctx,
                                BMFFEventId id,
                                void *data);

/**
 * Memory deallocator.
 */
typedef void (*bmff_free) (void *mem);

/**
 * Return codes.
 */
typedef enum BMFFCode {
    BMFF_OK                                 = 0x0000,
    BMFF_INVALID_CONTEXT                    = 0x0001,
    BMFF_INVALID_DATA                       = 0x0002,
    BMFF_INVALID_SIZE                       = 0x0003,
    BMFF_INVALID_PARAMETER                  = 0x0004,
} BMFFCode;

/**
 * Callback Event Ids.
 */
typedef enum BMFFEventId {
    something,
} BMFFEventId;

/**
 * BMFF Parsing Context.
 */
typedef struct BMFFContext {
    bmff_malloc malloc;
    bmff_realloc realloc;
    bmff_calloc calloc;
    bmff_free free;
    // sample count set by the stsz or stz2 parser and used by the sdtp and stdp parsers.
    uint32_t sample_count;
    // current track sampler handler type used by the stsd and sgpd boxes to parse sample
    // description data.
    // this data comes from the active HandlerBox.
    uint8_t track_sample_table_handler_type[4];
} BMFFContext;

#endif // CONTEXT_H
