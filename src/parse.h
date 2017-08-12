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

#ifndef PARSE_H
#define PARSE_H

#include "context.h"
#include "boxes.h"

#define PARSER_FUNC(func_name)  BMFFCode func_name(BMFFContext *ctx, const uint8_t * data, size_t size, Box **box_ptr)
// number of items in the parse_map
#define PARSE_MAP_LEN   (45) // 68

/*
 * Box parser functioin potiner.
 */
typedef BMFFCode (*parse_func) (BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr);

// conversion functions
uint16_t parse_u16(const uint8_t *data);
uint32_t parse_u32(const uint8_t *data);
uint64_t parse_u64(const uint8_t *data);
fxpt16_t parse_fp16(const uint8_t *data);

// list of parsing functions.
PARSER_FUNC(_bmff_parse_box_file_type);
PARSER_FUNC(_bmff_parse_box_generic_container);
PARSER_FUNC(_bmff_parse_box_track_reference);
PARSER_FUNC(_bmff_parse_box_full);
PARSER_FUNC(_bmff_parse_box_progressive_download_info);
PARSER_FUNC(_bmff_parse_box_media_data);
PARSER_FUNC(_bmff_parse_box_handler);
PARSER_FUNC(_bmff_parse_box_primary_item);
PARSER_FUNC(_bmff_parse_box_item_location);
PARSER_FUNC(_bmff_parse_box_item_info_entry);
PARSER_FUNC(_bmff_parse_box_item_info);
PARSER_FUNC(_bmff_parse_box_ipmp_control);
PARSER_FUNC(_bmff_parse_box_original_format);
PARSER_FUNC(_bmff_parse_box_ipmp_info);
PARSER_FUNC(_bmff_parse_box_scheme_type);
PARSER_FUNC(_bmff_parse_box_scheme_info);
PARSER_FUNC(_bmff_parse_box_protection_scheme_info);
PARSER_FUNC(_bmff_parse_box_item_protection);
PARSER_FUNC(_bmff_parse_box_meta);
PARSER_FUNC(_bmff_parse_box_movie_header);
PARSER_FUNC(_bmff_parse_box_movie_fragment_header);
PARSER_FUNC(_bmff_parse_box_track_fragment_random_access);
PARSER_FUNC(_bmff_parse_box_movie_fragment_random_access_offset);
PARSER_FUNC(_bmff_parse_box_xml);
PARSER_FUNC(_bmff_parse_box_track_header);
PARSER_FUNC(_bmff_parse_box_movie_extends_header);
PARSER_FUNC(_bmff_parse_box_track_extends);
PARSER_FUNC(_bmff_parse_box_track_fragment_header);
PARSER_FUNC(_bmff_parse_box_track_run);
PARSER_FUNC(_bmff_parse_box_sample_dependency_type);

typedef struct MapItem {
    union {
        const char  box_type[4];    // 4 character code for the Box type.
        uint32_t    box_type_value; // Box type as a 32 bit integer.
    };
    uint8_t     is_container_type;  // whether the Box is a continer Box.
    parse_func  parse_func;         // function used to parse this type of Box.
} MapItem;

/**
 * List of functions used to parse the different ISO BMFF Boxes.
 */
const MapItem parse_map[PARSE_MAP_LEN];

#endif // PARSE_H
