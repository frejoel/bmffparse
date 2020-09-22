#include <memory.h>
#include <stdio.h>
#include "parse_common.h"
#include "parse.h"

#define CALLBACK(c, e, f, d)  if((c)->callback) { (c)->callback((c), (e), (f), (void*)(d), (c)->callback_user_data); }

//const MapItem parse_map[] = {
MapItem _create_map_item(const char box_type[4], uint8_t is_container_type, parse_func parse_func)
{
    MapItem item;
    memcpy(item.box_type, box_type, 4);
    item.is_container_type = is_container_type;
    item.parse_func = parse_func;
    return item;
}

void _init_global_parse_map()
{
    parse_map[0] = _create_map_item("ftyp", 1, _bmff_parse_box_file_type);
    parse_map[1] = _create_map_item("styp", 1, _bmff_parse_box_file_type);
    parse_map[2] = _create_map_item("moov", 1, _bmff_parse_box_generic_container);
    parse_map[3] = _create_map_item("trak", 1, _bmff_parse_box_generic_container);
    parse_map[4] = _create_map_item("edts", 1, _bmff_parse_box_generic_container);
    parse_map[5] = _create_map_item("mdia", 1, _bmff_parse_box_generic_container);
    parse_map[6] = _create_map_item("minf", 1, _bmff_parse_box_generic_container);
    parse_map[7] = _create_map_item("dinf", 1, _bmff_parse_box_generic_container);
    parse_map[8] = _create_map_item("stbl", 1, _bmff_parse_box_generic_container);
    parse_map[9] = _create_map_item("mvex", 1, _bmff_parse_box_generic_container);
    parse_map[10] = _create_map_item("moof", 1, _bmff_parse_box_generic_container);
    parse_map[11] = _create_map_item("traf", 1, _bmff_parse_box_generic_container);
    parse_map[12] = _create_map_item("mfra", 1, _bmff_parse_box_generic_container);
    parse_map[13] = _create_map_item("udta", 1, _bmff_parse_box_generic_container);
    parse_map[14] = _create_map_item("tref", 1, _bmff_parse_box_generic_container);
    parse_map[15] = _create_map_item("meco", 1, _bmff_parse_box_generic_container);
    parse_map[16] = _create_map_item("strk", 1, _bmff_parse_box_generic_container);
    parse_map[17] = _create_map_item("strd", 1, _bmff_parse_box_generic_container);
    parse_map[18] = _create_map_item("schi", 1, _bmff_parse_box_generic_container);
    parse_map[19] = _create_map_item("free", 0, _bmff_parse_box);
    parse_map[20] = _create_map_item("hint", 0, _bmff_parse_box_track_reference_type);
    parse_map[21] = _create_map_item("cdsc", 0, _bmff_parse_box_track_reference_type);
    parse_map[22] = _create_map_item("font", 0, _bmff_parse_box_track_reference_type);
    parse_map[23] = _create_map_item("vdep", 0, _bmff_parse_box_track_reference_type);
    parse_map[24] = _create_map_item("vplx", 0, _bmff_parse_box_track_reference_type);
    parse_map[25] = _create_map_item("subt", 0, _bmff_parse_box_track_reference_type);
    parse_map[26] = _create_map_item("nmhd", 0, _bmff_parse_box_full);
    parse_map[27] = _create_map_item("pdin", 0, _bmff_parse_box_progressive_download_info);
    parse_map[28] = _create_map_item("mdat", 0, _bmff_parse_box_media_data);
    parse_map[29] = _create_map_item("hdlr", 0, _bmff_parse_box_handler);
    parse_map[30] = _create_map_item("pitm", 0, _bmff_parse_box_primary_item);
    parse_map[31] = _create_map_item("iloc", 0, _bmff_parse_box_primary_item);
    parse_map[32] = _create_map_item("infe", 0, _bmff_parse_box_item_info_entry);
    parse_map[33] = _create_map_item("iinf", 0, _bmff_parse_box_item_info);
    parse_map[34] = _create_map_item("ipmc", 0, _bmff_parse_box_ipmp_control);
    parse_map[35] = _create_map_item("frma", 0, _bmff_parse_box_original_format);
    parse_map[36] = _create_map_item("imif", 0, _bmff_parse_box_ipmp_info);
    parse_map[37] = _create_map_item("schm", 0, _bmff_parse_box_scheme_type);
    parse_map[38] = _create_map_item("sinf", 0, _bmff_parse_box_protection_scheme_info);
    parse_map[39] = _create_map_item("ipro", 0, _bmff_parse_box_item_protection);
    parse_map[40] = _create_map_item("meta", 0, _bmff_parse_box_meta);
    parse_map[41] = _create_map_item("mvhd", 0, _bmff_parse_box_movie_header);
    parse_map[42] = _create_map_item("mfhd", 0, _bmff_parse_box_movie_fragment_header);
    parse_map[43] = _create_map_item("tfra", 0, _bmff_parse_box_track_fragment_random_access);
    parse_map[44] = _create_map_item("mfro", 0, _bmff_parse_box_movie_fragment_random_access_offset);
    parse_map[45] = _create_map_item("xml ", 0, _bmff_parse_box_xml);
    parse_map[46] = _create_map_item("bxml", 0, _bmff_parse_box_xml);
    parse_map[47] = _create_map_item("tkhd", 0, _bmff_parse_box_track_header);
    parse_map[48] = _create_map_item("mehd", 0, _bmff_parse_box_movie_extends_header);
    parse_map[49] = _create_map_item("trex", 0, _bmff_parse_box_track_extends);
    parse_map[50] = _create_map_item("tfhd", 0, _bmff_parse_box_track_fragment_header);
    parse_map[51] = _create_map_item("trun", 0, _bmff_parse_box_track_run);
    parse_map[52] = _create_map_item("sdtp", 0, _bmff_parse_box_sample_dependency_type);
    parse_map[53] = _create_map_item("sbgp", 0, _bmff_parse_box_sample_to_group);
    parse_map[54] = _create_map_item("subs", 0, _bmff_parse_box_sub_sample_information);
    parse_map[55] = _create_map_item("cprt", 0, _bmff_parse_box_copyright);
    parse_map[56] = _create_map_item("url ", 0, _bmff_parse_box_data_entry_url);
    parse_map[57] = _create_map_item("urn ", 0, _bmff_parse_box_data_entry_urn);
    parse_map[58] = _create_map_item("dref", 0, _bmff_parse_box_data_reference);
    parse_map[59] = _create_map_item("elst", 0, _bmff_parse_box_edit_list);
    parse_map[60] = _create_map_item("mdhd", 0, _bmff_parse_box_media_header);
    parse_map[61] = _create_map_item("vmhd", 0, _bmff_parse_box_video_media_header);
    parse_map[62] = _create_map_item("smhd", 0, _bmff_parse_box_sound_media_header);
    parse_map[63] = _create_map_item("hmhd", 0, _bmff_parse_box_hint_media_header);
    parse_map[64] = _create_map_item("sthd", 0, _bmff_parse_box_subtitle_media_header);
    parse_map[65] = _create_map_item("stsd", 0, _bmff_parse_box_sample_description);
    parse_map[66] = _create_map_item("stts", 0, _bmff_parse_box_time_to_sample);
    parse_map[67] = _create_map_item("ctts", 0, _bmff_parse_box_composition_offset);
    parse_map[68] = _create_map_item("stsc", 0, _bmff_parse_box_sample_to_chunk);
    parse_map[69] = _create_map_item("stsz", 0, _bmff_parse_box_sample_size);
    parse_map[70] = _create_map_item("stz2", 0, _bmff_parse_box_compact_sample_size);
    parse_map[71] = _create_map_item("stco", 0, _bmff_parse_box_chunk_offset);
    parse_map[72] = _create_map_item("co64", 0, _bmff_parse_box_chunk_large_offset);
    parse_map[73] = _create_map_item("stss", 0, _bmff_parse_box_sync_sample);
    parse_map[74] = _create_map_item("stsh", 0, _bmff_parse_box_shadow_sync_sample);
    parse_map[75] = _create_map_item("padb", 0, _bmff_parse_box_padding_bits);
    parse_map[76] = _create_map_item("stdp", 0, _bmff_parse_box_degradation_priority);
    parse_map[77] = _create_map_item("sgpd", 0, _bmff_parse_box_sample_group_description);
    parse_map[78] = _create_map_item("msrc", 0, _bmff_parse_box_track_group_type);
    parse_map[79] = _create_map_item("elng", 0, _bmff_parse_box_extended_language_tag);
    parse_map[80] = _create_map_item("btrt", 0, _bmff_parse_box_bit_rate);
    parse_map[81] = _create_map_item("cslg", 0, _bmff_parse_box_composition_to_decode);
    parse_map[82] = _create_map_item("saiz", 0, _bmff_parse_box_sample_aux_info_sizes);
    parse_map[83] = _create_map_item("saio", 0, _bmff_parse_box_sample_aux_info_offsets);
    parse_map[84] = _create_map_item("tfdt", 0, _bmff_parse_box_track_fragment_decode_time);
    parse_map[85] = _create_map_item("leva", 0, _bmff_parse_box_level_assignment);
    parse_map[86] = _create_map_item("trep", 0, _bmff_parse_box_track_extension_properties);
    parse_map[87] = _create_map_item("assp", 0, _bmff_parse_box_alt_startup_seq_properties);
    parse_map[88] = _create_map_item("tsel", 0, _bmff_parse_box_track_selection);
    parse_map[89] = _create_map_item("kind", 0, _bmff_parse_box_kind);
    parse_map[90] = _create_map_item("iref", 0, _bmff_parse_box_item_reference);
    parse_map[91] = _create_map_item("idat", 0, _bmff_parse_box_item_data);
    parse_map[92] = _create_map_item("mere", 0, _bmff_parse_box_metabox_relation);
    parse_map[93] = _create_map_item("fpar", 0, _bmff_parse_box_file_partition);
    parse_map[94] = _create_map_item("fecr", 0, _bmff_parse_box_reservoir);
    parse_map[95] = _create_map_item("fire", 0, _bmff_parse_box_reservoir);
    parse_map[96] = _create_map_item("paen", 0, _bmff_parse_box_partition_entry);
    parse_map[97] = _create_map_item("segr", 0, _bmff_parse_box_fd_session_group);
    parse_map[98] = _create_map_item("gitn", 0, _bmff_parse_box_group_id_to_name);
    parse_map[99] = _create_map_item("fiin", 0, _bmff_parse_box_fd_item_information);
    parse_map[100] = _create_map_item("stri", 0, _bmff_parse_box_sub_track_information);
    parse_map[101] = _create_map_item("stsg", 0, _bmff_parse_box_sub_track_sample_group);
    parse_map[102] = _create_map_item("rinf", 0, _bmff_parse_box_protection_scheme_info);
    parse_map[103] = _create_map_item("stvi", 0, _bmff_parse_box_stereo_video);
    parse_map[104] = _create_map_item("sidx", 0, _bmff_parse_box_segment_index);
    parse_map[105] = _create_map_item("prft", 0, _bmff_parse_box_producer_reference_time);
    parse_map[106] = _create_map_item("cinf", 0, _bmff_parse_box_complete_track_info);
    parse_map[107] = _create_map_item("clap", 0, _bmff_parse_box_clean_aperture);
    parse_map[108] = _create_map_item("pasp", 0, _bmff_parse_box_pixel_aspect_ratio);
    parse_map[109] = _create_map_item("chnl", 0, _bmff_parse_box_channel_layout);
    parse_map[110] = _create_map_item("srat", 0, _bmff_parse_box_sampling_rate);
    parse_map[111] = _create_map_item("ssix", 0, _bmff_parse_box_subsegment_index);
    parse_map[112] = _create_map_item("rtp ", 0, _bmff_parse_box_rtp_hint_sample_entry);
    parse_map[113] = _create_map_item("srtp", 0, _bmff_parse_box_rtp_hint_sample_entry);
    parse_map[114] = _create_map_item("rrtp", 0, _bmff_parse_box_rtp_hint_sample_entry);
    parse_map[115] = _create_map_item("rsrp", 0, _bmff_parse_box_rtp_hint_sample_entry);
    parse_map[116] = _create_map_item("fdp ", 0, _bmff_parse_box_fd_hint_sample_entry);
    parse_map[117] = _create_map_item("metx", 0, _bmff_parse_box_xml_meta_data_sample_entry);
    parse_map[118] = _create_map_item("txtC", 0, _bmff_parse_box_full_string);
    parse_map[119] = _create_map_item("mett", 0, _bmff_parse_box_text_meta_data_sample_entry);
    parse_map[120] = _create_map_item("uri ", 0, _bmff_parse_box_full_string);
    parse_map[121] = _create_map_item("uriI", 0, _bmff_parse_box_full_data);
    parse_map[122] = _create_map_item("urim", 0, _bmff_parse_box_uri_meta_sample_entry);
    parse_map[123] = _create_map_item("iods", 0, _bmff_parse_box_object_descriptor);
    parse_map[124] = _create_map_item("esds", 0, _bmff_parse_box_es_descriptor);
    parse_map[125] = _create_map_item("avcC", 0, _bmff_parse_box_avc_decoder_config);
    parse_map[126] = _create_map_item("senc", 0, _bmff_parse_box_sample_encryption);
    parse_map[127] = _create_map_item("tenc", 0, _bmff_parse_box_track_encryption);
    parse_map[128] = _create_map_item("pssh", 0, _bmff_parse_box_protection_system_specific_header);
    parse_map[129] = _create_map_item("ID32", 0, _bmff_parse_box_id3v2_metadata);
    parse_map[130] = _create_map_item("emsg", 0, _bmff_parse_box_event_message);
};

