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

#ifndef BOXES_H
#define BOXES_H

#include <stdint.h>

typedef enum {
    eBooleanUnknown    = 0,
    eBooleanTrue       = 1,
    eBooleanFalse      = 2,
    eBooleanOther      = 3,
} eBoolean;

typedef enum {
    eTfhdBaseDataOffsetPresent          = 0x000001,
    eTfhdSampleDescIdxPresent           = 0x000002,
    eTfhdDefaultSampleDurationPresent   = 0x000008,
    eTfhdDefaultSampleSizePresent       = 0x000010,
    eTfhdDefaultSampleFlagsPresent      = 0x000020,
    eTfhdDurationIsEmpty                = 0x010000
} eTrackHeaderBoxFlags;

typedef enum {
    eTrunDataOffsetPresent              = 0x000001,
    eTrunFirstSampleFlagsPresent        = 0x000004,
    eTrunSampleDurationPresent          = 0x000100,
    eTrunSampleSizePresent              = 0x000200,
    eTrunSampleFlagsPresent             = 0x000400,
    eTrunSampleCompTimeOffsetsPresent   = 0x000800,
} eTrackRunFlags;

typedef float fxpt16_t;  // Fixed Point 16.16
typedef float fxpt8_t;   // Fixed Point 8.8

typedef uint8_t IPMPDescriptor;           // TODO: see 14496-1 for definition.

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

// All Boxes contain the base Box as the first item in the structure.
typedef struct Box {
    uint32_t        size;
    uint8_t         type[4];
    size_t          large_size;
    const uint8_t   *user_type;
} Box;

typedef struct FullBox {
    // Box
    uint32_t        size;
    uint8_t         type[4];
    size_t          large_size;
    const uint8_t   *user_type;
    // FullBox items
    uint8_t     version;
    uint32_t    flags;
} FullBox;

// Abstraction of a Box that all Boxes inherit from.
typedef struct AbstractBox {
    Box box;
} AbstractBox;

// All Boxes that can contain other Boxes "inherit" the ContainerBox.
typedef struct ContainerBox {
    Box         box;
    uint32_t    child_count;
    Box         **children;
} ContainerBox;

// Box Definitions.

typedef ContainerBox MovieBox; // moov
typedef ContainerBox MovieFragmentBox; // moof
typedef ContainerBox MovieFragmentRandomAccessBox; // mfra
typedef ContainerBox DataInformationBox; // dinf
typedef ContainerBox TrackBox; //trak
typedef ContainerBox MovieExtendsBox; // mvex
typedef ContainerBox TrackFragmentBox; // traf
typedef ContainerBox UserDataBox; // udta
typedef ContainerBox EditBox; // edts
typedef ContainerBox MediaBox; // mdia
typedef ContainerBox MediaInformationBox; // minf
typedef ContainerBox SampleTableBox; // stbl
typedef ContainerBox AdditionalMetadataContainerBox; // meco
typedef ContainerBox SubTrackBox; // strk
typedef ContainerBox SubTrackDefinitionBox; // strd

typedef Box FreeSpaceBox; // free, skip
typedef Box TrackReferenceBox; // tref
typedef FullBox NullMediaHeaderBox; // nmhd

typedef struct FileTypeBox { // ftyp
    Box             box;
    uint8_t         major_brand[4];
    uint32_t        minor_version;
    const uint8_t   *compatible_brands;     // printable 4 character code
    size_t          nb_compatible_brands;   // number of 4 character codes
} FileTypeBox;

typedef FileTypeBox SegmentTypeBox; // styp

typedef struct ProgressiveDownloadBitrate {
    uint32_t    rate;
    uint32_t    initial_delay;
} ProgressiveDownloadBitrate;

typedef struct ProgressiveDownloadBox { // pdin
    FullBox                     box;
    size_t                      nb_bitrates;
    ProgressiveDownloadBitrate  *bitrates;
} ProgressiveDownloadBox;

