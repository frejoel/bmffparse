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

#include "bmff.h"

/**
 * Adds a new to the stack of memory allocations.
 */
void bmff_context_alloc_stack_push(BMFFContext *ctx);

/**
 * Removes the last layer of the memory allocations stack freeing all
 * allocations that were done on this layer.
 */
void bmff_context_alloc_stack_pop(BMFFContext *ctx);

/**
 * Allocates memory on the active stack.
 */
void * bmff_context_alloc_on_stack(BMFFContext *ctx, size_t size);

/**
 * Adds an item onto the breadcrumb
 */
void _bmff_breadcrumb_push(BMFFContext *ctx, const uint8_t *crumb);

/**
 * Removes the last item from the breadcrumb.
 */
void _bmff_breadcrumb_pop(BMFFContext *ctx);

#endif // CONTEXT_H
