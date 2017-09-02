#include "parse.h"

#include <memory.h>
#include <stdio.h>

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

#define BOX_MALLOC(M, T)        T *M = ctx->malloc(sizeof(T)); memset(M, 0, sizeof(T));
#define BOX_MALLOCN(M, T, N)    M = ctx->malloc(sizeof(T)*(N)); memset(M, 0, sizeof(T)*(N));      

const MapItem parse_map[] = {
    {"ftyp", 1, _bmff_parse_box_file_type},
    {"moov", 1, _bmff_parse_box_generic_container},
    {"trak", 1, _bmff_parse_box_generic_container},
    {"edts", 1, _bmff_parse_box_generic_container},
    {"mdia", 1, _bmff_parse_box_generic_container},
    {"minf", 1, _bmff_parse_box_generic_container},
    {"dinf", 1, _bmff_parse_box_generic_container},
    {"stbl", 1, _bmff_parse_box_generic_container},
    {"mvex", 1, _bmff_parse_box_generic_container},
    {"moof", 1, _bmff_parse_box_generic_container},
    {"traf", 1, _bmff_parse_box_generic_container},
    {"mfra", 1, _bmff_parse_box_generic_container},
    {"udta", 1, _bmff_parse_box_generic_container},
    {"tref", 1, _bmff_parse_box_generic_container},
    {"hint", 0, _bmff_parse_box_track_reference_type},
    {"cdsc", 0, _bmff_parse_box_track_reference_type},
    {"font", 0, _bmff_parse_box_track_reference_type},
    {"vdep", 0, _bmff_parse_box_track_reference_type},
    {"vplx", 0, _bmff_parse_box_track_reference_type},
    {"subt", 0, _bmff_parse_box_track_reference_type},
    {"nmhd", 0, _bmff_parse_box_full},
    {"pdin", 0, _bmff_parse_box_progressive_download_info},
    {"mdat", 0, _bmff_parse_box_media_data},
    {"hdlr", 0, _bmff_parse_box_handler},
    {"pitm", 0, _bmff_parse_box_primary_item},
    {"iloc", 0, _bmff_parse_box_primary_item},
    {"infe", 0, _bmff_parse_box_item_info_entry},
    {"iinf", 0, _bmff_parse_box_item_info},
    {"ipmc", 0, _bmff_parse_box_ipmp_control},
    {"frma", 0, _bmff_parse_box_original_format},
    {"imif", 0, _bmff_parse_box_ipmp_info},
    {"schm", 0, _bmff_parse_box_scheme_type},
    {"schi", 0, _bmff_parse_box_scheme_info},
    {"sinf", 0, _bmff_parse_box_protection_scheme_info},
    {"ipro", 0, _bmff_parse_box_item_protection},
    {"meta", 0, _bmff_parse_box_meta},
    {"mvhd", 0, _bmff_parse_box_movie_header},
    {"mfhd", 0, _bmff_parse_box_movie_fragment_header},
    {"tfra", 0, _bmff_parse_box_track_fragment_random_access},
    {"mfro", 0, _bmff_parse_box_movie_fragment_random_access_offset},
    {"xml ", 0, _bmff_parse_box_xml},
    {"bxml", 0, _bmff_parse_box_xml},
    {"tkhd", 0, _bmff_parse_box_track_header},
    {"mehd", 0, _bmff_parse_box_movie_extends_header},
    {"trex", 0, _bmff_parse_box_track_extends},
    {"tfhd", 0, _bmff_parse_box_track_fragment_header},
    {"trun", 0, _bmff_parse_box_track_run},
    {"sdtp", 0, _bmff_parse_box_sample_dependency_type},
    {"sbgp", 0, _bmff_parse_box_sample_to_group},
    {"subs", 0, _bmff_parse_box_sub_sample_information},
    {"cprt", 0, _bmff_parse_box_copyright},
    {"url ", 0, _bmff_parse_box_data_entry_url},
    {"urn ", 0, _bmff_parse_box_data_entry_urn},
    {"dref", 0, _bmff_parse_box_data_reference},
    {"elst", 0, _bmff_parse_box_edit_list},
    {"mdhd", 0, _bmff_parse_box_media_header},
    {"vmhd", 0, _bmff_parse_box_video_media_header},
    {"smhd", 0, _bmff_parse_box_sound_media_header},
    {"hmhd", 0, _bmff_parse_box_hint_media_header},
    {"stsd", 0, _bmff_parse_box_sample_description},
    {"stts", 0, _bmff_parse_box_time_to_sample},
    {"ctts", 0, _bmff_parse_box_composition_offset},
    {"stsc", 0, _bmff_parse_box_sample_to_chunk},
    {"stsz", 0, _bmff_parse_box_sample_size},
    {"stz2", 0, _bmff_parse_box_compact_sample_size},
    {"stco", 0, _bmff_parse_box_chunk_offset},
    {"co64", 0, _bmff_parse_box_chunk_large_offset},
    {"stss", 0, _bmff_parse_box_sync_sample},
    {"stsh", 0, _bmff_parse_box_shadow_sync_sample},
    {"padb", 0, _bmff_parse_box_padding_bits},
    {"stdp", 0, _bmff_parse_box_degradation_priority},
    {"sgpd", 0, _bmff_parse_box_sample_group_description},
    {"msrc", 0, _bmff_parse_box_track_group_type},
    {"elng", 0, _bmff_parse_box_extended_language_tag},
    {"btrt", 0, _bmff_parse_box_bit_rate},
    {"cslg", 0, _bmff_parse_box_composition_to_decode},
};