const int parse_map_len = sizeof(parse_map) / sizeof(MapItem);

int parse_box(const uint8_t *data, size_t size, Box *box)
{
    const uint8_t *ptr = data;
    ADV_PARSE_U32(box->size, ptr);
    
    memcpy(&box->type, ptr, 4); // hint or cdsc
    ptr += 4;

    if(box->size == 1) {
        ADV_PARSE_U64(box->size, ptr);
    }
    if(box->size == 0) {
        box->size = size;
    }

    if(box->type[0] == 'u' && box->type[1] == 'u' && box->type[2] == 'i' && box->type[3] == 'd') {
        box->user_type = ptr;
        ptr += 16;
    }else{
        box->user_type = NULL;
    }

    return ptr - data;
}

int parse_full_box(const uint8_t *data, size_t size, FullBox *box)
{
    const uint8_t *ptr = data;
    ptr += parse_box(data, size, (Box*)box);

    box->version = *ptr;
    ptr++;
    box->flags = (parse_u32(ptr) >> 8) & 0x00FFFFFF;
    ptr += 3;

    return ptr - data;
}

void parse_iso639_2_lang(uint16_t value, uint8_t *output)
{
    output[0] = (uint8_t)(0x0060 + ((value >> 10) & 0x001F));
    output[1] = (uint8_t)(0x0060 + ((value >> 5) & 0x001F));
    output[2] = (uint8_t)(0x0060 + (value & 0x001F));
}

int parse_original_format_box(const uint8_t *data, size_t size, OriginalFormatBox *box)
{
    const uint8_t *ptr = data;
    ptr += parse_box(data, size, (Box*)box);

    memcpy(box->data_format, ptr, 4);
    ptr += 4;

    return ptr - data;
}

BMFFCode _bmff_parse_box(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 8)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, AbstractBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_file_type(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FileTypeBox);

    const uint8_t *ptr = data;
    ptr += parse_box(ptr, size, &box->box);

    memcpy(&box->major_brand, ptr, 4);
    ptr += 4;
    ADV_PARSE_U32(box->minor_version, ptr);
    box->nb_compatible_brands = (box->box.size-16) / 4;
    box->compatible_brands = ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

uint32_t _is_valid_cc4(const uint8_t *cc4) {
    if( (cc4[0] >= 0x20 && cc4[0] <= 0x7E) &&
        (cc4[1] >= 0x20 && cc4[1] <= 0x7E) &&
        (cc4[2] >= 0x20 && cc4[2] <= 0x7E) &&
        (cc4[3] >= 0x20 && cc4[3] <= 0x7E) )
    {
        return 1;
    }
    return 0;
}

BMFFCode _bmff_parse_child(BMFFContext *ctx, parse_func func, const uint8_t *data, size_t size, Box **box_ptr)
{
    const uint8_t *fourCC = data+4;
    
    CALLBACK(ctx, BMFFEventParseStart, fourCC, NULL);
    _bmff_breadcrumb_push(ctx, fourCC);

    BMFFCode res = func(ctx, data, size, box_ptr);
    if(res != BMFF_OK) {
        _bmff_breadcrumb_pop(ctx);
        CALLBACK(ctx, BMFFEventParseError, fourCC, (void*)data);
    }else{
        _bmff_breadcrumb_pop(ctx);
        CALLBACK(ctx, BMFFEventParseComplete, fourCC, (void*)(*box_ptr));
    }
    return res;
}

uint32_t _bmff_parse_children(BMFFContext *ctx, const uint8_t *data, size_t size, uint32_t *child_count, Box ***children)
{
    const uint8_t *tmp = data;
    const uint8_t *end = &data[size];

    uint32_t count = 0;
    while(tmp + 8 < end && _is_valid_cc4(tmp + 4) == 1) {
        uint32_t box_size = parse_u32(tmp);
        if(box_size == 0 || tmp + box_size > end) {
            break; // something went wrong
        }
        tmp += box_size;
        count++;
    }
    *child_count = count;

    // allocate room for the children
    if(count > 0) {
        BOX_MALLOCN(*children, Box*, count);
    }else{
        return 0;
    }

    // parse all the Boxes.
    int child_idx = 0;

    const uint8_t *ptr = data;
    while(ptr + 8 < end && child_idx < count)
    {
        uint32_t box_size = parse_u32(ptr);
        // get the numerical value of the type, making sure to keep the bytes in
        // the correct order.
        uint32_t box_type = *((uint32_t*)(ptr+4));

        // find the parser for the next Child.
        int i=0;
        for(; i < PARSE_MAP_LEN; ++i)
        {
            uint32_t parser_box_type = parse_map[i].box_type_value;
            if(parser_box_type == box_type) {
                // parse the Box.
                Box *child_box;
                BMFFCode res = _bmff_parse_child(ctx, parse_map[i].parse_func, ptr, end-ptr, &child_box);
                if(res == BMFF_OK) {
                    // add the parsed Box to the list of children.
                    (*children)[child_idx] = child_box;
                }
                // break out once we have found a parser.
                break;
            }
        }

        if(i == PARSE_MAP_LEN) {
            CALLBACK(ctx, BMFFEventParserNotFound, ptr+4, (void*)ptr);
        }

        child_idx++;
        ptr += box_size;
    }

    // return how many bytes were parsed
    return ptr - data;
}

