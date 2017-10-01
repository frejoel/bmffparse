#include "test.h"
#include <bmff.h>

#include <string.h>

void test_parse_box_file_type(void);
void test_parse_box_track_reference_type(void);
void test_parse_box_null_media_header(void);
void test_parse_box_progressive_download_info(void);
void test_parse_box_media_data(void);
void test_parse_box_primary_item(void);
void test_parse_box_item_location(void);
void test_parse_box_item_info_entry_v1(void);
void test_parse_box_item_info_entry_v2(void);
void test_parse_box_item_info(void);
void test_parse_box_ipmp_control(void);
void test_parse_box_original_format(void);
void test_parse_box_ipmp_info(void);
void test_parse_box_scheme_type(void);
void test_parse_box_scheme_info(void);
void test_parse_box_protection_scheme_info(void);
void test_parse_box_item_protection(void);
void test_parse_box_meta(void);
void test_parse_box_movie_header(void);
void test_parse_box_movie_fragment_header(void);
void test_parse_box_track_fragment_random_access(void);
void test_parse_box_movie_fragment_random_access_offset(void);
void test_parse_box_xml(void);
void test_parse_box_track_header(void);
void test_parse_box_movie_extends_header(void);
void test_parse_box_track_extends(void);
void test_parse_box_track_fragment_header(void);
void test_parse_box_track_run(void);
void test_parse_box_sample_dependency_type(void);
void test_parse_box_sample_to_group(void);
void test_parse_box_sub_sample_information(void);
void test_parse_box_copyright(void);
void test_parse_box_data_entry_urn(void);
void test_parse_box_data_entry_url(void);
void test_parse_box_data_entry_url_zero(void);
void test_parse_box_data_reference(void);
void test_parse_box_edit_list(void);
void test_parse_box_media_header(void);
void test_parse_box_video_media_header(void);
void test_parse_box_sound_media_header(void);
void test_parse_box_hint_media_header(void);
void test_parse_box_sample_description_soun(void);
void test_parse_box_sample_description_hint(void);
void test_parse_box_sample_description_vide(void);
void test_parse_box_sample_description_zero(void);
void test_parse_box_sample_description_invalid_type(void);
void test_parse_box_time_to_sample(void);
void test_parse_box_composition_offset(void);
void test_parse_box_sample_to_chunk(void);
void test_parse_box_sample_size(void);
void test_parse_box_compact_sample_size_4(void);
void test_parse_box_compact_sample_size_8(void);
void test_parse_box_compact_sample_size_16(void);
void test_parse_box_chunk_offset(void);
void test_parse_box_chunk_large_offset(void);
void test_parse_box_sync_sample(void);
void test_parse_box_shadow_sync_sample(void);
void test_parse_box_padding_bits(void);
void test_parse_box_degradation_priority(void);
void test_parse_box_sample_group_description(void);
void test_parse_box_track_group_type(void);
void test_parse_box_extended_language_tag(void);
void test_parse_box_bit_rate(void);
void test_parse_box_composition_to_decode(void);
void test_parse_box_sample_aux_info_sizes(void);
void test_parse_box_sample_aux_info_offsets(void);
void test_parse_box_track_fragment_decode_time(void);
void test_parse_box_level_assignment(void);
void test_parse_box_track_extension_properties(void);
void test_parse_box_alt_startup_seq_properties(void);
void test_parse_box_track_selection(void);
void test_parse_box_kind(void);
void test_parse_box_item_reference(void);
void test_parse_box_item_data(void);
void test_parse_box_metabox_relation(void);
void test_parse_box_file_partition(void);
void test_parse_box_reservoir(void);
void test_parse_box_partition_entry(void);
void test_parse_box_fd_session_group(void);
void test_parse_box_group_id_to_name(void);
void test_parse_box_fd_item_inforamation(void);
void test_parse_box_sub_track_information(void);
void test_parse_box_sub_track_sample_group(void);
void test_parse_box_stereo_video(void);
void test_parse_box_segment_index(void);
void test_parse_box_producer_reference_time(void);
void test_parse_box_complete_track_info(void);

int main(int argc, char** argv)
{
    test_parse_box_file_type();
    test_parse_box_track_reference_type();
    test_parse_box_null_media_header();
    test_parse_box_progressive_download_info();
    test_parse_box_media_data();
    test_parse_box_primary_item();
    test_parse_box_item_location();
    test_parse_box_item_info_entry_v1();
    test_parse_box_item_info_entry_v2();
    test_parse_box_item_info();
    test_parse_box_ipmp_control();
    test_parse_box_original_format();
    test_parse_box_ipmp_info();
    test_parse_box_scheme_type();
    test_parse_box_scheme_info();
    test_parse_box_protection_scheme_info();
    test_parse_box_item_protection();
    test_parse_box_meta();
    test_parse_box_movie_header();
    test_parse_box_movie_fragment_header();
    test_parse_box_track_fragment_random_access();
    test_parse_box_movie_fragment_random_access_offset();
    test_parse_box_xml();
    test_parse_box_track_header();
    test_parse_box_movie_extends_header();
    test_parse_box_track_extends();
    test_parse_box_track_fragment_header();
    test_parse_box_track_run();
    test_parse_box_sample_dependency_type();
    test_parse_box_sample_to_group();
    test_parse_box_sub_sample_information();
    test_parse_box_copyright();
    test_parse_box_data_entry_url();
    test_parse_box_data_entry_url_zero();
    test_parse_box_data_entry_urn();
    test_parse_box_data_reference();
    test_parse_box_edit_list();
    test_parse_box_media_header();
    test_parse_box_video_media_header();
    test_parse_box_sound_media_header();
    test_parse_box_hint_media_header();
    test_parse_box_sample_description_soun();
    test_parse_box_sample_description_hint();
    test_parse_box_sample_description_vide();
    test_parse_box_sample_description_zero();
    test_parse_box_sample_description_invalid_type();
    test_parse_box_time_to_sample();
    test_parse_box_composition_offset();
    test_parse_box_sample_to_chunk();
    test_parse_box_sample_size();
    test_parse_box_compact_sample_size_4();
    test_parse_box_compact_sample_size_8();
    test_parse_box_compact_sample_size_16();
    test_parse_box_chunk_offset();
    test_parse_box_chunk_large_offset();
    test_parse_box_sync_sample();
    test_parse_box_shadow_sync_sample();
    test_parse_box_padding_bits();
    test_parse_box_degradation_priority();
    test_parse_box_sample_group_description();
    test_parse_box_track_group_type();
    test_parse_box_extended_language_tag();
    test_parse_box_bit_rate();
    test_parse_box_composition_to_decode();
    test_parse_box_sample_aux_info_sizes();
    test_parse_box_sample_aux_info_offsets();
    test_parse_box_track_fragment_decode_time();
    test_parse_box_level_assignment();
    test_parse_box_track_extension_properties();
    test_parse_box_alt_startup_seq_properties();
    test_parse_box_track_selection();
    test_parse_box_kind();
    test_parse_box_item_reference();
    test_parse_box_item_data();
    test_parse_box_metabox_relation();
    test_parse_box_file_partition();
    test_parse_box_reservoir();
    test_parse_box_partition_entry();
    test_parse_box_fd_session_group();
    test_parse_box_group_id_to_name();
    test_parse_box_fd_item_inforamation();
    test_parse_box_sub_track_information();
    test_parse_box_sub_track_sample_group();
    test_parse_box_stereo_video();
    test_parse_box_segment_index();
    test_parse_box_producer_reference_time();
    test_parse_box_complete_track_info();
    return 0;
}

