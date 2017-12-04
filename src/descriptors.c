#include "descriptors.h"
#include "context.h"
#include "parse_common.h"

/*
size_t _bmff_parse_slconfig_descriptor(BMFFContext *ctx,
                                       const uint8_t *data,
                                       size_t size,
                                       SLConfigDescriptor *desc);
{
    const uint8_t *ptr = data;
    
    ADV_PARSE_U8(desc->tag, ptr);
    ADV_PARSE_U8(desc->predefined, ptr);

    if(desc->predefined == 0) {
        ADV_PARSE_U8(desc->flags, ptr);
        ADV_PARSE_U32(desc->time_stamp_resolution, ptr);
        ADV_PARSE_U32(desc->ocr_resolution, ptr);
        ADV_PARSE_U8(desc->time_stamp_length, ptr);
        ADV_PARSE_U8(desc->ocr_length, ptr);
        ADV_PARSE_U8(desc->au_length, ptr);
        ADV_PARSE_U8(desc->instant_bitrate_length, ptr);
        desc->degradation_priority_length = ((*ptr) >> 4) & 0x0F;
        desc->au_seq_num_length = ((*ptr) & 0x0F) | ((ptr[1] >> 3) & 0x10);
        desc->packet_seq_num_length = (ptr[1] >> 2) & 0x1F;
        desc += 2;
    }

    if(desc->flags & eSLConfigFlagsDuration) {
        ADV_PARSE_U32(desc->time_scale, ptr);
        ADV_PARSE_U16(desc->access_unit_duration, ptr);
        ADV_PARSE_U16(desc->composition_unit_duration, ptr);
    }

    if(desc->flags & eSLConfigFlagsUseTimeStamps && desc->time_stamp_length > 0) {
        uint8_t len = desc->time_stamp_length;
        if(len <= 8) {
            ADV_PARSE_U8(desc->start_decoding_time_stamp, ptr);
        }else if(len <= 16) {
            ADV_PARSE_U16(desc->start_decoding_time_stamp, ptr);
        }else if(len <= 32) {
            ADV_PARSE_U32(desc->start_decoding_time_stamp, ptr);
        }else if(len <= 64) {
            ADV_PARSE_U64(desc->start_decoding_time_stamp, ptr);
        }
    }

    return ptr - data;
}

size_t _bmff_parse_es_descriptor(BMFFContext *ctx, const uint8_t *data, size_t size, ESDescriptor *desc, uint8_t od_profile_level_indicator)
{
    const uint8_t *ptr = data;

    ADV_PARSE_U16(desc->es_id, ptr);

    uint8_t val = *ptr;
    desc->stream_dependence_flag = (val >> 7) & 0x01;
    desc->url_flag = (val >> 6) & 0x01;
    desc->ocr_stream_flag = (val >> 5) & 0x01;
    desc->stream_priority = val & 0x1F;
    ptr++;

    if(desc->stream_dependence_flag == 0x01) {
        ADV_PARSE_U16(desc->depends_on_es_id, ptr);
    }
    if(desc->url_flag == 0x01) {
        ADV_PARSE_U8(desc->url_length, ptr);
        if(desc->url_length > 0) {
            BOX_MALLOCN(desc->url, uint8_t, desc->url_length + 1);
            memcpy(desc->url, ptr, desc->url_length);
            desc->url[desc->url_length] = 0;
        }
    }
    if(desc->ocr_stream_flag == 0x01) {
        ADV_PARSE_U16(desc->ocr_es_id, ptr);
    }

    // DecoderConfigDescriptor
    if(od_profile_level_indicator == 0x01) {
        // SLConfigDescriptor - no SL Extension
        ptr += _bmff_parse_slconfig_descriptor(ctx, ptr, size - (ptr - data), &desc->sl_config_descriptor);
    }else{
        // SLConfigDescriptor - SL Extension is possible
        ptr += _bmff_parse_slconfig_descriptor(ctx, ptr, size - (ptr - data), &desc->sl_config_descriptor);
    }

    // IPIDescriptorPtr 0 | 1
    // IPIdentificationDataSet 0-255
    // IPMPDescritptorPtr 0-255
    // LanguageDescriptor 0-255
    // QoSDescriptor 0 | 1
    // RegistrationDescriptor 0 | 1
    // ExtensionDescriptor 0-255

    return ptr - data;
}
*/

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
        // TODO: Parse Child Descriptors
        /*
        // allocate enough space for the maximum number of descriptors
        ESDescriptor **tmp_array;
        BOX_MALLOCN(tmp_array, ESDescriptor*, 255);
        uint32_t i = 0;
        // parse the ES descriptors
        while(ptr < end && *ptr == eDescrTagES && i < 255) {
            BOX_MALLOC(es_desc, ESDescriptor);
            ptr += _bmff_parse_es_descriptor(ctx, ptr, end-ptr, es_desc, desc->od_profile_level_indicator);
            tmp_array[i] = es_desc;
            ++i;
        }
        desc->es_descriptors = tmp_array;
        desc->es_descriptor_count = i;

        // OCIDescriptor 0-255
        // IPMPDescriptorPtr 0-255
        // IPMPDescriptor 0-255
        */
    }

    // ExtensionDescriptor 0-255

    return ptr - data;
}