typedef struct MediaDataBox { // mdat
    Box             box;
    const uint8_t   *data;
    size_t          data_len;
} MediaDataBox;

typedef struct HandlerBox { // hdlr
    FullBox     box;
    uint32_t    handler_type;
    const char  *name;
} HandlerBox;

typedef struct PrimaryItemBox { // pitm
    FullBox     box;
    uint32_t    item_id;
} PrimaryItemBox;

typedef struct Extent {
    uint64_t    index;
    uint64_t    offset;
    uint64_t    length;
} Extent;

typedef struct ItemLocation {
    uint32_t    item_id;
    uint8_t     construction_method;
    uint16_t    data_reference_index;
    uint64_t    base_offset;
    uint16_t    extent_count;
    Extent      *extents;
} ItemLocation;

typedef struct ItemLocationBox { // iloc
    FullBox         box;
    uint16_t        offset_size;
    uint16_t        length_size;
    uint16_t        base_offset_size;
    uint8_t         index_size;
    uint32_t        item_count;
    ItemLocation    *items;
} ItemLocationBox;

typedef struct FDItemInfoExtension { // fdel
    const char      *content_location;
    const char      *content_md5;
    uint64_t        content_length;
    uint64_t        transfer_length;
    uint8_t         entry_count;
    uint32_t        *group_ids;
} FDItemInfoExtension;

typedef struct ItemInfoEntry { // infe
    FullBox             box;
    uint32_t            item_id;
    uint16_t            item_protection_index;
    const char          *item_name;
    const char          *content_type;
    const char          *content_encoding;  // optional
    uint8_t             extension_type[4]; // optional
    const uint8_t       *extension_bytes;
    FDItemInfoExtension *extension;
    uint32_t            extension_size;
    uint8_t             item_type[4];
    const char          *item_uri_type;
} ItemInfoEntry;

typedef struct ItemInfoBox { // iinf
    FullBox         box;
    uint32_t        entry_count;
    ItemInfoEntry   **entries;
} ItemInfoBox;

typedef struct IPMPControlBox { // ipmc
    FullBox                 box;
    IPMPToolListDescriptor  tool_list;
    const IPMPDescriptor    *ipmp_descriptors;
    size_t                  ipmp_descriptors_len;
} IPMPControlBox;

typedef struct OriginalFormatBox { // frma
    Box             box;
    uint8_t         data_format[4];
} OriginalFormatBox;

typedef struct IPMPInfoBox { // imif
    FullBox                 box;
    const IPMPDescriptor    *ipmp_desc;
    uint32_t                ipmp_desc_count;
} IPMPInfoBox;

typedef struct SchemeTypeBox { // schm
    FullBox                 box;
    uint8_t                 scheme_type[4];
    uint32_t                scheme_version;
    const char              *scheme_uri;
} SchemeTypeBox;

typedef struct SchemeInformationBox { // schi
    Box                     box;
    Box                     *scheme_specific_data;
    uint32_t                scheme_specific_data_count;
} SchemeInformationBox;

typedef struct ProtectionSchemeInfoBox { // sinf
    Box                     box;
    OriginalFormatBox       original_format;
    SchemeTypeBox           *scheme_type;            // optional
    SchemeInformationBox    *scheme_info;            // optional
} ProtectionSchemeInfoBox;

typedef ProtectionSchemeInfoBox RestrictedSchemeInfoBox; // rinf

typedef struct ItemProtectionBox { // ipro
    FullBox                 box;
    uint16_t                protection_count;
    ProtectionSchemeInfoBox **protection_info;
} ItemProtectionBox;

typedef struct SingleItemTypeReferenceBox {
    Box         box;
    uint32_t    from_item_id;
    uint16_t    reference_count;
    uint32_t    *to_item_ids;
} SingleItemTypeReferenceBox;

typedef struct ItemReferenceBox { // iref
    FullBox                     box;
    SingleItemTypeReferenceBox  *references;
    uint32_t                    references_count;
} ItemReferenceBox;