BMFFCode _bmff_parse_box_generic_container(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size <= 8)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ContainerBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_full_string(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 13)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, StringFullBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(ptr, size, &box->box);

    ADV_PARSE_STR(box->value, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_full_data(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)    return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, DataFullBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(ptr, size, &box->box);
    const uint8_t *end = data + box->box.size;

    box->data_len = end-ptr;
    if(box->data_len > 0) {
        box->data = ptr;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_reference_type(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 8)    return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackReferenceTypeBox);

    const uint8_t *ptr = data;
    ptr += parse_box(ptr, size, &box->box); // hint or cdsc

    box->nb_track_ids = (box->box.size - 8) / 4;
    BOX_MALLOCN(box->track_ids, uint32_t, box->nb_track_ids);

    int i = 0;
    for(; i < box->nb_track_ids; ++i) {
        ADV_PARSE_U32(box->track_ids[i], ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_full(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FullBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, box);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_progressive_download_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ProgressiveDownloadBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->nb_bitrates = (size - (ptr - data)) / 8;
    BOX_MALLOCN(box->bitrates, ProgressiveDownloadBitrate, box->nb_bitrates);

    int i=0;
    for(; i<box->nb_bitrates; ++i) {
        ADV_PARSE_U32(box->bitrates[i].rate, ptr);
        ADV_PARSE_U32(box->bitrates[i].initial_delay, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_media_data(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 8)    return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MediaDataBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    box->data = ptr;
    box->data_len = size - (ptr - data);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_handler(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 22)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, HandlerBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ptr += 4; // pre-defined (0).
    // copy the active handler type to the context
    memcpy(ctx->handler_type, ptr, 4);
    memcpy(box->handler_type, ptr, 4);
    ptr += 4;
    ptr += 12; // uint32_t x 3 (12) reserved.
    box->name = ptr; // NULL terminated string.

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_primary_item(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, PrimaryItemBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 0) {
        ADV_PARSE_U16(box->item_id, ptr);
    }else {
        ADV_PARSE_U32(box->item_id, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_item_location(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemLocationBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->offset_size = ((*ptr) >> 4) & 0x0F;
    box->length_size = (*ptr) & 0x0F;
    ptr++;

    box->base_offset_size = ((*ptr) >> 4) & 0x0F;

    uint8_t ver = box->box.version;
    if(ver == 1 || ver == 2) {
        box->index_size = (*ptr) & 0x0F;
    }
    ptr++;

    if(ver < 2) {
        ADV_PARSE_U16(box->item_count, ptr);
    } else if(ver == 2) {
        ADV_PARSE_U32(box->item_count, ptr);
    }

    if(box->item_count > 0) {
        BOX_MALLOCN(box->items, ItemLocation, box->item_count);

        int offset_shift = 64 - (((int)box->offset_size) * 8);
        int length_shift = 64 - (((int)box->length_size) * 8);

        int i=0;
        for(; i < box->item_count; ++i) {
            ItemLocation *item = &box->items[i];
            if(ver < 2) {
                ADV_PARSE_U16(item->item_id, ptr);
            }else if(ver == 2) {
                ADV_PARSE_U32(item->item_id, ptr);
            }
            if(ver == 1 || ver == 2) {
                ++ptr; // (12) reserved
                item->construction_method = (*ptr) & 0x0F;
                ++ptr;
            }
            ADV_PARSE_U16(item->data_reference_index, ptr);
            
            if(box->base_offset_size == 4) {
                ADV_PARSE_U32(item->base_offset, ptr);
            }else if(box->base_offset_size == 8) {
                ADV_PARSE_U64(item->base_offset, ptr);
            }else{
                item->base_offset = 0;
            }

            ADV_PARSE_U16(item->extent_count, ptr);
            if(item->extent_count > 0) {
                BOX_MALLOCN(item->extents, Extent, item->extent_count);
                
                int j=0;
                for(; j<item->extent_count; ++j) {
                    Extent *extent = &item->extents[j];
                    
                    if((ver == 1 || ver ==2) && (box->index_size > 0)) {
                        if(box->index_size == 4) {
                            ADV_PARSE_U32(extent->index, ptr);
                        }else if(box->index_size == 8) {
                            ADV_PARSE_U64(extent->index, ptr);
                        }else{
                            extent->index = 0;
                        }
                    }

                    if(box->offset_size == 4) {
                        ADV_PARSE_U32(extent->offset, ptr);
                    }else if(box->offset_size == 8) {
                        ADV_PARSE_U64(extent->offset, ptr);
                    }else{
                        extent->offset = 0;
                    }

                    if(box->length_size == 4) {
                        ADV_PARSE_U32(extent->length, ptr);
                    }else if(box->length_size == 8) {
                        ADV_PARSE_U64(extent->length, ptr);
                    }else{
                        extent->length = 0;
                    }
                }
            }
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

size_t _bmff_parse_fd_item_info_extension(BMFFContext *ctx, const uint8_t *data, size_t size, FDItemInfoExtension **box_ptr)
{
    if(!ctx)        return 0;
    if(!data)       return 0;
    if(size < 27)   return 0;
    if(!box_ptr)    return 0;

    BOX_MALLOC(box, FDItemInfoExtension);

    const uint8_t *ptr = data;

    ADV_PARSE_STR(box->content_location, ptr);
    ADV_PARSE_STR(box->content_md5, ptr);
    ADV_PARSE_U64(box->content_length, ptr);
    ADV_PARSE_U64(box->transfer_length, ptr);
    ADV_PARSE_U8(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->group_ids, uint32_t, box->entry_count);
    }

    uint8_t i = 0;
    for(; i < box->entry_count; ++i) {
        ADV_PARSE_U32(box->group_ids[i], ptr);
    }

    *box_ptr = box;
    return ptr - data;
}

BMFFCode _bmff_parse_box_item_info_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 19)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemInfoEntry);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    uint8_t ver = box->box.version;
    if(ver <= 2) {
        ADV_PARSE_U16(box->item_id, ptr);
    }else if(ver == 3) {
        ADV_PARSE_U32(box->item_id, ptr);
    }
    ADV_PARSE_U16(box->item_protection_index, ptr);

    if(ver >= 2) {
        memcpy(box->item_type, ptr, 4);
        ptr += 4;
    }

    ADV_PARSE_STR(box->item_name, ptr);

    if(ver == 0 || ver == 1 || memcmp(&box->item_type, "mime", 4) == 0) {
        ADV_PARSE_STR(box->content_type, ptr);
        ADV_PARSE_STR(box->content_encoding, ptr);
    }

    if(ver == 1) {
        memcpy(box->extension_type, ptr, 4);
        ptr += 4;
        const uint8_t *end = data + box->box.size;
        if(strcmp(box->extension_type, "fdel") == 0) {
            BOX_MALLOC(ext, FDItemInfoExtension); 
            box->extension_size = _bmff_parse_fd_item_info_extension(ctx, ptr, end - ptr, &ext);
            box->extension = ext;
            ptr += box->extension_size;
        }else{
            box->extension_bytes = ptr;
            box->extension_size = end - ptr;
            ptr = end;
        }
    }

    if(ver >= 2 && memcmp(&box->item_type, "uri ", 4) == 0) {
        ADV_PARSE_STR(box->item_uri_type, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_item_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemInfoBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 0) {
        ADV_PARSE_U16(box->entry_count, ptr);
    }else {
        ADV_PARSE_U32(box->entry_count, ptr);
    }

    BOX_MALLOCN(box->entries, ItemInfoEntry*, box->entry_count);
    uint32_t i=0;
    for(; i < box->entry_count; ++i) {

        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_item_info_entry, ptr, size-(ptr-data), (Box**)&box->entries[i]);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->entries[i]->box.size;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_ipmp_control(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 15)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    const uint8_t *ptr = data;

    BOX_MALLOC(box, IPMPControlBox);
    ptr += parse_full_box(data, size, &box->box);

    box->tool_list.tag = ptr[0];
    box->tool_list.num_tools = ptr[1];
    ptr += 2;

    if(box->tool_list.num_tools > 0)
    {
        BOX_MALLOCN(box->tool_list.ipmp_tools, IPMPTool, box->tool_list.num_tools);

        int i = 0;
        for(; i < box->tool_list.num_tools; ++i) {
            IPMPTool *tool = &box->tool_list.ipmp_tools[i];
            memcpy(tool->tool_id, ptr, 16);
            ptr += 16;
            tool->is_alt_group = ((*ptr) & 0x80) >> 7;
            tool->is_parametric = ((*ptr) & 0x40) >> 6;
            ptr++;

            if(tool->is_alt_group) {
                tool->num_alternates = *ptr;
                ptr++;
                memcpy(tool->specific_tool_id, ptr, 16);
                ptr += 16;
            }

            if(tool->is_parametric) {
                uint32_t len = parse_u32(ptr);
                ptr += 4;
                tool->tool_param_desc = ptr;
                ptr += len + 1;
            }

            tool->num_urls = *ptr;
            ptr++;

            if(tool->num_urls > 0)
            {
                BOX_MALLOCN(tool->tool_urls, uint8_t*, tool->num_urls);

                int j=0;
                for(; j < tool->num_urls; ++j) {
                    uint32_t len = parse_u32(ptr);
                    ptr += 4;
                    tool->tool_urls[j] = (uint8_t*)ptr;
                    ptr += len + 1;
                }
            }
        }
    }

    box->ipmp_descriptors_len = *ptr;
    if(box->ipmp_descriptors_len > 0) {
        ptr++;
        box->ipmp_descriptors = ptr;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_original_format(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, OriginalFormatBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    memcpy(box->data_format, ptr, 4);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_ipmp_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 13)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, IPMPInfoBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    // TODO: parse IPMP descriptors
    box->ipmp_desc = ptr;
    box->ipmp_desc_count = 0;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_scheme_type(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SchemeTypeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    memcpy(box->scheme_type, ptr, 4);
    ptr += 4;
    ADV_PARSE_U32(box->scheme_version, ptr);

    if(box->box.flags && 0x000001) {
        box->scheme_uri = ptr;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_protection_scheme_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ProtectionSchemeInfoBox);

    const uint8_t *ptr = data;
    ptr += parse_box(ptr, size, &box->box);
    ptr += parse_original_format_box(ptr, size, &box->original_format);

    const uint8_t *end = data + box->box.size;

    // parse the optional boxes
    if(ptr < end && strncmp(ptr+4, "schm", 4) == 0) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_scheme_type, ptr, end-ptr, (Box**)&box->scheme_type);
        if(res != BMFF_OK) {
            return res;
        }
        uint32_t box_size = parse_u32(ptr);
        ptr += box_size;
    }

    if(ptr < end && strncmp(ptr+4, "schi", 4) == 0) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_generic_container, ptr, end-ptr, (Box**)&box->scheme_info);
        if(res != BMFF_OK) {
            return res;
        }
        uint32_t box_size = parse_u32(ptr);
        ptr += box_size;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_item_protection(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemProtectionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    const uint8_t *end = data + box->box.size;

    ADV_PARSE_U16(box->protection_count, ptr);

    if(box->protection_count > 0) {
        BOX_MALLOCN(box->protection_info, ProtectionSchemeInfoBox*, box->protection_count)

        int i=0;
        for(; i<box->protection_count; ++i) {
            BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_protection_scheme_info, ptr, end-ptr, (Box**) &box->protection_info[i]);
            if(res != BMFF_OK) {
                return res;
            }
            uint32_t box_size = parse_u32(ptr);
            ptr += box_size;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_meta(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 34)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MetaBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    const uint8_t *end = data + box->box.size;

    BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_handler, ptr, end-ptr, (Box**)&box->handler);
    if(res != BMFF_OK) {
        return res;
    }

    ptr += box->handler->box.size;

    // parse all the optional and "other" boxes
    // define a structure we can use to make a box type to a parsing function
    struct Map {
        uint8_t type[4];    // box type
        parse_func func;    // parsing function
        AbstractBox **box_ptr;  // address of the pointer to the parsed box
    };
    // map of parsing functions
    const int map_count = 8;
    struct Map map[8] = {
         { "pitm", _bmff_parse_box_primary_item, (AbstractBox**)&box->primary_resource },
         { "dinf", _bmff_parse_box_generic_container, (AbstractBox**)&box->file_locations },
         { "iloc", _bmff_parse_box_item_location, (AbstractBox**)&box->item_locations },
         { "ipro", _bmff_parse_box_item_protection, (AbstractBox**)&box->protections },
         { "iinf", _bmff_parse_box_item_info, (AbstractBox**)&box->item_infos },
         { "ipmc", _bmff_parse_box_ipmp_control, (AbstractBox**)&box->ipmp_control },
         { "iref", _bmff_parse_box_item_reference, (AbstractBox**)&box->item_refs },
         { "idat", _bmff_parse_box_item_data, (AbstractBox**)&box->item_data },
    };

    // Parse optional Boxes
    while(ptr < end) {
        int i=0;
        // find the parser for the next box
        const char *_t = &ptr[4];
        int found = 0;
        int _s = parse_u32(ptr);
        for(; i<map_count; ++i) {
            if(memcmp(&ptr[4], map[i].type, 4) == 0) {
                found = 1;
                res = _bmff_parse_child(ctx, map[i].func, ptr, end-ptr, (Box**)map[i].box_ptr);
                if(res != BMFF_OK) {
                    return res;
                }
                ptr += (*(map[i].box_ptr))->box.size;
                break;
            }
        }
        // if we see any box we don't recognize, just assume everything else
        // is an "other" box.
        if(found == 0) {
            break;
        }
    }

    if(ptr < end) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->other_boxes_len, &box->other_boxes);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_movie_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 32)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MovieHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
      ADV_PARSE_U64(box->creation_time, ptr);
      ADV_PARSE_U64(box->modification_time, ptr);
      ADV_PARSE_U64(box->timescale, ptr);
      ADV_PARSE_U64(box->duration, ptr);
    }else{
      ADV_PARSE_U32(box->creation_time, ptr);
      ADV_PARSE_U32(box->modification_time, ptr);
      ADV_PARSE_U32(box->timescale, ptr);
      ADV_PARSE_U32(box->duration, ptr);
    }

    ADV_PARSE_FP16(box->rate, ptr);
    ADV_PARSE_FP8(box->volume, ptr);
    // reserved 16, 32[2]
    ptr += 10; // (16 + 32 + 32) / 8
    // parse the matrix
    ADV_PARSE_MATRIX(box->matrix, ptr);
    // pre defined 32[6]
    ptr += 24; // 32 / 8 * 6
    ADV_PARSE_U32(box->next_track_id, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_movie_fragment_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MovieFragmentHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sequence_number, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_fragment_random_access(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 24)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackFragmentRandomAccessBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->track_id, ptr);
    ptr += 3; // reserved
    uint8_t value = ptr[0];
    box->length_size_of_traf_num = (value >> 4) & 0x03;
    box->length_size_of_trun_num = (value >> 2) & 0x03;
    box->length_size_of_sample_num = value & 0x03;
    ptr++;
    ADV_PARSE_U32(box->number_of_entry, ptr);

    BOX_MALLOCN(box->entries, Entry, box->number_of_entry);

    uint32_t i=0;
    for(; i<box->number_of_entry; ++i) {
        Entry *entry = &box->entries[i];
        if(box->box.version == 1) {
            ADV_PARSE_U64(entry->entry_time, ptr);
            ADV_PARSE_U64(entry->moof_offset, ptr);
        }else{
            ADV_PARSE_U32(entry->entry_time, ptr);
            ADV_PARSE_U32(entry->moof_offset, ptr);
        }

        entry->traf_number = parse_var_length(ptr, box->length_size_of_traf_num + 1);
        ptr += box->length_size_of_traf_num + 1;
        entry->trun_number = parse_var_length(ptr, box->length_size_of_trun_num + 1);
        ptr += box->length_size_of_trun_num + 1;
        entry->sample_number = parse_var_length(ptr, box->length_size_of_sample_num + 1);
        ptr += box->length_size_of_sample_num + 1;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_movie_fragment_random_access_offset(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MovieFragmentRandomAccessOffsetBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->size, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_xml(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 13)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, XMLBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->data = ptr;
    box->data_len = &data[size] - ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
        ADV_PARSE_U64(box->creation_time, ptr);
        ADV_PARSE_U64(box->modification_time, ptr);
        ADV_PARSE_U32(box->track_id, ptr);
        // reserved (32)
        ptr += 4;
        ADV_PARSE_U64(box->duration, ptr);
    }else{
        ADV_PARSE_U32(box->creation_time, ptr);
        ADV_PARSE_U32(box->modification_time, ptr);
        ADV_PARSE_U32(box->track_id, ptr);
        // reserved (32)
        ptr += 4;
        ADV_PARSE_U32(box->duration, ptr);
    }

    // reserved (32 * 2)
    ptr += 8;
    ADV_PARSE_S16(box->layer, ptr);
    ADV_PARSE_S16(box->alternate_group, ptr);
    ADV_PARSE_FP8(box->volume, ptr);
    // reserved (16)
    ptr += 2;
    ADV_PARSE_MATRIX(box->matrix, ptr);
    ADV_PARSE_FP16(box->width, ptr);
    ADV_PARSE_FP16(box->height, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_movie_extends_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MovieExtendsHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
        ADV_PARSE_U64(box->fragment_duration, ptr);
    }else{
        ADV_PARSE_U32(box->fragment_duration, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_extends(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 32)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackExtendsBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->track_id, ptr);
    ADV_PARSE_U32(box->default_sample_description_index, ptr);
    ADV_PARSE_U32(box->default_sample_duration, ptr);
    ADV_PARSE_U32(box->default_sample_size, ptr);

    // default sample flags
    // (4) reserved
    box->default_sample_is_leading = (eBoolean)((ptr[0] >> 2) & 0x03); // (2) sample is leading
    box->default_sample_depends_on = (eBoolean)(ptr[0] & 0x03); // (2) sample depends on
    box->default_sample_is_depended_on = (eBoolean)((ptr[1] >> 6) & 0x03); // (2) sample is depended on
    box->default_sample_has_redundancy = (eBoolean)((ptr[1] >> 4) & 0x03); // (2) sample has redundency
    box->default_sample_padding_value = (ptr[1] >> 1) & 0x07; // (3) sample padding value
    box->default_sample_is_difference_sample = (ptr[1] & 0x01) == 1 ? eBooleanTrue : eBooleanFalse; // (1) sample is difference sample
    ptr += 2;
    ADV_PARSE_U16(box->default_sample_degradation_priority, ptr); // (16) sample degradation priority

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_fragment_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackFragmentHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->track_id, ptr);

    if(box->box.flags & eTfhdBaseDataOffsetPresent == eTfhdBaseDataOffsetPresent) {
        ADV_PARSE_U64(box->base_data_offset, ptr);
    }

    if(box->box.flags & eTfhdSampleDescIdxPresent == eTfhdSampleDescIdxPresent) {
        ADV_PARSE_U32(box->sample_description_index, ptr);
    }

    if(box->box.flags & eTfhdDefaultSampleDurationPresent == eTfhdDefaultSampleDurationPresent) {
        ADV_PARSE_U32(box->default_sample_duration, ptr);
    }

    if(box->box.flags & eTfhdDefaultSampleSizePresent == eTfhdDefaultSampleSizePresent) {
        ADV_PARSE_U32(box->default_sample_size, ptr);
    }

    if(box->box.flags & eTfhdDefaultSampleFlagsPresent == eTfhdDefaultSampleFlagsPresent) {
        ADV_PARSE_U32(box->default_sample_flags, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_run(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackRunBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sample_count, ptr);

    if(box->sample_count > 0) {
        BOX_MALLOCN(box->samples, TrackRunSample, box->sample_count);
    }

    eTrackRunFlags flags = box->box.flags;

    if(flags & eTrunDataOffsetPresent == eTrunDataOffsetPresent) {
        ADV_PARSE_U32(box->data_offset, ptr);
    }

    if(flags & eTrunFirstSampleFlagsPresent == eTrunFirstSampleFlagsPresent) {
        ADV_PARSE_U32(box->first_sample_flags, ptr);
    }

    uint32_t i=0;
    for(;i < box->sample_count; ++i) {
        TrackRunSample *sample = &box->samples[i];

        if(flags & eTrunSampleDurationPresent == eTrunSampleDurationPresent) {
            ADV_PARSE_U32(sample->duration, ptr);
        }
        if(flags & eTrunSampleSizePresent == eTrunSampleSizePresent) {
            ADV_PARSE_U32(sample->size, ptr);
        }
        if(flags & eTrunSampleFlagsPresent == eTrunSampleFlagsPresent) {
            ADV_PARSE_U32(sample->flags, ptr);
        }
        if(flags & eTrunSampleCompTimeOffsetsPresent == eTrunSampleCompTimeOffsetsPresent) {
            if(box->box.version == 0) {
                ADV_PARSE_U32(sample->composition_time_offset, ptr);
            }else{
                ADV_PARSE_S32(sample->composition_time_offset, ptr);
            }
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_dependency_type(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleDependencyTypeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(ctx->sample_count > 0) {
        BOX_MALLOCN(box->samples, SampleDependencyType, ctx->sample_count);
    }

    // use the sample count set in the context.
    // this is set by the stsz or stz2 parser.
    uint32_t i=0;
    for(; i < ctx->sample_count; ++i) {
        SampleDependencyType *sample = &box->samples[i];
        sample->is_leading = (eBoolean)((ptr[0] >> 6) & 0x03); // (2) is a leading sample
        sample->depends_on = (eBoolean)((ptr[0] >> 4) & 0x03); // (2) sample depends on
        sample->is_depended_on = (eBoolean)((ptr[0] >> 2) & 0x03); // (2) sample is depended on
        sample->has_redundancy = (eBoolean)(ptr[0] & 0x03); // (2) sample has redundency
        ptr++;
    };

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_to_group(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleToGroupBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->grouping_type, ptr);
    if(box->box.version == 1) {
        ADV_PARSE_U32(box->grouping_type_param, ptr);
    }
    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, SampleToGroupEntry, box->entry_count);
    }

    uint32_t i=0;
    for(; i < box->entry_count; ++i) {
        SampleToGroupEntry *entry = &box->entries[i];
        ADV_PARSE_U32(entry->sample_count, ptr);
        ADV_PARSE_U32(entry->group_description_index, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sub_sample_information(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SubSampleInformationBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, SubSampleInformationEntry, box->entry_count);
    }

    uint32_t i=0;
    for(; i<box->entry_count; ++i) {
        SubSampleInformationEntry *entry = &box->entries[i]; 
        ADV_PARSE_U32(entry->sample_delta, ptr);
        ADV_PARSE_U16(entry->subsample_count, ptr);

        if(entry->subsample_count > 0) {
            BOX_MALLOCN(entry->subsamples, SubSampleInformation, entry->subsample_count);

            uint32_t j=0;
            for(; j<entry->subsample_count; ++j) {
                SubSampleInformation *info = &entry->subsamples[j];
                if(box->box.version == 1) {
                    ADV_PARSE_U32(info->size, ptr);
                }else{
                    ADV_PARSE_U16(info->size, ptr);
                }
                ADV_PARSE_U8(info->priority, ptr);
                ADV_PARSE_U8(info->discardable, ptr);
                ADV_PARSE_U32(info->codec_specific_params, ptr);
            }
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_copyright(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, CopyrightBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    uint16_t val = parse_u16(ptr);
    parse_iso639_2_lang(val, box->language);
    ptr += 2;

    if(ptr < &data[size]) {
        box->notice = ptr;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_data_entry_url(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, DataEntryBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(ptr < data + size) {
        ADV_PARSE_STR(box->location, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_data_entry_urn(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, DataEntryBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_STR(box->name, ptr);
    ADV_PARSE_STR(box->location, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_data_reference(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, DataReferenceBox);

    const uint8_t *ptr = data;
    const uint8_t *end = data + size;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->data_entries, DataEntryBox*, box->entry_count);

        uint32_t i=0;
        for(; i < box->entry_count; ++i) {
            // this can contain either url or urn boxes, so we just need to check for the
            // 'l' vs 'n' in to the type of the next box to identify them correctly.
            char d[12];
            DataEntryBox **dataEntry = &box->data_entries[i];
            BMFFCode res = BMFF_OK;
            if(ptr[6] == 'n') {
                res = _bmff_parse_child(ctx, _bmff_parse_box_data_entry_urn, ptr, end-ptr, (Box**)dataEntry);
            }else{
                res = _bmff_parse_child(ctx, _bmff_parse_box_data_entry_url, ptr, end-ptr, (Box**)dataEntry);
            }
            // the version and flags are copied from the Data Reference Box
            if(res == BMFF_OK) {
                (*dataEntry)->box.version = box->box.version;
                (*dataEntry)->box.flags = box->box.flags;
            }
            // move ptr to the start of the next Data Entry box.
            uint32_t box_size = parse_u32(ptr);
            ptr += box_size;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_edit_list(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, EditListBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, EditEntry, box->entry_count);

        uint32_t i=0;
        for(; i < box->entry_count; ++i) {
            EditEntry *entry = &box->entries[i];
            if(box->box.version == 1) {
                ADV_PARSE_U64(entry->segment_duration, ptr);
                ADV_PARSE_S64(entry->media_time, ptr);
            }else{
                ADV_PARSE_U32(entry->segment_duration, ptr);
                ADV_PARSE_S32(entry->media_time, ptr);
            }
            ADV_PARSE_S16(entry->media_rate_integer, ptr);
            ADV_PARSE_S16(entry->media_rate_fraction, ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_media_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 32)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MediaHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
        ADV_PARSE_U64(box->creation_time, ptr);
        ADV_PARSE_U64(box->modification_time, ptr);
        ADV_PARSE_U32(box->timescale, ptr);
        ADV_PARSE_U64(box->duration, ptr);
    }else{
        ADV_PARSE_U32(box->creation_time, ptr);
        ADV_PARSE_U32(box->modification_time, ptr);
        ADV_PARSE_U32(box->timescale, ptr);
        ADV_PARSE_U32(box->duration, ptr);
    }

    uint16_t val = parse_u16(ptr);
    parse_iso639_2_lang(val, box->language);
    ptr += 2;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_video_media_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, VideoMediaHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U16(box->graphics_mode, ptr);
    ADV_PARSE_U16(box->op_color[0], ptr);
    ADV_PARSE_U16(box->op_color[1], ptr);
    ADV_PARSE_U16(box->op_color[2], ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sound_media_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SoundMediaHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_FP8(box->balance, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_hint_media_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 28)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, HintMediaHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U16(box->max_pdu_size, ptr);
    ADV_PARSE_U16(box->avg_pdu_size, ptr);
    ADV_PARSE_U32(box->max_bitrate, ptr);
    ADV_PARSE_U32(box->avg_bitrate, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_subtitle_media_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SubtitleMediaHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_incomplete_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, IncompleteSampleEntry **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, IncompleteSampleEntry);

    const uint8_t *ptr = data;
    const uint8_t *end = data + size;

    BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_complete_track_info, ptr, end-ptr, (Box**)&box->complete_track_info);
    if(res != BMFF_OK) {
        return res;
    }
    ptr += box->complete_track_info->box.size;

    // parse any other boxes
    if(end > ptr) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);
    }

    *box_ptr = box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_visual_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 53)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, VisualSampleEntry);
    box->is_incomplete = eBooleanFalse;

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    // Sample Entry parsing
    ptr += 6; // reserverd (8)[6]
    ADV_PARSE_U16(box->data_reference_index, ptr);

    // Visual Sample Entry parsing
    ptr += 16; // predefined(2), reserved(2), predefined(12)
    ADV_PARSE_U16(box->width, ptr);
    ADV_PARSE_U16(box->height, ptr);
    ADV_PARSE_FP16(box->horiz_resolution, ptr);
    ADV_PARSE_FP16(box->vert_resolution, ptr);
    ptr += 4; // reserved
    ADV_PARSE_U16(box->frame_count, ptr);
    // the first byte contains the length of the compressor string
    uint8_t len = *ptr;
    if(len > 31) len = 31; // make sure the length is valid
    ptr++;
    // copy the string
    strncpy(box->compressor_name, ptr, len);
    // null terminate the string at it's length
    box->compressor_name[len] = '\0';
    ptr += 31;
    ADV_PARSE_U16(box->depth, ptr);
    ptr += 2; // predefined

    // CleanApertureBox
    if(ptr + 8 < end && strncmp(&ptr[4], "clap", 4) == 0) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_clean_aperture, ptr, end-ptr, (Box**)&box->clap);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->clap->box.size;
    }

    // PixelAspectRatioBox
    if(ptr + 8 < end && strncmp(&ptr[4], "pasp", 4) == 0) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_pixel_aspect_ratio, ptr, end-ptr, (Box**)&box->pasp);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->pasp->box.size;
    }

    // parse incomplete data if the sample has an incomplete tag
    if(ptr + 8 < end && strncmp(box->box.type, "icpv", 4) == 0) {
        box->is_incomplete = eBooleanTrue;
    }

    if(ptr + 8 < end) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_audio_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 36)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, AudioSampleEntry);
    box->is_incomplete = eBooleanFalse;

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    // Sample Entry parsing
    ptr += 6; // reserverd (8)[6]
    ADV_PARSE_U16(box->data_reference_index, ptr);

    ptr += 8; // reserved (32)[2]
    ADV_PARSE_U16(box->channel_count, ptr);
    ADV_PARSE_U16(box->sample_size, ptr);
    ptr += 2; // predefined
    ptr += 2; // reserved
    ADV_PARSE_FP16(box->sample_rate, ptr);

    // assign the channel count to the context for any child box parsing
    ctx->channel_count = box->channel_count;

    // Sampling Rate
    BMFFCode res;
    if(ctx->sample_description_version == 1 && strncmp(&ptr[4], "srat", 4) == 0) {
        res = _bmff_parse_child(ctx, _bmff_parse_box_sampling_rate, ptr, end-ptr, (Box**)&box->sampling_rate);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->sampling_rate->box.size;
    }

    // Channel Layout
    if(strncmp(&ptr[4], "chnl", 4) == 0) {
        res = _bmff_parse_child(ctx, _bmff_parse_box_channel_layout, ptr, end-ptr, (Box**)&box->channel_layout);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->channel_layout->box.size;
    }

    if(strncmp(box->box.type, "icpa", 4) == 0) {
        box->is_incomplete = eBooleanTrue;
    }

    if(ptr < end) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_hint_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, HintSampleEntry);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    // Sample Entry parsing
    ptr += 6; // reserverd (8)[6]
    ADV_PARSE_U16(box->data_reference_index, ptr);

    box->data = ptr;
    box->data_size = (data + box->box.size) -  ptr;

    ptr += box->data_size;

    // parse incomplete data if the sample has an incomplete tag
    if(strncmp(box->box.type, "icph", 4) == 0) {
        box->is_incomplete = eBooleanTrue;
        // NOTE: Not sure tell where the hint data ends and the
        //       incomplete sample data begins ?!?!?!?!
    }else{
        box->is_incomplete = eBooleanFalse;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_description(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleDescriptionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);
    const uint8_t *end = ptr + box->box.size;

    ADV_PARSE_U32(box->entry_count, ptr);
    if(box->entry_count > 0) {

        parse_func parser;

        BOX_MALLOCN(box->entries, SampleEntry*, box->entry_count);

        if( strncmp(ctx->handler_type, "vide", 4) == 0 ||
            strncmp(ctx->handler_type, "encv", 4) == 0 ||
            strncmp(ctx->handler_type, "icpv", 4) == 0)
        {
            parser = _bmff_parse_box_visual_sample_entry;
        }
        else if( strncmp(ctx->handler_type, "soun", 4) == 0 ||
                 strncmp(ctx->handler_type, "enca", 4) == 0 ||
                 strncmp(ctx->handler_type, "icpa", 4) == 0)
        {
            parser = _bmff_parse_box_audio_sample_entry;
        }
        else if( strncmp(ctx->handler_type, "hint", 4) == 0 ||
                 strncmp(ctx->handler_type, "icph", 4) == 0)
        {
            parser = _bmff_parse_box_hint_sample_entry;
        }
        else
        {
            parser = _bmff_parse_box;
        }

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            BMFFCode res = _bmff_parse_child(ctx, parser, ptr, end-ptr, (Box**)&box->entries[i]);
            if(res != BMFF_OK) {
                return res;
            }
            ptr += box->entries[i]->box.size;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_time_to_sample(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TimeToSampleBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sample_count, ptr);
    if(box->sample_count > 0) {
        BOX_MALLOCN(box->samples, TimeToSample, box->sample_count);

        uint32_t i = 0;
        for(; i < box->sample_count; ++i) {
            TimeToSample *sample = &box->samples[i];
            ADV_PARSE_U32(sample->count, ptr);
            ADV_PARSE_U32(sample->delta, ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_composition_offset(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, CompositionOffsetBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);
    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, CompositionOffset, box->entry_count);

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            CompositionOffset *entry = &box->entries[i];
            ADV_PARSE_U32(entry->count, ptr);
            if(box->box.version == 0) {
                uint32_t offset;
                ADV_PARSE_U32(offset, ptr);
                entry->offset = (int64_t)offset;
            }else if(box->box.version == 1) {
                int32_t offset;
                ADV_PARSE_S32(offset, ptr);
                entry->offset = (int64_t)offset;
            }
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_to_chunk(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleToChunkBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);
    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, SampleToChunk, box->entry_count);

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            SampleToChunk *entry = &box->entries[i];
            ADV_PARSE_U32(entry->first_chunk, ptr);
            ADV_PARSE_U32(entry->samples_per_chunk, ptr);
            ADV_PARSE_U32(entry->sample_description_index, ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_size(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 24)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleSizeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sample_size, ptr);
    ADV_PARSE_U32(box->sample_count, ptr);

    if(box->sample_size == 0 && box->sample_count > 0) {
        BOX_MALLOCN(box->entry_sizes, uint32_t, box->sample_count);
        uint32_t i = 0;
        for(; i < box->sample_count; ++i) {
            ADV_PARSE_U32(box->entry_sizes[i], ptr);
        }   
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_compact_sample_size(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, CompactSampleSizeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ptr += 3; // reserved
    ADV_PARSE_U8(box->field_size, ptr);
    ADV_PARSE_U32(box->sample_count, ptr);

    if(box->sample_count > 0) {
        BOX_MALLOCN(box->entry_sizes, uint16_t, box->sample_count);
        uint32_t i = 0;
        for(; i < box->sample_count; ++i) {
            if(box->field_size == 4) {
                uint8_t val = *ptr;
                if(i % 2 == 0) {
                    val = (val >> 4) & 0x0F;
                }else{
                    val = val & 0x0F;
                    ptr++;
                }
                box->entry_sizes[i] = (uint16_t)val;
            }else if(box->field_size == 8) {
                box->entry_sizes[i] = (uint16_t) *ptr;
                ptr++;
            }else if(box->field_size == 16) {
                ADV_PARSE_U16(box->entry_sizes[i], ptr);
            }
        }   
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_chunk_offset(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ChunkOffsetBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);
    if(box->entry_count > 0) {
        BOX_MALLOCN(box->chunk_offsets, uint32_t, box->entry_count);
    }

    uint32_t i = 0;
    for(; i < box->entry_count; ++i) {
        ADV_PARSE_U32(box->chunk_offsets[i], ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_chunk_large_offset(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ChunkLargeOffsetBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);
    if(box->entry_count > 0) {
        BOX_MALLOCN(box->chunk_offsets, uint32_t, box->entry_count);
    }

    uint32_t i = 0;
    for(; i < box->entry_count; ++i) {
        ADV_PARSE_U64(box->chunk_offsets[i], ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sync_sample(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SyncSampleBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->sample_numbers, uint32_t, box->entry_count);
    }

    uint32_t i = 0;
    for(; i < box->entry_count; ++i) {
        ADV_PARSE_U32(box->sample_numbers[i], ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_shadow_sync_sample(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ShadowSyncSampleBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, ShadowSyncSample, box->entry_count);
    }

    uint32_t i = 0;
    for(; i < box->entry_count; ++i) 
    {
        ShadowSyncSample *sample = &box->entries[i];
        ADV_PARSE_U32(sample->shadowed_sample_number, ptr);
        ADV_PARSE_U32(sample->sync_sample_number, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_padding_bits(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, PaddingBitsBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sample_count, ptr);
    if(box->sample_count > 0) {
        BOX_MALLOCN(box->samples, PaddingBits, box->sample_count);
    }

    uint32_t i = 0;
    for(; i < box->sample_count; ++i) {
        PaddingBits *sample = &box->samples[i];
        uint8_t val = *ptr;
        sample->pad1 = (val >> 4) & 0x07;
        sample->pad2 = val & 0x07;
        ptr++;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_degradation_priority(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, DegradationPriorityBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(ctx->sample_count > 0) {
        BOX_MALLOCN(box->priorities, uint16_t, ctx->sample_count);
    }
    box->priority_count = ctx->sample_count;

    uint32_t i = 0;
    for(; i < box->priority_count; ++i) {
        ADV_PARSE_U16(box->priorities[i], ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_group_description(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleGroupDescriptionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->grouping_type, ptr);
    if(box->box.version == 1) {
        ADV_PARSE_U32(box->default_length, ptr);
    } else if(box->box.version >= 2) {
        ADV_PARSE_U32(box->default_sample_description_index, ptr);
    }
    ADV_PARSE_U32(box->entry_count, ptr);

    box->sample_group_entries = ptr;
    box->sample_group_entries_size = (data + size) - ptr;

    if(box->box.version == 1 && box->default_length == 0 && box->entry_count > 0) {
        BOX_MALLOCN(box->description_lengths, uint32_t, box->entry_count);

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            ADV_PARSE_U32(box->description_lengths[i], ptr);
            ptr += box->description_lengths[i];
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_group_type(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackGroupTypeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->track_group_id, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_extended_language_tag(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ExtendedLanguageTagBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_STR(box->extended_language, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_bit_rate(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, BitRateBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    ADV_PARSE_U32(box->buffer_size_db, ptr);
    ADV_PARSE_U32(box->max_bitrate, ptr);
    ADV_PARSE_U32(box->avg_bitrate, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_composition_to_decode(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 32)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, CompositionToDecodeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 0) {
        ADV_PARSE_S32(box->composition_to_dts_shift, ptr);
        ADV_PARSE_S32(box->least_decode_to_display_delta, ptr);
        ADV_PARSE_S32(box->greatest_decode_to_display_delta, ptr);
        ADV_PARSE_S32(box->composition_start_time, ptr);
        ADV_PARSE_S32(box->composition_end_time, ptr);
    }else if(box->box.version == 1) {
        ADV_PARSE_S64(box->composition_to_dts_shift, ptr);
        ADV_PARSE_S64(box->least_decode_to_display_delta, ptr);
        ADV_PARSE_S64(box->greatest_decode_to_display_delta, ptr);
        ADV_PARSE_S64(box->composition_start_time, ptr);
        ADV_PARSE_S64(box->composition_end_time, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_aux_info_sizes(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 17)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleAuxInfoSizesBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.flags & 0x01) {
        ADV_PARSE_U32(box->aux_info_type, ptr);
        ADV_PARSE_U32(box->aux_info_type_param, ptr);
    }
    ADV_PARSE_U8(box->default_sample_info_size, ptr);
    ADV_PARSE_U32(box->sample_count, ptr);

    if(box->default_sample_info_size == 0 && box->sample_count > 0) {
        BOX_MALLOCN(box->sample_info_sizes, uint8_t, box->sample_count);
        uint32_t i = 0;
        for(; i < box->sample_count; ++i) {
            ADV_PARSE_U8(box->sample_info_sizes[i], ptr);
        }        
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_aux_info_offsets(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleAuxInfoOffsetsBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.flags & 0x01) {
        ADV_PARSE_U32(box->aux_info_type, ptr);
        ADV_PARSE_U32(box->aux_info_type_param, ptr);
    }
    ADV_PARSE_U32(box->entry_count, ptr);

    if(box->entry_count  > 0) {
        BOX_MALLOCN(box->offsets, uint64_t, box->entry_count);
        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            if(box->box.version == 0) {
                ADV_PARSE_U32(box->offsets[i], ptr);
            }else{
                ADV_PARSE_U64(box->offsets[i], ptr);
            }
        }        
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_fragment_decode_time(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackFragmentDecodeTimeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
        ADV_PARSE_U64(box->base_media_decode_time, ptr);
    } else {
        ADV_PARSE_U32(box->base_media_decode_time, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_level_assignment(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 13)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, LevelAssignmentBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U8(box->level_count, ptr);
    if(box->level_count > 0) {
        BOX_MALLOCN(box->levels, LevelAssignment, box->level_count);
    }

    uint32_t i = 0;
    for(; i < box->level_count; ++i) {
        LevelAssignment *level = &box->levels[i];
        ADV_PARSE_U32(level->track_id, ptr);
        level->padding_flag = (ptr[0] >> 7) & 0x01;
        level->assignment_type = ptr[0] & 0x7F;
        ++ptr;
        switch(level->assignment_type) {
            case 0: {
                ADV_PARSE_U32(level->grouping_type, ptr);
            } break;
            case 1: {
                ADV_PARSE_U32(level->grouping_type, ptr);
                ADV_PARSE_U32(level->grouping_type_parameter, ptr);
            } break;
            case 4: {
                ADV_PARSE_U32(level->sub_track_id, ptr);
            } break;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_extension_properties(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackExtensionPropertiesBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->track_id, ptr);

    const uint8_t *end = data + box->box.size;
    _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_alt_startup_seq_properties(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, AltStartupSeqPropertiesBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 0) {
        ADV_PARSE_U32(box->min_initial_alt_startup_offset, ptr);
    }else if(box->box.version == 1) {
        ADV_PARSE_U32(box->entry_count, ptr);
        if(box->entry_count > 0) {
            BOX_MALLOCN(box->entries, AltStartSeqPropertiesEntry, box->entry_count);
        }

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            AltStartSeqPropertiesEntry *entry = &box->entries[i];
            ADV_PARSE_U32(entry->grouping_type_param, ptr);
            ADV_PARSE_S32(entry->min_initial_alt_startup_offset, ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_selection(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackSelectionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->switch_group, ptr);

    const uint8_t *end = data + size;
    uint32_t count = (end - ptr) / 4;
    box->attribute_list_count = count;

    if(count > 0) {
        BOX_MALLOCN(box->attribute_list, int32_t, count);
        uint32_t i = 0;
        for(; i < count; ++i) {
            ADV_PARSE_S32(box->attribute_list[i], ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_kind(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, KindBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    const uint8_t *end = data + size;
    if(end > ptr) {
        ADV_PARSE_STR(box->scheme_uri, ptr);
    }
    if(end > ptr) {
        ADV_PARSE_STR(box->value, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_item_reference(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemReferenceBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    // count the number of reference boxes coming up
    const uint8_t *end = data + box->box.size;
    const uint8_t *tmp = ptr;
    uint32_t count = 0;
    while(tmp < end) {
        tmp += parse_u32(ptr);
        ++count;        
    }

    box->references_count = count;

    if(count > 0) {
        BOX_MALLOCN(box->references, SingleItemTypeReferenceBox, count);
    }

    uint32_t i = 0;
    for(; i < count; ++i) {
        SingleItemTypeReferenceBox *ref_box = &box->references[i];
        ptr += parse_box(data, size, &ref_box->box);
        
        if(box->box.version == 0) {
            ADV_PARSE_U16(ref_box->from_item_id, ptr);
            ADV_PARSE_U16(ref_box->reference_count, ptr);
            
            if(ref_box->reference_count > 0) {
                BOX_MALLOCN(ref_box->to_item_ids, uint16_t, ref_box->reference_count);
            }

            uint16_t j = 0;
            for(; j < ref_box->reference_count; ++j) {
                ADV_PARSE_U16(ref_box->to_item_ids[j], ptr);
            }
        }else if(box->box.version == 1) {
            // large version of the same box above
            ADV_PARSE_U32(ref_box->from_item_id, ptr);
            ADV_PARSE_U16(ref_box->reference_count, ptr);
            
            if(ref_box->reference_count > 0) {
                BOX_MALLOCN(ref_box->to_item_ids, uint32_t, ref_box->reference_count);
            }

            uint16_t j = 0;
            for(; j < ref_box->reference_count; ++j) {
                ADV_PARSE_U32(ref_box->to_item_ids[j], ptr);
            }
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_item_data(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 8)    return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemDataBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    box->data = ptr;
    box->data_size = (data + box->box.size) - ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_metabox_relation(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 21)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, MetaboxRelationBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    memcpy(box->first_metabox_handler_type, ptr, 4);
    ptr += 4;
    memcpy(box->second_metabox_handler_type, ptr, 4);
    ptr += 4;
    ADV_PARSE_U8(box->metabox_relation, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_file_partition(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 28)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FilePartitionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 0) {
        ADV_PARSE_U16(box->item_id, ptr);
    }else{
        ADV_PARSE_U32(box->item_id, ptr);
    }

    ADV_PARSE_U16(box->packet_payload_size, ptr);
    ptr++; // reserved
    ADV_PARSE_U8(box->fec_encoding_id, ptr);
    ADV_PARSE_U16(box->fec_instance_id, ptr);
    ADV_PARSE_U16(box->max_source_block_length, ptr);
    ADV_PARSE_U16(box->encoding_symbol_length, ptr);
    ADV_PARSE_U16(box->max_number_of_encoding_symbols, ptr);
    ADV_PARSE_STR(box->scheme_specific_info, ptr);

    if(box->box.version == 0) {
        ADV_PARSE_U16(box->entry_count, ptr);
    } else {
        ADV_PARSE_U32(box->entry_count, ptr);
    }

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->block_counts, uint16_t, box->entry_count);
        BOX_MALLOCN(box->block_sizes, uint32_t, box->entry_count);

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            ADV_PARSE_U16(box->block_counts[i], ptr);
            ADV_PARSE_U32(box->block_sizes[i], ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_reservoir(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FECReservoirBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 0) {
        ADV_PARSE_U16(box->entry_count, ptr);
    }else{
        ADV_PARSE_U32(box->entry_count, ptr);
    }

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->item_ids, uint32_t, box->entry_count);        
        BOX_MALLOCN(box->symbol_counts, uint32_t, box->entry_count);    

        uint32_t i = 0;
        uint8_t ver = box->box.version;
        for(; i < box->entry_count; ++i) {
            if(ver == 0) {
                ADV_PARSE_U16(box->item_ids[i], ptr);
            }else{
                ADV_PARSE_U32(box->item_ids[i], ptr);
            }
            ADV_PARSE_U32(box->symbol_counts[i], ptr);
        }    
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_partition_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 30)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, PartitionEntryBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_file_partition, ptr, end - ptr, (Box**)&box->blocks_and_symbols);
    if(res != BMFF_OK) {
        return res;
    }
    ptr += box->blocks_and_symbols->box.size;

    if(ptr + 8 < end) {
        res = _bmff_parse_child(ctx, _bmff_parse_box_reservoir, ptr, end - ptr, (Box**)&box->fec_symbol_locations);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->fec_symbol_locations->box.size;
    }

    if(ptr + 8 < end) {
        res = _bmff_parse_child(ctx, _bmff_parse_box_reservoir, ptr, end - ptr, (Box**)&box->file_symbol_locations);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->file_symbol_locations->box.size;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_fd_session_group(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 10)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FDSessionGroupBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    ADV_PARSE_U16(box->num_session_groups, ptr);

    if(box->num_session_groups > 0) {
        BOX_MALLOCN(box->session_groups, FDSessionGroupEntry, box->num_session_groups);

        uint32_t i = 0;
        for(; i < box->num_session_groups; ++i) {
            FDSessionGroupEntry *entry = &box->session_groups[i];
            ADV_PARSE_U8(entry->entry_count, ptr);

            if(entry->entry_count > 0) {
                BOX_MALLOCN(entry->group_ids, uint32_t, entry->entry_count);
                uint8_t j = 0;
                for(; j < entry->entry_count; ++j) {
                    ADV_PARSE_U32(entry->group_ids[j], ptr);
                } 
            }

            ADV_PARSE_U16(entry->num_channels_in_session_group, ptr);
            if(entry->num_channels_in_session_group) {
                BOX_MALLOCN(entry->hint_track_ids, uint32_t, entry->num_channels_in_session_group);
                uint16_t k = 0;
                for(; k < entry->num_channels_in_session_group; ++k) {
                    ADV_PARSE_U32(entry->hint_track_ids[k], ptr);
                } 
            }                  
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_group_id_to_name(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, GroupIdToNameBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U16(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->group_ids, uint32_t, box->entry_count);
        BOX_MALLOCN(box->group_names, char*, box->entry_count);

        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            ADV_PARSE_U32(box->group_ids[i], ptr);
            ADV_PARSE_STR(box->group_names[i], ptr);
        }        
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_fd_item_information(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FDItemInformationBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    const uint8_t *end = data + box->box.size;

    ADV_PARSE_U16(box->entry_count, ptr);

    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, PartitionEntryBox*, box->entry_count);
        uint16_t i = 0;
        for(; i < box->entry_count; ++i) {
            BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_partition_entry, ptr, end-ptr, (Box**)&box->entries[i]);
            if(res != BMFF_OK) {
                return res;
            }
            ptr += box->entries[i]->box.size;
        }
    }

    if(ptr + 8 < end) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_fd_session_group, ptr, end-ptr, (Box**)&box->session_info);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->session_info->box.size;
    }

    if(ptr + 8 < end) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_group_id_to_name, ptr, end-ptr, (Box**)&box->group_id_to_name);
        if(res != BMFF_OK) {
            return res;
        }
        ptr += box->group_id_to_name->box.size;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sub_track_information(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 24)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SubTrackInformationBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U16(box->switch_group, ptr);
    ADV_PARSE_U16(box->alternate_group, ptr);
    ADV_PARSE_U32(box->sub_track_id, ptr);

    const uint8_t *end = data + box->box.size;
    box->attribute_list_count = (end - ptr) / 4;

    if(box->attribute_list_count > 0) {
        BOX_MALLOCN(box->attribute_list, uint8_t*, box->attribute_list_count);

        uint32_t i = 0;
        for(; i < box->attribute_list_count; ++i) {
            box->attribute_list[i] = ptr;
            ptr += 4;
        }
    }    

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sub_track_sample_group(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SubTrackSampleGroupBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->grouping_type, ptr);
    ADV_PARSE_U16(box->item_count, ptr);

    if(box->item_count > 0) {
        BOX_MALLOCN(box->group_description_indicies, uint32_t, box->item_count);
        
        uint16_t i = 0;
        for(; i < box->item_count; ++i) {
            ADV_PARSE_U32(box->group_description_indicies[i], ptr);
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_stereo_video(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 26)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, StereoVideoBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->single_view_allowed = (eSingleViewMode)(ptr[3] & 0x03);
    ptr += 4;
    
    ADV_PARSE_U32(box->stereo_scheme, ptr);
    ADV_PARSE_U32(box->length, ptr);

    switch(box->length) {
        case 1: ADV_PARSE_U8(box->stereo_indication_type, ptr); break;
        case 2: ADV_PARSE_U16(box->stereo_indication_type, ptr); break;
        case 4: ADV_PARSE_U32(box->stereo_indication_type, ptr); break;
        case 8: ADV_PARSE_U64(box->stereo_indication_type, ptr); break;
    }

    const uint8_t *end = data + box->box.size;
    if(ptr < end) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_segment_index(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 32)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SegmentIndexBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->reference_id, ptr);
    ADV_PARSE_U32(box->timescale, ptr);

    if(box->box.version == 0) {
        ADV_PARSE_U32(box->earliest_presentation_time, ptr);
        ADV_PARSE_U32(box->first_offset, ptr);
    }else{
        ADV_PARSE_U64(box->earliest_presentation_time, ptr);
        ADV_PARSE_U64(box->first_offset, ptr);
    }

    ptr += 2; // reserved(16)
    ADV_PARSE_U16(box->reference_count, ptr);

    if(box->reference_count > 0) {
        BOX_MALLOCN(box->references, SegmentIndexRefEntry, box->reference_count);

        uint16_t i = 0;
        for(; i < box->reference_count; ++i) {
            SegmentIndexRefEntry *ref = &box->references[i];
            ref->reference_type = ((*ptr) >> 7) & 0x01;
            ADV_PARSE_U32(ref->referenced_size, ptr);
            ref->referenced_size &= 0x07FFFFFFF;
            ADV_PARSE_U32(ref->subsegment_duration, ptr);
            ref->starts_with_sap = ((*ptr) >> 7) & 0x01;
            ref->sap_type = ((*ptr) >> 4) & 0x07;
            ADV_PARSE_U32(ref->sap_delta_time, ptr);
            ref->sap_delta_time &= 0x0FFFFFFF;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_producer_reference_time(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 28)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ProducerReferenceTimeBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->reference_track_id, ptr);
    ADV_PARSE_U64(box->ntp_timestamp, ptr);

    if(box->box.version == 0) {
        ADV_PARSE_U32(box->media_time, ptr);
    }else{
        ADV_PARSE_U64(box->media_time, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_complete_track_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, CompleteTrackInfoBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    const uint8_t *end = data + box->box.size;
    ptr += parse_original_format_box(ptr, end-ptr, &box->original_format);

    _bmff_parse_children(ctx, ptr, end-ptr, &box->child_count, &box->children);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_clean_aperture(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 40)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, CleanApertureBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    ADV_PARSE_U32(box->clean_aperture_width_n, ptr);
    ADV_PARSE_U32(box->clean_aperture_width_d, ptr);
    ADV_PARSE_U32(box->clean_aperture_height_n, ptr);
    ADV_PARSE_U32(box->clean_aperture_height_d, ptr);
    ADV_PARSE_U32(box->horiz_off_n, ptr);
    ADV_PARSE_U32(box->horiz_off_d, ptr);
    ADV_PARSE_U32(box->vert_off_n, ptr);
    ADV_PARSE_U32(box->vert_off_d, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_pixel_aspect_ratio(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, PixelAspectRatioBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    ADV_PARSE_U32(box->h_spacing, ptr);
    ADV_PARSE_U32(box->v_spacing, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_channel_layout(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 14)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ChannelLayoutBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U8(box->stream_structure, ptr);

    if(box->stream_structure & eStreamStructureChannel == eStreamStructureChannel) {
        ADV_PARSE_U8(box->channel.defined_layout, ptr);
        box->channel.channel_count = ctx->channel_count;

        if(box->channel.defined_layout == 0) {
            if(ctx->channel_count > 0) {
                BOX_MALLOCN(box->channel.speaker_positions, uint8_t, ctx->channel_count);
                BOX_MALLOCN(box->channel.azimuths, uint16_t, ctx->channel_count);
                BOX_MALLOCN(box->channel.elevations, uint8_t, ctx->channel_count);
            }
            uint32_t i = 0;
            for(; i < ctx->channel_count; ++i) {
                ADV_PARSE_U8(box->channel.speaker_positions[i], ptr);
                if(box->channel.speaker_positions[i] == 126) {
                    ADV_PARSE_U16(box->channel.azimuths[i], ptr);
                    ADV_PARSE_U8(box->channel.elevations[i], ptr);
                }
            }
        }else{
            ADV_PARSE_U64(box->channel.omitted_channels_map, ptr);
        }
    }

    if((box->stream_structure & eStreamStructureObject) == eStreamStructureObject) {
        ADV_PARSE_U8(box->object.object_count, ptr);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sampling_rate(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SamplingRateBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sampling_rate, ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_subsegment_index(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SubsegmentIndexBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->subsegment_count, ptr);

    if(box->subsegment_count > 0) {
        BOX_MALLOCN(box->subsegments, SubsegmentIndexEntry, box->subsegment_count);
    }

    uint32_t i = 0;
    for(; i < box->subsegment_count; ++i) {
        SubsegmentIndexEntry *entry = &box->subsegments[i];

        ADV_PARSE_U32(entry->range_count, ptr);
        if(entry->range_count > 0) {
            BOX_MALLOCN(entry->levels, uint8_t, entry->range_count);
            BOX_MALLOCN(entry->range_sizes, uint32_t, entry->range_count);
        }

        uint32_t j = 0;
        for(; j < entry->range_count; ++j) {
            entry->levels[j] = *ptr;
            entry->range_sizes[j] = parse_u32(ptr) & 0x00FFFFFF;
            ptr += 4;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_rtp_hint_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 24)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, RtpHintSampleEntry);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    ptr += 6; // reserved
    ADV_PARSE_U16(box->data_reference_index, ptr);
    ADV_PARSE_U16(box->hint_track_version, ptr);
    ADV_PARSE_U16(box->highest_compatible_version, ptr);
    ADV_PARSE_U32(box->max_packet_size, ptr);

    if(ptr < end) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->additional_data_count, &box->additional_data);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_fd_hint_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 22)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, FDHintSampleEntry);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    ptr += 6; // reserved
    ADV_PARSE_U16(box->data_reference_index, ptr);
    ADV_PARSE_U16(box->hint_track_version, ptr);
    ADV_PARSE_U16(box->highest_compatible_version, ptr);
    ADV_PARSE_U16(box->partition_entry_id, ptr);
    ADV_PARSE_U16(box->fec_overhead, ptr);

    if(ptr < end) {
        _bmff_parse_children(ctx, ptr, end-ptr, &box->additional_data_count, &box->additional_data);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_xml_meta_data_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 19)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, XMLMetaDataSampleEntry);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    ptr += 6; // reserved
    ADV_PARSE_U16(box->data_reference_index, ptr);

    uint32_t c = _bmff_parse_children(ctx, ptr, end-ptr, &box->other_boxes_count, &box->other_boxes);
    ptr += c;

    ADV_PARSE_STR(box->content_encoding, ptr);
    ADV_PARSE_STR(box->nmspace, ptr);
    ADV_PARSE_STR(box->schema_location, ptr);

    if(ptr < end) {
        BMFFCode res = _bmff_parse_child(ctx, _bmff_parse_box_bit_rate, ptr, end-ptr, (Box**)&box->bitrate);
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_text_meta_data_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 18)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TextMetaDataSampleEntry);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    ptr += 6; // reserved
    ADV_PARSE_U16(box->data_reference_index, ptr);

    uint32_t c = _bmff_parse_children(ctx, ptr, end-ptr, &box->other_boxes_count, &box->other_boxes);
    ptr += c;

    ADV_PARSE_STR(box->content_encoding, ptr);
    ADV_PARSE_STR(box->mime_format, ptr);

    if(ptr < end && strncmp(&ptr[4], "btrt", 4) == 0) {
        if(BMFF_OK == _bmff_parse_child(ctx, _bmff_parse_box_bit_rate, ptr, end-ptr, (Box**)&box->bitrate)) {
            ptr += box->bitrate->box.size;
        }
    }
    if(ptr < end && strncmp(&ptr[4], "txtC", 4) == 0) {
        if(BMFF_OK == _bmff_parse_child(ctx, _bmff_parse_box_full_string, ptr, end-ptr, (Box**)&box->text_config)) {
            ptr += box->text_config->box.size;
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_uri_meta_sample_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, UriMetaSampleEntryBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    ptr += 6; // reserved
    ADV_PARSE_U16(box->data_reference_index, ptr);

    uint32_t c = _bmff_parse_children(ctx, ptr, end-ptr, &box->other_boxes_count, &box->other_boxes);
    ptr += c;

    // all of the known boxes would have been parsed in the children, so we'll
    // copy the pointers to the "box" if they exist.

    uint32_t i = box->other_boxes_count;
    for(; i > 0; --i) {
        if(strncmp("uri ", box->other_boxes[i-1]->type, 4) == 0) {
            --i;
            break;
        }
    }

    box->the_label = (UriBox*) box->other_boxes[i];

    // optional boxes
    uint32_t count = 1;
    if(i + count < box->other_boxes_count && strncmp("uriI", box->other_boxes[i + count]->type, 4) == 0) {
        box->init = (UriInitBox*) box->other_boxes[i + count];
        count++;
    }         
    if(i + count < box->other_boxes_count && strncmp("btrt", box->other_boxes[i + count]->type, 4) == 0) {
        box->bitrate = (BitRateBox*) box->other_boxes[i + count];
        count++;
    }

    // adjust the count of other boxes due to reassigning pointers from "the label" box.
    box->other_boxes_count = i;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_object_descriptor(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ObjectDescriptorBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ptr += _bmff_parse_object_descriptor(ctx, ptr, box->box.size, &box->od);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_es_descriptor(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ESDescriptorBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    box->descriptor = ptr;
    box->descriptor_size = end - ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_avc_decoder_config(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, AVCDecoderConfigBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    box->config_record = ptr;
    box->config_record_size = end - ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_sample_encryption(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleEncryptionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->sample_count, ptr);
    BOX_MALLOCN(box->samples, EncryptionSample, box->sample_count);

    uint32_t i=0;
    for(; i<box->sample_count; ++i) {
        EncryptionSample *sample = &box->samples[i];
        sample->iv_size = ctx->default_iv_size;
        if(sample->iv_size > 0 && ctx->is_constant_iv == eBooleanFalse) {
            sample->iv = ptr;
            ptr += sample->iv_size;
        }

        if((box->box.flags & 0x02) == 0x02) {
            ADV_PARSE_U16(sample->subsample_count, ptr);
            BOX_MALLOCN(sample->subsamples, EncryptionSubsample, sample->subsample_count);

            uint32_t j=0;
            for(; j<sample->subsample_count; ++j) {
                EncryptionSubsample *subs = &sample->subsamples[j];
                ADV_PARSE_U16(subs->bytes_of_clear_data, ptr);
                ADV_PARSE_U32(subs->bytes_of_encrypted_data, ptr);
            }
        }
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_encryption(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 17)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, TrackEncryptionBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ptr++; // reserved

    if(box->box.version >= 1) {
        uint8_t val = *ptr;
        box->default_crypt_byte_block = (val >> 4) & 0x0F;
        box->default_skip_byte_block = val & 0x0F;
    }
    ptr++; // reserved or default values above

    box->default_is_protected = (*ptr)==1 ? eBooleanTrue : eBooleanFalse;
    ptr++;

    ADV_PARSE_U8(box->default_per_sample_iv_size, ptr);
    // set the default IV size in the context.
    // this is used by the Sample Encryption Box parser.
    // note: this may get overwritten by the constant iv size.
    ctx->default_iv_size = box->default_per_sample_iv_size;

    memcpy(box->default_kid, ptr, 16);
    ptr += 16;

    if(box->default_is_protected == 1 && box->default_per_sample_iv_size == 0) {
        ADV_PARSE_U8(box->default_constant_iv_size, ptr);
        box->default_constant_iv = ptr;
        ptr += box->default_constant_iv_size;
        // set the default IV size in the context.
        // this is used by the Sample Encryption Box parser.
        ctx->default_iv_size = box->default_constant_iv_size;
        ctx->is_constant_iv = eBooleanTrue;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_protection_system_specific_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 32)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ProtectionSystemSpecificHeaderBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    memcpy(box->system_id, ptr, 16);
    ptr += 16;

    if(box->box.version > 0) {
        ADV_PARSE_U32(box->kid_count, ptr);
        if(box->kid_count) {
            box->kids = ptr;
            ptr += (box->kid_count * 16);
        }
    }

    ADV_PARSE_U32(box->data_size, ptr);
    if(box->data_size > 0) {
        box->data = ptr;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_id3v2_metadata(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ID3v2MetadataBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    uint16_t val = parse_u16(ptr);
    parse_iso639_2_lang(val, box->language);
    ptr += 2;

    box->data = ptr;
    box->data_size = end - ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_event_message(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 19)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, EventMessageBox);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);
    const uint8_t *end = data + box->box.size;

    ADV_PARSE_STR(box->scheme_id_uri, ptr);
    ADV_PARSE_STR(box->value, ptr);
    ADV_PARSE_U32(box->timescale, ptr);
    ADV_PARSE_U32(box->presentation_time_delta, ptr);
    ADV_PARSE_U32(box->event_duration, ptr);
    ADV_PARSE_U32(box->id, ptr);

    if(ptr < end) {
        box->message_data = ptr;
        box->message_data_size = end - ptr;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

/*
BMFFCode _bmff_parse_box_(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 012)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, );

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}
*/
