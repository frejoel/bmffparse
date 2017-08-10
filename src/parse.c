#include "parse.h"

#include <memory.h>
#include <stdio.h>

const MapItem parse_map[] = {
    {"ftyp", 1, _bmff_parse_box_file_type},
    {"moov", 1, _bmff_parse_box_generic_container},
    {"trak", 1, _bmff_parse_box_generic_container},
    {"edts", 1, _bmff_parse_box_generic_container},
    {"mdia", 1, _bmff_parse_box_generic_container},
    {"mnif", 1, _bmff_parse_box_generic_container},
    {"dinf", 1, _bmff_parse_box_generic_container},
    {"stbl", 1, _bmff_parse_box_generic_container},
    {"mvex", 1, _bmff_parse_box_generic_container},
    {"moof", 1, _bmff_parse_box_generic_container},
    {"traf", 1, _bmff_parse_box_generic_container},
    {"mfra", 1, _bmff_parse_box_generic_container},
    {"udta", 1, _bmff_parse_box_generic_container},
    {"tref", 1, _bmff_parse_box_generic_container},
    {"hint", 0, _bmff_parse_box_track_reference},
    {"cdsc", 0, _bmff_parse_box_track_reference},
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
    float val = (float) parse_u32(bytes);
    return val / 65536.f;
}

