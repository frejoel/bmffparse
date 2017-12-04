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

// TODO: Parse the Descriptors
/*
enum eDescrTags {
    eDescrTagES                 = 0x03,
    eDescrTagDecoderConfig      = 0x04,
    eDescrTagSLConfig           = 0x06,
    eDescrTagIPIPtr             = 0x09,
    eDescrTagIPMPPtr            = 0x0A,
    eDescrTagIPMP               = 0x0B,
    eDescrTagQoS                = 0x0C,
    eDescrTagReg                = 0x0D,
    eDescrTagMp4IOD             = 0x10,
    eDescrTagMp4OD              = 0x11,
};

enum eSLConfigFlags {
    eSLConfigFlagsUseAccessUnitStart    = 0x80,
    eSLConfigFlagsUseAccessUnitEnd      = 0x40, 
    eSLConfigFlagsUseAccessPoint        = 0x20, 
    eSLConfigFlagsUseAccessUnitsOnly    = 0x10, 
    eSLConfigFlagsUseUsePadding         = 0x08, 
    eSLConfigFlagsUseTimeStamps         = 0x04, 
    eSLConfigFlagsUseIdle               = 0x02, 
    eSLConfigFlagsDuration              = 0x01, 
};
*/

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

// TODO: Parse Descriptors
/*
typedef struct OCIDescriptor { 
    uint8_t                 tag;
} OCIDescriptor;

typedef struct IPMPDescriptorPtr {
    uint8_t                 tag;
} IPMPDescriptorPtr;

typedef struct ExtensionDescriptor {
    uint8_t     tag;
} ExtensionDescriptor;

typedef struct DecoderConfigDescriptor {
    uint8_t     tag;
} DecoderConfigDescriptor;

typedef struct SLConfigDescriptor {
    uint8_t     tag;
    uint8_t     predefined;
    uint8_t     flags;
    uint32_t    time_stamp_resolution;
    uint32_t    ocr_resolution;
    uint8_t     time_stamp_length;
    uint8_t     ocr_length;
    uint8_t     au_length;
    uint8_t     instant_bitrate_length;
    uint8_t     degradation_priority_length;
    uint8_t     au_seq_num_length;
    uint8_t     packet_seq_num_length;
    uint32_t    time_scale;
    uint16_t    access_unit_duration;
    uint16_t    composition_unit_duration;
    uint64_t    start_decoding_time_stamp;
    uint64_t    start_composition_time_stamp;
} SLConfigDescriptor;

typedef struct IPIDescriptorPtr {
    uint8_t     tag;
} IPIDescriptorPtr;

typedef struct IPIdentificationDataSet {
    uint8_t     tag;
} IPIdentificationDataSet;

typedef struct LanguageDescriptor {
    uint8_t     tag;
} LanguageDescriptor;

typedef struct QoSDescriptor {
    uint8_t     tag;
} QoSDescriptor;

typedef struct RegistrationDescriptor {
    uint8_t     tag;
} RegistrationDescriptor;

typedef struct ESDescriptor { 
    uint8_t                 tag;
    uint16_t                es_id;
    uint8_t                 stream_dependence_flag;
    uint8_t                 url_flag;
    uint8_t                 ocr_stream_flag;
    uint8_t                 stream_priority;
    uint16_t                depends_on_es_id;
    uint8_t                 url_length;
    uint8_t                 *url;
    uint16_t                ocr_es_id;
    DecoderConfigDescriptor dec_config_descriptor;
    SLConfigDescriptor      sl_config_descriptor;
    uint32_t                ipi_ptr_count;
    IPIDescriptorPtr        *ipi_ptr;
    uint32_t                ip_ids_count;
    IPIdentificationDataSet **ip_ids;
    uint32_t                ipmp_descriptor_ptr_count;
    IPMPDescriptorPtr       **ipmp_descriptor_ptr;
    uint32_t                language_descriptor_count;
    LanguageDescriptor      **language_descriptor;
    QoSDescriptor           *qos_descriptor;
    RegistrationDescriptor  *registration_descriptor;
    uint32_t                extension_descriptor_count;
    ExtensionDescriptor     **extension_descriptor;
} ESDescriptor;
*/

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
    // TODO: Parse child Descriptors
    /*
    uint32_t                es_descriptor_count;
    ESDescriptor            **es_descriptors;
    uint32_t                oci_descriptor_count;
    OCIDescriptor           **oci_descriptors;
    uint32_t                ipmp_descriptor_ptr_count;
    IPMPDescriptorPtr       **ipmp_descriptor_ptrs;
    uint32_t                ipmp_descriptor_count;
    IPMPDescriptor          **ipmp_descriptors;
    */
} ObjectDescriptor;

#ifdef __cplusplus
}
#endif

#endif // DESCRIPTORS_H
