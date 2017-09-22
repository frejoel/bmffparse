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
#define PARSE_MAP_LEN   (106)

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
PARSER_FUNC(_bmff_parse_box_track_reference_type);
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
PARSER_FUNC(_bmff_parse_box_sample_to_group);
PARSER_FUNC(_bmff_parse_box_sub_sample_information);
PARSER_FUNC(_bmff_parse_box_copyright);
PARSER_FUNC(_bmff_parse_box_data_entry_url);
PARSER_FUNC(_bmff_parse_box_data_entry_urn);
PARSER_FUNC(_bmff_parse_box_data_reference);
PARSER_FUNC(_bmff_parse_box_edit_list);
PARSER_FUNC(_bmff_parse_box_media_header);
PARSER_FUNC(_bmff_parse_box_video_media_header);
PARSER_FUNC(_bmff_parse_box_sound_media_header);
PARSER_FUNC(_bmff_parse_box_hint_media_header);
PARSER_FUNC(_bmff_parse_box_sample_description);
PARSER_FUNC(_bmff_parse_box_time_to_sample);
PARSER_FUNC(_bmff_parse_box_composition_offset);
PARSER_FUNC(_bmff_parse_box_sample_to_chunk);
PARSER_FUNC(_bmff_parse_box_sample_size);
PARSER_FUNC(_bmff_parse_box_compact_sample_size);
PARSER_FUNC(_bmff_parse_box_chunk_offset);
PARSER_FUNC(_bmff_parse_box_chunk_large_offset);
PARSER_FUNC(_bmff_parse_box_sync_sample);
PARSER_FUNC(_bmff_parse_box_shadow_sync_sample);
PARSER_FUNC(_bmff_parse_box_padding_bits);
PARSER_FUNC(_bmff_parse_box_degradation_priority);
PARSER_FUNC(_bmff_parse_box_sample_group_description);
PARSER_FUNC(_bmff_parse_box_track_group_type);
PARSER_FUNC(_bmff_parse_box_extended_language_tag);
PARSER_FUNC(_bmff_parse_box_bit_rate);
PARSER_FUNC(_bmff_parse_box_composition_to_decode);
PARSER_FUNC(_bmff_parse_box_sample_aux_info_sizes);
PARSER_FUNC(_bmff_parse_box_sample_aux_info_offsets);
PARSER_FUNC(_bmff_parse_box_track_fragment_decode_time);
PARSER_FUNC(_bmff_parse_box_level_assignment);
PARSER_FUNC(_bmff_parse_box_track_extension_properties);
PARSER_FUNC(_bmff_parse_box_alt_startup_seq_properties);
PARSER_FUNC(_bmff_parse_box_track_selection);
PARSER_FUNC(_bmff_parse_box_kind);
PARSER_FUNC(_bmff_parse_box_item_reference);
PARSER_FUNC(_bmff_parse_box_item_data);
PARSER_FUNC(_bmff_parse_box_metabox_relation);
PARSER_FUNC(_bmff_parse_box_file_partition);
PARSER_FUNC(_bmff_parse_box_reservoir);
PARSER_FUNC(_bmff_parse_box_partition_entry);
PARSER_FUNC(_bmff_parse_box_fd_session_group);
PARSER_FUNC(_bmff_parse_box_group_id_to_name);
PARSER_FUNC(_bmff_parse_box_fd_item_information);
PARSER_FUNC(_bmff_parse_box_sub_track_information);
PARSER_FUNC(_bmff_parse_box_sub_track_sample_group);
PARSER_FUNC(_bmff_parse_box_stereo_video);
PARSER_FUNC(_bmff_parse_box_segment_index);
PARSER_FUNC(_bmff_parse_box_producer_reference_time);
PARSER_FUNC(_bmff_parse_box_complete_track_info);

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