typedef struct ItemDataBox { // idat
    Box             box;
    const uint8_t   *data;
    uint32_t        data_size;       
} ItemDataBox;

typedef struct MetaBox { // meta
    FullBox             box;
    HandlerBox          *handler;
    PrimaryItemBox      *primary_resource;  // optional
    DataInformationBox  *file_locations;    // optional
    ItemLocationBox     *item_locations;    // optional
    ItemProtectionBox   *protections;       // optional
    ItemInfoBox         *item_infos;        // optional
    IPMPControlBox      *ipmp_control;      // optional
    ItemReferenceBox    *item_refs;         // optional
    ItemDataBox         *item_data;         // optional
    Box                 *other_boxes;       // optional
    size_t              other_boxes_len;
} MetaBox;

typedef struct MovieHeaderBox { // mvhd
    FullBox     box;
    uint64_t    creation_time;
    uint64_t    modification_time;
    uint32_t    timescale;
    uint64_t    duration;
    fxpt16_t    rate;
    fxpt8_t     volume;
    int32_t     matrix[9];
    uint32_t    next_track_id;
} MovieHeaderBox;

typedef struct MovieFragmentHeaderBox { // mfhd
    FullBox     box;
    uint32_t    sequence_number;
} MovieFragmentHeaderBox;

typedef struct Entry {
    uint64_t    entry_time;
    uint64_t    moof_offset;
    uint32_t    traf_number;
    uint32_t    trun_number;
    uint32_t    sample_number;
} Entry;

typedef struct TrackFragmentRandomAccessBox { // tfra
    FullBox     box;
    uint32_t    track_id;
    uint8_t     length_size_of_traf_num;
    uint8_t     length_size_of_trun_num;
    uint8_t     length_size_of_sample_num;
    uint32_t    number_of_entry;
    Entry       *entries;
} TrackFragmentRandomAccessBox;

typedef struct MovieFragmentRandomAccessOffsetBox { // mfro
    FullBox     box;
    uint32_t    size;
} MovieFragmentRandomAccessOffsetBox;

typedef struct XMLBox { // xml and bxml
    FullBox         box;
    const uint8_t   *data;
    size_t          data_len;
} XMLBox;

// third tier

typedef struct TrackHeaderBox { // tkhd
    FullBox     box;
    uint64_t    creation_time;
    uint64_t    modification_time;
    uint32_t    track_id;
    uint64_t    duration;
    int16_t     layer;
    int16_t     alternate_group;
    fxpt8_t     volume;
    int32_t     matrix[9];
    uint32_t    width;
    uint32_t    height;
} TrackHeaderBox;

typedef struct TrackReferenceTypeBox {
    Box         box;
    uint32_t    *track_ids;
    size_t      nb_track_ids;
} TrackReferenceTypeBox;

typedef struct MovieExtendsHeaderBox { // mehd
    FullBox     box;
    uint64_t    fragment_duration;
} MovieExtendsHeaderBox;

typedef struct TrackExtendsBox { // trex
    FullBox     box;
    uint32_t    track_id;
    uint32_t    default_sample_description_index;
    uint32_t    default_sample_duration;
    uint32_t    default_sample_size;
    // defaut sample flags
    eBoolean    default_sample_is_leading;
    eBoolean    default_sample_depends_on;
    eBoolean    default_sample_is_depended_on;
    eBoolean    default_sample_has_redundancy;
    uint8_t     default_sample_padding_value;
    eBoolean    default_sample_is_difference_sample;
    uint16_t    default_sample_degradation_priority;
} TrackExtendsBox;

typedef struct TrackFragmentHeaderBox { // tfhd
    FullBox     box;
    uint32_t    track_id;
    uint64_t    base_data_offset;
    uint32_t    sample_description_index;
    uint32_t    default_sample_duration;
    uint32_t    default_sample_size;
    uint32_t    default_sample_flags;
} TrackFragmentHeaderBox;

typedef struct TrackRunSample {
    uint32_t    duration;                   // optional
    uint32_t    size;                       // optional
    uint32_t    flags;                      // optional
    int64_t     composition_time_offset;    // optional
} TrackRunSample;