const int parse_map_len = sizeof(parse_map) / sizeof(MapItem);

void print_box(const uint8_t *data, size_t size)
{
    const uint8_t *ptr = data;
    const uint8_t *end = data + size;
    printf("uint8_t data[] = {\n");
    while(ptr < end) {
        printf("    %02X (%c), %02X (%c), %02X (%c), %02X (%c),\n", ptr[0], ptr[0], ptr[1], ptr[1], ptr[2], ptr[2], ptr[3], ptr[3]);
        ptr += 4;
    }
    printf("};\n\n");
}

uint16_t parse_u16(const uint8_t *bytes)
{
    uint16_t val = *((uint16_t*)bytes);
#ifdef __BIG_ENDIAN__
    return val;
#else
    return ((val >> 8) & 0x00FF) | ((val << 8) & 0xFF00);
#endif
}

uint32_t parse_u32(const uint8_t *bytes)
{
    uint32_t val = *((uint32_t*)bytes);
#ifdef __BIG_ENDIAN__
    return val;
#else
    return ((val >> 24) & 0x000000FF) |
           ((val >>  8) & 0x0000FF00) |
           ((val <<  8) & 0x00FF0000) |
           ((val << 24) & 0xFF000000) ;
#endif
}

uint64_t parse_u64(const uint8_t *bytes)
{
    uint64_t val = *((uint64_t*)bytes);
#ifdef __BIG_ENDIAN__
    return val;
#else
    return ((val >> 56) & 0x00000000000000FFL) |
           ((val >> 40) & 0x000000000000FF00L) |
           ((val >> 24) & 0x0000000000FF0000L) |
           ((val >>  8) & 0x00000000FF000000L) |
           ((val <<  8) & 0x000000FF00000000L) |
           ((val << 24) & 0x0000FF0000000000L) |
           ((val << 40) & 0x00FF000000000000L) |
           ((val << 56) & 0xFF00000000000000L) ;
#endif
}

fxpt16_t parse_fp16(const uint8_t *bytes)
{
    float val = (float) ((int32_t) parse_u32(bytes));
    return val / 65536.f;
}

fxpt8_t parse_fp8(const uint8_t *bytes)
{
    float val = (float) ((int16_t) parse_u16(bytes));
    return val / 256.f;
}

uint32_t parse_var_length(const uint8_t *bytes, uint8_t length)
{
    uint32_t val = 0;

    switch(length) {
        case 1: val = bytes[0]; break;
        case 2: val = (uint32_t) parse_u16(bytes); break;
        case 3: val = (parse_u32(bytes) >> 8) & 0xFFFFFF; break;
        case 4: val = parse_u32(bytes); break;
    }

    return val;
}