void test_parse_box_file_type(void)
{
    test_start("test_parse_box_file_type");

    BMFFContext ctx;
    FileTypeBox *box;
    BMFFCode res;

    uint8_t data[] = {
        0x00, 0x00, 0x00, 0x1C,
        'f', 't', 'y', 'p',
        'i', 's', 'o', 'm',
        0x00, 0x00, 0x02, 0x00,
        'i', 's', 'o', 'm',
        'i', 's', 'o', '2',
        'm', 'p', '4', '1',
    };

    bmff_context_init(&ctx);

    res = _bmff_parse_box_file_type(NULL, data, sizeof(data), (Box**)&box);
    test_assert_equal(res, BMFF_INVALID_CONTEXT, "invalid context");

    res = _bmff_parse_box_file_type(&ctx, NULL, sizeof(data), (Box**)&box);
    test_assert_equal(res, BMFF_INVALID_DATA, "invalid data");

    res = _bmff_parse_box_file_type(&ctx, data, 19, (Box**)&box);
    test_assert_equal(res, BMFF_INVALID_SIZE, "invalid size");

    res = _bmff_parse_box_file_type(&ctx, data, sizeof(data), NULL);
    test_assert_equal(res, BMFF_INVALID_PARAMETER, "invalid parameter");

    res = _bmff_parse_box_file_type(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(res, BMFF_OK, "success");
    test_assert_equal(box->box.size, 0x1C, "size");
    test_assert_equal(strncmp(box->box.type, "ftyp", 4), 0, "type");
    test_assert_equal(box->nb_compatible_brands, 3, "nb_compatible_brands");
    test_assert_equal(strncmp(box->compatible_brands, "isomiso2mp41", 12), 0, "compatible_brands");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_reference_type(void)
{
    test_start("test_parse_box_track_reference_type");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x14,
        'h', 'i', 'n', 't',
        0x01, 0x02, 0x03, 0x04,
        0xFF, 0xFE, 0xFD, 0xFC,
        0xF0, 0xE1, 0x40, 0x05,
    };

    BMFFCode res;
    TrackReferenceTypeBox *box = NULL;
    res = _bmff_parse_box_track_reference_type(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x14, "size");
    test_assert_equal(strncmp(box->box.type, "hint", 4), 0, "type");
    test_assert_equal(box->nb_track_ids, 3, "nb_track_ids");
    test_assert_equal(box->track_ids[0], 0x01020304, "track_id[0]");
    test_assert_equal(box->track_ids[1], 0xFFFEFDFC, "track_id[1]");
    test_assert_equal(box->track_ids[2], 0xF0E14005, "track_id[2]");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_null_media_header(void)
{
    test_start("test_parse_box_null_media_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x12,
        'n', 'm', 'h', 'd',
        0x0A, 0xF2, 0xE3, 0xD4,
    };

    BMFFCode res;
    FullBox *box = NULL;
    res = _bmff_parse_box_full(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->size, 0x12, "size");
    test_assert_equal(strncmp(box->type, "nmhd", 4), 0, "type");
    test_assert_equal(box->version, 0x0A, "version");
    test_assert_equal(box->flags, 0xF2E3D4, "flags");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_progressive_download_info(void)
{
    test_start("test_parse_box_progressive_download_info");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x30,
        'p', 'd', 'i', 'n',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x01, // rate
        0x11, 0x22, 0x00, 0xFF, // initial delay
        0x93, 0x00, 0x39, 0xF5, // rate
        0xFF, 0x00, 0x22, 0x11, // initial delay
    };

    BMFFCode res;
    ProgressiveDownloadBox *box = NULL;
    res = _bmff_parse_box_progressive_download_info(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x30, "size");
    test_assert_equal(strncmp(box->box.type, "pdin", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->nb_bitrates, 2, "nb_bitrates");
    test_assert_equal(box->bitrates[0].rate, 0x00000001, "bitrate[0].rate");
    test_assert_equal(box->bitrates[0].initial_delay, 0x112200FF, "bitrate[0].initial_delay");
    test_assert_equal(box->bitrates[1].rate, 0x930039F5, "bitrate[1].rate");
    test_assert_equal(box->bitrates[1].initial_delay, 0xFF002211, "bitrate[1].initial_delay");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_media_data(void)
{
    test_start("test_parse_box_media_data");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x0D,
        'm', 'd', 'a', 't',
        0x00,  0xFF, 0xE4, 0x12, 0xD2, // data
    };

    BMFFCode res;
    MediaDataBox *box = NULL;
    res = _bmff_parse_box_media_data(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x0D, "size");
    test_assert_equal(strncmp(box->box.type, "mdat", 4), 0, "type");
    test_assert_equal_ptr((size_t)box->data, (size_t)&data[8], "data pointer");
    test_assert_equal(box->data_len, 0x05, "data length");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_handler(void)
{
    test_start("test_parse_box_handler");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x31,
        'h', 'd', 'l', 'r',
        0x00, // version
        0xFF, 0xFF, 0xFA, // flags
        0, 0, 0, 0, // pre_defined
        0xEE, 0xE1, 0x45, 0x09, // handler_type
        0, 0, 0 ,0, // reserved
        0, 0, 0 ,0, // reserved
        0, 0, 0 ,0, // reserved
        'h','a','n','d','l','e','r',' ','b','o','x',' ','n','a','m','e',0, // name (17)
    };

    BMFFCode res;
    HandlerBox *box = NULL;
    res = _bmff_parse_box_handler(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x31, "size");
    test_assert_equal(strncmp(box->box.type, "hdlr", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xFFFFFA, "flags");
    test_assert_equal(box->handler_type, 0xEEE14509, "handler type");
    test_assert_equal(strcmp(box->name, "handler box name"), 0, "name");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_primary_item(void)
{
    test_start("test_parse_box_primary_item");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x0E,
        'p', 'i', 't', 'm',
        0x01, // version
        0xEE, 0xCC, 0xBB, // flags
        0x01, 0x02, 0x03, 0x04, // item id
    };

    BMFFCode res;
    PrimaryItemBox *box = NULL;
    res = _bmff_parse_box_primary_item(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x0E, "size");
    test_assert_equal(strncmp(box->box.type, "pitm", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xEECCBB, "flags");
    test_assert_equal(box->item_id, 0x01020304, "item id");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_location(void)
{
    test_start("test_parse_box_item_location");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x40,
        'i', 'l', 'o', 'c',
        0x01, // version
        0x00, 0x11, 0x00, // flags
        0x44, // offset size (4), length size (4) one of {0,4,8}
        0x44, // base offset size (4) and index size (4) one of {0,4,8},
        0x00, 0x02, // item count
            // item [0]
            0x00, 0x01, // item id
            0x00, 0x08, // reserved (12), construction method (4)
            0x00, 0x00, // data reference index
            0xE1, 0xE1, 0xC2, 0xC2, // base offset (4*8)
            0x00, 0x02, // extent count
                // extend[0]
                0x90, 0xA0, 0xB0, 0xC0, // index
                0x10, 0x20, 0x30, 0x40, // offset
                0x50, 0x60, 0x70, 0x80, // size
                // extend[1]
                0x91, 0xA1, 0xB1, 0xC1, // index
                0xA1, 0xB2, 0xC3, 0xD4, // offset
                0xA9, 0xB8, 0xC7, 0xD6, // size
            // item [1]
            0xFE, 0xDC, // item id
            0x00, 0x01, // reserved (12), construction method (4)
            0x00, 0x01, // data reference index
            0x12, 0x34, 0x56, 0x78, // base offset (4*8)
            0x00, 0x00, // extent count
    };

    BMFFCode res;
    ItemLocationBox *box = NULL;
    res = _bmff_parse_box_item_location(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "iloc", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0x001100, "flags");
    test_assert_equal(box->offset_size, 4, "offset size");
    test_assert_equal(box->length_size, 4, "length size");
    test_assert_equal(box->index_size, 4, "index size");
    test_assert_equal(box->base_offset_size, 4, "base offset size");
    test_assert_equal(box->item_count, 2, "item count");
    test_assert_equal(box->items[0].item_id, 1, "item[0] item id");
    test_assert_equal(box->items[0].data_reference_index, 0, "item[0] data reference index");
    test_assert_equal(box->items[0].base_offset, 0xE1E1C2C2, "item[0] base offset");
    test_assert_equal(box->items[0].construction_method, 0x08, "item[0] construction method");
    test_assert_equal(box->items[0].extent_count, 2, "item[0] extent count");
    test_assert_equal(box->items[0].extents[0].index, 0x90A0B0C0, "item[0].extent[0] index");
    test_assert_equal(box->items[0].extents[0].offset, 0x10203040, "item[0].extent[0] offset");
    test_assert_equal(box->items[0].extents[0].length, 0x50607080, "item[0].extent[0] length");
    test_assert_equal(box->items[0].extents[1].index, 0x91A1B1C1, "item[0].extent[1] index");
    test_assert_equal(box->items[0].extents[1].offset, 0xA1B2C3D4, "item[0].extent[1] offset");
    test_assert_equal(box->items[0].extents[1].length, 0xA9B8C7D6, "item[0].extent[1] length");
    test_assert_equal(box->items[1].item_id, 0xFEDC, "item[1] item id");
    test_assert_equal(box->items[1].data_reference_index, 1, "item[1] data reference index");
    test_assert_equal(box->items[1].base_offset, 0x12345678, "item[1] base offset");
    test_assert_equal(box->items[1].construction_method, 0x01, "item[1] construction method");
    test_assert_equal(box->items[1].extent_count, 0, "item[1] extent count");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_info_entry_v1(void)
{
    test_start("test_parse_box_item_info_entry_v1");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x5D,
        'i', 'n', 'f', 'e',
        0x01, // version
        0x00, 0x00, 0x00, // flags
        0x12, 0x34, // item id
        0xAB, 0xCD, // item protection index
        'i','t','e','m',' ','n','a','m','e',0, // 10
        'c','o','n','t','e','n','t',' ','t','y','p','e',0, // 13
        'c','o','n','t','e','n','t',' ','e','n','c','o','d','i','n','g',0, // 17
        'f','d','e','l', // extension type
        'l','o','c','\0', // extension
        'm','d','5','\0',
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // content length
        0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, // transfer length
        0x02, // entry count
        0x0A, 0x0B, 0x0C, 0x0D, // group id
        0x1A, 0x1B, 0x1C, 0x1D, // group id
    };

    BMFFCode res;
    ItemInfoEntry *box = NULL;
    res = _bmff_parse_box_item_info_entry(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "infe", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0x000000, "flags");
    test_assert_equal(box->item_id, 0x1234, "item id");
    test_assert_equal(box->item_protection_index, 0xABCD, "item protection index");
    test_assert_equal(strcmp(box->item_name, "item name"), 0, "item name");
    test_assert_equal(strcmp(box->content_type, "content type"), 0, "content type");
    test_assert_equal(strcmp(box->content_encoding, "content encoding"), 0, "content encoding");
    test_assert_equal(strncmp(box->extension_type, "fdel", 4), 0, "extension type");

    FDItemInfoExtension *ext = box->extension;
    test_assert_equal(strcmp(ext->content_location, "loc"), 0, "content location");
    test_assert_equal(strcmp(ext->content_md5, "md5"), 0, "content md5");
    test_assert_equal_uint64(ext->content_length, 0x0102030405060708ULL, "content length");
    test_assert_equal_uint64(ext->transfer_length, 0x1112131415161718ULL, "transfer length");
    test_assert_equal(ext->entry_count, 2, "entry count");
    test_assert_equal(ext->group_ids[0], 0x0A0B0C0D, "group ids 0");
    test_assert_equal(ext->group_ids[1], 0x1A1B1C1D, "group ids 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_info_entry_v2(void)
{
    test_start("test_parse_box_item_info_entry_v2");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x3C,
        'i', 'n', 'f', 'e',
        0x02, // version
        0x00, 0x00, 0x00, // flags
        0x12, 0x34, // item id
        0xAB, 0xCD, // item protection index
        'm', 'i', 'm', 'e', // item type
        'i','t','e','m',' ','n','a','m','e',0, // 10
        'c','o','n','t','e','n','t',' ','t','y','p','e',0, // 13
        'c','o','n','t','e','n','t',' ','e','n','c','o','d','i','n','g',0, // 17
    };

    BMFFCode res;
    ItemInfoEntry *box = NULL;
    res = _bmff_parse_box_item_info_entry(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "infe", 4), 0, "type");
    test_assert_equal(box->box.version, 0x02, "version");
    test_assert_equal(box->box.flags, 0x000000, "flags");
    test_assert_equal(box->item_id, 0x1234, "item id");
    test_assert_equal(box->item_protection_index, 0xABCD, "item protection index");
    test_assert_equal(strncmp(box->item_type, "mime", 4), 0, "item type");
    test_assert_equal(strcmp(box->item_name, "item name"), 0, "item name");
    test_assert_equal(strcmp(box->content_type, "content type"), 0, "content type");
    test_assert_equal(strcmp(box->content_encoding, "content encoding"), 0, "content encoding");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_info(void)
{
    test_start("test_parse_box_item_info");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x4F,
        'i', 'i', 'n', 'f',
        0x00, // version
        0x11, 0x11, 0x11, // flags
        0x00, 0x02, // entry count
        // 1st
        0, 0, 0, 0x1B,
        'i', 'n', 'f', 'e',
        0x00, // version
        0x22, 0x22, 0x22, // flags
        0x88, 0x77, // item id
        0x35, 0x79, // item protection index
        'n','a','m','e',0,
        't','y','p','e',0,
        0, // encoding (27)
        // 2nd
        0, 0, 0, 0x26,
        'i', 'n', 'f', 'e',
        0x00, // version
        0x33, 0x33, 0x33, // flags
        0x34, 0x56, // item id
        0x98, 0x76, // item protection index
        'n','a','m','e','2',0,
        't','y','p','e','2',0,
        'e','n','c','o','d','i','n','g','2',0, // 38
    };

    BMFFCode res;
    ItemInfoBox *box = NULL;
    res = _bmff_parse_box_item_info(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "iinf", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x111111, "flags");
    test_assert_equal(box->entry_count, 2, "flags");

    ItemInfoEntry *item = box->entries[0];
    test_assert_equal(item->box.size, 0x1B, "item[0] size");
    test_assert_equal(strncmp(item->box.type, "infe", 4), 0, "item[0] type");
    test_assert_equal(item->box.version, 0x00, "item[0] version");
    test_assert_equal(item->box.flags, 0x222222, "item[0] flags");
    test_assert_equal(item->item_id, 0x8877, "item[0] item id");
    test_assert_equal(item->item_protection_index, 0x3579, "item[0] item protection index");
    test_assert_equal(strcmp(item->item_name, "name"), 0, "item[0] item name");
    test_assert_equal(strcmp(item->content_type, "type"), 0, "item[0] content type");
    test_assert_equal(item->content_encoding[0], 0, "item[0] content encoding");

    item = box->entries[1];
    test_assert_equal(item->box.size, 0x26, "item[1] size");
    test_assert_equal(strncmp(item->box.type, "infe", 4), 0, "item[1] type");
    test_assert_equal(item->box.version, 0x00, "item[1] version");
    test_assert_equal(item->box.flags, 0x333333, "item[1] flags");
    test_assert_equal(item->item_id, 0x3456, "item[1] item id");
    test_assert_equal(item->item_protection_index, 0x9876, "item[1] item protection index");
    test_assert_equal(strcmp(item->item_name, "name2"), 0, "item[1] item name");
    test_assert_equal(strcmp(item->content_type, "type2"), 0, "item[1] content type");
    test_assert_equal(strcmp(item->content_encoding, "encoding2"), 0, "item[1] content encoding");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_ipmp_control(void)
{
    test_start("test_parse_box_ipmp_control");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x95,
        'i', 'p', 'm', 'c',
        0x00, // version
        0xFE, 0xDC, 0xBA, // flags
        // IPMP descriptor List
        0x60, // Tool list descriptor tag
        0x02, // num of tools
        // IPMP Tool 1
        0xF2, 0xD5, 0x0A, 0x49, 0x3C, 0xBB, 0x0E, 0x31, // IPMP Tool Id (64)
        0x4C, 0x32, 0xBC, 0x00, 0x8F, 0x10, 0x43, 0xFE, // IPMP Tool Id (128)
        0xC0, // iaAltGroup (1), isParametric (1)
        0x40, // numAlternates
        0x01, 0x23, 0x45, 0x67, 0x89, 0x9A, 0xBC, 0xDE, // specific tool ID (64)
        0xF0, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, // specific tool ID (64)
        0x00, 0x00, 0x00, 0x0F, 't','o','o','l',' ','p','a','r','a','m',' ','d','e','s','c',0x00, // ByteArray toolPatamDesc
        0x03, // num urls
        0x00, 0x00, 0x00, 0x05, 'u','r','l',' ','1', 0x00, // toolUrl 1
        0x00, 0x00, 0x00, 0x05, 'u','r','l',' ','2', 0x00, // toolUrl 2
        0x00, 0x00, 0x00, 0x05, 'u','r','l',' ','3', 0x00, // toolUrl 3
        // IPMP Tool 2
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (64)
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (128)
        0x40, // iaAltGroup (1), isParametric (1)
        0x00, 0x00, 0x00, 0x0A, 't','o','o','l',' ','p','a','r','a','m',0x00, // ByteArray toolPatamDesc
        0x01, // num urls
        0x00, 0x00, 0x00, 0x03, 'u','r','l', 0x00, // toolUrl 1
        // IPMP Control Box Continued
        0x02, // no of IPMPDesctriptors
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    };

    BMFFCode res;
    IPMPControlBox *box = NULL;
    res = _bmff_parse_box_ipmp_control(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "ipmc", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xFEDCBA, "flags");

    test_assert_equal(box->tool_list.tag, 0x60, "tool list descriptor tag");
    test_assert_equal(box->tool_list.num_tools, 2, "num of tool");

    IPMPTool *tool = &box->tool_list.ipmp_tools[0];
    uint8_t tool_id_0[] = {
        0xF2, 0xD5, 0x0A, 0x49, 0x3C, 0xBB, 0x0E, 0x31,
        0x4C, 0x32, 0xBC, 0x00, 0x8F, 0x10, 0x43, 0xFE,
    };
    test_assert_equal(memcmp(tool->tool_id, tool_id_0, 16), 0, "tool 0 tool id");
    test_assert_equal(tool->is_alt_group, 1, "tool 0 is alt group");
    test_assert_equal(tool->is_parametric, 1, "tool 0 is parametric");
    test_assert_equal(tool->num_alternates, 0x40, "tool 0 num alternates");
    uint8_t specific_tool_id_0[] = {
        0x01, 0x23, 0x45, 0x67, 0x89, 0x9A, 0xBC, 0xDE, // specific tool ID (64)
        0xF0, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, // specific tool ID (64)
    };
    test_assert_equal(memcmp(tool->specific_tool_id, specific_tool_id_0, 16), 0, "tool 0 specific tool id");
    test_assert_equal(strcmp(tool->tool_param_desc, "tool param desc"), 0, "tool 0 tool param description");
    test_assert_equal(tool->num_urls, 3, "tool 0 urls");
    test_assert_equal(strcmp(tool->tool_urls[0], "url 1"), 0, "tool 0 url 0");
    test_assert_equal(strcmp(tool->tool_urls[1], "url 2"), 0, "tool 0 url 1");
    test_assert_equal(strcmp(tool->tool_urls[2], "url 3"), 0, "tool 0 url 2");

    tool = &box->tool_list.ipmp_tools[1];
    uint8_t tool_id_1[] = {
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (64)
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (128)
    };
    test_assert_equal(memcmp(tool->tool_id, tool_id_1, 16), 0, "tool 1 tool id");
    test_assert_equal(tool->is_alt_group, 0, "tool 1 is alt group");
    test_assert_equal(tool->is_parametric, 1, "tool 1 is parametric");
    test_assert_equal(tool->num_alternates, 0x00, "tool 1 num alternates");
    uint8_t specific_tool_id_1[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    test_assert_equal(memcmp(tool->specific_tool_id, specific_tool_id_1, 16), 0, "tool 1 specific tool id");
    test_assert_equal(strcmp(tool->tool_param_desc, "tool param"), 0, "tool 1 tool param description");
    test_assert_equal(tool->num_urls, 1, "tool 1 urls");
    test_assert_equal(strcmp(tool->tool_urls[0], "url"), 0, "tool 1 url 0");

    test_assert_equal(box->ipmp_descriptors_len, 0x02, "descriptors length");
    uint8_t descriptors[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, };
    test_assert_equal(memcmp(box->ipmp_descriptors, descriptors, 8), 0, "descriptor data");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_original_format(void)
{
    test_start("test_parse_box_original_format");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x0C, // size
        'f', 'r', 'm', 'a',
        'm','p','4','v', // coded name
    };

    BMFFCode res;
    OriginalFormatBox *box = NULL;
    res = _bmff_parse_box_original_format(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 12, "size");
    test_assert_equal(strncmp(box->box.type, "frma", 4), 0, "type");
    test_assert_equal(strncmp(box->data_format, "mp4v", 4), 0, "codec name");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_ipmp_info(void)
{
    test_start("test_parse_box_ipmp_info");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x16,
        'i', 'm', 'i', 'f',
        0x00, // version
        0x10, 0x20, 0x30, // flags
        't','o','d','o',':','t','h','i','s',0, // IPMP descriptors
    };

    BMFFCode res;
    IPMPInfoBox *box = NULL;
    res = _bmff_parse_box_ipmp_info(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "imif", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x102030, "flags");
    // TODO: IPMP Descriptors
    test_assert_equal(strcmp(box->ipmp_desc, "todo:this"), 0, "ipmp descriptors");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_scheme_type(void)
{
    test_start("test_parse_box_scheme_type");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1F,
        's', 'c', 'h', 'm',
        0x00, // version
        0x00, 0x00, 0x01, // flags
        't','y','p','e',
        0xF0, 0x00, 0x00, 0x01,
        's','c','h','e','m','e',' ','u','r','i',0
    };

    BMFFCode res;
    SchemeTypeBox *box = NULL;
    res = _bmff_parse_box_scheme_type(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "schm", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000001, "flags");
    test_assert_equal(strncmp(box->scheme_type, "type", 4), 0, "scheme type");
    test_assert_equal(box->scheme_version, 0xF0000001, "scheme version");
    test_assert_equal(strcmp(box->scheme_uri, "scheme uri"), 0, "scheme uri");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_scheme_info(void)
{
    test_start("test_parse_box_scheme_info");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x3B,
        's', 'c', 'h', 'i',
        // scheme specific Boxes
        0, 0, 0, 0x0C,
        'a','b','c','d',
        0xFF, 0xFF, 0xFF, 0xFF,
        0, 0, 0, 0x0F,
        'e','f','g','h',
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0, 0, 0, 0x18,
        'i','j','k','l',
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    };

    BMFFCode res;
    SchemeInformationBox *box = NULL;
    res = _bmff_parse_box_scheme_info(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "schi", 4), 0, "type");
    test_assert_equal(box->scheme_specific_data_count, 3, "scheme specific data count");
    test_assert_equal(strncmp(box->scheme_specific_data[0].type, "abcd", 4), 0, "scheme specifi data 0 type");
    test_assert_equal(box->scheme_specific_data[0].size, 0x0C, "scheme specific data 0 size");
    test_assert_equal(strncmp(box->scheme_specific_data[1].type, "efgh", 4), 0, "scheme specifi data 1 type");
    test_assert_equal(box->scheme_specific_data[1].size, 0x0F, "scheme specific data 1 size");
    test_assert_equal(strncmp(box->scheme_specific_data[2].type, "ijkl", 4), 0, "scheme specifi data 2 type");
    test_assert_equal(box->scheme_specific_data[2].size, 0x18, "scheme specific data 2 size");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_protection_scheme_info(void)
{
    test_start("test_parse_box_protection_scheme_info");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x3F,
        's', 'i', 'n', 'f',
        0, 0, 0, 0x0C,
        'f', 'r', 'm', 'a',
        'm','p','4','v', // data format
        // Scheme Type Box
        0, 0, 0, 0x14,
        's', 'c', 'h', 'm',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        'a','b','c','d',    // 4CC scheme id
        0xAB, 0xCD, 0xEF, 0x98, // scheme version
        // Scheme Information Box
        0, 0, 0, 0x17, //(23)
        's', 'c', 'h', 'i',
            // scheme specific Boxes
        0, 0, 0, 0x0F,
        'a','b','c','d',
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    };

    BMFFCode res;
    ProtectionSchemeInfoBox *box = NULL;
    res = _bmff_parse_box_protection_scheme_info(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "sinf", 4), 0, "type");

    test_assert_equal(box->original_format.box.size, 0x0C, "original format size");
    test_assert_equal(strncmp(box->original_format.box.type, "frma", 4), 0, "original format type");
    test_assert_equal(strncmp(box->original_format.data_format, "mp4v", 4), 0, "original format data");

    test_assert(box->scheme_type != NULL, "NULL Scheme Type box");
    SchemeTypeBox *schm_type = box->scheme_type;
    test_assert_equal(strncmp("schm", schm_type->box.type, 4), 0, "Scheme Type type");
    test_assert_equal(schm_type->box.size, 0x14, "Scheme Type size");
    test_assert_equal(schm_type->box.version, 0x00, "Scheme Type version");
    test_assert_equal(schm_type->box.flags, 0x000000, "Scheme Type flags");
    test_assert_equal(strncmp("abcd", schm_type->scheme_type, 4), 0, "Scheme Type's scheme_type");
    test_assert_equal(schm_type->scheme_version, 0xABCDEF98, "Scheme Type scheme_version");

    test_assert(box->scheme_info != NULL, "NULL Scheme Info box");
    SchemeInformationBox *schm_info = box->scheme_info;
    test_assert_equal(strncmp("schi", schm_info->box.type, 4), 0, "Scheme Info type");
    test_assert_equal(schm_info->box.size, 0x17, "Scheme Info size");
    test_assert_equal(schm_info->scheme_specific_data_count, 1, "Scheme Info scheme specific count");
    Box *ssd = &schm_info->scheme_specific_data[0];
    test_assert_equal(strncmp("abcd", ssd->type, 4), 0, "Scheme specific data type");
    test_assert_equal(ssd->size, 0x0F, "Scheme specific data size");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_protection(void)
{
    test_start("test_parse_box_item_protection");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x4D,
        'i', 'p', 'r', 'o',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        0x00, 0x01, // protection count
        ////////
        // Protection Scheme Info Box
        ///////
        0, 0, 0, 0x4F,
        's', 'i', 'n', 'f',
        0, 0, 0, 0x0C, // original format
        'f', 'r', 'm', 'a',
        'm','p','4','v', // data format
        // Scheme Type Box
        0, 0, 0, 0x14,
        's', 'c', 'h', 'm',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        'a','b','c','d',    // 4CC scheme id
        0xAB, 0xCD, 0xEF, 0x98, // scheme version
        // Scheme Information Box
        0, 0, 0, 0x17, //(23)
        's', 'c', 'h', 'i',
            // scheme specific Boxes
        0, 0, 0, 0x0F,
        'a','b','c','d',
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    };

    BMFFCode res;
    ItemProtectionBox *box = NULL;
    res = _bmff_parse_box_item_protection(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "ipro", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000000, "flags");
    test_assert_equal(box->protection_count, 1, "protection count");
    test_assert(box->protection_info != NULL, "protection info");

    ProtectionSchemeInfoBox *info = box->protection_info[0];

    test_assert_equal(info->box.size, 0x4F, "size");
    test_assert_equal(strncmp(info->box.type, "sinf", 4), 0, "type");

    test_assert_equal(info->original_format.box.size, 0x0C, "original format size");
    test_assert_equal(strncmp(info->original_format.box.type, "frma", 4), 0, "original format type");
    test_assert_equal(strncmp(info->original_format.data_format, "mp4v", 4), 0, "original format data");

    test_assert(info->scheme_type != NULL, "NULL Scheme Type box");
    SchemeTypeBox *schm_type = info->scheme_type;
    test_assert_equal(strncmp("schm", schm_type->box.type, 4), 0, "Scheme Type type");
    test_assert_equal(schm_type->box.size, 0x14, "Scheme Type size");
    test_assert_equal(schm_type->box.version, 0x00, "Scheme Type version");
    test_assert_equal(schm_type->box.flags, 0x000000, "Scheme Type flags");
    test_assert_equal(strncmp("abcd", schm_type->scheme_type, 4), 0, "Scheme Type's scheme_type");
    test_assert_equal(schm_type->scheme_version, 0xABCDEF98, "Scheme Type scheme_version");

    test_assert(info->scheme_info != NULL, "NULL Scheme Info box");
    SchemeInformationBox *schm_info = info->scheme_info;
    test_assert_equal(strncmp("schi", schm_info->box.type, 4), 0, "Scheme Info type");
    test_assert_equal(schm_info->box.size, 0x17, "Scheme Info size");
    test_assert_equal(schm_info->scheme_specific_data_count, 1, "Scheme Info scheme specific count");
    Box *ssd = &schm_info->scheme_specific_data[0];
    test_assert_equal(strncmp("abcd", ssd->type, 4), 0, "Scheme specific data type");
    test_assert_equal(ssd->size, 0x0F, "Scheme specific data size");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_meta(void)
{
    test_start("test_parse_box_meta");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0x02, 0x2A,
        'm', 'e', 't', 'a',
        0x00, // version
        0x00, 0x00, 0x00, // flags

        // handler
        0, 0, 0, 0x31,
        'h', 'd', 'l', 'r',
        0x00, // version
        0xFF, 0xFF, 0xFA, // flags
        0, 0, 0, 0, // pre_defined
        0xEE, 0xE1, 0x45, 0x09, // handler_type
        0, 0, 0 ,0, // reserved
        0, 0, 0 ,0, // reserved
        0, 0, 0 ,0, // reserved
        'h','a','n','d','l','e','r',' ','b','o','x',' ','n','a','m','e',0, // name (17)

        // Primary Item
        0, 0, 0, 0x0E,
        'p', 'i', 't', 'm',
        0x00, // version
        0xEE, 0xCC, 0xBB, // flags
        0x01, 0x05, // item id

        // Data Information
        0, 0, 0, 20,
        'd','i','n','f',
        // random box within Data Information
        0, 0, 0, 12,
        'x','x','x','x',
        'd','a','t','a',

        // Item Location Box
        0, 0, 0, 0x34,
        'i', 'l', 'o', 'c',
        0x00, // version
        0x00, 0x11, 0x00, // flags
        0x44, // offset size (4), length size (4) one of {0,4,8}
        0x40, // base offset size (4) one of {0,4,8}, reserved (4)
        0x00, 0x02, // item count
        // item [0]
        0x00, 0x01, // item id
        0x00, 0x00, // data reference index
        0xE1, 0xE1, 0xC2, 0xC2, // base offset (4*8)
        0x00, 0x02, // extent count
        // extend[0]
        0x10, 0x20, 0x30, 0x40, // offset
        0x50, 0x60, 0x70, 0x80, // size
        // extend[1]
        0xA1, 0xB2, 0xC3, 0xD4, // offset
        0xA9, 0xB8, 0xC7, 0xD6, // size
        // item [1]
        0xFE, 0xDC, // item id
        0x00, 0x01, // data reference index
        0x12, 0x34, 0x56, 0x78, // base offset (4*8)
        0x00, 0x00, // extent count

        // Item Protection
        0, 0, 0, 0x4D,
        'i', 'p', 'r', 'o',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        0x00, 0x01, // protection count
        // Protection Scheme Info Box
        0, 0, 0, 0x3F,
        's', 'i', 'n', 'f',
        0, 0, 0, 0x0C,
        'f','r','m','a',
        'm','p','4','v', // data format
        // Scheme Type Box
        0, 0, 0, 0x14,
        's', 'c', 'h', 'm',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        'a','b','c','d',    // 4CC scheme id
        0xAB, 0xCD, 0xEF, 0x98, // scheme version
        // Scheme Information Box
        0, 0, 0, 0x17, //(23)
        's', 'c', 'h', 'i',
        // scheme specific Boxes
        0, 0, 0, 0x0F,
        'a','b','c','d',
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,

        // Item Information (iinf)
        0, 0, 0, 0x4F,
        'i', 'i', 'n', 'f',
        0x00, // version
        0x11, 0x11, 0x11, // flags
        0x00, 0x02, // entry count
        // 1st
        0, 0, 0, 0x1B,
        'i', 'n', 'f', 'e',
        0x00, // version
        0x22, 0x22, 0x22, // flags
        0x88, 0x77, // item id
        0x35, 0x79, // item protection index
        'n','a','m','e',0,
        't','y','p','e',0,
        0, // encoding (27)
        // 2nd
        0, 0, 0, 0x26,
        'i', 'n', 'f', 'e',
        0x00, // version
        0x33, 0x33, 0x33, // flags
        0x34, 0x56, // item id
        0x98, 0x76, // item protection index
        'n','a','m','e','2',0,
        't','y','p','e','2',0,
        'e','n','c','o','d','i','n','g','2',0, // 38

        // IPMP Control (ipmc)
        0, 0, 0, 0x95,
        'i', 'p', 'm', 'c',
        0x00, // version
        0xFE, 0xDC, 0xBA, // flags
        // IPMP descriptor List
        0x60, // Tool list descriptor tag
        0x02, // num of tools
        // IPMP Tool 1
        0xF2, 0xD5, 0x0A, 0x49, 0x3C, 0xBB, 0x0E, 0x31, // IPMP Tool Id (64)
        0x4C, 0x32, 0xBC, 0x00, 0x8F, 0x10, 0x43, 0xFE, // IPMP Tool Id (128)
        0xC0, // iaAltGroup (1), isParametric (1)
        0x40, // numAlternates
        0x01, 0x23, 0x45, 0x67, 0x89, 0x9A, 0xBC, 0xDE, // specific tool ID (64)
        0xF0, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, // specific tool ID (64)
        0x00, 0x00, 0x00, 0x0F, 't','o','o','l',' ','p','a','r','a','m',' ','d','e','s','c',0x00, // ByteArray toolPatamDesc
        0x03, // num urls
        0x00, 0x00, 0x00, 0x05, 'u','r','l',' ','1', 0x00, // toolUrl 1
        0x00, 0x00, 0x00, 0x05, 'u','r','l',' ','2', 0x00, // toolUrl 2
        0x00, 0x00, 0x00, 0x05, 'u','r','l',' ','3', 0x00, // toolUrl 3
        // IPMP Tool 2
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (64)
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (128)
        0x40, // iaAltGroup (1), isParametric (1)
        0x00, 0x00, 0x00, 0x0A, 't','o','o','l',' ','p','a','r','a','m',0x00, // ByteArray toolPatamDesc
        0x01, // num urls
        0x00, 0x00, 0x00, 0x03, 'u','r','l', 0x00, // toolUrl 1
        // IPMP Control Box Continued
        0x02, // no of IPMPDesctriptors
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,

        // Item Reference
        0, 0, 0, 0x3C,
        'i', 'r', 'e', 'f',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0, 0, 0, 0x10,
        'i','r','e','f',
        0x12, 0x34, // from item id
        0x00, 0x02, // reference count
        0x01, 0x02, 0x03, 0x04, // to item ids
        0, 0, 0, 0x0E,
        'i','r','e','f',
        0x56, 0x78, // from item id
        0x00, 0x01, // reference count
        0x11, 0x12, // to item ids
        0, 0, 0, 0x12,
        'i','r','e','f',
        0x9A, 0xBC, // from item id
        0x00, 0x03, // reference count
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26, // to item ids

        // Item Data
        0, 0, 0, 0x10,
        'i', 'd', 'a', 't',
        0x01, 0x02, 0x03, 0x04, // data
        0x05, 0x06, 0x07, 0x08,

        // "Other" Boxes
        0x00, 0x00, 0x00, 0x0C,
        'a', 'b', 'c', 'd',
        0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x00, 0x00, 0x0E,
        'e', 'f', 'g', 'h',
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    };

    BMFFCode res;
    MetaBox *box = NULL;
    res = _bmff_parse_box_meta(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    //test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "meta", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000000, "flags");

    // Handler Box
    HandlerBox *hdlr = box->handler;
    test_assert_equal(hdlr->box.size, 0x31, "handler box size");
    test_assert_equal(strncmp(hdlr->box.type, "hdlr", 4), 0, "handler box type");
    test_assert_equal(hdlr->box.version, 0x00, "handler box version");
    test_assert_equal(hdlr->box.flags, 0xFFFFFA, "handler box flags");
    test_assert_equal(hdlr->handler_type, 0xEEE14509, "handler box handler type");
    test_assert_equal(strcmp(hdlr->name, "handler box name"), 0, "handler box name");

    // Primary Item
    PrimaryItemBox *pitem = box->primary_resource;
    test_assert_equal(pitem->box.size, 0x0E, "primary item size");
    test_assert_equal(strncmp(pitem->box.type, "pitm", 4), 0, "primary item type");
    test_assert_equal(pitem->box.version, 0x00, "primary item version");
    test_assert_equal(pitem->box.flags, 0xEECCBB, "primary item flags");
    test_assert_equal(pitem->item_id, 0x0105, "primary item item id");

    // Data Information box
    DataInformationBox *dinf = box->file_locations;
    test_assert_equal(dinf->box.size, 20, "dinf size");
    test_assert_equal(strncmp(dinf->box.type, "dinf", 4), 0, "dinf type");

    // Item Location
    ItemLocationBox *iloc = box->item_locations;
    test_assert_equal(iloc->box.size, 0x34, "iloc size");
    test_assert_equal(strncmp(iloc->box.type, "iloc", 4), 0, "iloc type");
    test_assert_equal(iloc->box.version, 0x00, "iloc version");
    test_assert_equal(iloc->box.flags, 0x001100, "iloc flags");
    test_assert_equal(iloc->offset_size, 4, "iloc offset size");
    test_assert_equal(iloc->length_size, 4, "iloc length size");
    test_assert_equal(iloc->base_offset_size, 4, "iloc base offset size");
    test_assert_equal(iloc->item_count, 2, "iloc item count");
    test_assert_equal(iloc->items[0].item_id, 1, "iloc item[0] item id");
    test_assert_equal(iloc->items[0].data_reference_index, 0, "iloc item[0] data reference index");
    test_assert_equal(iloc->items[0].base_offset, 0xE1E1C2C2, "iloc item[0] base offset");
    test_assert_equal(iloc->items[0].extent_count, 2, "iloc item[0] extent count");
    test_assert_equal(iloc->items[0].extents[0].offset, 0x10203040, "iloc item[0].extent[0] offset");
    test_assert_equal(iloc->items[0].extents[0].length, 0x50607080, "iloc item[0].extent[0] length");
    test_assert_equal(iloc->items[0].extents[1].offset, 0xA1B2C3D4, "iloc item[0].extent[1] offset");
    test_assert_equal(iloc->items[0].extents[1].length, 0xA9B8C7D6, "iloc item[0].extent[1] length");
    test_assert_equal(iloc->items[1].item_id, 0xFEDC, "iloc item[1] item id");
    test_assert_equal(iloc->items[1].data_reference_index, 1, "iloc item[1] data reference index");
    test_assert_equal(iloc->items[1].base_offset, 0x12345678, "iloc item[1] base offset");
    test_assert_equal(iloc->items[1].extent_count, 0, "iloc item[1] extent count");

    // Item Protection
    ItemProtectionBox *ipro = box->protections;
    test_assert_equal(ipro->box.size, 0x4D, "ipro size");
    test_assert_equal(strncmp(ipro->box.type, "ipro", 4), 0, "ipro type");
    test_assert_equal(ipro->box.version, 0x00, "ipro version");
    test_assert_equal(ipro->box.flags, 0x000000, "ipro flags");
    test_assert_equal(ipro->protection_count, 1, "ipro protection count");
    test_assert(ipro->protection_info != NULL, "ipro protection info");

    ProtectionSchemeInfoBox *info = ipro->protection_info[0];
    test_assert_equal(info->box.size, 0x3F, "sinf size");
    test_assert_equal(strncmp(info->box.type, "sinf", 4), 0, "sinf type");

    test_assert_equal(info->original_format.box.size, 0x0C, "original format size");
    test_assert_equal(strncmp(info->original_format.box.type, "frma", 4), 0, "original format type");
    test_assert_equal(strncmp(info->original_format.data_format, "mp4v", 4), 0, "original format data");

    SchemeTypeBox *schm_type = info->scheme_type;
    test_assert_equal(strncmp("schm", schm_type->box.type, 4), 0, "Scheme Type type");
    test_assert_equal(schm_type->box.size, 0x14, "Scheme Type size");
    test_assert_equal(schm_type->box.version, 0x00, "Scheme Type version");
    test_assert_equal(schm_type->box.flags, 0x000000, "Scheme Type flags");
    test_assert_equal(strncmp("abcd", schm_type->scheme_type, 4), 0, "Scheme Type's scheme_type");
    test_assert_equal(schm_type->scheme_version, 0xABCDEF98, "Scheme Type scheme_version");
    test_assert(info->scheme_info != NULL, "NULL Scheme Info box");

    SchemeInformationBox *schm_info = info->scheme_info;
    test_assert_equal(strncmp("schi", schm_info->box.type, 4), 0, "Scheme Info type");
    test_assert_equal(schm_info->box.size, 0x17, "Scheme Info size");
    test_assert_equal(schm_info->scheme_specific_data_count, 1, "Scheme Info scheme specific count");

    Box *ssd = &schm_info->scheme_specific_data[0];
    test_assert_equal(strncmp("abcd", ssd->type, 4), 0, "Scheme specific data type");
    test_assert_equal(ssd->size, 0x0F, "Scheme specific data size");

    ItemInfoBox *iinf = box->item_infos;
    test_assert_equal(iinf->box.size, 0x4F, "iinf size");
    test_assert_equal(strncmp(iinf->box.type, "iinf", 4), 0, "iinf type");
    test_assert_equal(iinf->box.version, 0x00, "iinf version");
    test_assert_equal(iinf->box.flags, 0x111111, "iinf flags");
    test_assert_equal(iinf->entry_count, 2, "iinf flags");

    ItemInfoEntry *item = iinf->entries[0];
    test_assert_equal(item->box.size, 0x1B, "iinf item[0] size");
    test_assert_equal(strncmp(item->box.type, "infe", 4), 0, "iinf item[0] type");
    test_assert_equal(item->box.version, 0x00, "iinf item[0] version");
    test_assert_equal(item->box.flags, 0x222222, "iinf item[0] flags");
    test_assert_equal(item->item_id, 0x8877, "iinf item[0] item id");
    test_assert_equal(item->item_protection_index, 0x3579, "iinf item[0] item protection index");
    test_assert_equal(strcmp(item->item_name, "name"), 0, "iinf item[0] item name");
    test_assert_equal(strcmp(item->content_type, "type"), 0, "iinf item[0] content type");
    test_assert_equal(item->content_encoding[0], 0, "iinf item[0] content encoding");

    item = iinf->entries[1];
    test_assert_equal(item->box.size, 0x26, "iinf item[1] size");
    test_assert_equal(strncmp(item->box.type, "infe", 4), 0, "iinf item[1] type");
    test_assert_equal(item->box.version, 0x00, "iinf item[1] version");
    test_assert_equal(item->box.flags, 0x333333, "iinf item[1] flags");
    test_assert_equal(item->item_id, 0x3456, "iinf item[1] item id");
    test_assert_equal(item->item_protection_index, 0x9876, "iinf item[1] item protection index");
    test_assert_equal(strcmp(item->item_name, "name2"), 0, "iinf item[1] item name");
    test_assert_equal(strcmp(item->content_type, "type2"), 0, "iinf item[1] content type");
    test_assert_equal(strcmp(item->content_encoding, "encoding2"), 0, "iinf item[1] content encoding");

    IPMPControlBox *ipmc = box->ipmp_control;
    test_assert_equal(ipmc->box.size, 0x95, "ipmc size");
    test_assert_equal(strncmp(ipmc->box.type, "ipmc", 4), 0, "ipmc type");
    test_assert_equal(ipmc->box.version, 0x00, "ipmc version");
    test_assert_equal(ipmc->box.flags, 0xFEDCBA, "ipmc flags");

    test_assert_equal(ipmc->tool_list.tag, 0x60, "ipmc tool list descriptor tag");
    test_assert_equal(ipmc->tool_list.num_tools, 2, "ipmc num of tool");

    IPMPTool *tool = &ipmc->tool_list.ipmp_tools[0];
    uint8_t tool_id_0[] = {
        0xF2, 0xD5, 0x0A, 0x49, 0x3C, 0xBB, 0x0E, 0x31,
        0x4C, 0x32, 0xBC, 0x00, 0x8F, 0x10, 0x43, 0xFE,
    };
    test_assert_equal(memcmp(tool->tool_id, tool_id_0, 16), 0, "ipmc tool 0 tool id");
    test_assert_equal(tool->is_alt_group, 1, "ipmc tool 0 is alt group");
    test_assert_equal(tool->is_parametric, 1, "ipmc tool 0 is parametric");
    test_assert_equal(tool->num_alternates, 0x40, "ipmc tool 0 num alternates");
    uint8_t specific_tool_id_0[] = {
        0x01, 0x23, 0x45, 0x67, 0x89, 0x9A, 0xBC, 0xDE, // specific tool ID (64)
        0xF0, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, // specific tool ID (64)
    };
    test_assert_equal(memcmp(tool->specific_tool_id, specific_tool_id_0, 16), 0, "ipmc tool 0 specific tool id");
    test_assert_equal(strcmp(tool->tool_param_desc, "tool param desc"), 0, "ipmc tool 0 tool param description");
    test_assert_equal(tool->num_urls, 3, "ipmc tool 0 urls");
    test_assert_equal(strcmp(tool->tool_urls[0], "url 1"), 0, "ipmc tool 0 url 0");
    test_assert_equal(strcmp(tool->tool_urls[1], "url 2"), 0, "ipmc tool 0 url 1");
    test_assert_equal(strcmp(tool->tool_urls[2], "url 3"), 0, "ipmc tool 0 url 2");

    tool = &ipmc->tool_list.ipmp_tools[1];
    uint8_t tool_id_1[] = {
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (64)
        0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, // IPMP Tool Id (128)
    };
    test_assert_equal(memcmp(tool->tool_id, tool_id_1, 16), 0, "ipmc tool 1 tool id");
    test_assert_equal(tool->is_alt_group, 0, "ipmc tool 1 is alt group");
    test_assert_equal(tool->is_parametric, 1, "ipmc tool 1 is parametric");
    test_assert_equal(tool->num_alternates, 0x00, "ipmc tool 1 num alternates");
    uint8_t specific_tool_id_1[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    test_assert_equal(memcmp(tool->specific_tool_id, specific_tool_id_1, 16), 0, "ipmc ool 1 specific tool id");
    test_assert_equal(strcmp(tool->tool_param_desc, "tool param"), 0, "ipmc tool 1 tool param description");
    test_assert_equal(tool->num_urls, 1, "ipmc tool 1 urls");
    test_assert_equal(strcmp(tool->tool_urls[0], "url"), 0, "ipmc tool 1 url 0");

    test_assert_equal(ipmc->ipmp_descriptors_len, 0x02, "ipmc descriptors length");
    uint8_t descriptors[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, };
    test_assert_equal(memcmp(ipmc->ipmp_descriptors, descriptors, 8), 0, "ipmc descriptor data");

    // Item Reference Box
    ItemReferenceBox *iref_box = box->item_refs;
    test_assert_equal(strncmp(iref_box->box.type, "iref", 4), 0, "type");
    test_assert_equal(iref_box->box.version, 0x00, "version");
    test_assert_equal(iref_box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(iref_box->references_count, 3, "references count");

    // Item Data Box
    ItemDataBox *idat_box = box->item_data;
    test_assert_equal(strncmp(idat_box->box.type, "idat", 4), 0, "type");
    test_assert(idat_box->data != NULL, "data");
    test_assert_equal(idat_box->data_size, 8, "data size");
    test_assert_equal(idat_box->data[0], 0x01, "data[0]");
    test_assert_equal(idat_box->data[7], 0x08, "data[7]");

    test_assert_equal(box->other_boxes_len, 2, "ipmc other boxes length");
    test_assert(NULL != box->other_boxes, "ipmc other boxes length");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_movie_header(void)
{
    test_start("test_parse_box_movie_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x6C,
        'm', 'v', 'h', 'd',
        0x00, // version, 0 = 32 bit values
        0xDE, 0xAD, 0xBE, // flags
        0x01, 0x02, 0x03, 0x04, // creation time
        0x05, 0x06, 0x07, 0x08, // modification time
        0x09, 0x0A, 0x0B, 0x0C, // timescale
        0x0D, 0x0E, 0x0F, 0x10, // duration
        0x00, 0x01, 0x00, 0x00, // rate
        0x01, 0x00, // volume
        0x00, 0x00, // reserved
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x12, 0x34, 0x56, 0x78, // Matrix 0
        0x90, 0xAB, 0xCD, 0xEF, // Matrix 1
        0x00, 0x11, 0x22, 0x33, // Matrix 2
        0x44, 0x55, 0x66, 0x77, // Matrix 3
        0x88, 0x99, 0xAA, 0xBB, // Matrix 4
        0xCC, 0xDD, 0xEE, 0xFF, // Matrix 5
        0xFE, 0xDC, 0xBA, 0x98, // Matrix 6
        0x76, 0x54, 0x32, 0x10, // Matrix 7
        0xFF, 0xEE, 0xDD, 0xCC, // Matrix 8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // predefined
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // predefined
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // predefined
        0x11, 0x11, 0x22, 0x22, // next track id
    };

    BMFFCode res;
    MovieHeaderBox *box = NULL;
    res = _bmff_parse_box_movie_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "mvhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xDEADBE, "flags");
    test_assert_equal(box->creation_time, 0x01020304, "creation time");
    test_assert_equal(box->modification_time, 0x05060708, "modification time");
    test_assert_equal(box->timescale, 0x090A0B0C, "timescale");
    test_assert_equal(box->duration, 0x0D0E0F10, "duration");
    test_assert_equal_f32(box->rate, 1.f, "rate");
    test_assert_equal_f32(box->volume, 1.f, "volume");
    test_assert_equal(box->matrix[0], 0x12345678, "matrix 0");
    test_assert_equal(box->matrix[1], 0x90ABCDEF, "matrix 1");
    test_assert_equal(box->matrix[2], 0x00112233, "matrix 2");
    test_assert_equal(box->matrix[3], 0x44556677, "matrix 3");
    test_assert_equal(box->matrix[4], 0x8899AABB, "matrix 4");
    test_assert_equal(box->matrix[5], 0xCCDDEEFF, "matrix 5");
    test_assert_equal(box->matrix[6], 0xFEDCBA98, "matrix 6");
    test_assert_equal(box->matrix[7], 0x76543210, "matrix 7");
    test_assert_equal(box->matrix[8], 0xFFEEDDCC, "matrix 8");
    test_assert_equal(box->next_track_id, 0x11112222, "next track id");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_movie_fragment_header(void)
{
    test_start("test_parse_box_movie_fragment_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x10,
        'm', 'f', 'h', 'd',
        0x00, // version
        0x3F, 0x11, 0xF3, // flags
        0x10, 0x10, 0x10, 0x2F, // sequence number
    };

    BMFFCode res;
    MovieFragmentHeaderBox *box = NULL;
    res = _bmff_parse_box_movie_fragment_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "mfhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x3F11F3, "flags");
    test_assert_equal(box->sequence_number, 0x1010102F, "sequence number");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_fragment_random_access(void)
{
    test_start("test_parse_box_track_fragment_random_access");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x48,
        't', 'f', 'r', 'a',
        0x01, // version
        0xFE, 0xDC, 0xBA, // flags
        0x01, 0x02, 0x03, 0x04, // track id
        0x00, 0x00, 0x00, // reserver (24)
        0b00111000, // reserved (2), lengths of trak, trun, sample (2,2,2)
        0x00, 0x00, 0x00, 0x02, // num of entries
        // entry 1
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // time
        0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x1F, // moof offset
        0xFE, 0xDC, 0xBA, 0x98, // traf number
        0x12, 0x23, 0x45, // trun number
        0x91, // sample number
        // entry 2
        0x19, 0x21, 0x32, 0x43, 0x54, 0x65, 0x76, 0x87, // time
        0x92, 0x83, 0x74, 0x65, 0x56, 0x47, 0x38, 0x29, // moof offset
        0xCD, 0xEF, 0xAB, 0x35, // traf number
        0x62, 0xC7, 0xDE, // trun number
        0xE5, // sample number
    };

    BMFFCode res;
    TrackFragmentRandomAccessBox *box = NULL;
    res = _bmff_parse_box_track_fragment_random_access(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "tfra", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xFEDCBA, "flags");
    test_assert_equal(box->track_id, 0x01020304, "track id");
    test_assert_equal(box->length_size_of_traf_num, 3, "length of traf");
    test_assert_equal(box->length_size_of_trun_num, 2, "length of trun");
    test_assert_equal(box->length_size_of_sample_num, 0, "length of sample");
    test_assert_equal(box->number_of_entry, 2, "number of entries");
    test_assert_equal_uint64(box->entries[0].entry_time, 0x0102030405060708ULL, "entry 0 time");
    test_assert_equal_uint64(box->entries[0].moof_offset, 0x090A0B0C0D0E0F1FULL, "entry 0 moof offset");
    test_assert_equal(box->entries[0].traf_number, 0xFEDCBA98, "entry 0 traf number");
    test_assert_equal(box->entries[0].trun_number, 0x122345, "entry 0 trun number");
    test_assert_equal(box->entries[0].sample_number, 0x91, "entry 0 sample number");
    test_assert_equal_uint64(box->entries[1].entry_time, 0x1921324354657687ULL, "entry 1 time");
    test_assert_equal_uint64(box->entries[1].moof_offset, 0x9283746556473829ULL, "entry 1 moof offset");
    test_assert_equal(box->entries[1].traf_number, 0xCDEFAB35, "entry 1 traf number");
    test_assert_equal(box->entries[1].trun_number, 0x62C7DE, "entry 1 trun number");
    test_assert_equal(box->entries[1].sample_number, 0xE5, "entry 1 sample number");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_movie_fragment_random_access_offset(void)
{
    test_start("test_parse_box_movie_fragment_random_access_offset");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x10,
        'm', 'f', 'r', 'o',
        0xE3, // version
        0xF1, 0x0F, 0xBA, // flags
        0x5B, 0x32, 0xE1, 0x0A,
    };

    BMFFCode res;
    MovieFragmentRandomAccessOffsetBox *box = NULL;
    res = _bmff_parse_box_movie_fragment_random_access_offset(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "mfro", 4), 0, "type");
    test_assert_equal(box->box.version, 0xE3, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->size, 0x5B32E10A, "size");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_xml(void)
{
    test_start("test_parse_box_xml");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1C,
        'x', 'm', 'l', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        '<','x','m','l','>','d','a','t','a','<','/','x','m','l','>',0x00,
    };

    BMFFCode res;
    XMLBox *box = NULL;
    res = _bmff_parse_box_xml(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "xml ", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strcmp(box->data, "<xml>data</xml>"), 0, "xml data");
    test_assert_equal(box->data_len, 16, "data length");

    uint8_t data2[] = {
        0, 0, 0, 0x1C,
        'b', 'x', 'm', 'l',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        '<','x','m','l','>','d','a','t','a','<','/','x','m','l','>',0x00,
    };

    box = NULL;
    res = _bmff_parse_box_xml(&ctx, data2, sizeof(data2), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "bxml success");
    test_assert(box != NULL, "bxml NULL box reference");
    test_assert_equal(box->box.size, sizeof(data2), "bxml size");
    test_assert_equal(strncmp(box->box.type, "bxml ", 4), 0, "bxml type");
    test_assert_equal(box->box.version, 0x00, "bxml version");
    test_assert_equal(box->box.flags, 0xF10FBA, "bxml flags");
    test_assert_equal(strcmp(box->data, "<xml>data</xml>"), 0, "bxml xml data");
    test_assert_equal(box->data_len, 16, "bxml data length");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_header(void)
{
    test_start("test_parse_box_track_hedaer");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x68,
        't', 'k', 'h', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, // creation time
        0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, // modification time
        0xA1, 0xB2, 0xC3, 0xD4, // track Id
        0x00, 0x00, 0x00, 0x00, // reserved
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x7A, 0x8B, // duration
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x00, 0x00, 0x00, // reserved
        0xAA, 0xBB, // layer
        0xCC, 0xDD, // alternate group
        0x01, 0x00, // volume
        0x00, 0x00, // resered
        0x00, 0x01, 0x00, 0x01, // matrix 0
        0x00, 0x00, 0x00, 0x02, // matrix 1
        0x00, 0x00, 0x00, 0x03, // matrix 2
        0x00, 0x00, 0x00, 0x04, // matrix 3
        0x00, 0x01, 0x00, 0x05, // matrix 4
        0x00, 0x00, 0x00, 0x06, // matrix 5
        0x00, 0x00, 0x00, 0x07, // matrix 6
        0x00, 0x00, 0x00, 0x08, // matrix 7
        0x40, 0x00, 0x00, 0x09, // matrix 8
        0x11, 0x22, 0x33, 0x44, // width
        0x55, 0x66, 0x77, 0x88, // height
    };

    BMFFCode res;
    TrackHeaderBox *box = NULL;
    res = _bmff_parse_box_track_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "tkhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal_uint64(box->creation_time, 0x1020304050607080ULL, "creation time");
    test_assert_equal_uint64(box->modification_time, 0xF1F2F3F4F5F6F7F8ULL, "modification time");
    test_assert_equal(box->track_id, 0xA1B2C3D4, "track id");
    test_assert_equal_uint64(box->duration, 0x1A2B3C4D5E6F7A8B, "duration");
    test_assert_equal(box->layer, (int16_t)0xAABB, "layer");
    test_assert_equal(box->alternate_group, (int16_t)0xCCDD, "alternate group");
    test_assert_equal_f32(box->volume, 1.f, "volume");
    test_assert_equal(box->matrix[0], 0x00010001, "matrix 0");
    test_assert_equal(box->matrix[1], 0x00000002, "matrix 1");
    test_assert_equal(box->matrix[2], 0x00000003, "matrix 2");
    test_assert_equal(box->matrix[3], 0x00000004, "matrix 3");
    test_assert_equal(box->matrix[4], 0x00010005, "matrix 4");
    test_assert_equal(box->matrix[5], 0x00000006, "matrix 5");
    test_assert_equal(box->matrix[6], 0x00000007, "matrix 6");
    test_assert_equal(box->matrix[7], 0x00000008, "matrix 7");
    test_assert_equal(box->matrix[8], 0x40000009, "matrix 8");
    test_assert_equal(box->width, 0x11223344, "width");
    test_assert_equal(box->height, 0x55667788, "height");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_movie_extends_header(void)
{
    test_start("test_parse_box_movie_extends_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x14,
        'm', 'e', 'h', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x8, // fragment duration
    };

    BMFFCode res;
    MovieExtendsHeaderBox *box = NULL;
    res = _bmff_parse_box_movie_extends_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "mehd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal_uint64(box->fragment_duration, 0x0102030405060708ULL, "fragment duration");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_extends(void)
{
    test_start("test_parse_box_track_extends");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        't', 'r', 'e', 'x',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x01, 0x02, 0x03, 0x04, // track ID
        0xFF, 0xEE, 0xDD, 0xCC, // default sample description index
        0x10, 0x20, 0x30, 0x40, // default sample duration
        0x1A, 0x2B, 0x3C, 0x4D, // default sample size
        // flags
        0b00000101, // reserved (4), is leading (2), sample depends on (2)
        0b10001011, // sample is depended on (2), sample has redundancy (2), sample padding (3), sample is difference sample (1) 
        0xF3, 0xF4, // sample degradation priority
    };

    BMFFCode res;
    TrackExtendsBox *box = NULL;
    res = _bmff_parse_box_track_extends(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "trex", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->default_sample_is_leading, eBooleanTrue, "sample is leading");
    test_assert_equal(box->default_sample_depends_on, eBooleanTrue, "sample depends on");
    test_assert_equal(box->default_sample_is_depended_on, eBooleanFalse, "sample is depended on");
    test_assert_equal(box->default_sample_has_redundancy, eBooleanUnknown, "sample has redundancy");
    test_assert_equal(box->default_sample_padding_value, 5, "sample padding value");
    test_assert_equal(box->default_sample_is_difference_sample, eBooleanTrue, "sample is difference sample");
    test_assert_equal(box->default_sample_degradation_priority, 0xF3F4, "sample degradation priority");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_fragment_header(void)
{
    test_start("test_parse_box_track_fragment_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        't', 'f', 'h', 'd',
        0x00, // version
        0x01, 0x00, 0x3B, // flags (all of the below)
        0xA1, 0xB2, 0xC3, 0xD4, // track id
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // base data offset
        0xFF, 0xEE, 0xDD, 0xCC, // sample description index
        0xAA, 0xBB, 0xCC, 0xDD, // default sample duration
        0x12, 0x34, 0x56, 0x78, // default sample size
        0x11, 0x22, 0x33, 0x44, // default sample flags
    };

    BMFFCode res;
    TrackFragmentHeaderBox *box = NULL;
    res = _bmff_parse_box_track_fragment_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "tfhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x01003B, "flags value");

    eTrackHeaderBoxFlags flags = eTfhdBaseDataOffsetPresent;
    flags |= eTfhdDefaultSampleDurationPresent;
    flags |= eTfhdDefaultSampleFlagsPresent;
    flags |= eTfhdDefaultSampleSizePresent;
    flags |= eTfhdSampleDescIdxPresent;
    flags |= eTfhdDurationIsEmpty;

    test_assert_equal(box->box.flags, (uint32_t)flags, "flags");
    test_assert_equal(box->track_id, 0xA1B2C3D4, "track id");
    test_assert_equal_uint64(box->base_data_offset, 0x0102030405060708ULL, "base data offset");
    test_assert_equal(box->sample_description_index, 0xFFEEDDCC, "sample description index");
    test_assert_equal(box->default_sample_duration, 0xAABBCCDD, "default sample duration");
    test_assert_equal(box->default_sample_size, 0x12345678, "defaut sample size");
    test_assert_equal(box->default_sample_flags, 0x11223344, "default sample flags");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_run(void)
{
    test_start("test_parse_box_track_run");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x48,
        't', 'r', 'u', 'n',
        0x00, // version
        0x00, 0x0F, 0x05, // flags
        0x00, 0x00, 0x00, 0x03, // sample count
        0x12, 0x34, 0x56, 0x78, // data offset
        0xA1, 0xB2, 0xC3, 0xD4, // first sample flags
        // sample 0
        0x01, 0x02, 0x03, 0x04, // duration
        0x05, 0x06, 0x07, 0x08, // size
        0x09, 0x0A, 0x0B, 0x0C, // flags
        0x0D, 0x0E, 0x0F, 0x00, // composition time offset
        // sample 1
        0x11, 0x12, 0x13, 0x14, // duration
        0x15, 0x16, 0x17, 0x18, // size
        0x19, 0x1A, 0x1B, 0x1C, // flags
        0x1D, 0x1E, 0x1F, 0x10, // composition time offset
        // sample 2
        0x21, 0x22, 0x23, 0x24, // duration
        0x25, 0x26, 0x27, 0x28, // size
        0x29, 0x2A, 0x2B, 0x2C, // flags
        0x2D, 0x2E, 0x2F, 0x20, // composition time offset
    };

    BMFFCode res;
    TrackRunBox *box = NULL;
    res = _bmff_parse_box_track_run(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "trun", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000F05, "flags");
    test_assert_equal(box->sample_count, 0x03, "sample count");
    test_assert_equal(box->data_offset, 0x12345678, "data offset");
    test_assert_equal(box->first_sample_flags, 0xA1B2C3D4, "first sample flags");

    TrackRunSample *sample = &box->samples[0];
    test_assert_equal(sample->duration, 0x01020304, "sample 0 duration");
    test_assert_equal(sample->size, 0x05060708, "sample 0 size");
    test_assert_equal(sample->flags, 0x090A0B0C, "sample 0 flags");
    test_assert_equal(sample->composition_time_offset, 0x0D0E0F00, "sample 0 composition time offset");

    sample = &box->samples[1];
    test_assert_equal(sample->duration, 0x11121314, "sample 1 duration");
    test_assert_equal(sample->size, 0x15161718, "sample 1 size");
    test_assert_equal(sample->flags, 0x191A1B1C, "sample 1 flags");
    test_assert_equal(sample->composition_time_offset, 0x1D1E1F10, "sample 1 composition time offset");

    sample = &box->samples[2];
    test_assert_equal(sample->duration, 0x21222324, "sample 2 duration");
    test_assert_equal(sample->size, 0x25262728, "sample 2 size");
    test_assert_equal(sample->flags, 0x292A2B2C, "sample 2 flags");
    test_assert_equal(sample->composition_time_offset, 0x2D2E2F20, "sample 2 composition time offset");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_dependency_type(void)
{
    test_start("test_parse_box_sample_dependency_type");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x10,
        's', 'd', 't', 'p',
        0x00, // version
        0xB0, 0xC0, 0xD0, // flags
        // samples 1-4
        0x00, 0x55, 0xAA, 0xC6,
    };

    ctx.sample_count = 4;

    BMFFCode res;
    SampleDependencyTypeBox *box = NULL;
    res = _bmff_parse_box_sample_dependency_type(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "sdtp", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xB0C0D0, "flags");

    SampleDependencyType *sample = &box->samples[0];
    test_assert_equal(sample->is_leading, eBooleanUnknown, "sample 0 is leading");
    test_assert_equal(sample->depends_on, eBooleanUnknown, "sample 0 depends on");
    test_assert_equal(sample->is_depended_on, eBooleanUnknown, "sample 0 is depended on");
    test_assert_equal(sample->has_redundancy, eBooleanUnknown, "sample 0 has redundancy");

    sample = &box->samples[1];
    test_assert_equal(sample->is_leading, eBooleanTrue, "sample 0 is leading");
    test_assert_equal(sample->depends_on, eBooleanTrue, "sample 1 depends on");
    test_assert_equal(sample->is_depended_on, eBooleanTrue, "sample 1 is depended on");
    test_assert_equal(sample->has_redundancy, eBooleanTrue, "sample 1 has redundancy");

    sample = &box->samples[2];
    test_assert_equal(sample->is_leading, eBooleanFalse, "sample 0 is leading");
    test_assert_equal(sample->depends_on, eBooleanFalse, "sample 2 depends on");
    test_assert_equal(sample->is_depended_on, eBooleanFalse, "sample 2 is depended on");
    test_assert_equal(sample->has_redundancy, eBooleanFalse, "sample 2 has redundancy");

    sample = &box->samples[3];
    test_assert_equal(sample->is_leading, eBooleanOther, "sample 0 is leading");
    test_assert_equal(sample->depends_on, eBooleanUnknown, "sample 3 depends on");
    test_assert_equal(sample->is_depended_on, eBooleanTrue, "sample 3 is depended on");
    test_assert_equal(sample->has_redundancy, eBooleanFalse, "sample 3 has redundancy");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_to_group(void)
{
    test_start("test_parse_box_sample_to_group");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x30,
        's', 'b', 'g', 'p',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // grouping type
        0x9A, 0xBC, 0xDE, 0xF0, // grouping type param
        0x00, 0x00, 0x00, 0x03, // entry count
        // entry 0
        0x01, 0x02, 0x03, 0x04, // sample count
        0x05, 0x06, 0x07, 0x08, // group description index
        // entry 1  
        0x11, 0x12, 0x13, 0x14, // sample count
        0x15, 0x16, 0x17, 0x18, // group description index
        // entry 2
        0x21, 0x22, 0x23, 0x24, // sample count
        0x25, 0x26, 0x27, 0x28, // group description index
    };

    BMFFCode res;
    SampleToGroupBox *box = NULL;
    res = _bmff_parse_box_sample_to_group(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "sbgp", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->grouping_type, 0x12345678, "grouping type");
    test_assert_equal(box->grouping_type_param, 0x9ABCDEF0, "grouping type param");
    test_assert_equal(box->entry_count, 0x03, "entry count");

    SampleToGroupEntry *entry = &box->entries[0];
    test_assert_equal(entry->sample_count, 0x01020304, "entry 0 sample count");
    test_assert_equal(entry->group_description_index, 0x05060708, "entry 0 description index");

    entry = &box->entries[1];
    test_assert_equal(entry->sample_count, 0x11121314, "entry 1 sample count");
    test_assert_equal(entry->group_description_index, 0x15161718, "entry 1 description index");

    entry = &box->entries[2];
    test_assert_equal(entry->sample_count, 0x21222324, "entry 2 sample count");
    test_assert_equal(entry->group_description_index, 0x25262728, "entry 2 description index");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sub_sample_information(void)
{
    test_start("test_parse_box_sub_sample_information");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x42,
        's', 'u', 'b', 's',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x03, // entry count
        // entry 0
        0x01, 0x02, 0x03, 0x04, // sample delta
        0x00, 0x03, // sub sample count
        // entry 0 - subsample 0
        0x0A, 0x0B, // subsample size
        0x0C, // subsample priority
        0x01, // discardable
        0x01, 0x02, 0x03, 0x04, // codec specific params
        // entry 0 - subsample 1
        0x1A, 0x1B, // subsample size
        0x1C, // subsample priority
        0x00, // discardable
        0x10, 0x20, 0x30, 0x40, // codec specific params
        // entry 0 - subsample 2
        0x2A, 0x2B, // subsample size
        0x2C, // subsample priority
        0x01, // discardable
        0x0A, 0x0B, 0x0C, 0x0D, // codec specific params
        // entry 1
        0x11, 0x12, 0x13, 0x14, // sample delta
        0x00, 0x00, // sub sample count
        // entry 2
        0x21, 0x22, 0x23, 0x24, // sample delta
        0x00, 0x01, // sub sample count
        // entry 2 - subsample 0
        0x21, 0x22, // subsample size
        0x23, // subsample priority
        0x01, // discardable
        0x12, 0x34, 0x56, 0x78, // codec specific params
    };

    BMFFCode res;
    SubSampleInformationBox *box = NULL;
    res = _bmff_parse_box_sub_sample_information(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "subs", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 0x03, "entry count");

    SubSampleInformationEntry *entry = &box->entries[0];
    test_assert_equal(entry->sample_delta, 0x01020304, "entry 0 sample delta");
    test_assert_equal(entry->subsample_count, 0x03, "entry 0 subsample count");
    SubSampleInformation *info = &entry->subsamples[0];
    test_assert_equal(info->size, 0x0A0B, "entry 0 subsample 0 - size");
    test_assert_equal(info->priority, 0x0C, "entry 0 subsample 0 - priority");
    test_assert_equal(info->discardable, 0x01, "entry 0 subsample 0 - discardable");
    test_assert_equal(info->codec_specific_params, 0x01020304, "entry 0 subsample 0 - codec specific params");
    info = &entry->subsamples[1];
    test_assert_equal(info->size, 0x1A1B, "entry 0 subsample 1 - size");
    test_assert_equal(info->priority, 0x1C, "entry 0 subsample 1 - priority");
    test_assert_equal(info->discardable, 0x00, "entry 0 subsample 1 - discardable");
    test_assert_equal(info->codec_specific_params, 0x10203040, "entry 0 subsample 1 - codec specific params");
    info = &entry->subsamples[2];
    test_assert_equal(info->size, 0x2A2B, "entry 0 subsample 2 - size");
    test_assert_equal(info->priority, 0x2C, "entry 0 subsample 2 - priority");
    test_assert_equal(info->discardable, 0x01, "entry 0 subsample 2 - discardable");
    test_assert_equal(info->codec_specific_params, 0x0A0B0C0D, "entry 0 subsample 2 - codec specific params");

    entry = &box->entries[1];
    test_assert_equal(entry->sample_delta, 0x11121314, "entry 1 sample delta");
    test_assert_equal(entry->subsample_count, 0x00, "entry 1 subsample count");
    test_assert_equal_ptr((size_t)entry->subsamples, (size_t)NULL, "entry 1 subsamples");

    entry = &box->entries[2];
    test_assert_equal(entry->sample_delta, 0x21222324, "entry 2 sample delta");
    test_assert_equal(entry->subsample_count, 0x01, "entry 2 subsample count");
    info = &entry->subsamples[0];
    test_assert_equal(info->size, 0x2122, "entry 2 subsample 0 - size");
    test_assert_equal(info->priority, 0x23, "entry 2 subsample 0 - priority");
    test_assert_equal(info->discardable, 0x01, "entry 2 subsample 0 - discardable");
    test_assert_equal(info->codec_specific_params, 0x12345678, "entry 2 subsample 0 - codec specific params");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_copyright(void)
{
    test_start("test_parse_box_copyright");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x15,
        'c', 'p', 'r', 't',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x15, 0xC7, // ISO 639-2/T Language code diff (5)[3]. Add 0x60 to get each character.
        'n','o','t','i','c','e','\0', 
    };

    BMFFCode res;
    CopyrightBox *box = NULL;
    res = _bmff_parse_box_copyright(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "cprt", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strncmp(box->language, "eng", 3), 0, "language");
    test_assert_equal(strcmp(box->notice, "notice"), 0, "notice");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_data_entry_url(void)
{
    test_start("test_parse_box_data_entry_url");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x23,
        'u', 'r', 'l', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        'h','t','t','p',':','/','/','w','w','w','.','e','x','a','m','p','l','e','.','c','o','m','\0',
    };

    BMFFCode res;
    DataEntryBox *box = NULL;
    res = _bmff_parse_box_data_entry_url(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "url ", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strcmp(box->location, "http://www.example.com"), 0, "location");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_data_entry_url_zero(void)
{
    test_start("test_parse_box_data_entry_url_zero");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x0C,
        'u', 'r', 'l', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
    };

    BMFFCode res;
    DataEntryBox *box = NULL;
    res = _bmff_parse_box_data_entry_url(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "url ", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert(box->location == NULL, "location");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_data_entry_urn(void)
{
    test_start("test_parse_box_data_entry_urn");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        'u', 'r', 'n', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        'n','a','m','e','\0',
        'h','t','t','p',':','/','/','w','w','w','.','e','x','a','m','p','l','e','.','c','o','m','\0',
    };

    BMFFCode res;
    DataEntryBox *box = NULL;
    res = _bmff_parse_box_data_entry_urn(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "urn ", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strcmp(box->name, "name"), 0, "name");
    test_assert_equal(strcmp(box->location, "http://www.example.com"), 0, "location");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_data_reference(void)
{
    test_start("test_parse_box_data_reference");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x7B,
        'd', 'r', 'e', 'f',
        0x01, // version
        0xAB, 0xCD, 0xEF, // flags
        0x00, 0x00, 0x00, 0x03, // entry count

        0, 0, 0, 0x24,
        'u', 'r', 'n', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        '\0', // name
        'h','t','t','p',':','/','/','w','w','w','.','e','x','a','m','p','l','e','.','c','o','m','\0',

        0, 0, 0, 0x1F,
        'u', 'r', 'l', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        'h','t','t','p',':','/','/','w','w','w','.','u','r','l','.','c','o','m','\0',

        0, 0, 0, 0x28,
        'u', 'r', 'n', ' ',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        'u','r','n',' ','n','a','m','e','\0', // name
        'h','t','t','p',':','/','/','w','w','w','.','u','r','n','.','c','o','m','\0',
    };

    BMFFCode res;
    DataReferenceBox *box = NULL;
    res = _bmff_parse_box_data_reference(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "dref", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xABCDEF, "flags");
    test_assert_equal(box->entry_count, 0x03, "entry count");

    DataEntryBox *entry = box->data_entries[0];
    test_assert(entry != NULL, "data entry 0 NULL box reference");
    test_assert_equal(entry->box.size, 0x24, "data entry 0 size");
    test_assert_equal(strncmp(entry->box.type, "urn ", 4), 0, "data entry 0 type");
    test_assert_equal(entry->box.version, 0x01, "data entry 0 version");
    test_assert_equal(entry->box.flags, 0xABCDEF, "data entry 0 flags");
    test_assert_equal(entry->name[0], 0, "data entry 0 name");
    test_assert_equal(strcmp(entry->location, "http://www.example.com"), 0, "data entry 0 location");

    entry = box->data_entries[1];
    test_assert(entry != NULL, "data entry 1 NULL box reference");
    test_assert_equal(entry->box.size, 0x1F, "data entry 1 size");
    test_assert_equal(strncmp(entry->box.type, "url ", 4), 0, "data entry 1 type");
    test_assert_equal(entry->box.version, 0x01, "data entry 1 version");
    test_assert_equal(entry->box.flags, 0xABCDEF, "data entry 1 flags");
    test_assert(entry->name == NULL, "data entry 1 name");
    test_assert_equal(strcmp(entry->location, "http://www.url.com"), 0, "data entry 1 location");

    entry = box->data_entries[2];
    test_assert(entry != NULL, "data entry 2 NULL box reference");
    test_assert_equal(entry->box.size, 0x28, "data entry 2 size");
    test_assert_equal(strncmp(entry->box.type, "urn ", 4), 0, "data entry 2 type");
    test_assert_equal(entry->box.version, 0x01, "data entry 2 version");
    test_assert_equal(entry->box.flags, 0xABCDEF, "data entry 2 flags");
    test_assert_equal(strcmp(entry->name, "urn name"), 0, "data entry 2 name");
    test_assert_equal(strcmp(entry->location, "http://www.urn.com"), 0, "data entry 2 location");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_edit_list(void)
{
    test_start("test_parse_box_edit_list");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        'e', 'l', 's', 't',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // entry count

        0x11, 0x22, 0x33, 0x44, // segment duration
        0x55, 0x66, 0x77, 0x88, // media time
        0xAA, 0xBB, // media rate integer
        0xCC, 0xDD, // media rate fraction
        
        0x41, 0x32, 0x23, 0x14, // segment duration
        0x85, 0x76, 0x67, 0x58, // media time
        0xA1, 0xB2, // media rate integer
        0xC3, 0xD4, // media rate fraction
    };

    BMFFCode res;
    EditListBox *box = NULL;
    res = _bmff_parse_box_edit_list(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "elst", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 2, "entry count");

    EditEntry *entry = &box->entries[0];
    test_assert_equal(entry->segment_duration, 0x11223344, "entry 0 segment duration");
    test_assert_equal(entry->media_time, 0x55667788, "entry 0 media time");
    test_assert_equal(entry->media_rate_integer, (int16_t)0xAABB, "entry 0 media rate integer");
    test_assert_equal(entry->media_rate_fraction, (int16_t)0xCCDD, "entry 0 media rate fraction");

    entry = &box->entries[1];
    test_assert_equal(entry->segment_duration, 0x41322314, "entry 1 segment duration");
    test_assert_equal(entry->media_time, 0x85766758, "entry 1 media time");
    test_assert_equal(entry->media_rate_integer, (int16_t)0xA1B2, "entry 1 media rate integer");
    test_assert_equal(entry->media_rate_fraction, (int16_t)0xC3D4, "entry 1 media rate fraction");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_media_header(void)
{
    test_start("test_parse_box_media_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x2C,
        'm', 'd', 'h', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, // creation time
        0x0F, 0xED, 0xCB, 0xA9, 0x87, 0x65, 0x43, 0x21, // modification time
        0x11, 0x22, 0x33, 0x44, // timescale
        0xAA, 0xBB, 0xCC, 0xDD, 0x55, 0x66, 0x77, 0x88, // duration
        0x15, 0xC7, // ISO 639-2/T Language code diff (5)[3]. Add 0x60 to get each character.
        0x00, 0x00, // predefined
    };

    BMFFCode res;
    MediaHeaderBox *box = NULL;
    res = _bmff_parse_box_media_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "mdhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal_uint64(box->creation_time, 0x123456789ABCDEF0ULL, "creation time");
    test_assert_equal_uint64(box->modification_time, 0x0FEDCBA987654321ULL, "modification time");
    test_assert_equal(box->timescale, 0x11223344, "timescale");
    test_assert_equal_uint64(box->duration, 0xAABBCCDD55667788ULL, "duration");
    test_assert_equal(strncmp(box->language, "eng", 3), 0, "language");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_video_media_header(void)
{
    test_start("test_parse_box_video_media_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x14,
        'v', 'm', 'h', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, // graphics mode
        0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, // op color
    };

    BMFFCode res;
    VideoMediaHeaderBox *box = NULL;
    res = _bmff_parse_box_video_media_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "vmhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->graphics_mode, 0x1234, "graphics mode");
    test_assert_equal(box->op_color[0], 0xFEDC, "op color[0]");
    test_assert_equal(box->op_color[1], 0xBA98, "op color[1]");
    test_assert_equal(box->op_color[2], 0x7654, "op color[2]");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sound_media_header(void)
{
    test_start("test_parse_box_sound_media_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x0E,
        's', 'm', 'h', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0xFF, 0x00, // balance
    };

    BMFFCode res;
    SoundMediaHeaderBox *box = NULL;
    res = _bmff_parse_box_sound_media_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "smhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->balance, -1.f, "balance");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_hint_media_header(void)
{
    test_start("test_parse_box_hint_media_header");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1C,
        'h', 'm', 'h', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, // max pdu size
        0xAB, 0xCD, // avg pdu size
        0x11, 0x22, 0x33, 0x44, // max bitrate
        0xAA, 0xBB, 0xCC, 0xDD, // avg bitrate
        0x00, 0x00, 0x00, 0x00, // reserved
    };

    BMFFCode res;
    HintMediaHeaderBox *box = NULL;
    res = _bmff_parse_box_hint_media_header(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "hmhd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->max_pdu_size, 0x1234, "max pdu size");
    test_assert_equal(box->avg_pdu_size, 0xABCD, "avg pdu size");
    test_assert_equal(box->max_bitrate, 0x11223344, "max bitrate");
    test_assert_equal(box->avg_bitrate, 0xAABBCCDD, "avg bitrate");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_description_soun(void)
{
    test_start("test_parse_box_sample_description_soun");

    BMFFContext ctx;
    bmff_context_init(&ctx);
    uint8_t data[] = {
        0, 0, 0x01, 0x1A,
        's', 't', 's', 'd',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x03, // entry count

        // soun sample entry
        0x00, 0x00, 0x00, 0x48, // size
        's','o','u','n', // coding name
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x12, 0x34, // data reference index
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x02, // channel count
        0x00, 0x10, // samplesize
        0x00, 0x00, // pre defined
        0x00, 0x00, // reserved
        0x10, 0x20, 0x30, 0x40, // sample rate
        // sample rate box
        0x00, 0x00, 0x00, 0x10,
        's','r','a','t',
        0x00, 0x00, 0x00, 0x00, // version and flags
        0x12, 0x34, 0x56, 0x78, // sample rate
        // channel layout box
        0x00, 0x00, 0x00, 0x14,
        'c','h','n','l',
        0x00, 0x00, 0x00, 0x00, // version and flags
        0x03, // stream structure
        0x00, // defined layout
        0x7E, // speaker position 0
        0x10, 0x20, // azimuth
        0xFA, // elevation
        0x22, // speaker position 1
        0x11, // object count

        // soun sample entry
        0x00, 0x00, 0x00, 0x48, // size
        's','o','u','n', // coding name
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0xAB, 0xCD, // data reference index
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x06, // channel count
        0x01, 0x23, // samplesize
        0x00, 0x00, // pre defined
        0x00, 0x00, // reserved
        0xA0, 0xB0, 0xC0, 0xD0, // sample rate
        // sample rate box
        0x00, 0x00, 0x00, 0x10,
        's','r','a','t',
        0x00, 0x00, 0x00, 0x00, // version and flags
        0x12, 0x34, 0x56, 0x78, // sample rate
        // channel layout box
        0x00, 0x00, 0x00, 0x14,
        'c','h','n','l',
        0x00, 0x00, 0x00, 0x00, // version and flags
        0x01, // stream structure
        0x00, // defined layout
        0x01, // speaker position 0
        0x02, // speaker position 1
        0x03, // speaker position 2
        0x04, // speaker position 3
        0x05, // speaker position 4
        0x06, // speaker position 5

        // Incomplete soun sample entry
        0x00, 0x00, 0x00, 0x7A, // size
        'i','c','p','a', // coding name
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0xAB, 0xCD, // data reference index
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x00, 0x00, 0x00, // reserved
        0x00, 0x00, // channel count
        0x01, 0x23, // samplesize
        0x00, 0x00, // pre defined
        0x00, 0x00, // reserved
        0xA0, 0xB0, 0xC0, 0xD0, // sample rate
        // sample rate box
        0x00, 0x00, 0x00, 0x10,
        's','r','a','t',
        0x00, 0x00, 0x00, 0x00, // version and flags
        0x12, 0x34, 0x56, 0x78, // sample rate
        // channel layout box
        0x00, 0x00, 0x00, 0x0E,
        'c','h','n','l',
        0x00, 0x00, 0x00, 0x00, // version and flags
        0x02, // stream structure
        0xEE, // object count
        // random boxes
        0x00, 0x00, 0x00, 0x0C,
        'a','b','c','d',
        0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x00, 0x00, 0x0C,
        'a','b','c','d',
        0xFF, 0xFF, 0xFF, 0xFF,
        // complete track inf
        0x00, 0x00, 0x00, 0x14,
        'c', 'i', 'n', 'f',
            // orginal format box
            0x00, 0x00, 0x00, 0x0C,
            'f', 'r', 'm', 'a',
            's', 'o', 'u', 'n', // orignal data format
        // "other" boxes
        0x00, 0x00, 0x00, 0x0C,
        'a', 'b', 'c', 'd',
        0xFF, 0xFF, 0xFF, 0xFF
    };

    memcpy(ctx.track_sample_table_handler_type, "soun", 4);
    ctx.sample_description_version = 1;

    BMFFCode res;
    SampleDescriptionBox *box = NULL;
    res = _bmff_parse_box_sample_description(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 3, "entry count");

    AudioSampleEntry *entry = (AudioSampleEntry*) box->entries[0];
    test_assert_equal(entry->box.size, 0x48, "entry 0 size");
    test_assert_equal(strncmp(entry->box.type, "soun", 4), 0, "entry 0 coding name / type");
    test_assert_equal(entry->data_reference_index, 0x1234, "entry 0 data reference index");
    test_assert_equal(entry->channel_count, 2, "entry 0 channel count");
    test_assert_equal(entry->sample_size, 16, "entry 0 sample size");
    test_assert_equal(entry->sample_rate, 0x10203040, "entry 0 sample rate");
    test_assert_equal(strncmp(entry->sampling_rate->box.type, "srat", 4), 0, "entry 1 sampling rate type");
    test_assert_equal(entry->sampling_rate->box.size, 16, "entry 0 sampling rate size");
    test_assert_equal(entry->sampling_rate->sampling_rate, 0x12345678, "entry 0 sampling rate");
    test_assert_equal(entry->channel_layout->box.size, 20, "entry 0 channel layout size");
    test_assert_equal(strncmp(entry->channel_layout->box.type, "chnl", 4), 0, "entry 0 channel layout type");
    test_assert_equal(entry->channel_layout->stream_structure, 3, "entry 0 channel layout stream structure");
    test_assert_equal(entry->channel_layout->channel.defined_layout, 0, "entry 0 channel layout channel defined lauout");
    test_assert_equal(entry->channel_layout->channel.channel_count, 2, "entry 0 channel layout channel count");
    test_assert_equal(entry->channel_layout->channel.speaker_positions[0], 0x7E, "entry 0 channel layout speaker position 0");
    test_assert_equal(entry->channel_layout->channel.azimuths[0], 0x1020, "entry 0 channel layout azimuth 0");
    test_assert_equal(entry->channel_layout->channel.elevations[0], 0xFA, "entry 0 channel layout elevation 0");
    test_assert_equal(entry->channel_layout->channel.speaker_positions[1], 0x22, "entry 0 channel layout speaker position 1");
    test_assert_equal(entry->channel_layout->object.object_count, 0x11, "enrtry 0 channel layout object count");
    test_assert_equal(entry->is_incomplete, eBooleanFalse, "entry 0 is incomplete");
    test_assert_equal(entry->child_count, 0, "entry 0 child count");

    entry = (AudioSampleEntry*) box->entries[1];
    test_assert_equal(entry->box.size, 0x48, "entry 1 size");
    test_assert_equal(strncmp(entry->box.type, "soun", 4), 0, "entry 1 coding name / type");
    test_assert_equal(entry->data_reference_index, 0xABCD, "entry 1 data reference index");
    test_assert_equal(entry->channel_count, 6, "entry 1 channel count");
    test_assert_equal(entry->sample_size, 0x0123, "entry 1 sample size");
    test_assert_equal(entry->sample_rate, 0xA0B0C0D0, "entry 1 sample rate");
    test_assert_equal(strncmp(entry->sampling_rate->box.type, "srat", 4), 0, "entry 1 sampling rate type");
    test_assert_equal(entry->sampling_rate->box.size, 16, "entry 1 sampling rate size");
    test_assert_equal(entry->sampling_rate->sampling_rate, 0x12345678, "entry 1 sampling rate");
    test_assert_equal(entry->channel_layout->box.size, 0x14, "entry 1 channel layout size");
    test_assert_equal(strncmp(entry->channel_layout->box.type, "chnl", 4), 0, "entry 1 channel layout type");
    test_assert_equal(entry->channel_layout->stream_structure, 1, "entry 1 channel layout stream structure");
    test_assert_equal(entry->channel_layout->channel.defined_layout, 0, "entry 1 channel layout channel defined lauout");
    test_assert_equal(entry->channel_layout->channel.channel_count, 6, "entry 1 channel layout channel count");
    test_assert_equal(entry->channel_layout->channel.speaker_positions[0], 1, "entry 1 channel layout speaker position 0");
    test_assert_equal(entry->channel_layout->channel.speaker_positions[5], 6, "entry 1 channel layout speaker position 5");
    test_assert_equal(entry->is_incomplete, eBooleanFalse, "entry 1 is incomplete");
    test_assert_equal(entry->child_count, 0, "entry 1 child count");

    entry = (AudioSampleEntry*) box->entries[2];
    test_assert_equal(entry->box.size, 0x7A, "entry 2 size");
    test_assert_equal(strncmp(entry->box.type, "icpa", 4), 0, "entry 2 coding name / type");
    test_assert_equal(entry->data_reference_index, 0xABCD, "entry 2 data reference index");
    test_assert_equal(entry->channel_count, 0, "entry 2 channel count");
    test_assert_equal(entry->sample_size, 0x0123, "entry 2 sample size");
    test_assert_equal(entry->sample_rate, 0xA0B0C0D0, "entry 2 sample rate");
    test_assert_equal(strncmp(entry->sampling_rate->box.type, "srat", 4), 0, "entry 2 sampling rate type");
    test_assert_equal(entry->sampling_rate->box.size, 16, "entry 2 sampling rate size");
    test_assert_equal(entry->sampling_rate->sampling_rate, 0x12345678, "entry 2 sampling rate");
    test_assert_equal(entry->channel_layout->box.size, 0x0E, "entry 2 channel layout size");
    test_assert_equal(strncmp(entry->channel_layout->box.type, "chnl", 4), 0, "entry 2 channel layout type");
    test_assert_equal(entry->channel_layout->stream_structure, 2, "entry 2 channel layout stream structure");
    test_assert_equal(entry->channel_layout->object.object_count, 0xEE, "entry 2 channel layout object count");
    test_assert_equal(entry->is_incomplete, eBooleanTrue, "entry 2 is incomplete");
    test_assert_equal(entry->child_count, 4, "entry 2 child count");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_description_hint(void)
{
    test_start("test_parse_box_sample_description_hint");

    BMFFContext ctx;
    bmff_context_init(&ctx);
    uint8_t data[] = {
        0, 0, 0, 0xA2,
        's', 't', 's', 'd',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x04, // entry count

        // hint sample entry
        0x00, 0x00, 0x00, 0x20, // size
        'h','i','n','t', // format
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x01, 0x02, // data reference index
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // data
        0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, //data

        0x00, 0x00, 0x00, 0x1B, // size
        'h','i','n','t', // format
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x03, 0x04, // data reference index
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // data
        0x09, 0x0A, 0x0B, // data

        0x00, 0x00, 0x00, 0x44, // size
        'i', 'c', 'p', 'h', // incomplete box
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x0F, 0xFF, // data reference index
        0x01, 0x02, 0x03, 0x04, // data
        // complete track info
        0x00, 0x00, 0x00, 0x14,
        'c', 'i', 'n', 'f',
            // orginal format box
            0x00, 0x00, 0x00, 0x0C,
            'f', 'r', 'm', 'a',
            'h', 'i', 'n', 't', // orignal data format
        // "other" boxes
        0x00, 0x00, 0x00, 0x0C,
        'a', 'b', 'c', 'd',
        0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x00, 0x00, 0x10,
        'a', 'b', 'c', 'd',
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,

        0x00, 0x00, 0x00, 0x13, // size
        'h','i','n','t', // format
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x05, 0x06, // data reference index
        0x01, 0x02, 0x03, // data
    };

    memcpy(ctx.track_sample_table_handler_type, "hint", 4);

    BMFFCode res;
    SampleDescriptionBox *box = NULL;
    res = _bmff_parse_box_sample_description(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 4, "entry count");

    HintSampleEntry *entry = (HintSampleEntry*) box->entries[0];
    test_assert_equal(entry->box.size, 0x20, "entry 0 size");
    test_assert_equal(strncmp(entry->box.type, "hint", 4), 0, "entry 0 format / type");
    test_assert_equal(entry->data_reference_index, 0x0102, "entry 0 data reference index");
    test_assert_equal(entry->data_size, 16, "entry 0 data_size");
    test_assert_equal(entry->data[0], 0x01, "entry 0 data start");
    test_assert_equal(entry->data[15], 0x10, "entry 0 data end");
    test_assert_equal(entry->is_incomplete, eBooleanFalse, "entry 0 is incomplete");

    entry = (HintSampleEntry*) box->entries[1];
    test_assert_equal(entry->box.size, 0x1B, "entry 1 size");
    test_assert_equal(strncmp(entry->box.type, "hint", 4), 0, "entry 1 format / type");
    test_assert_equal(entry->data_reference_index, 0x0304, "entry 1 data reference index");
    test_assert_equal(entry->data_size, 11, "entry 1 data_size");
    test_assert_equal(entry->data[0], 0x01, "entry 1 data start");
    test_assert_equal(entry->data[10], 0x0B, "entry 1 data end");
    test_assert_equal(entry->is_incomplete, eBooleanFalse, "entry 1 is incomplete");

    entry = (HintSampleEntry*) box->entries[2];
    test_assert_equal(entry->box.size, 0x44, "entry 2 size");
    test_assert_equal(strncmp(entry->box.type, "icph", 4), 0, "entry 2 format / type");
    test_assert_equal(entry->is_incomplete, eBooleanTrue, "entry 2 is incomplete");
    test_assert(entry->incomplete_sample == NULL, "incomplete sample is NULL");
    test_assert_equal(entry->data_reference_index, 0x0FFF, "entry 2 data reference index");
    test_assert_equal(entry->data_size, 52, "entry 2 data_size");
    test_assert_equal(entry->data[0], 0x01, "entry 2 data start");
    test_assert_equal(entry->data[51], 0xFF, "entry 2 data end");

    entry = (HintSampleEntry*) box->entries[3];
    test_assert_equal(entry->box.size, 0x13, "entry 3 size");
    test_assert_equal(strncmp(entry->box.type, "hint", 4), 0, "entry 3 format / type");
    test_assert_equal(entry->data_reference_index, 0x0506, "entry 3 data reference index");
    test_assert_equal(entry->data_size, 3, "entry 3 data_size");
    test_assert_equal(entry->data[0], 0x01, "entry 3 data start");
    test_assert_equal(entry->data[2], 0x03, "entry 3 data end");
    test_assert_equal(entry->is_incomplete, eBooleanFalse, "entry 3 is incomplete");
    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_description_vide(void)
{
    test_start("test_parse_box_sample_description_vide");

    BMFFContext ctx;
    bmff_context_init(&ctx);
    uint8_t data[] = {
        0, 0, 0, 0xBC,
        's', 't', 's', 'd',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // entry count

        // vide sample entry
        0x00, 0x00, 0x00, 0x56, // size
        'v','i','d','e', // coding name
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x12, 0x34, // data reference index
        0x00, 0x00, 0x00, 0x00, // pre-defined[2] and reserved[2]
        0x00, 0x00, 0x00, 0x00, // predefined (32)[3]
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x56, 0x78, 0x9A, 0xBC, // width(16), height(16)
        0x00, 0x48, 0x00, 0x00, // horizresolution
        0x00, 0x60, 0x00, 0x00, // vertresolution
        0x00, 0x00, 0x00, 0x00, // reserved
        0xAB, 0xCD, // framecount
        0x0F, 'c', 'o', 'm', 'p', 'r', 'e', 's', 's', 'o', 'r', ' ', 'n', 'a', 'm', 'e', // [16]
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // padding
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x18, // depth
        0xFF, 0xFF, // predefined(16) = -1

        // vide entry
        0x00, 0x00, 0x00, 0x56, // size
        'v','i','d','e', // coding name
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x56, 0x78, // data reference index
        0x00, 0x00, 0x00, 0x00, // pre-defined[2] and reserved[2]
        0x00, 0x00, 0x00, 0x00, // predefined (32)[3]
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0xDE, 0xF1, 0x23, 0x45, // width(16), height(16)
        0x00, 0x60, 0x00, 0x00, // horizresolution
        0x00, 0x48, 0x00, 0x00, // vertresolution
        0x00, 0x00, 0x00, 0x00, // reserved
        0x1A, 0x2B, // framecount
        0x07, 'c', 'o', 'm', 'p', 'r', 'e', 's', // [8]
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // padding
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xED, 0xCB, // depth
        0xFF, 0xFF, // predefined(16) = -1
    };

    memcpy(ctx.track_sample_table_handler_type, "vide", 4);

    BMFFCode res;
    SampleDescriptionBox *box = NULL;
    res = _bmff_parse_box_sample_description(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 2, "entry count");

    VisualSampleEntry *entry = (VisualSampleEntry*) box->entries[0];
    test_assert_equal(entry->box.size, 0x56, "entry 0 size");
    test_assert_equal(strncmp(entry->box.type, "vide", 4), 0, "entry 0 coding name / type");
    test_assert_equal(entry->data_reference_index, 0x1234, "entry 0 data reference index");
    test_assert_equal(entry->width, 0x5678, "entry 0 width");
    test_assert_equal(entry->height, 0x9ABC, "entry 0 height");
    test_assert_equal(entry->horiz_resolution, 72.f, "entry 0 horizontal resolution");
    test_assert_equal(entry->vert_resolution, 96.f, "entry 0 vertical resolution");
    test_assert_equal(entry->frame_count, 0xABCD, "entry 0 frame count");
    test_assert_equal(strcmp("compressor name", entry->compressor_name), 0, "entry 0 compressor name");
    test_assert_equal(entry->depth, 0x18, "entry 0 depth");

    entry = (VisualSampleEntry*) box->entries[1];
    test_assert_equal(entry->box.size, 0x56, "entry 1 size");
    test_assert_equal(strncmp(entry->box.type, "vide", 4), 0, "entry 1 coding name / type");
    test_assert_equal(entry->data_reference_index, 0x5678, "entry 1 data reference index");
    test_assert_equal(entry->width, 0xDEF1, "entry 1 width");
    test_assert_equal(entry->height, 0x2345, "entry 1 height");
    test_assert_equal(entry->horiz_resolution, 96.f, "entry 1 horizontal resolution");
    test_assert_equal(entry->vert_resolution, 72.f, "entry 1 vertical resolution");
    test_assert_equal(entry->frame_count, 0x1A2B, "entry 1 frame count");
    test_assert_equal(strcmp("compres", entry->compressor_name), 0, "entry 1 compressor name");
    test_assert_equal(entry->depth, 0xEDCB, "entry 1 depth");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_description_zero(void)
{
    test_start("test_parse_box_sample_description_zero");

    BMFFContext ctx;
    bmff_context_init(&ctx);
    uint8_t data[] = {
        0, 0, 0, 0x10,
        's', 't', 's', 'd',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x00, // entry count
    };

    memcpy(ctx.track_sample_table_handler_type, "vide", 4);

    BMFFCode res;
    SampleDescriptionBox *box = NULL;
    res = _bmff_parse_box_sample_description(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 0, "entry count");
    test_assert(box->entries == NULL, "entries");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_description_invalid_type(void)
{
    test_start("test_parse_box_sample_description_invalid_type");

    BMFFContext ctx;
    bmff_context_init(&ctx);
    uint8_t data[] = {
        0, 0, 0, 0x4B,
        's', 't', 's', 'd',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // entry count

        // hint sample entry
        0x00, 0x00, 0x00, 0x20, // size
        'h','i','n','t', // format
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x01, 0x02, // data reference index
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // data
        0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, //data

        0x00, 0x00, 0x00, 0x1B, // size
        'h','i','n','t', // format
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // reserved
        0x03, 0x04, // data reference index
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // data
        0x09, 0x0A, 0x0B, // data

    };

    memcpy(ctx.track_sample_table_handler_type, "\0\0\0\0", 4);

    BMFFCode res;
    SampleDescriptionBox *box = NULL;
    res = _bmff_parse_box_sample_description(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 2, "entry count");
    test_assert(box->entries != NULL, "entries");
    test_assert(box->entries[0] != NULL, "entries 0 - not NULL");
    test_assert(box->entries[1] != NULL, "entries 1 - not NULL");

    bmff_context_destroy(&ctx);

    test_end();
}
void test_parse_box_time_to_sample(void)
{
    test_start("test_parse_box_time_to_sample");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        's', 't', 't', 's',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x03, // sample count
        // sample 0
        0x12, 0x34, 0x56, 0x78, // count
        0x9A, 0xBC, 0xDE, 0xF1, // delta
        // sample 1
        0x1A, 0x2B, 0x3C, 0x4D, // count
        0x5E, 0x6F, 0x71, 0x82, // delta
        // sample 2
        0xFF, 0xEE, 0xDD, 0xCC, // count
        0xBB, 0xAA, 0x99, 0x88, // delta
    };

    BMFFCode res;
    TimeToSampleBox *box = NULL;
    res = _bmff_parse_box_time_to_sample(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stts", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->sample_count, 3, "sample count");

    TimeToSample *sample = &box->samples[0];
    test_assert_equal(sample->count, 0x12345678, "sample 0 count");
    test_assert_equal(sample->delta, 0x9ABCDEF1, "sample 0 delta");

    sample = &box->samples[1];
    test_assert_equal(sample->count, 0x1A2B3C4D, "sample 1 count");
    test_assert_equal(sample->delta, 0x5E6F7182, "sample 1 delta");

    sample = &box->samples[2];
    test_assert_equal(sample->count, 0xFFEEDDCC, "sample 2 count");
    test_assert_equal(sample->delta, 0xBBAA9988, "sample 3 delta");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_composition_offset(void)
{
    test_start("test_parse_box_composition_offset");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        'c', 't', 't', 's',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // sample count
        // sample 0
        0x12, 0x34, 0x56, 0x78, // count
        0x9A, 0xBC, 0xDE, 0xF1, // offset
        // sample 1
        0x1A, 0x2B, 0x3C, 0x4D, // count
        0x5E, 0x6F, 0x71, 0x82, // offset
    };

    BMFFCode res;
    CompositionOffsetBox *box = NULL;
    res = _bmff_parse_box_composition_offset(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "ctts", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 2, "entry count");

    CompositionOffset *entry = &box->entries[0];
    test_assert_equal(entry->count, 0x12345678, "entry 0 count");
    test_assert_equal(entry->offset, 0x9ABCDEF1, "entry 0 offset");

    entry = &box->entries[1];
    test_assert_equal(entry->count, 0x1A2B3C4D, "entry 1 count");
    test_assert_equal(entry->offset, 0x5E6F7182, "entry 1 offset");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_to_chunk(void)
{
    test_start("test_parse_box_sample_to_chunk");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        's', 't', 's', 'c',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // sample count
        // sample 0
        0x12, 0x34, 0x56, 0x78, // first chunk
        0x9A, 0xBC, 0xDE, 0xF1, // samples per chunk
        0x1A, 0x2B, 0x3C, 0x4D, // sample description index
        // sample 1
        0x99, 0x88, 0x77, 0x66, // first chunk
        0x55, 0x44, 0x33, 0x22, // samples per chunk
        0x11, 0xFF, 0xEE, 0xDD, // sample description index
    };

    BMFFCode res;
    SampleToChunkBox *box = NULL;
    res = _bmff_parse_box_sample_to_chunk(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsc", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 2, "entry count");

    SampleToChunk *entry = &box->entries[0];
    test_assert_equal(entry->first_chunk, 0x12345678, "entry 0 first chunk");
    test_assert_equal(entry->samples_per_chunk, 0x9ABCDEF1, "entry 0 samples per chunk");
    test_assert_equal(entry->sample_description_index, 0x1A2B3C4D, "entry 0 sample description index");

    entry = &box->entries[1];
    test_assert_equal(entry->first_chunk, 0x99887766, "entry 1 first chunk");
    test_assert_equal(entry->samples_per_chunk, 0x55443322, "entry 1 samples per chunk");
    test_assert_equal(entry->sample_description_index, 0x11FFEEDD, "entry 1 sample description index");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_size(void)
{
    test_start("test_parse_box_sample_size");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        's', 't', 's', 'z',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x00, // sample size
        0x00, 0x00, 0x00, 0x03, // sampe count
        0x00, 0x00, 0x00, 0x10, // entry 0
        0x00, 0x00, 0x01, 0x00, // entry 1
        0x00, 0x00, 0x10, 0x00, // entry 2
    };

    BMFFCode res;
    SampleSizeBox *box = NULL;
    res = _bmff_parse_box_sample_size(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsz", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->sample_size, 0, "sample size");
    test_assert_equal(box->sample_count, 3, "sample count");
    test_assert_equal(box->entry_sizes[0], 0x10, "entry size 0");
    test_assert_equal(box->entry_sizes[1], 0x100, "entry size 1");
    test_assert_equal(box->entry_sizes[2], 0x1000, "entry size 2");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_compact_sample_size_4(void)
{
    test_start("test_parse_box_compact_sample_size_4");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x17,
        's', 't', 'z', '2',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, // reserved
        0x04, // field size
        0x00, 0x00, 0x00, 0x05, // sample count
        0x12, 0x34, 0x5F, // sample entries
    };

    BMFFCode res;
    CompactSampleSizeBox *box = NULL;
    res = _bmff_parse_box_compact_sample_size(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stz2", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->field_size, 4, "field size");
    test_assert_equal(box->sample_count, 5, "sample count");
    test_assert_equal(box->entry_sizes[0], 1, "entry size 0");
    test_assert_equal(box->entry_sizes[1], 2, "entry size 1");
    test_assert_equal(box->entry_sizes[2], 3, "entry size 2");
    test_assert_equal(box->entry_sizes[3], 4, "entry size 3");
    test_assert_equal(box->entry_sizes[4], 5, "entry size 4");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_compact_sample_size_8(void)
{
    test_start("test_parse_box_compact_sample_size_8");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x19,
        's', 't', 'z', '2',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, // reserved
        0x08, // field size
        0x00, 0x00, 0x00, 0x05, // sample count
        0x12, 0x34, 0x56, 0x78, 0x9A, // sample entries
    };

    BMFFCode res;
    CompactSampleSizeBox *box = NULL;
    res = _bmff_parse_box_compact_sample_size(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stz2", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->field_size, 8, "field size");
    test_assert_equal(box->sample_count, 5, "sample count");
    test_assert_equal(box->entry_sizes[0], 0x12, "entry size 0");
    test_assert_equal(box->entry_sizes[1], 0x34, "entry size 1");
    test_assert_equal(box->entry_sizes[2], 0x56, "entry size 2");
    test_assert_equal(box->entry_sizes[3], 0x78, "entry size 3");
    test_assert_equal(box->entry_sizes[4], 0x9A, "entry size 4");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_compact_sample_size_16(void)
{
    test_start("test_parse_box_compact_sample_size_16");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1E,
        's', 't', 'z', '2',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, // reserved
        0x10, // field size
        0x00, 0x00, 0x00, 0x05, // sample count
        0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF1, 0x11, 0x22, // sample entries
    };

    BMFFCode res;
    CompactSampleSizeBox *box = NULL;
    res = _bmff_parse_box_compact_sample_size(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stz2", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->field_size, 16, "field size");
    test_assert_equal(box->sample_count, 5, "sample count");
    test_assert_equal(box->entry_sizes[0], 0x1234, "entry size 0");
    test_assert_equal(box->entry_sizes[1], 0x5678, "entry size 1");
    test_assert_equal(box->entry_sizes[2], 0x9ABC, "entry size 2");
    test_assert_equal(box->entry_sizes[3], 0xDEF1, "entry size 3");
    test_assert_equal(box->entry_sizes[4], 0x1122, "entry size 4");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_chunk_offset(void)
{
    test_start("test_parse_box_chunk_offset");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x24,
        's', 't', 'c', 'o',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x05, // entry count
        0x12, 0x34, 0x56, 0x78, // chunk offsets
        0x9A, 0xBC, 0xDE, 0xF1, 
        0x10, 0x20, 0x30, 0x40,
        0x50, 0x60, 0x70, 0x80,
        0x90, 0xA0, 0xB0, 0xC0,
    };

    BMFFCode res;
    ChunkOffsetBox *box = NULL;
    res = _bmff_parse_box_chunk_offset(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stco", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 5, "entry count");
    test_assert_equal(box->chunk_offsets[0], 0x12345678, "chunk offset 0");
    test_assert_equal(box->chunk_offsets[4], 0x90A0B0C0, "chunk offset 4");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_chunk_large_offset(void)
{
    test_start("test_parse_box_chunk_large_offset");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        'c', 'o', '6', '4',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x03, // entry count
        0x12, 0x34, 0x56, 0x78, // chunk offsets (64 bit)
        0x9A, 0xBC, 0xDE, 0xF1, 
        0x10, 0x20, 0x30, 0x40,
        0x50, 0x60, 0x70, 0x80,
        0xAA, 0xBB, 0xCC, 0xDD,
        0xEE, 0xFF, 0x11, 0x22,
    };

    BMFFCode res;
    ChunkLargeOffsetBox *box = NULL;
    res = _bmff_parse_box_chunk_large_offset(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "co64", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 3, "entry count");
    test_assert_equal_uint64(box->chunk_offsets[0], 0x123456789ABCDEF1ULL, "chunk offset 0");
    test_assert_equal_uint64(box->chunk_offsets[2], 0xAABBCCDDEEFF1122ULL, "chunk offset 2");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sync_sample(void)
{
    test_start("test_parse_box_sync_sample");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        's', 't', 's', 's',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x04, // entry count
        0x12, 0x34, 0x56, 0x78, // chunk offsets
        0x9A, 0xBC, 0xDE, 0xF1, 
        0x10, 0x20, 0x30, 0x40,
        0x50, 0x60, 0x70, 0x80,
    };

    BMFFCode res;
    SyncSampleBox *box = NULL;
    res = _bmff_parse_box_sync_sample(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stss", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 4, "entry count");
    test_assert_equal(box->sample_numbers[0], 0x12345678, "sample number 0");
    test_assert_equal(box->sample_numbers[3], 0x50607080, "sample number 3");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_shadow_sync_sample(void)
{
    test_start("test_parse_box_shadown_sync_sample");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x28,
        's', 't', 's', 'h',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x03, // entry count
        0x12, 0x34, 0x56, 0x78, // shadowed sample number
        0x9A, 0xBC, 0xDE, 0xF1, // sync sample number
        0x10, 0x20, 0x30, 0x40,
        0x50, 0x60, 0x70, 0x80,
        0x90, 0xA0, 0xB0, 0xC0,
        0xD0, 0xE0, 0xF0, 0x10,
    };

    BMFFCode res;
    ShadowSyncSampleBox *box = NULL;
    res = _bmff_parse_box_shadow_sync_sample(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsh", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 3, "entry count");
    ShadowSyncSample *entry = &box->entries[0];
    test_assert_equal(entry->shadowed_sample_number, 0x12345678, "shadowed sample number 0");
    test_assert_equal(entry->sync_sample_number, 0x9ABCDEF1, "sync sample number 0");
    entry = &box->entries[2];
    test_assert_equal(entry->shadowed_sample_number, 0x90A0B0C0, "shadowed sample number 2");
    test_assert_equal(entry->sync_sample_number, 0xD0E0F010, "sync sample number 2");
    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_padding_bits(void)
{
    test_start("test_parse_box_padding_bits");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x12,
        'p', 'a', 'd', 'b',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // sample count
        0b01110010, // padding bits
        0b00010101, // padding bits
    };

    BMFFCode res;
    PaddingBitsBox *box = NULL;
    res = _bmff_parse_box_padding_bits(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "padb", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->sample_count, 2, "sample count");
    test_assert_equal(box->samples[0].pad1, 7, "sample 0 pad1");
    test_assert_equal(box->samples[0].pad2, 2, "sample 0 pad2");
    test_assert_equal(box->samples[1].pad1, 1, "sample 1 pad1");
    test_assert_equal(box->samples[1].pad2, 5, "sample 1 pad2");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_degradation_priority(void)
{
    test_start("test_parse_box_degradation_priority");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x14,
        's', 't', 'd', 'p',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // priorities
        0x9A, 0xBC, 0xDE, 0xF0,
    };

    ctx.sample_count = 4;

    BMFFCode res;
    DegradationPriorityBox *box = NULL;
    res = _bmff_parse_box_degradation_priority(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stdp", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->priority_count, 4, "priority count");
    test_assert_equal(box->priorities[0], 0x1234, "priority 0");
    test_assert_equal(box->priorities[1], 0x5678, "priority 1");
    test_assert_equal(box->priorities[2], 0x9ABC, "priority 2");
    test_assert_equal(box->priorities[3], 0xDEF0, "priority 3");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_group_description(void)
{
    test_start("test_parse_box_sample_group_description");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x26,
        's', 'g', 'p', 'd',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // grouping type
        0x00, 0x00, 0x00, 0x00, // default length
        0x00, 0x00, 0x00, 0x02, // entry count
        0x00, 0x00, 0x00, 0x04, // description length
        0x50, 0x60, 0x70, 0x80, // data
        0x00, 0x00, 0x00, 0x02, // description length
        0xAA, 0xBB, // data
    };

    memcpy(ctx.track_sample_table_handler_type, "vide", 4);

    BMFFCode res;
    SampleGroupDescriptionBox *box = NULL;
    res = _bmff_parse_box_sample_group_description(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "sgpd", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->grouping_type, 0x12345678, "grouping type");
    test_assert_equal(box->default_length, 0, "default length");
    test_assert_equal(box->entry_count, 2, "entry count");
    test_assert_equal(box->sample_group_entries_size, 14, "entry count");
    test_assert_equal(box->description_lengths[0], 4, "description length 0");
    test_assert_equal(box->description_lengths[1], 2, "description length 1");
    test_assert_equal(box->sample_group_entries[0], 0x00, "sample entry byte 0");
    test_assert_equal(box->sample_group_entries[13], 0xBB, "sample entry byte 13");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_group_type(void)
{
    test_start("test_parse_box_track_group_type");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x10,
        'm', 's', 'r', 'c',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x10, 0x20, 0x30, 0x40, // track group id
    };

    BMFFCode res;
    TrackGroupTypeBox *box = NULL;
    res = _bmff_parse_box_track_group_type(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "msrc", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->track_group_id, 0x10203040, "track group id");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_extended_language_tag(void)
{
    test_start("test_parse_box_extended_language_tag");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x12,
        'e', 'l', 'n', 'g',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        'e','n','-','U','S','\0',
    };

    BMFFCode res;
    ExtendedLanguageTagBox *box = NULL;
    res = _bmff_parse_box_extended_language_tag(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "elng", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strcmp(box->extended_language, "en-US"), 0, "extended language");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_bit_rate(void)
{
    test_start("test_parse_box_bit_rate");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x14,
        'b', 't', 'r', 't',
        0x10, 0x20, 0x30, 0x40, // buffer size db
        0x12, 0x34, 0x56, 0x78, // max bit rate
        0x9A, 0xBC, 0xDE, 0xF0, // avg bit rate
    };

    BMFFCode res;
    BitRateBox *box = NULL;
    res = _bmff_parse_box_bit_rate(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "btrt", 4), 0, "type");
    test_assert_equal(box->buffer_size_db, 0x10203040, "buffer size db");
    test_assert_equal(box->max_bitrate, 0x12345678, "max bitrate");
    test_assert_equal(box->avg_bitrate, 0x9ABCDEF0, "avg bitrate");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_composition_to_decode(void)
{
    test_start("test_parse_box_composition_to_decode");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        'c', 's', 'l', 'g',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // composition to dts shift
        0x00, 0x00, 0x01, 0xC7, // least decode to display delta
        0x10, 0x20, 0x30, 0x40, // greatest decode to display delta
        0x50, 0x60, 0x70, 0x80, // composition start time
        0x01, 0xA0, 0xB0, 0xC0, // composition end time
    };

    BMFFCode res;
    CompositionToDecodeBox *box = NULL;
    res = _bmff_parse_box_composition_to_decode(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "cslg", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal_int64(box->composition_to_dts_shift, 0x12345678LL, "composition to dts shift");
    test_assert_equal_int64(box->least_decode_to_display_delta, 455, "least decode to display delta");
    test_assert_equal_int64(box->greatest_decode_to_display_delta, 0x10203040LL, "greatest decode to display delta");
    test_assert_equal_int64(box->composition_start_time, 0x50607080LL, "composition start time");
    test_assert_equal_int64(box->composition_end_time, 0x01A0B0C0LL, "composition end time");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_aux_info_sizes(void)
{
    test_start("test_parse_box_sample_aux_info_sizes");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1D,
        's', 'a', 'i', 'z',
        0x00, // version
        0x00, 0x00, 0x01, // flags
        0x12, 0x34, 0x56, 0x78, // aux info type
        0x9A, 0xBC, 0xDE, 0xF0, // aux info type param
        0x00, // default sample info size
        0x00, 0x00, 0x00, 0x04, // sample count
        0x01, 0x02, 0x03, 0x04, // sizes
    };

    BMFFCode res;
    SampleAuxInfoSizesBox *box = NULL;
    res = _bmff_parse_box_sample_aux_info_sizes(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "saiz", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000001, "flags");
    test_assert_equal(box->aux_info_type, 0x12345678, "aux info type");
    test_assert_equal(box->aux_info_type_param, 0x9ABCDEF0, "aux info type param");
    test_assert_equal(box->default_sample_info_size, 0, "default sampe info size");
    test_assert_equal(box->sample_count, 4, "sample count");
    test_assert_equal(box->sample_info_sizes[0], 0x01, "sizes 0");
    test_assert_equal(box->sample_info_sizes[3], 0x04, "sizes 3");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sample_aux_info_offsets(void)
{
    test_start("test_parse_box_sample_aux_info_offsets");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        's', 'a', 'i', 'o',
        0x00, // version
        0x00, 0x00, 0x01, // flags
        0x12, 0x34, 0x56, 0x78, // aux info type
        0x9A, 0xBC, 0xDE, 0xF0, // aux info type param
        0x00, 0x00, 0x00, 0x02, // entry count
        0x01, 0x02, 0x03, 0x04, // offsets
        0x05, 0x06, 0x07, 0x08,
    };

    BMFFCode res;
    SampleAuxInfoOffsetsBox *box = NULL;
    res = _bmff_parse_box_sample_aux_info_offsets(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "saio", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000001, "flags");
    test_assert_equal(box->aux_info_type, 0x12345678, "aux info type");
    test_assert_equal(box->aux_info_type_param, 0x9ABCDEF0, "aux info type param");
    test_assert_equal(box->entry_count, 2, "entry count");
    test_assert_equal(box->offsets[0], 0x01020304, "offset 0");
    test_assert_equal(box->offsets[1], 0x05060708, "offset 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_fragment_decode_time(void)
{
    test_start("test_parse_box_track_fragment_decode_time");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x10,
        't', 'f', 'd', 't',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x01, 0x02, 0x03, 0x04, // base media decode time
    };

    BMFFCode res;
    TrackFragmentDecodeTimeBox *box = NULL;
    res = _bmff_parse_box_track_fragment_decode_time(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "tfdt", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal_uint64(box->base_media_decode_time, 0x01020304LL, "base media decode time");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_level_assignment(void)
{
    test_start("test_parse_box_level_assignment");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x31,
        'l', 'e', 'v', 'a',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x04, // level count

        0x01, 0x02, 0x03, 0x04, // track id
        0x01, // padding flag (1), assignment type (7)
        0x10, 0x20, 0x30, 0x40, // grouping type
        0x12, 0x34, 0x56, 0x78, // grouping type parameter

        0x12, 0x22, 0x32, 0x42, // track id
        0x02, // padding flag (1), assignment type (7)

        0x11, 0x22, 0x33, 0x44, // track id
        0x84, // padding flag (1), assignment type (7)
        0x11, 0x21, 0x31, 0x41, // sub track id

        0x10, 0x20, 0x30, 0x40, // track id
        0x80, // padding flag (1), assignment type (7)
        0xA0, 0xB0, 0xC0, 0xD0, // grouping type
    };

    BMFFCode res;
    LevelAssignmentBox *box = NULL;
    res = _bmff_parse_box_level_assignment(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "leva", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->level_count, 4, "level count");

    LevelAssignment *level = &box->levels[0];
    test_assert_equal(level->track_id, 0x01020304, "level 0 track id");
    test_assert_equal(level->padding_flag, 0, "level 0 padding flag");
    test_assert_equal(level->assignment_type, 1, "level 0 assignment type");
    test_assert_equal(level->grouping_type, 0x10203040, "level 0 grouping type");
    test_assert_equal(level->grouping_type_parameter, 0x12345678, "level 0 grouping type parameter");

    level = &box->levels[1];
    test_assert_equal(level->track_id, 0x12223242, "level 1 track id");
    test_assert_equal(level->padding_flag, 0, "level 1 padding flag");
    test_assert_equal(level->assignment_type, 2, "level 1 assignment type");

    level = &box->levels[2];
    test_assert_equal(level->track_id, 0x11223344, "level 2 track id");
    test_assert_equal(level->padding_flag, 1, "level 2 padding flag");
    test_assert_equal(level->assignment_type, 4, "level 2 assignment type");
    test_assert_equal(level->sub_track_id, 0x11213141, "level 2 sub track id");

    level = &box->levels[3];
    test_assert_equal(level->track_id, 0x10203040, "level 3 track id");
    test_assert_equal(level->padding_flag, 1, "level 3 padding flag");
    test_assert_equal(level->assignment_type, 0, "level 3 assignment type");
    test_assert_equal(level->grouping_type, 0xA0B0C0D0, "level 3 grouping type");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_extension_properties(void)
{
    test_start("test_parse_box_track_extension_properties");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x21,
        't', 'r', 'e', 'p',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // track id

        0, 0, 0, 0x11,
        'a','s','s','p',
        0x00, // version
        0x00, 0x00, 0x00, 0x00, // flags
        0x10, 0x02, 0x30, 0x04,
    };

    BMFFCode res;
    TrackExtensionPropertiesBox *box = NULL;
    res = _bmff_parse_box_track_extension_properties(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "trep", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->track_id, 0x12345678, "track id");
    test_assert_equal(box->child_count, 1, "child count");
    test_assert(box->children != NULL, "children");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_alt_startup_seq_properties(void)
{
    test_start("test_parse_box_alt_startup_seq_properties");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x18,
        'a', 's', 's', 'p',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x01, // num entries
        0x01, 0x02, 0x03, 0x04, // grouping type param
        0x00, 0x11, 0x22, 0x33, // min initial alt startup offset
    };

    BMFFCode res;
    AltStartupSeqPropertiesBox *box = NULL;
    res = _bmff_parse_box_alt_startup_seq_properties(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "assp", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 1, "entry count");
    test_assert_equal(box->entries[0].grouping_type_param, 0x01020304, "entry 0 grouping type param");
    test_assert_equal(box->entries[0].min_initial_alt_startup_offset, 0x00112233, "entry 0 min initial startup offset");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_track_selection(void)
{
    test_start("test_parse_box_track_selection");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x18,
        't', 's', 'e', 'l',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x10, 0x20, 0x30, 0x40, // switch group
        0x00, 0x11, 0x22, 0x33, // attribute list
        0x44, 0x55, 0x66, 0x77,
    };

    BMFFCode res;
    TrackSelectionBox *box = NULL;
    res = _bmff_parse_box_track_selection(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "tsel", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->switch_group, 0x10203040, "switch group");
    test_assert_equal(box->attribute_list_count, 2, "attribute list count");
    test_assert_equal(box->attribute_list[0], 0x00112233, "attribute list 0");
    test_assert_equal(box->attribute_list[1], 0x44556677, "attribute list 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_kind(void)
{
    test_start("test_parse_box_kind");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1D,
        'k', 'i', 'n', 'd',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        's','c','h','e','m','e',' ','u','r','i','\0',
        'v','a','l','u','e','\0',
    };

    BMFFCode res;
    KindBox *box = NULL;
    res = _bmff_parse_box_kind(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "kind", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strcmp(box->scheme_uri, "scheme uri"), 0, "scheme uri");
    test_assert_equal(strcmp(box->value, "value"), 0, "value");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_reference(void)
{
    test_start("test_parse_box_item_reference");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x3C,
        'i', 'r', 'e', 'f',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags

        0, 0, 0, 0x10,
        'i','r','e','f',
        0x12, 0x34, // from item id
        0x00, 0x02, // reference count
        0x01, 0x02, 0x03, 0x04, // to item ids

        0, 0, 0, 0x0E,
        'i','r','e','f',
        0x56, 0x78, // from item id
        0x00, 0x01, // reference count
        0x11, 0x12, // to item ids

        0, 0, 0, 0x12,
        'i','r','e','f',
        0x9A, 0xBC, // from item id
        0x00, 0x03, // reference count
        0x21, 0x22, 0x23, 0x24, 0x25, 0x26 // to item ids
    };

    BMFFCode res;
    ItemReferenceBox *box = NULL;
    res = _bmff_parse_box_item_reference(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "iref", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->references_count, 3, "references count");

    SingleItemTypeReferenceBox *ref_box = &box->references[0];
    test_assert_equal(ref_box->from_item_id, 0x1234, "from item id 0");
    test_assert_equal(ref_box->reference_count, 2, "reference count 0");
    test_assert_equal(ref_box->to_item_ids[0], 0x0102, "to items ids 0 0");
    test_assert_equal(ref_box->to_item_ids[1], 0x0304, "to items ids 0 1");

    ref_box = &box->references[1];
    test_assert_equal(ref_box->from_item_id, 0x5678, "from item id 1");
    test_assert_equal(ref_box->reference_count, 1, "reference count 1");
    test_assert_equal(ref_box->to_item_ids[0], 0x1112, "to items ids 1 0");
    bmff_context_destroy(&ctx);

    ref_box = &box->references[2];
    test_assert_equal(ref_box->from_item_id, 0x9ABC, "from item id 2");
    test_assert_equal(ref_box->reference_count, 3, "reference count 2");
    test_assert_equal(ref_box->to_item_ids[0], 0x2122, "to items ids 2 0");
    test_assert_equal(ref_box->to_item_ids[1], 0x2324, "to items ids 2 1");
    test_assert_equal(ref_box->to_item_ids[2], 0x2526, "to items ids 2 2");
    test_end();
}

void test_parse_box_item_data(void)
{
    test_start("test_parse_box_item_data");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x10,
        'i', 'd', 'a', 't',
        0x01, 0x02, 0x03, 0x04, // data
        0x05, 0x06, 0x07, 0x08,
    };

    BMFFCode res;
    ItemDataBox *box = NULL;
    res = _bmff_parse_box_item_data(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "idat", 4), 0, "type");
    test_assert(box->data != NULL, "data");
    test_assert_equal(box->data_size, 8, "data size");
    test_assert_equal(box->data[0], 0x01, "data[0]");
    test_assert_equal(box->data[7], 0x08, "data[7]");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_metabox_relation(void)
{
    test_start("test_parse_box_metabox_relation");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x15,
        'm', 'e', 'r', 'e',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        'a', 'b', 'c', 'd', // first metabox handler type
        'e', 'f', 'g', 'h', // second metabox handler type
        0x03, // metabox relation
    };

    BMFFCode res;
    MetaboxRelationBox *box = NULL;
    res = _bmff_parse_box_metabox_relation(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "mere", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(strncmp(box->first_metabox_handler_type, "abcd", 4), 0, "first metabox handler");
    test_assert_equal(strncmp(box->second_metabox_handler_type, "efgh", 4), 0, "second metabox handler");
    test_assert_equal(box->metabox_relation, eMetaboxRelationComplementary, "metabox relation");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_file_partition(void)
{
    test_start("test_parse_box_file_partition");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x38,
        'f', 'p', 'a', 'r',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, // item id
        0x00, 0x05, // packet payload size
        0x00, 0xF0, // reserved (8), FEC Encoding ID
        0x56, 0x78, // FEC instance id
        0x9A, 0xBC, // max source block length
        0xDE, 0xF1, // encoding symbol length
        0xFF, 0xEE, // max number of encoding symbols
        's','c','h','e','m','e',' ','s','p','e','c','i','f','i','c','\0', // scheme specific info
        0x00, 0x02, // entry count
        0x00, 0x01, // block count
        0xDC, 0xBA, 0x98, 0x76, //block size
        0x00, 0x02, // block count
        0x54, 0x32, 0x10, 0xFE, // block size
    };

    BMFFCode res;
    FilePartitionBox *box = NULL;
    res = _bmff_parse_box_file_partition(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "fpar", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->item_id, 0x1234, "item id");
    test_assert_equal(box->packet_payload_size, 5, "packet payload size");
    test_assert_equal(box->fec_encoding_id, 0xF0, "FEC encoding id");
    test_assert_equal(box->fec_instance_id, 0x5678, "FEC instance id");
    test_assert_equal(box->max_source_block_length, 0x9ABC, "max source block length");
    test_assert_equal(box->encoding_symbol_length, 0xDEF1, "encoding symbol length");
    test_assert_equal(box->max_number_of_encoding_symbols, 0xFFEE, "max number of encoding symbols");
    test_assert_equal(strcmp(box->scheme_specific_info, "scheme specific"), 0, "scheme specific info");
    test_assert_equal(box->entry_count, 2, "entry count");
    test_assert_equal(box->block_counts[0], 1, "block count 0");
    test_assert_equal(box->block_sizes[0], 0xDCBA9876, "block size 0");
    test_assert_equal(box->block_counts[1], 2, "block count 1");
    test_assert_equal(box->block_sizes[1], 0x543210FE, "block size 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_reservoir(void)
{
    test_start("test_parse_box_reservoir");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1A,
        'f', 'e', 'c', 'r',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x02, // entry count
        0xFE, 0x01, // item id
        0xAB, 0xCD, 0xEF, 0x01, // symbol count
        0xFE, 0x02, // item id
        0x12, 0x34, 0x56, 0x78, // symbol count
    };

    BMFFCode res;
    FECReservoirBox *box = NULL;
    res = _bmff_parse_box_reservoir(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "fecr", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 0x02, "entry count");
    test_assert_equal(box->item_ids[0], 0xFE01, "item id 0");
    test_assert_equal(box->symbol_counts[0], 0xABCDEF01, "symbol count 0");
    test_assert_equal(box->item_ids[1], 0xFE02, "item id 1");
    test_assert_equal(box->symbol_counts[1], 0x12345678, "symbol count 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_partition_entry(void)
{
    test_start("test_parse_box_partition_entry");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x66,
        'p', 'a', 'e', 'n',
        // File Partition Box
        0, 0, 0, 0x30,
        'f', 'p', 'a', 'r',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // item id
        0x00, 0x05, // packet payload size
        0x00, 0xF0, // reserved (8), FEC Encoding ID
        0x56, 0x78, // FEC instance id
        0x9A, 0xBC, // max source block length
        0xDE, 0xF1, // encoding symbol length
        0xFF, 0xEE, // max number of encoding symbols
        's','c','h','e','m','e',' ','s','p','e','c','i','f','i','c','\0', // scheme specific info
        0x00, 0x00, 0x00, 0x00, // entry count
        // FEC Reservoir Box
        0, 0, 0, 0x0E,
        'f', 'e', 'c', 'r',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, // entry count
        // File Reservoir Box
        0, 0, 0, 0x20,
        'f', 'i', 'r', 'e',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x02, // entry count
        0xFE, 0x01, 0x02, 0x03, // item id
        0xAB, 0xCD, 0xEF, 0x01, // symbol count
        0x12, 0x34, 0x56, 0x78, // item id
        0xFE, 0xDC, 0xBA, 0x98, // symbol count
    };

    BMFFCode res;
    PartitionEntryBox *box = NULL;
    res = _bmff_parse_box_partition_entry(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "paen", 4), 0, "type");

    FilePartitionBox *fpar = box->blocks_and_symbols;
    test_assert_equal(fpar->box.size, 0x30, "fpar size");
    test_assert_equal(fpar->box.version, 1, "fpar version");
    test_assert_equal(strncmp(fpar->box.type, "fpar", 4), 0, "fpar type");
    test_assert_equal(fpar->item_id, 0x12345678, "fpar item id");
    test_assert_equal(fpar->packet_payload_size, 5, "fpar packet payload size");
    test_assert_equal(fpar->fec_encoding_id, 0xF0, "fpar FEC encoding id");
    test_assert_equal(fpar->fec_instance_id, 0x5678, "fpar FEC instance id");
    test_assert_equal(fpar->max_source_block_length, 0x9ABC, "fpar max source block length");
    test_assert_equal(fpar->encoding_symbol_length, 0xDEF1, "fpar encoding symbol length");
    test_assert_equal(fpar->max_number_of_encoding_symbols, 0xFFEE, "fpar max number of encoding symbols");
    test_assert_equal(strcmp(fpar->scheme_specific_info, "scheme specific"), 0, "fpar scheme specific info");
    test_assert_equal(fpar->entry_count, 0, "fpar entry count");

    FECReservoirBox *reservoir = box->fec_symbol_locations; 
    test_assert_equal(reservoir->box.size, 0x0E, "fecr size");
    test_assert_equal(strncmp(reservoir->box.type, "fecr", 4), 0, "fecr type");
    test_assert_equal(reservoir->box.version, 0x00, "fecr version");
    test_assert_equal(reservoir->box.flags, 0xF10FBA, "fecr flags");
    test_assert_equal(reservoir->entry_count, 0x00, "fecr entry count");

    reservoir = box->file_symbol_locations;
    test_assert_equal(reservoir->box.size, 0x20, "fire size");
    test_assert_equal(strncmp(reservoir->box.type, "fire", 4), 0, "fire type");
    test_assert_equal(reservoir->box.version, 0x01, "fire version");
    test_assert_equal(reservoir->box.flags, 0xF10FBA, "fire flags");
    test_assert_equal(reservoir->entry_count, 0x02, "fire entry count");
    test_assert_equal(reservoir->item_ids[0], 0xFE010203, "fire item id 0");
    test_assert_equal(reservoir->symbol_counts[0], 0xABCDEF01, "fire symbol count 0");
    test_assert_equal(reservoir->item_ids[1], 0x12345678, "fire item id 1");
    test_assert_equal(reservoir->symbol_counts[1], 0xFEDCBA98, "fire symbol count 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_fd_session_group(void)
{
    test_start("test_parse_box_fd_session_group");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x2F,
        's', 'e', 'g', 'r',
        0x00, 0x03, // num of session groups
        0x01, // entry count
        0x01, 0x02, 0x03, 0x04, // group Id
        0x00, 0x01, // num of channels in session group
        0x12, 0x34, 0x56, 0x78, // hint track id
        0x00, // entry count
        0x00, 0x00, // num of channels in session group
        0x02, // entry count
        0x05, 0x06, 0x07, 0x08, // group Id
        0x09, 0x0A, 0x0B, 0x0C, // group Id
        0x00, 0x03, // num of channels in session group
        0x12, 0x34, 0x56, 0x78, // hint track id
        0x9A, 0xBC, 0xDE, 0xF1, // hint track id
        0x23, 0x45, 0x67, 0x89, // hint track id
    };

    BMFFCode res;
    FDSessionGroupBox *box = NULL;
    res = _bmff_parse_box_fd_session_group(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "segr", 4), 0, "type");
    test_assert_equal(box->num_session_groups, 3, "number of session groups");

    FDSessionGroupEntry *entry = &box->session_groups[0];
    test_assert_equal(entry->entry_count, 1, "entry count 0");
    test_assert_equal(entry->group_ids[0], 0x01020304, "groupd id 0");
    test_assert_equal(entry->num_channels_in_session_group, 1, "num of channels in session group 0");
    test_assert_equal(entry->hint_track_ids[0], 0x12345678, "hint track ids 0");

    entry = &box->session_groups[1];
    test_assert_equal(entry->entry_count, 0, "entry count 1");
    test_assert_equal(entry->num_channels_in_session_group, 0, "num of channels in session group 1");

    entry = &box->session_groups[2];
    test_assert_equal(entry->entry_count, 2, "entry count 2");
    test_assert_equal(entry->group_ids[0], 0x05060708, "groupd id 2 0");
    test_assert_equal(entry->group_ids[1], 0x090A0B0C, "groupd id 2 1");
    test_assert_equal(entry->num_channels_in_session_group, 3, "num of channels in session group 2");
    test_assert_equal(entry->hint_track_ids[0], 0x12345678, "hint track ids 2 0");
    test_assert_equal(entry->hint_track_ids[1], 0x9ABCDEF1, "hint track ids 2 1");
    test_assert_equal(entry->hint_track_ids[2], 0x23456789, "hint track ids 2 2");
    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_group_id_to_name(void)
{
    test_start("test_parse_box_group_id_to_name");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x29,
        'g', 'i', 't', 'n',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x03, // entry count
        0x01, 0x02, 0x03, 0x04, // group id
        'n','a','m','e','0','\00', // group name
        0x01, 0x02, 0x03, 0x04, // group id
        'n','a','m','e','1','_','_','\00', // group name
        0x01, 0x02, 0x03, 0x04, // group id
        '\00', // group name
    };

    BMFFCode res;
    GroupIdToNameBox *box = NULL;
    res = _bmff_parse_box_group_id_to_name(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "gitn", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 3, "entry count");
    test_assert_equal(box->group_ids[0], 0x01020304, "group id 0");
    test_assert_equal(strcmp(box->group_names[0], "name0"), 0, "group name 0");
    test_assert_equal(box->group_ids[1], 0x01020304, "group id 1");
    test_assert_equal(strcmp(box->group_names[1], "name1__"), 0, "group name 0");
    test_assert_equal(box->group_ids[2], 0x01020304, "group id 2");
    test_assert_equal(strcmp(box->group_names[2], ""), 0, "group name 0");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_fd_item_inforamation(void)
{
    test_start("test_parse_box_fd_item_information");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x55,
        'f', 'i', 'i', 'n',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x01, // number of entries

        // PartitionEntry - parition entries (1)
        0, 0, 0, 0x2F,
        'p', 'a', 'e', 'n',
        // File Partition Box
        0, 0, 0, 0x27,
        'f', 'p', 'a', 'r',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // item id
        0x00, 0x05, // packet payload size
        0x00, 0xF0, // reserved (8), FEC Encoding ID
        0x56, 0x78, // FEC instance id
        0x9A, 0xBC, // max source block length
        0xDE, 0xF1, // encoding symbol length
        0xFF, 0xEE, // max number of encoding symbols
        's','c','h','e','m','e','\00', // scheme specific info
        0x00, 0x00, 0x00, 0x00, // entry count
        
        // FDSessionGroupBox - session info
        0, 0, 0, 0x0A,
        's', 'e', 'g', 'r',
        0x00, 0x00, // num of session groups

        // GroupIdToNameBox - group id to name
        0, 0, 0, 0x0E,
        'g', 'i', 't', 'n',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, // entry count
    };

    BMFFCode res;
    FDItemInformationBox *box = NULL;
    res = _bmff_parse_box_fd_item_information(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "fiin", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->entry_count, 1, "number of entries");

    PartitionEntryBox *entry = box->entries[0];
    test_assert_equal_ptr((size_t)entry->fec_symbol_locations, (size_t)NULL, "fec symbol location");
    test_assert_equal_ptr((size_t)entry->file_symbol_locations, (size_t)NULL, "file symbol location");

    FilePartitionBox *fpar = entry->blocks_and_symbols;
    test_assert_equal(fpar->box.size, 0x027, "fpar size");
    test_assert_equal(strncmp(fpar->box.type, "fpar", 4), 0, "fpar type");
    test_assert_equal(fpar->box.version, 0x01, "fpar version");
    test_assert_equal(fpar->box.flags, 0xF10FBA, "fpar flags");
    test_assert_equal(fpar->item_id, 0x12345678, "fpar item id");
    test_assert_equal(fpar->packet_payload_size, 5, "fpar packet payload size");
    test_assert_equal(fpar->fec_encoding_id, 0xF0, "fpar FEC encoding id");
    test_assert_equal(fpar->fec_instance_id, 0x5678, "fpar FEC instance id");
    test_assert_equal(fpar->max_source_block_length, 0x9ABC, "fpar max source block length");
    test_assert_equal(fpar->encoding_symbol_length, 0xDEF1, "fpar encoding symbol length");
    test_assert_equal(fpar->max_number_of_encoding_symbols, 0xFFEE, "fpar max number of encoding symbols");
    test_assert_equal(strcmp(fpar->scheme_specific_info, "scheme"), 0, "fpar scheme specific info");
    test_assert_equal(fpar->entry_count, 0, "fpar entry count");

    FDSessionGroupBox *segr = box->session_info;
    test_assert_equal(segr->box.size, 0x0A, "segr size");
    test_assert_equal(strncmp(segr->box.type, "segr", 4), 0, "segr type");
    test_assert_equal(segr->num_session_groups, 0x00, "segr num of session groups");

    GroupIdToNameBox *gitn = box->group_id_to_name;
    test_assert_equal(gitn->box.size, 0x0E, "size");
    test_assert_equal(strncmp(gitn->box.type, "gitn", 4), 0, "type");
    test_assert_equal(gitn->box.version, 0x00, "version");
    test_assert_equal(gitn->box.flags, 0xF10FBA, "flags");
    test_assert_equal(gitn->entry_count, 0, "entry count");

    bmff_context_destroy(&ctx);
    
    test_end();
}

void test_parse_box_sub_track_information(void)
{
    test_start("test_parse_box_sub_track_information");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x20,
        's', 't', 'r', 'i',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x01, 0x02, // switch group
        0x03, 0x04, // alternate group
        0x05, 0x06, 0x07, 0x08, // sub track id
        'a','b','c','d', // attribute 0
        'e','f','g','h', // attribute 0
        'i','j','k','l', // attribute 0
    };

    BMFFCode res;
    SubTrackInformationBox *box = NULL;
    res = _bmff_parse_box_sub_track_information(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stri", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->switch_group, 0x0102, "switch group");
    test_assert_equal(box->alternate_group, 0x0304, "alternate group");
    test_assert_equal(box->sub_track_id, 0x05060708, "sub track id");
    test_assert_equal(box->attribute_list_count, 3, "attribute list count");
    test_assert_equal(strncmp(box->attribute_list[0], "abcd", 4), 0, "attribute 0");
    test_assert_equal(strncmp(box->attribute_list[1], "efgh", 4), 0, "attribute 1");
    test_assert_equal(strncmp(box->attribute_list[2], "ijkl", 4), 0, "attribute 2");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_sub_track_sample_group(void)
{
    test_start("test_parse_box_sub_track_sample_group");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1E,
        's', 't', 's', 'g',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x01, 0x02, 0x03, 0x4, // grouping type
        0x00, 0x03, // item count
        0x01, 0x02, 0x03, 0x04, // group description index 0
        0x11, 0x12, 0x13, 0x14, // group description index 1
        0x21, 0x22, 0x23, 0x24, // group description index 2
    };

    BMFFCode res;
    SubTrackSampleGroupBox *box = NULL;
    res = _bmff_parse_box_sub_track_sample_group(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stsg", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->grouping_type, 0x01020304, "grouping type");
    test_assert_equal(box->item_count, 3, "item count");
    test_assert_equal(box->group_description_indicies[0], 0x01020304, "group description index 0");
    test_assert_equal(box->group_description_indicies[1], 0x11121314, "group description index 1");
    test_assert_equal(box->group_description_indicies[2], 0x21222324, "group description index 2");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_stereo_video(void)
{
    test_start("test_parse_box_stereo_video");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x3C,
        's', 't', 'v', 'i',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x00, 0x00, 0x00, 0x03, // reserved (30), single view allowed(2)
        0x10, 0x20, 0x30, 0x40, // stereo scheme
        0x00, 0x00, 0x00, 0x08, // length
        0x12, 0x34, 0x56, 0x78,
        0x9A, 0xBC, 0xDE, 0xF1, // stereo indication type
        0x00, 0x00, 0x00, 0x0C, // random boxes
        'a', 'b', 'c', 'd',
        0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x00, 0x00, 0x10,
        'a', 'b', 'c', 'd',
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
    };

    BMFFCode res;
    StereoVideoBox *box = NULL;
    res = _bmff_parse_box_stereo_video(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "stvi", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->single_view_allowed, 0x03, "single view allowed");
    test_assert_equal(box->stereo_scheme, 0x10203040, "stereo scheme");
    test_assert_equal(box->length, 0x08, "length");
    test_assert_equal_uint64(box->stereo_indication_type, 0x123456789ABCDEF1ULL, "stereo indication type");
    test_assert_equal(box->child_count, 2, "child count");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_segment_index(void)
{
    test_start("test_parse_box_segment_index");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x38,
        's', 'i', 'd', 'x',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x10, 0x20, 0x30, 0x40, // reference id
        0x50, 0x60, 0x70, 0x80, // timescale
        0x90, 0xA0, 0xB0, 0xC0, // earliest presentation time
        0xD0, 0xE0, 0xF0, 0x01, // first offset
        0x00, 0x00, // reserved
        0x00, 0x02, // reference count
        0x8F, 0x0E, 0x0D, 0x0C, // reference type (1), referenced size (31)
        0x12, 0x34, 0x56, 0x78, // subsegment duration
        0xDF, 0xED, 0xCB, 0xA9, // starts with sap(1), sap type(3), sap delta time (28)
        0x00, 0xA1, 0xB2, 0xC3, // reference type (1), referenced size (31)
        0xF9, 0xE8, 0xD7, 0xC6, // subsegment duration
        0x40, 0xFF, 0xEE, 0xDD, // starts with sap(1), sap type(3), sap delta time (28)
    };

    BMFFCode res;
    SegmentIndexBox *box = NULL;
    res = _bmff_parse_box_segment_index(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "sidx", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->reference_id, 0x10203040, "reference id");
    test_assert_equal(box->timescale, 0x50607080, "timescale");
    test_assert_equal(box->earliest_presentation_time, 0x90A0B0C0, "earliest presentation time");
    test_assert_equal(box->first_offset, 0xD0E0F001, "first offset");
    test_assert_equal(box->reference_count, 2, "reference count");

    SegmentIndexRefEntry *ref = &box->references[0];
    test_assert_equal(ref->reference_type, 1, "reference type 0");
    test_assert_equal(ref->referenced_size, 0x0F0E0D0C, "referenced size 0");
    test_assert_equal(ref->subsegment_duration, 0x12345678, "subsegment duration 0");
    test_assert_equal(ref->starts_with_sap, 1, "starts with sap 0");
    test_assert_equal(ref->sap_type, 5, "sap type 0");
    test_assert_equal(ref->sap_delta_time, 0x0FEDCBA9, "sap delta time 0");

    ref = &box->references[1];
    test_assert_equal(ref->reference_type, 0, "reference type 1");
    test_assert_equal(ref->referenced_size, 0x00A1B2C3, "referenced size 1");
    test_assert_equal(ref->subsegment_duration, 0xF9E8D7C6, "subsegment duration 1");
    test_assert_equal(ref->starts_with_sap, 0, "starts with sap 1");
    test_assert_equal(ref->sap_type, 4, "sap type 1");
    test_assert_equal(ref->sap_delta_time, 0xFFEEDD, "sap delta time 1");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_producer_reference_time(void)
{
    test_start("test_parse_box_producer_reference_time");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x1C,
        'p', 'r', 'f', 't',
        0x00, // version
        0xF1, 0x0F, 0xBA, // flags
        0x12, 0x34, 0x56, 0x78, // reference track id
        0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, // ntp timestamp
        0x11, 0x22, 0x33, 0x44, // media time
    };

    BMFFCode res;
    ProducerReferenceTimeBox *box = NULL;
    res = _bmff_parse_box_producer_reference_time(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "prft", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");
    test_assert_equal(box->reference_track_id, 0x12345678, "reference track id");
    test_assert_equal_uint64(box->ntp_timestamp, 0x1020304050607080ULL, "ntp timestamp");
    test_assert_equal(box->media_time, 0x11223344, "media time");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_complete_track_info(void)
{
    test_start("test_parse_box_complete_track_info");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x31,
        'c', 'i', 'n', 'f',
        0, 0, 0, 0x0C,
        'h','i','n','t',
        'a','b','c','d', //data format
        0, 0 ,0, 0x0D, // random boxes
        'e','f','g','h',
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0, 0, 0, 0x10, // random boxes
        'i','j','k','l',
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    };

    BMFFCode res;
    CompleteTrackInfoBox *box = NULL;
    res = _bmff_parse_box_complete_track_info(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "cinf", 4), 0, "type");
    test_assert_equal(box->original_format.box.size, 0x0C, "original format size");
    test_assert_equal(strncmp(box->original_format.box.type, "hint", 4), 0, "original format type");
    test_assert_equal(strncmp(box->original_format.data_format, "abcd", 4), 0, "original format data format");
    test_assert_equal(box->child_count, 2, "child count");
    test_assert(box->children != NULL, "children");

    bmff_context_destroy(&ctx);

    test_end();
}

/*
void test_parse_box_(void)
{
    test_start("test_parse_box_");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x30,
        'p', 'd', 'i', 'n',
        0x01, // version
        0xF1, 0x0F, 0xBA, // flags
    };

    BMFFCode res;
    Box *box = NULL;
    res = _bmff_parse_box_(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.type, "pdin", 4), 0, "type");
    test_assert_equal(box->box.version, 0x01, "version");
    test_assert_equal(box->box.flags, 0xF10FBA, "flags");

    bmff_context_destroy(&ctx);

    test_end();
}
*/