typedef struct TrackRunBox { // trun
    FullBox         box;
    uint32_t        sample_count;
    int32_t         data_offset;            // optional
    uint32_t        first_sample_flags;     // optional
    TrackRunSample  *samples;               // optional
} TrackRunBox;

typedef struct SampleDependencyType {
    uint8_t     is_leading;
    uint8_t     depends_on;
    uint8_t     is_depended_on;
    uint8_t     has_redundancy;
} SampleDependencyType;

typedef struct SampleDependencyTypeBox { // sdtp
    FullBox                 box;
    uint32_t                sample_count;
    SampleDependencyType    *samples;
} SampleDependencyTypeBox;

typedef struct SampleToGroupEntry {
    uint32_t    sample_count;
    uint32_t    group_description_index;
} SampleToGroupEntry;

typedef struct SampleToGroupBox { //sbgp
    FullBox             box;
    uint32_t            grouping_type;
    uint32_t            grouping_type_param;
    uint32_t            entry_count;
    SampleToGroupEntry  *entries;
} SampleToGroupBox;

typedef struct SubSampleInformation {
    uint32_t            size;
    uint8_t             priority;
    uint8_t             discardable;
    uint32_t            codec_specific_params;
} SubSampleInformation;

typedef struct SubSampleInformationEntry {
    uint32_t                sample_delta;
    uint16_t                subsample_count;
    SubSampleInformation    *subsamples;
} SubSampleInformationEntry;

typedef struct SubSampleInformationBox { // subs
    FullBox                     box;
    uint32_t                    entry_count;
    SubSampleInformationEntry   *entries;
} SubSampleInformationBox;

typedef struct CopyrightBox { // cprt
    FullBox     box;
    uint8_t     language[3];
    const char  *notice;
} CopyrightBox;

typedef struct DataEntryBox { // url_ and urn_
    FullBox     box;
    const char  *name;
    const char  *location;
} DataEntryBox;

typedef struct DataReferenceBox { // dref
    FullBox         box;
    uint32_t        entry_count;
    DataEntryBox    **data_entries;
} DataReferenceBox;

// fourth Tier

typedef struct EditEntry {
    uint64_t        segment_duration;
    int64_t         media_time;
    int16_t         media_rate_integer;
    int16_t         media_rate_fraction;
} EditEntry;

typedef struct EditListBox { // elst
    FullBox         box;
    uint32_t        entry_count;
    EditEntry       *entries;
} EditListBox;

typedef struct MediaHeaderBox { // mdhd
    FullBox         box;
    uint64_t        creation_time;
    uint64_t        modification_time;
    uint32_t        timescale;
    uint64_t        duration;
    uint8_t         language[3];
} MediaHeaderBox;

typedef struct VideoMediaHeaderBox { // vmhd
    FullBox         box;
    uint16_t        graphics_mode;
    uint16_t        op_color[3];
} VideoMediaHeaderBox;

typedef struct SoundMediaHeaderBox { // smhd
    FullBox         box;
    fxpt8_t         balance;
} SoundMediaHeaderBox;

typedef struct HintMediaHeaderBox { // hmhd
    FullBox         box;
    uint16_t        max_pdu_size;
    uint16_t        avg_pdu_size;
    uint32_t        max_bitrate;
    uint32_t        avg_bitrate;
} HintMediaHeaderBox;

typedef struct SampleEntry {
    Box             box;
    uint16_t        data_reference_index;
} SampleEntry;

typedef struct HintSampleEntry {
    Box             box;
    uint16_t        data_reference_index;
    const uint8_t   *data;
    size_t          data_size;
} HintSampleEntry;

typedef struct VisualSampleEntry {
    Box             box;
    uint16_t        data_reference_index;
    uint16_t        width;
    uint16_t        height;
    fxpt16_t        horiz_resolution;
    fxpt16_t        vert_resolution;
    uint16_t        frame_count;
    uint8_t         compressor_name[31];
    uint16_t        depth;
} VisualSampleEntry;

