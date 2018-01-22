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

#ifndef BMFF_H
#define BMFF_H

#include <stdint.h>
#include <stdlib.h>
#include "boxes.h"

// Software version, format MAJOR.MINOR.PATCH
#define BMFF_VERSION                             "0.1.0"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Callback Event Ids.
 */
typedef enum BMFFEventId {
    BMFFEventParseStart,
    BMFFEventParseComplete,
    BMFFEventParseError,
    BMFFEventParserNotFound,
} BMFFEventId;

// forward declaration
typedef struct BMFFContext BMFFContext;

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
 * Memory deallocator.
 */
typedef void (*bmff_free) (void *mem);

/**
 * Parse Callback.
 */
typedef void (*bmff_on_event) (BMFFContext *ctx,
                                BMFFEventId id,
                                const uint8_t *fourCC,
                                void *data);

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
 * LinkList of pointers.
 */
typedef struct MemList {
    size_t *addresses;
    uint32_t count;
    uint32_t used;
    struct MemList *next;
} MemList;

/**
 * BMFF Parsing Context.
 */
typedef struct BMFFContext {
    bmff_malloc malloc;
    bmff_realloc realloc;
    bmff_calloc calloc;
    bmff_free free;
    // user specified callback that is called when Boxes are parsed
    bmff_on_event callback;
    // sample count set by the stsz or stz2 parser and used by the sdtp and stdp parsers.
    uint32_t sample_count;
    // current track sampler handler type used by the stsd and sgpd boxes to parse sample
    // description data.
    // this data comes from the active HandlerBox.
    uint8_t handler_type[4];
    // channel count set by the last AudioSampleEntry that was parsed.
    // this is used by the chnl box parser.
    uint32_t channel_count;
    // version of the last sample description box. Used by the AudioSampleEntry box parser.
    uint32_t sample_description_version;
    // memory allocations stack (linked list)
    MemList *allocs_stack;
    // default IV size set by the Track Encryption Box parser. Used by the Sample Encrpytion Box Parser.
    uint8_t default_iv_size;
} BMFFContext;

const char *bmff_get_version(void);

/**
 * Initializes a parsing context.
 */
BMFFCode bmff_context_init(BMFFContext *ctx);

/**
 * Destroys an initialized parsing Context.
 */
BMFFCode bmff_context_destroy(BMFFContext *ctx);

/**
 * Sets the parsing callback.
 * The user must set the callback to retreive Box information.
 */
BMFFCode bmff_set_event_callback(BMFFContext *ctx, bmff_on_event callback);

/**
 * Parses ISO BMFF boxes.
 * The data must contain complete boxes, but does not need to contain a full file.
 */
size_t bmff_parse(BMFFContext *ctx, const uint8_t *data, size_t size, BMFFCode *code);

/**
 * This needs to be called to end a parsing session.
 */
BMFFCode bmff_parse_end(BMFFContext *ctx);

#ifdef __cplusplus
}
#endif

#endif // BMFF_H