fxpt8_t parse_fp8(const uint8_t *bytes)
{
    float val = (float) parse_u16(bytes);
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
    box->size = parse_u32(ptr);
    ptr += 4;
    memcpy(&box->type, ptr, 4); // hint or cdsc
    ptr += 4;

    if(box->size == 1) {
        box->large_size = parse_u64(ptr);
        ptr += 8;
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
        box->large_size = parse_u64(ptr);
        ptr += 8;
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

    FileTypeBox *box = (FileTypeBox*) ctx->malloc(sizeof(FileTypeBox));

    const uint8_t *ptr = data;
    ptr += parse_box(ptr, size, &box->box);

    memcpy(&box->major_brand, ptr, 4);
    ptr += 4;
    box->minor_version = parse_u32(ptr);
    ptr += 4;
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

    ContainerBox *box = (ContainerBox*) ctx->malloc(sizeof(ContainerBox));

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
        box->children = (Box**) ctx->malloc(sizeof(Box*) * box->child_count);
        memset(box->children, 0, sizeof(Box*) * box->child_count);
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

BMFFCode _bmff_parse_box_track_reference(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 8)    return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    TrackReferenceTypeBox *box = (TrackReferenceTypeBox*) ctx->malloc(sizeof(TrackReferenceTypeBox));

    print_box(data, size);

    const uint8_t *ptr = data;
    ptr += parse_box(ptr, size, &box->box); // hint or cdsc

    box->nb_track_ids = (box->box.size - 8) / 4;
    box->track_ids = (uint32_t*) ctx->malloc(sizeof(uint32_t) * box->nb_track_ids);

    int i = 0;
    for(; i < box->nb_track_ids; ++i) {
        box->track_ids[i] = parse_u32(ptr);
        ptr += 4;
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

    FullBox *box = (FullBox*) ctx->malloc(sizeof(FullBox));

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

    ProgressiveDownloadBox *box = (ProgressiveDownloadBox*) ctx->malloc(sizeof(ProgressiveDownloadBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->nb_bitrates = (size - (ptr - data)) / 8;
    box->bitrates = (ProgressiveDownloadBitrate*) ctx->malloc(sizeof(ProgressiveDownloadBitrate) * box->nb_bitrates);

    int i=0;
    for(; i<box->nb_bitrates; ++i) {
        box->bitrates[i].rate = parse_u32(ptr);
        ptr += 4;
        box->bitrates[i].initial_delay = parse_u32(ptr);
        ptr += 4;
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

    MediaDataBox *box = (MediaDataBox*) ctx->malloc(sizeof(MediaDataBox));

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

    HandlerBox *box = (HandlerBox*) ctx->malloc(sizeof(HandlerBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    ptr += 4; // pre-defined (0).
    box->handler_type = parse_u32(ptr);
    ptr += 16; // handler type (4) and uint32_t x 3 (12) reserved.
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

    PrimaryItemBox *box = (PrimaryItemBox*) ctx->malloc(sizeof(PrimaryItemBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->item_id = parse_u16(ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_item_location(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    ItemLocationBox *box = (ItemLocationBox*) ctx->malloc(sizeof(ItemLocationBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->offset_size = ((*ptr) >> 4) & 0x0F;
    box->length_size = (*ptr) & 0x0F;
    ptr++;

    box->base_offset_size = ((*ptr) >> 4) & 0x0F;
    ptr++;

    box->item_count = parse_u16(ptr);
    ptr += 2;

    if(box->item_count > 0) {
        box->items = (ItemLocation*) ctx->malloc(sizeof(ItemLocation) * box->item_count);

        int offset_shift = 64 - (((int)box->offset_size) * 8);
        int length_shift = 64 - (((int)box->length_size) * 8);

        int i=0;
        for(; i < box->item_count; ++i) {
            ItemLocation *item = &box->items[i];
            item->item_id = parse_u16(ptr);
            ptr += 2;
            item->data_reference_index = parse_u16(ptr);
            ptr += 2;
            if(box->base_offset_size == 4) {
                uint32_t val = parse_u32(ptr);
                item->base_offset = (uint64_t)val;
                ptr += 4;
            }else if(box->base_offset_size == 8) {
                item->base_offset = parse_u64(ptr);
                ptr += 8;
            }else{
                item->base_offset = 0;
            }
            item->extent_count = parse_u16(ptr);
            ptr += 2;

            if(item->extent_count > 0) {
                item->extents = (Extent*) ctx->malloc(sizeof(Extent) * item->extent_count);
                int j=0;
                for(; j<item->extent_count; ++j) {
                    Extent *extent = &item->extents[j];
                    if(box->offset_size == 4) {
                        uint32_t val = parse_u32(ptr);
                        extent->offset = val;
                        ptr += 4;
                    }else if(box->offset_size == 8) {
                        extent->offset = parse_u64(ptr);
                        ptr += 8;
                    }else{
                        extent->offset = 0;
                    }
                    if(box->length_size == 4) {
                        uint32_t val = parse_u32(ptr);
                        extent->length = val;
                        ptr += 4;
                    }else if(box->length_size == 8) {
                        extent->length = parse_u64(ptr);
                        ptr += 8;
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

    ItemInfoEntry *box = (ItemInfoEntry*) ctx->malloc(sizeof(ItemInfoEntry));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->item_id = parse_u16(ptr);
    ptr += 2;
    box->item_protection_index = parse_u16(ptr);
    ptr += 2;
    box->item_name = ptr;
    while(*ptr != '\0') {
        ptr++;
    }
    ptr++;
    box->content_type = ptr;
    while(*ptr != '\0') {
        ptr++;
    }
    ptr++;
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

    ItemInfoBox *box = (ItemInfoBox*) ctx->malloc(sizeof(ItemInfoBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->entry_count = parse_u16(ptr);
    ptr += 2;

    box->entries = (ItemInfoEntry**) ctx->malloc(sizeof(size_t) * box->entry_count);
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

    IPMPControlBox *box = (IPMPControlBox*) ctx->malloc(sizeof(IPMPControlBox));
    ptr += parse_full_box(data, size, &box->box);

    box->tool_list.tag = ptr[0];
    box->tool_list.num_tools = ptr[1];
    ptr += 2;

    if(box->tool_list.num_tools > 0)
    {
        size_t tool_size = sizeof(IPMPTool) * box->tool_list.num_tools;
        box->tool_list.ipmp_tools = (IPMPTool*) ctx->malloc(tool_size);
        memset(box->tool_list.ipmp_tools, 0, tool_size);

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
                tool->tool_urls = (uint8_t**) ctx->malloc(sizeof(size_t) * tool->num_urls);

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

    OriginalFormatBox *box = (OriginalFormatBox*) ctx->malloc(sizeof(OriginalFormatBox));

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

    IPMPInfoBox *box = (IPMPInfoBox*) ctx->malloc(sizeof(IPMPInfoBox));

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

    SchemeTypeBox *box = (SchemeTypeBox*) ctx->malloc(sizeof(SchemeTypeBox));
    memset(box, 0, sizeof(box));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    memcpy(box->scheme_type, ptr, 4);
    ptr += 4;
    box->scheme_version = parse_u32(ptr);
    ptr += 4;

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

    SchemeInformationBox *box = (SchemeInformationBox*) ctx->malloc(sizeof(SchemeInformationBox));

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
    box->scheme_specific_data = (Box*)ctx->malloc(sizeof(Box) * count);
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

    ProtectionSchemeInfoBox *box = (ProtectionSchemeInfoBox*) ctx->malloc(sizeof(ProtectionSchemeInfoBox));
    memset(box, 0, sizeof(ProtectionSchemeInfoBox));

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

    ItemProtectionBox *box = (ItemProtectionBox*) ctx->malloc(sizeof(ItemProtectionBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    const uint8_t *end = data + box->box.size;

    box->protection_count = parse_u16(ptr);
    ptr += 2;

    if(box->protection_count > 0) {
        box->protection_info = (ProtectionSchemeInfoBox **) ctx->malloc(sizeof(size_t) * box->protection_count);

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

    MetaBox *box = (MetaBox*) ctx->malloc(sizeof(MetaBox));
    memset(box, 0, sizeof(MetaBox));

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

    MovieHeaderBox *box = (MovieHeaderBox*) ctx->malloc(sizeof(MovieHeaderBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
      box->creation_time = parse_u64(ptr);
      box->modification_time = parse_u64(ptr + 8);
      box->timescale = parse_u64(ptr + 16);
      box->duration = parse_u64(ptr + 24);
      ptr += 32;
    }else{
      box->creation_time = parse_u32(ptr);
      box->modification_time = parse_u32(ptr + 4);
      box->timescale = parse_u32(ptr + 8);
      box->duration = parse_u32(ptr + 12);
      ptr += 16;
    }

    box->rate = parse_fp16(ptr);
    ptr += 4;
    box->volume = parse_fp8(ptr);
    ptr += 2;
    // reserved 16, 32[2]
    ptr += 10; // (16 + 32 + 32) / 8
    // parse the matrix
    int i=0;
    for(; i<9; ++i) {
      box->matrix[i] = (int32_t) parse_u32(ptr);
      ptr += 4;
    }
    // pre defined 32[6]
    ptr += 24; // 32 / 8 * 6
    box->next_track_id = parse_u32(ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_movie_fragment_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    MovieFragmentHeaderBox *box = (MovieFragmentHeaderBox*) ctx->malloc(sizeof(MovieFragmentHeaderBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->sequence_number = parse_u32(ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_fragment_random_access(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 24)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    TrackFragmentRandomAccessBox *box = (TrackFragmentRandomAccessBox*) ctx->malloc(sizeof(TrackFragmentRandomAccessBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->track_id = parse_u32(ptr);
    ptr += 4;
    ptr += 3; // reserved
    uint8_t value = ptr[0];
    box->length_size_of_traf_num = (value >> 4) & 0x03;
    box->length_size_of_trun_num = (value >> 2) & 0x03;
    box->length_size_of_sample_num = value & 0x03;
    ptr++;
    box->number_of_entry = parse_u32(ptr);
    ptr += 4;

    box->entries = (Entry*) ctx->malloc(sizeof(Entry) * box->number_of_entry);

    uint32_t i=0;
    for(; i<box->number_of_entry; ++i) {
        Entry *entry = &box->entries[i];
        if(box->box.version == 1) {
            entry->entry_time = parse_u64(ptr);
            ptr += 8;
            entry->moof_offset = parse_u64(ptr);
            ptr += 8;
        }else{
            entry->entry_time = parse_u32(ptr);
            ptr += 4;
            entry->moof_offset = parse_u32(ptr);
            ptr += 4;
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

    MovieFragmentRandomAccessOffsetBox *box = (MovieFragmentRandomAccessOffsetBox*) ctx->malloc(sizeof(MovieFragmentRandomAccessOffsetBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->size = parse_u32(ptr);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_xml(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 13)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    XMLBox *box = (XMLBox*) ctx->malloc(sizeof(XMLBox));

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

    TrackHeaderBox *box = (TrackHeaderBox*) ctx->malloc(sizeof(TrackHeaderBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
        box->creation_time = parse_u64(ptr);
        box->modification_time = parse_u64(ptr + 8);
        box->track_id = parse_u32(ptr + 16);
        // reserved (32)
        box->duration = parse_u64(ptr + 24);
        ptr += 32;
    }else{
        box->creation_time = parse_u32(ptr);
        box->modification_time = parse_u32(ptr + 4);
        box->track_id = parse_u32(ptr + 8);
        // reserved (32)
        box->duration = parse_u32(ptr + 16);
        ptr += 20;
    }

    // reserved (32 * 2)
    ptr += 8;
    box->layer = (int16_t)parse_u16(ptr);
    box->alternate_group = (int16_t)parse_u16(ptr + 2);
    box->volume = parse_fp8(ptr + 4);
    // reserved (16)
    ptr += 8;
    
    int i=0;
    for(; i<9; ++i) {
        box->matrix[i] = (int32_t) parse_u32(ptr);
        ptr += 4;
    }

    box->width = parse_u32(ptr);
    box->height = parse_u32(ptr + 4);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_movie_extends_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    MovieExtendsHeaderBox *box = (MovieExtendsHeaderBox*) ctx->malloc(sizeof(MovieExtendsHeaderBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    if(box->box.version == 1) {
        box->fragment_duration = parse_u64(ptr);
    }else{
        box->fragment_duration = parse_u32(ptr);
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

    TrackExtendsBox *box = (TrackExtendsBox*) ctx->malloc(sizeof(TrackExtendsBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->track_id = parse_u32(ptr);
    box->default_sample_description_index = parse_u32(ptr + 4);
    box->default_sample_duration = parse_u32(ptr + 8);
    box->default_sample_size = parse_u32(ptr + 12);
    ptr += 16;

    // default sample flags
    // (6) reserved
    box->default_sample_depends_on = ptr[0] & 0x03; // (2) sample depends on
    box->default_sample_is_depended_on = (eBoolean)((ptr[1] >> 6) & 0x03); // (2) sample is depended on
    box->default_sample_has_redundancy = (eBoolean)((ptr[1] >> 4) & 0x03); // (2) sample has redundency
    box->default_sample_padding_value = (ptr[1] >> 1) & 0x07; // (3) sample padding value
    box->default_sample_is_difference_sample = (ptr[1] & 0x01) == 1 ? eBooleanTrue : eBooleanFalse; // (1) sample is difference sample
    box->default_sample_degradation_priority = parse_u16(ptr + 2); // (16) sample degradation priority

    *box_ptr = (Box*)box;
    return BMFF_OK;
}

BMFFCode _bmff_parse_box_track_fragment_header(BMFFContext *ctx, const uint8_t *data, size_t size, Box **box_ptr)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 16)   return BMFF_INVALID_SIZE;
    if(!box_ptr)    return BMFF_INVALID_PARAMETER;

    TrackFragmentHeaderBox *box = (TrackFragmentHeaderBox*) ctx->malloc(sizeof(TrackFragmentHeaderBox));
    memset(box, 0, sizeof(TrackFragmentHeaderBox));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    box->track_id = parse_u32(ptr);
    ptr += 4;

    if(box->box.flags & eTfhdBaseDataOffsetPresent == eTfhdBaseDataOffsetPresent) {
        box->base_data_offset = parse_u64(ptr);
        ptr+= 8;
    }

    if(box->box.flags & eTfhdSampleDescIdxPresent == eTfhdSampleDescIdxPresent) {
        box->sample_description_index = parse_u32(ptr);
        ptr += 4;   
    }

    if(box->box.flags & eTfhdDefaultSampleDurationPresent == eTfhdDefaultSampleDurationPresent) {
        box->default_sample_duration = parse_u32(ptr);
        ptr += 4;
    }

    if(box->box.flags & eTfhdDefaultSampleSizePresent == eTfhdDefaultSampleSizePresent) {
        box->default_sample_size = parse_u32(ptr);
        ptr += 4;
    }

    if(box->box.flags & eTfhdDefaultSampleFlagsPresent == eTfhdDefaultSampleFlagsPresent) {
        box->default_sample_flags = parse_u32(ptr);
        ptr += 4;
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

    Box *box = (Box*) ctx->malloc(sizeof(Box));

    const uint8_t *ptr = data;
    ptr += parse_full_box(data, size, &box->box);

    *box_ptr = (Box*)box;
    return BMFF_OK;
}
*/