typedef struct AudioSampleEntry {
    Box             box;
    uint16_t        data_reference_index;
    uint16_t        channel_count;
    uint16_t        sample_size;
    uint32_t        sample_rate;
} AudioSampleEntry;

typedef struct SampleDescriptionBox { // stsd
    FullBox         box;
    uint32_t        entry_count;
    SampleEntry     **entries;
} SampleDescriptionBox;

typedef struct TimeToSample {
    uint32_t        count;
    uint32_t        delta;
} TimeToSample;

typedef struct TimeToSampleBox { // stts
    FullBox         box;
    uint32_t        sample_count;
    TimeToSample    *samples;
} TimeToSampleBox;

typedef struct CompositionOffset {
    uint32_t        count;
    int64_t         offset;
} CompositionOffset;

typedef struct CompositionOffsetBox { // ctts
    FullBox             box;
    uint32_t            entry_count;
    CompositionOffset   *entries;
} CompositionOffsetBox;

typedef struct SampleToChunk {
    uint32_t        first_chunk;
    uint32_t        samples_per_chunk;
    uint32_t        sample_description_index;
} SampleToChunk;

typedef struct SampleToChunkBox { // stsc
    FullBox             box;
    uint32_t            entry_count;
    SampleToChunk       *entries;
} SampleToChunkBox;

typedef struct SampleSizeBox { // stsz
    FullBox         box;
    uint32_t        sample_size;
    uint32_t        sample_count;
    uint32_t        *entry_sizes;
} SampleSizeBox;

typedef struct CompactSampleSizeBox { // stz2
    FullBox         box;
    uint8_t         field_size;
    uint32_t        sample_count;
    uint16_t        *entry_sizes;
} CompactSampleSizeBox;

typedef struct ChunkOffsetBox { // stco
    FullBox         box;
    uint32_t        entry_count;
    uint32_t        *chunk_offsets;
} ChunkOffsetBox;

typedef struct ChunkLargeOffsetBox { // co64
    FullBox         box;
    uint32_t        entry_count;
    uint64_t        *chunk_offsets;
} ChunkLargeOffsetBox;

typedef struct SyncSampleBox { // stss
    FullBox         box;
    uint32_t        entry_count;
    uint32_t        *sample_numbers;
} SyncSampleBox;

typedef struct ShadowSyncSample {
    uint32_t        shadowed_sample_number;
    uint32_t        sync_sample_number;
} ShadowSyncSample;

typedef struct ShadowSyncSampleBox { // stsh
    FullBox             box;
    uint32_t            entry_count;
    ShadowSyncSample    *entries;
} ShadowSyncSampleBox;

typedef struct PaddingBits {
    uint8_t         pad1;
    uint8_t         pad2;
} PaddingBits;

typedef struct PaddingBitsBox { // padb
    FullBox         box;
    uint32_t        sample_count;
    PaddingBits     *samples;
} PaddingBitsBox;

typedef struct DegradationPriorityBox { // stdp
    FullBox         box;
    uint16_t        *priorities;
    uint32_t        priority_count;
} DegradationPriorityBox;

typedef struct SampleGroupDescriptionBox { // sgpd
    FullBox         box;
    uint32_t        grouping_type;
    uint32_t        default_length;
    uint32_t        default_sample_description_index;
    uint32_t        entry_count;
    uint8_t         handler_type[4];
    const uint8_t   *sample_group_entries; // Visual, Audio, Hint, Subtitle, Text
    uint32_t        *description_lengths; // 
    uint32_t        sample_group_entries_size;
} SampleGroupDescriptionBox;

typedef struct TrackGroupTypeBox { // trgr -> msrc
    FullBox     box;
    uint32_t    track_group_id;
} TrackGroupTypeBox;

typedef struct ExtendedLanguageTagBox { // elng
    FullBox     box;
    const char  *extended_language;
} ExtendedLanguageTagBox;

