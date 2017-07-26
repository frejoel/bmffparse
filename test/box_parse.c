#include "test.h"
#include <bmff.h>

#include <string.h>

void test_parse_box_file_type(void);
void test_parse_box_track_reference(void);
void test_parse_box_null_media_header(void);
void test_parse_box_progressive_download_info(void);
void test_parse_box_media_data(void);
void test_parse_box_primary_item(void);
void test_parse_box_item_location(void);
void test_parse_box_item_info_entry(void);
void test_parse_box_item_info(void);
void test_parse_box_ipmp_control(void);
void test_parse_box_original_format(void);
void test_parse_box_ipmp_info(void);
void test_parse_box_scheme_type(void);
void test_parse_box_scheme_info(void);
void test_parse_box_protection_scheme_info(void);
void test_parse_box_item_protection(void);
void test_parse_box_meta(void);

int main(int argc, char** argv)
{
    test_parse_box_file_type();
    test_parse_box_track_reference();
    test_parse_box_null_media_header();
    test_parse_box_progressive_download_info();
    test_parse_box_media_data();
    test_parse_box_primary_item();
    test_parse_box_item_location();
    test_parse_box_item_info_entry();
    test_parse_box_item_info();
    test_parse_box_ipmp_control();
    test_parse_box_original_format();
    test_parse_box_ipmp_info();
    test_parse_box_scheme_type();
    test_parse_box_scheme_info();
    test_parse_box_protection_scheme_info();
    test_parse_box_item_protection();
    test_parse_box_meta();
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

void test_parse_box_track_reference(void)
{
    test_start("test_parse_box_track_reference");

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
    res = _bmff_parse_box_track_reference(&ctx, data, sizeof(data), (Box**)&box);
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
        0x00, // version
        0xEE, 0xCC, 0xBB, // flags
        0x01, 0x05, // item id
    };

    BMFFCode res;
    PrimaryItemBox *box = NULL;
    res = _bmff_parse_box_primary_item(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x0E, "size");
    test_assert_equal(strncmp(box->box.type, "pitm", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0xEECCBB, "flags");
    test_assert_equal(box->item_id, 0x0105, "item id");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_location(void)
{
    test_start("test_parse_box_item_location");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
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
    };

    BMFFCode res;
    ItemLocationBox *box = NULL;
    res = _bmff_parse_box_item_location(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x34, "size");
    test_assert_equal(strncmp(box->box.type, "iloc", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x001100, "flags");
    test_assert_equal(box->offset_size, 4, "offset size");
    test_assert_equal(box->length_size, 4, "length size");
    test_assert_equal(box->base_offset_size, 4, "base offset size");
    test_assert_equal(box->item_count, 2, "item count");
    test_assert_equal(box->items[0].item_id, 1, "item[0] item id");
    test_assert_equal(box->items[0].data_reference_index, 0, "item[0] data reference index");
    test_assert_equal(box->items[0].base_offset, 0xE1E1C2C2, "item[0] base offset");
    test_assert_equal(box->items[0].extent_count, 2, "item[0] extent count");
    test_assert_equal(box->items[0].extents[0].offset, 0x10203040, "item[0].extent[0] offset");
    test_assert_equal(box->items[0].extents[0].length, 0x50607080, "item[0].extent[0] length");
    test_assert_equal(box->items[0].extents[1].offset, 0xA1B2C3D4, "item[0].extent[1] offset");
    test_assert_equal(box->items[0].extents[1].length, 0xA9B8C7D6, "item[0].extent[1] length");
    test_assert_equal(box->items[1].item_id, 0xFEDC, "item[1] item id");
    test_assert_equal(box->items[1].data_reference_index, 1, "item[1] data reference index");
    test_assert_equal(box->items[1].base_offset, 0x12345678, "item[1] base offset");
    test_assert_equal(box->items[1].extent_count, 0, "item[1] extent count");

    bmff_context_destroy(&ctx);

    test_end();
}

void test_parse_box_item_info_entry(void)
{
    test_start("test_parse_box_item_info_entry");

    BMFFContext ctx;
    bmff_context_init(&ctx);

    uint8_t data[] = {
        0, 0, 0, 0x38,
        'i', 'n', 'f', 'e',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        0x12, 0x34, // item id
        0xAB, 0xCD, // item protection index
        'i','t','e','m',' ','n','a','m','e',0, // 10
        'c','o','n','t','e','n','t',' ','t','y','p','e',0, // 13
        'c','o','n','t','e','n','t',' ','e','n','c','o','d','i','n','g',0, // 17
    };

    BMFFCode res;
    ItemInfoEntry *box = NULL;
    res = _bmff_parse_box_item_info_entry(&ctx, data, sizeof(data), (Box**)&box);
    test_assert_equal(BMFF_OK, res, "success");
    test_assert(box != NULL, "NULL box reference");
    test_assert_equal(box->box.size, 0x38, "size");
    test_assert_equal(strncmp(box->box.type, "infe", 4), 0, "type");
    test_assert_equal(box->box.version, 0x00, "version");
    test_assert_equal(box->box.flags, 0x000000, "flags");
    test_assert_equal(box->item_id, 0x1234, "item id");
    test_assert_equal(box->item_protection_index, 0xABCD, "item protection index");
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
        0, 0, 0, 0x4F,
        's', 'i', 'n', 'f',
        'm','p','4','v', // data format
        // IPMP Info Box
        0, 0, 0, 0x18,
        'i', 'm', 'i', 'f',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        'd','e','s','c','r','i','p','t','o','r','s',0, // IPMP descriptors
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
    test_assert_equal(box->box.box.size, sizeof(data), "size");
    test_assert_equal(strncmp(box->box.box.type, "sinf", 4), 0, "type");
    test_assert_equal(strncmp(box->box.data_format, "mp4v", 4), 0, "data format");

    test_assert(box->ipmp_descriptors != NULL, "NULL IPMP box descriptors");
    IPMPInfoBox *ipmp = box->ipmp_descriptors;
    test_assert_equal(strncmp("imif", ipmp->box.type, 4), 0, "IPMP Info type");
    test_assert_equal(ipmp->box.size, 0x18, "IPMP Info size");
    test_assert_equal(ipmp->box.version, 0x00, "IPMP Info version");
    test_assert_equal(ipmp->box.flags, 0x000000, "IPMP Info flags");
    // TODO: IPMP Descriptors

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
        0, 0, 0, 0x5D,
        'i', 'p', 'r', 'o',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        0x00, 0x01, // protection count
        ////////
        // Protection Scheme Info Box
        ///////
        0, 0, 0, 0x4F,
        's', 'i', 'n', 'f',
        'm','p','4','v', // data format
        // IPMP Info Box
        0, 0, 0, 0x18,
        'i', 'm', 'i', 'f',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        'd','e','s','c','r','i','p','t','o','r','s',0, // IPMP descriptors
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

    test_assert_equal(info->box.box.size, 0x4F, "size");
    test_assert_equal(strncmp(info->box.box.type, "sinf", 4), 0, "type");
    test_assert_equal(strncmp(info->box.data_format, "mp4v", 4), 0, "data format");

    test_assert(info->ipmp_descriptors != NULL, "NULL IPMP box descriptors");
    IPMPInfoBox *ipmp = info->ipmp_descriptors;
    test_assert_equal(strncmp("imif", ipmp->box.type, 4), 0, "IPMP Info type");
    test_assert_equal(ipmp->box.size, 0x18, "IPMP Info size");
    test_assert_equal(ipmp->box.version, 0x00, "IPMP Info version");
    test_assert_equal(ipmp->box.flags, 0x000000, "IPMP Info flags");
    // TODO: IPMP Descriptors

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
        0, 0, 0x01, 0xD4,
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
        0, 0, 0, 0x5D,
        'i', 'p', 'r', 'o',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        0x00, 0x01, // protection count
        // Protection Scheme Info Box
        0, 0, 0, 0x4F,
        's', 'i', 'n', 'f',
        'm','p','4','v', // data format
        // IPMP Info Box
        0, 0, 0, 0x18,
        'i', 'm', 'i', 'f',
        0x00, // version
        0x00, 0x00, 0x00, // flags
        'd','e','s','c','r','i','p','t','o','r','s',0, // IPMP descriptors
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
    test_assert_equal(ipro->box.size, 0x5D, "ipro size");
    test_assert_equal(strncmp(ipro->box.type, "ipro", 4), 0, "ipro type");
    test_assert_equal(ipro->box.version, 0x00, "ipro version");
    test_assert_equal(ipro->box.flags, 0x000000, "ipro flags");
    test_assert_equal(ipro->protection_count, 1, "ipro protection count");
    test_assert(ipro->protection_info != NULL, "ipro protection info");

    ProtectionSchemeInfoBox *info = ipro->protection_info[0];
    test_assert_equal(info->box.box.size, 0x4F, "sinf size");
    test_assert_equal(strncmp(info->box.box.type, "sinf", 4), 0, "sinf type");
    test_assert_equal(strncmp(info->box.data_format, "mp4v", 4), 0, "sinf data format");
    test_assert(info->ipmp_descriptors != NULL, "NULL IPMP box descriptors");

    IPMPInfoBox *ipmp = info->ipmp_descriptors;
    test_assert_equal(strncmp("imif", ipmp->box.type, 4), 0, "IPMP Info type");
    test_assert_equal(ipmp->box.size, 0x18, "IPMP Info size");
    test_assert_equal(ipmp->box.version, 0x00, "IPMP Info version");
    test_assert_equal(ipmp->box.flags, 0x000000, "IPMP Info flags");
    // TODO: IPMP Descriptors
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
    test_assert_equal(ipmc->box.size, 0x95, "size");
    test_assert_equal(strncmp(ipmc->box.type, "ipmc", 4), 0, "type");
    test_assert_equal(ipmc->box.version, 0x00, "version");
    test_assert_equal(ipmc->box.flags, 0xFEDCBA, "flags");

    test_assert_equal(ipmc->tool_list.tag, 0x60, "tool list descriptor tag");
    test_assert_equal(ipmc->tool_list.num_tools, 2, "num of tool");

    IPMPTool *tool = &ipmc->tool_list.ipmp_tools[0];
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

    tool = &ipmc->tool_list.ipmp_tools[1];
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

    test_assert_equal(ipmc->ipmp_descriptors_len, 0x02, "descriptors length");
    uint8_t descriptors[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, };
    test_assert_equal(memcmp(ipmc->ipmp_descriptors, descriptors, 8), 0, "descriptor data");

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
