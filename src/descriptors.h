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
#ifndef DESCRIPTORS_H
#define DESCRIPTORS_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// Descriptor parsing from ISO/IEC 14496-1

typedef uint8_t IPMPDescriptor;

typedef struct IPMPTool {
    uint8_t         tool_id[16];
    uint8_t         is_alt_group;
    uint8_t         is_parametric;
    uint8_t         num_alternates;
    uint8_t         specific_tool_id[16];
    const uint8_t   *tool_param_desc;
    uint8_t         num_urls;
    uint8_t         **tool_urls;
} IPMPTool;

typedef struct IPMPToolListDescriptor {
    uint8_t     tag;
    uint8_t     num_tools;
    IPMPTool    *ipmp_tools;
} IPMPToolListDescriptor;

typedef struct ObjectDescriptor {
    uint8_t                 od_tag;
    uint16_t                od_id;
    uint8_t                 url_flag;
    uint8_t                 include_inline_profile_level_flag;
    uint8_t                 url_length;
    uint8_t                 *url;
    uint8_t                 od_profile_level_indicator;
    uint8_t                 scene_profile_level_indicator;
    uint8_t                 audio_profile_level_indicator;
    uint8_t                 visual_profile_level_indicator;
    uint8_t                 graphics_profile_level_indicator;
    const uint8_t           *descriptors; // raw descriptor data
    uint32_t                descriptors_size; // the number of bytes in descriptors
} ObjectDescriptor;

#ifdef __cplusplus
}
#endif

#endif // DESCRIPTORS_H
