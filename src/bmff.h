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
#include <stdio.h>

#include "parse.h"

// Software version, format MAJOR.MINOR.PATCH
#define BMFF_VERSION                             "0.1.0"

#ifdef __cplusplus
extern "C" {
#endif

const char *bmff_get_version(void);

/**
 * Initializes a Parsing Context.
 */
BMFFCode bmff_context_init(BMFFContext *ctx);

/**
 * Destroys an initialize Parsing Context.
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
