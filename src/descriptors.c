#include "bmff.h"
#include "parse_common.h"

size_t _bmff_parse_object_descriptor(BMFFContext *ctx, const uint8_t *data, size_t size, ObjectDescriptor *desc)
{
    const uint8_t *ptr = data;
    const uint8_t *end = data + size;

    ADV_PARSE_U8(desc->od_tag, ptr);
    uint16_t val = parse_u16(ptr);
    desc->od_id = val & 0x3FFF;
    desc->url_flag = (ptr[1] >> 2) & 0x01;
    desc->include_inline_profile_level_flag = (ptr[1] >> 3) & 0x01;
    ptr += 2;

    if(desc->url_flag == 1) {
        ADV_PARSE_U8(desc->url_length, ptr);
        if(desc->url_length > 0) {
            BOX_MALLOCN(desc->url, uint8_t, desc->url_length+1);
            memcpy(desc->url, ptr, desc->url_length);
        }
    }else{
        ADV_PARSE_U8(desc->od_profile_level_indicator, ptr);
        ADV_PARSE_U8(desc->scene_profile_level_indicator, ptr);
        ADV_PARSE_U8(desc->audio_profile_level_indicator, ptr);
        ADV_PARSE_U8(desc->visual_profile_level_indicator, ptr);
        ADV_PARSE_U8(desc->graphics_profile_level_indicator, ptr);
    }

    desc->descriptors = ptr;
    desc->descriptors_size = end - ptr;

    return ptr - data;
}
