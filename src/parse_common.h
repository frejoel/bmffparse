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

#ifndef PARSE_COMMON_H
#define PARSE_COMMON_H

#include <stdint.h>
#include <memory.h>
#include "bmff.h"
#include "context.h"

#define ADV_PARSE_U8(A,P)      ((A) = (P)[0]); ((P)++)
#define ADV_PARSE_S8(A,P)      ((A) = (P)[0]); ((P)++);
#define ADV_PARSE_U16(A,P)      ((A) = parse_u16(P)); ((P)+=2);
#define ADV_PARSE_S16(A,P)      ((A) = (int16_t)parse_u16(P)); ((P)+=2);
#define ADV_PARSE_U32(A,P)      ((A) = parse_u32(P)); ((P)+=4);
#define ADV_PARSE_S32(A,P)      ((A) = (int32_t)parse_u32(P)); ((P)+=4);
#define ADV_PARSE_U64(A,P)      ((A) = parse_u64(P)); ((P)+=8);
#define ADV_PARSE_S64(A,P)      ((A) = (int64_t)parse_u64(P)); ((P)+=8);
#define ADV_PARSE_FP16(A,P)     ((A) = parse_fp16(P)); ((P)+=4);
#define ADV_PARSE_FP8(A,P)      ((A) = parse_fp8(P)); ((P)+=2);
#define ADV_PARSE_STR(A,P)      ((A) = (P)); while(*(P) != '\0'){(P)++;}; (P)++;
#define ADV_PARSE_MATRIX(A,P)   int i=0; for(;i<9;++i){(A)[i] = (int32_t)parse_u32(P);(P)+=4;}; 

#define BOX_MALLOC(M, T)        T *M = bmff_context_alloc_on_stack(ctx, sizeof(T)); memset(M, 0, sizeof(T));
#define BOX_MALLOCN(M, T, N)    M = bmff_context_alloc_on_stack(ctx, sizeof(T)*(N)); memset(M, 0, sizeof(T)*(N));      

// conversion functions
uint16_t parse_u16(const uint8_t *data);
uint32_t parse_u32(const uint8_t *data);
uint64_t parse_u64(const uint8_t *data);
fxpt16_t parse_fp16(const uint8_t *data);
fxpt8_t parse_fp8(const uint8_t *bytes);
uint32_t parse_var_length(const uint8_t *bytes, uint8_t length);

#endif // PARSE_COMMON_H