typedef struct BitRateBox { // btrt
    Box         box;
    uint32_t    buffer_size_db;
    uint32_t    max_bitrate;
    uint32_t    avg_bitrate;
} BitRateBox;

typedef struct CompositionToDecodeBox { // cslg
    FullBox     box;
    int64_t     composition_to_dts_shift;
    int64_t     least_decode_to_display_delta;
    int64_t     greatest_decode_to_display_delta;
    int64_t     composition_start_time;
    int64_t     composition_end_time;
} CompositionToDecodeBox;


typedef struct SampleAuxInfoSizesBox { // saiz
    FullBox     box;
    uint32_t    aux_info_type;
    uint32_t    aux_info_type_param;
    uint8_t     default_sample_info_size;
    uint32_t    sample_count;
    uint8_t     *sample_info_sizes;
} SampleAuxInfoSizesBox;

typedef struct SampleAuxInfoOffsetsBox { // saio
    FullBox     box;
    uint32_t    aux_info_type;
    uint32_t    aux_info_type_param;
    uint32_t    entry_count;
    uint64_t     *offsets;
} SampleAuxInfoOffsetsBox;

typedef struct TrackFragmentDecodeTimeBox { // tfdt
    FullBox     box;
    uint64_t    base_media_decode_time;
} TrackFragmentDecodeTimeBox;

typedef struct LevelAssignment {
    uint32_t    track_id;
    uint8_t     padding_flag;
    uint8_t     assignment_type;
    uint32_t    grouping_type;
    uint32_t    grouping_type_parameter;
    uint32_t    sub_track_id;
} LevelAssignment;

typedef struct LevelAssignmentBox { // leva
    FullBox         box;
    uint8_t         level_count;
    LevelAssignment *levels;
} LevelAssignmentBox;

typedef struct TrackExtensionPropertiesBox { // trep
    FullBox     box;
    uint32_t    track_id;
    uint32_t    child_count;
    Box         **children;
} TrackExtensionPropertiesBox;

typedef struct AltStartSeqPropertiesEntry {
    uint32_t    grouping_type_param;
    int32_t     min_initial_alt_startup_offset;
} AltStartSeqPropertiesEntry;

typedef struct AltStartupSeqPropertiesBox { // assp 
    FullBox                     box;
    int32_t                     min_initial_alt_startup_offset;
    uint32_t                    entry_count;
    AltStartSeqPropertiesEntry  *entries;
} AltStartupSeqPropertiesBox;

typedef struct TrackSelectionBox { // tsel
    FullBox     box;
    int32_t     switch_group;
    uint32_t    *attribute_list;
    uint32_t    attribute_list_count;
} TrackSelectionBox;

typedef struct KindBox { // kind
    FullBox     box;
    const char  *scheme_uri;
    const char  *value;
} KindBox;

typedef enum {
    eMetaboxRelationUnknown            = 1,
    eMetaboxRelationUnrelated          = 2,
    eMetaboxRelationComplementary      = 3,
    eMetaboxRelationOverlap            = 4,
    eMetaboxRelationFirstPreferred     = 5,
} eMetaboxRelation;

typedef struct MetaboxRelationBox { // mere
    FullBox             box;
    uint8_t             first_metabox_handler_type[4];
    uint8_t             second_metabox_handler_type[4];
    eMetaboxRelation    metabox_relation;
} MetaboxRelationBox;

typedef struct FilePartitionBox { // fpar
    FullBox             box;
    uint32_t            item_id;
    uint16_t            packet_payload_size;
    uint8_t             fec_encoding_id;
    uint16_t            fec_instance_id;
    uint16_t            max_source_block_length;
    uint16_t            encoding_symbol_length;
    uint16_t            max_number_of_encoding_symbols;
    const char          *scheme_specific_info;
    uint32_t            entry_count;
    uint16_t            *block_counts;
    uint32_t            *block_sizes;
} FilePartitionBox;