int parse_box(const uint8_t *data, size_t size, Box *box)
{
    const uint8_t *ptr = data;
    ADV_PARSE_U32(box->size, ptr);
    
    memcpy(&box->type, ptr, 4); // hint or cdsc
    ptr += 4;

    if(box->size == 1) {
        ADV_PARSE_U64(box->large_size, ptr);
    }else{
        box->large_size = 0;
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

    if(box->size == 1) {
        ADV_PARSE_U64(box->large_size, ptr);
    }

    box->version = *ptr;
    ptr++;
    box->flags = (parse_u32(ptr) >> 8) & 0x00FFFFFF;
    ptr += 3;

    return ptr - data;
}

int parse_original_format_box(const uint8_t *data, size_t size, OriginalFormatBox *box)
{
    const uint8_t *ptr = data;
    ptr += parse_box(data, size, (Box*)box);

    memcpy(box->data_format, ptr, 4);
    ptr += 4;

    return ptr - data;
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
    box->nb_compatible_brands = (size-16) / 4;
    box->compatible_brands = ptr;

    *box_ptr = (Box*)box;
    return BMFF_OK;
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

    // count how many children Boxes there are.
    box->child_count = 0;
    box->children = NULL;

    const uint8_t *tmp = ptr;
    while(tmp + 8 < end) {
        uint32_t box_size = parse_u32(tmp);
        tmp += box_size;
        box->child_count++;
    }

    // allocate room for the children
    if(box->child_count > 0) {
        BOX_MALLOCN(box->children, Box*, box->child_count);
    }

    // parse all the Boxes.
    int child_idx = 0;

    while(ptr + 8 < end)
    {
        uint32_t box_size = parse_u32(ptr);
        // get the numerical value of the type, making sure to keep the bytes in
        // the correct order.
        uint32_t box_type = *((uint32_t*)(ptr+4));

        printf("%c%c%c%c, size: %d\n", ptr[4], ptr[5], ptr[6], ptr[7], box_size);

        // find the parser for the next Child.
        int i=0;
        for(; i < PARSE_MAP_LEN; ++i)
        {
            uint32_t parser_box_type = parse_map[i].box_type_value;
            if(parser_box_type == box_type) {
                // parse the Box.
                Box *child_box;
                BMFFCode res = parse_map[i].parse_func(ctx, ptr, end-ptr, &child_box);
                if(res == BMFF_OK) {
                    // add the parsed Box to the list of children.
                    box->children[child_idx] = child_box;
                    child_idx++;
                    printf("%c%c%c%c, size: %d\n", child_box->type[0], child_box->type[1], child_box->type[2], child_box->type[3], child_box->size);
                } else {
                    printf("Error paring box: %d\n", res);
                }
                // break out once we have found a parser.
                break;
            }
        }

        if(i == PARSE_MAP_LEN) {
            printf("no box parser found %c%c%c%c\n", ptr[4], ptr[5], ptr[6], ptr[7]);
        }

        ptr += box_size;
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

    print_box(data, size);

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
    ADV_PARSE_U32(box->handler_type, ptr);
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

    ADV_PARSE_U16(box->item_id, ptr);

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
    ptr++;

    ADV_PARSE_U16(box->item_count, ptr);

    if(box->item_count > 0) {
        BOX_MALLOCN(box->items, ItemLocation, box->item_count);

        int offset_shift = 64 - (((int)box->offset_size) * 8);
        int length_shift = 64 - (((int)box->length_size) * 8);

        int i=0;
        for(; i < box->item_count; ++i) {
            ItemLocation *item = &box->items[i];
            ADV_PARSE_U16(item->item_id, ptr);
            ADV_PARSE_U16(item->data_reference_index, ptr);
            if(box->base_offset_size == 4) {
                uint32_t val = parse_u32(ptr);
                item->base_offset = (uint64_t)val;
                ptr += 4;
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
                    if(box->offset_size == 4) {
                        uint32_t val = parse_u32(ptr);
                        extent->offset = (uint64_t)val;
                        ptr += 4;
                    }else if(box->offset_size == 8) {
                        ADV_PARSE_U64(extent->offset, ptr);
                    }else{
                        extent->offset = 0;
                    }
                    if(box->length_size == 4) {
                        uint32_t val = parse_u32(ptr);
                        extent->length = (uint64_t)val;
                        ptr += 4;
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

BMFFCode _bmff_parse_box_item_info_entry(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 19)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ItemInfoEntry);

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U16(box->item_id, ptr);
    ADV_PARSE_U16(box->item_protection_index, ptr);
    ADV_PARSE_STR(box->item_name, ptr);
    ADV_PARSE_STR(box->content_type, ptr);
    box->content_encoding = ptr;

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

    ADV_PARSE_U16(box->entry_count, ptr);

    BOX_MALLOCN(box->entries, ItemInfoEntry*, box->entry_count);
    int i=0;
    for(; i < box->entry_count; ++i) {
        BMFFCode res = _bmff_parse_box_item_info_entry(ctx, ptr, size-(ptr-data), (Box**)&box->entries[i]);
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

BMFFCode _bmff_parse_box_scheme_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SchemeInformationBox);

    const uint8_t *ptr = data;
    ptr += parse_box(data, size, &box->box);

    const uint8_t *end = data + box->box.size;

    // count the number of boxes
    const uint8_t *ptr2 = ptr;
    uint32_t count = 0;

    while(ptr2 < (end - 4)) {
        uint32_t size = parse_u32(ptr2);
        count++;
        ptr2 += size;
    }

    // allocate Box array
    BOX_MALLOCN(box->scheme_specific_data, Box, count);
    box->scheme_specific_data_count = count;

    // parse Boxes
    int i=0;
    for(; i<count; ++i) {
        parse_box(ptr, ptr-end, &box->scheme_specific_data[i]);
        ptr += box->scheme_specific_data[i].size;
    }

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_protection_scheme_info(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 12)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, ProtectionSchemeInfoBox);

    const uint8_t *ptr = data;
    ptr += parse_original_format_box(data, size, &box->box);

    const uint8_t *end = data + box->box.box.size;

    // parse the optional boxes
    if(ptr < end && strncmp(ptr+4, "imif", 4) == 0) {
        BMFFCode res = _bmff_parse_box_ipmp_info(ctx, ptr, end-ptr, (Box**)&box->ipmp_descriptors);
        if(res != BMFF_OK) {
            return res;
        }
        uint32_t box_size = parse_u32(ptr);
        ptr += box_size;
    }

    if(ptr < end && strncmp(ptr+4, "schm", 4) == 0) {
        BMFFCode res = _bmff_parse_box_scheme_type(ctx, ptr, end-ptr, (Box**)&box->scheme_type);
        if(res != BMFF_OK) {
            return res;
        }
        uint32_t box_size = parse_u32(ptr);
        ptr += box_size;
    }

    if(ptr < end && strncmp(ptr+4, "schi", 4) == 0) {
        BMFFCode res = _bmff_parse_box_scheme_info(ctx, ptr, end-ptr, (Box**)&box->scheme_info);
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
            BMFFCode res = _bmff_parse_box_protection_scheme_info(ctx, ptr, end-ptr, (Box**) &box->protection_info[i]);
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

    BMFFCode res = _bmff_parse_box_handler(ctx, ptr, end-ptr, (Box**)&box->handler);
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
    const int map_count = 6;
    struct Map map[6] = {
         { "pitm", _bmff_parse_box_primary_item, (AbstractBox**)&box->primary_resource },
         { "dinf", _bmff_parse_box_generic_container, (AbstractBox**)&box->file_locations },
         { "iloc", _bmff_parse_box_item_location, (AbstractBox**)&box->item_locations },
         { "ipro", _bmff_parse_box_item_protection, (AbstractBox**)&box->protections },
         { "iinf", _bmff_parse_box_item_info, (AbstractBox**)&box->item_infos },
         { "ipmc", _bmff_parse_box_ipmp_control, (AbstractBox**)&box->ipmp_control },
    };

    // Parse optional Boxes
    while(ptr < end) {
        int i=0;
        // find the parser for the next box keeping track of whether we found a parser.
        int found=0;
        const char *_t = &ptr[4];
        int _s = parse_u32(ptr);
        for(; i<map_count; ++i) {
            if(memcmp(&ptr[4], map[i].type, 4) == 0) {
                found=1;
                res = map[i].func(ctx, ptr, end-ptr, (Box**)map[i].box_ptr);
                if(res != BMFF_OK) return res;
                ptr += (*(map[i].box_ptr))->box.size;
                break;
            }
        }

        // if no parser was found, we must be parsing one of the "other" boxes.
        // Don't parse the "other" boxes, just assign the data to the MetaBox
        // when we reach the first Box, and keep track of how many there are.
        if(!found) {
          box->other_boxes_len++;
          if(!box->other_boxes) {
            box->other_boxes = (Box*)ptr;
          }
          ptr += parse_u32(ptr);
        }
    }
    // Item Protection Box
    // Item Info Box
    // IPMP Control Box

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
    ADV_PARSE_U32(box->width, ptr);
    ADV_PARSE_U32(box->height, ptr);

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
    // (6) reserved
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
            ADV_PARSE_U32(sample->composition_time_offset, ptr);
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
    box->language[0] = (uint8_t)(0x0060 + ((val >> 10) & 0x001F));
    box->language[1] = (uint8_t)(0x0060 + ((val >> 5) & 0x001F));
    box->language[2] = (uint8_t)(0x0060 + (val & 0x001F));
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
                res = _bmff_parse_box_data_entry_urn(ctx, ptr, end-ptr, (Box**)dataEntry);
            }else{
                res = _bmff_parse_box_data_entry_url(ctx, ptr, end-ptr, (Box**)dataEntry);
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
    box->language[0] = (uint8_t)(0x0060 + ((val >> 10) & 0x001F));
    box->language[1] = (uint8_t)(0x0060 + ((val >> 5) & 0x001F));
    box->language[2] = (uint8_t)(0x0060 + (val & 0x001F));
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

BMFFCode _bmff_parse_box_sample_description(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    BOX_MALLOC(box, SampleDescriptionBox);

    const uint8_t *ptr = data;
    const uint8_t *end = ptr + size;
    ptr += parse_full_box(data, size, &box->box);

    ADV_PARSE_U32(box->entry_count, ptr);
    if(box->entry_count > 0) {
        BOX_MALLOCN(box->entries, SampleEntry**, box->entry_count);
    }

    uint32_t i=0;
    for(; i<box->entry_count; ++i) {
        // skip past the SampleEntry info.
        const uint8_t *entry_ptr = ptr + 16;
        SampleEntry *entry = NULL;

        if(0 == strncmp(ctx->track_sample_table_handler_type,"soun",4)) {
            BOX_MALLOC(audio_entry, AudioSampleEntry);
            entry_ptr += 8; // reserved (32)[2]
            ADV_PARSE_U16(audio_entry->channel_count, entry_ptr);
            ADV_PARSE_U16(audio_entry->sample_size, entry_ptr);
            entry_ptr += 2; // predefined
            entry_ptr += 2; // reserved
            ADV_PARSE_U32(audio_entry->sample_rate, entry_ptr);
            entry = (SampleEntry*)audio_entry;
        }else if(0 == strncmp(ctx->track_sample_table_handler_type,"vide",4)) {
            BOX_MALLOC(visual_entry, VisualSampleEntry);
            entry_ptr += 16; // predefined(2), reserved(2), predefined(12)
            ADV_PARSE_U16(visual_entry->width, entry_ptr);
            ADV_PARSE_U16(visual_entry->height, entry_ptr);
            ADV_PARSE_FP16(visual_entry->horiz_resolution, entry_ptr);
            ADV_PARSE_FP16(visual_entry->vert_resolution, entry_ptr);
            entry_ptr += 4; // reserved
            ADV_PARSE_U16(visual_entry->frame_count, entry_ptr);
            // the first byte contains the length of the compressor string
            uint8_t len = *entry_ptr;
            if(len > 31) len = 31; // make sure the length is valid
            entry_ptr++;
            // copy the string
            strncpy(visual_entry->compressor_name, entry_ptr, len);
            // null terminate the string at it's length
            visual_entry->compressor_name[len] = '\0';
            entry_ptr += 31;
            ADV_PARSE_U16(visual_entry->depth, entry_ptr);
            entry_ptr += 2; // predefined
            entry = (SampleEntry*)visual_entry;
        }else if(0 == strncmp(ctx->track_sample_table_handler_type,"hint",4)) {
            BOX_MALLOC(hint_entry, HintSampleEntry);
            hint_entry->data = entry_ptr;
            const uint8_t *entry_ptr_end = ptr + parse_u32(ptr);
            hint_entry->data_size = entry_ptr_end - entry_ptr;
            entry_ptr = entry_ptr_end;
            entry = (SampleEntry*)hint_entry;
        }
        
        // parse the SampleEntry info
        if(entry != NULL) {
            ptr += parse_box(ptr, end-ptr, &entry->box);
            ptr += 6; // reserved (8)[6]
            ADV_PARSE_U16(entry->data_reference_index, ptr);
        }

        box->entries[i] = entry;

        // set the ptr to the end of the current box / start of the next one.
        ptr = entry_ptr;
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
    ADV_PARSE_U32(box->entry_count, ptr);

    memcpy(box->handler_type, ctx->track_sample_table_handler_type, 4);
    box->sample_group_entries = ptr;
    box->sample_group_entries_size = (data + size) - ptr;

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