typedef struct FECReservoirBox { // fecr
    FullBox             box;
    uint32_t            entry_count;
    uint32_t            *item_ids;
    uint32_t            *symbol_counts;
} FECReservoirBox;

typedef FECReservoirBox FileReservoirBox; // fire

typedef struct PartitionEntryBox { // paen
    Box                 box;
    FilePartitionBox    *blocks_and_symbols;
    FECReservoirBox     *fec_symbol_locations;   // optional
    FileReservoirBox    *file_symbol_locations;  // optional
} PartitionEntryBox;

typedef struct FDSessionGroupEntry {
    uint8_t             entry_count;
    uint32_t            *group_ids;
    uint16_t            num_channels_in_session_group;
    uint32_t            *hint_track_ids;
} FDSessionGroupEntry;

typedef struct FDSessionGroupBox { // segr
    Box                 box;
    uint16_t            num_session_groups;
    FDSessionGroupEntry *session_groups;
} FDSessionGroupBox;

typedef struct GroupIdToNameBox { // gitn
    FullBox             box;
    uint16_t            entry_count;
    uint32_t            *group_ids;
    const char          **group_names;
} GroupIdToNameBox;

typedef struct FDItemInformationBox { // fiin
    FullBox             box;
    uint16_t            entry_count;
    PartitionEntryBox   **entries;
    FDSessionGroupBox   *session_info;           // optional
    GroupIdToNameBox    *group_id_to_name;       // optional
} FDItemInformationBox;

typedef struct SubTrackInformationBox { // stri
    FullBox             box;
    uint16_t            switch_group;
    uint16_t            alternate_group;
    uint32_t            sub_track_id;
    uint32_t            attribute_list_count;
    const uint8_t       **attribute_list;
} SubTrackInformationBox;

typedef struct SubTrackSampleGroupBox { // stsg
    FullBox             box;
    uint32_t            grouping_type;
    uint16_t            item_count;
    uint32_t            *group_description_indicies;
} SubTrackSampleGroupBox;

typedef enum {
   eSingleViewModeStereoscopic      = 0,
   eSingleViewModeMonoscopicRight   = 1,
   eSingleViewModeMonoscopicLeft    = 2, 
} eSingleViewMode;

typedef struct StereoVideoBox { // stvi
    FullBox             box;
    eSingleViewMode     single_view_allowed;
    uint32_t            stereo_scheme;
    uint32_t            length;
    uint64_t            stereo_indication_type;
    uint32_t            child_count;
    Box                 **children;
} StereoVideoBox;

typedef struct SegmentIndexRefEntry {
    uint8_t             reference_type;
    uint32_t            referenced_size;
    uint32_t            subsegment_duration;
    uint8_t             starts_with_sap;
    uint8_t             sap_type;
    uint32_t            sap_delta_time;
} SegmentIndexRefEntry;

typedef struct SegmentIndexBox { // sidx
    FullBox                 box;
    uint32_t                reference_id;
    uint32_t                timescale;
    uint64_t                earliest_presentation_time;
    uint64_t                first_offset;
    uint16_t                reference_count;
    SegmentIndexRefEntry    *references;
} SegmentIndexBox;

// ssix
// prft
// icpv
// icnf
// rtp_
// tims
// tsro
// snro
// srtp
// srpp
// hnti
// sdp_
// hinf
// trpy
// nump
// tpyl
// totl
// npck
// tpay
// maxr
// dmed
// dimm
// drep
// tmin
// tmax
// pmax
// dmax
// payt
// fdp_
// fdsa
// fdpa
// extr
// feci
// rm2t
// sm2t
// tPAT
// tPMT
// tOD
// tsti
// istm
// pm2t
// rrtp
// tssy
// tssr
// rcsr
// rsrp
// ccid
// sroc
// prtp
// roll
// prol
// rash
// alst
// rap_
// tele
// sap_
// clap
// colr
// chn1
// dmix
// ludt
// alou
// tlou
// txtC
// urim
// stxt
// sthd
// stpp
// sbtt

#endif // BOXES_H
