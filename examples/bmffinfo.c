#include <stdio.h>
#include <bmff.h>
#include <string.h>

// indenting defines
#define INDENT_TOTAL_SIZE (400)
#define INDENT_SIZE (2)

// indenting info
int indent_count;
char indent[INDENT_TOTAL_SIZE];

// increases indentation
void indent_inc(void)
{
    indent[indent_count] = ' ';
    indent_count += INDENT_SIZE;
    indent[indent_count] = 0;
}

// decreases indentation
void indent_dec(void)
{
    indent[indent_count] = ' ';
    indent_count -= INDENT_SIZE;
    indent[indent_count] = 0;
}

// Callback that is fired during the parsing process
void on_event(BMFFContext *ctx, BMFFEventId event_id, const uint8_t *fourCC, void *data)
{
    // every box in the file will have this callback triggered during the
    // parsing process (including free and container Boxes)

    // the event_id tells us which event is being triggered.
    if(event_id == BMFFEventParserNotFound) {
        // a parsing function of the box in question is not specified.
        // data contains the raw box data in this scenario.
        // fourCC is the character code of the box.
        printf("\nParser Not Found: %c%c%c%c\n\n", indent, fourCC[0], fourCC[1], fourCC[2], fourCC[3]);
    }
    else if(event_id == BMFFEventParseStart) {
        // a parsing function was found, and it will now start parsing.
        // data will be NULL in this scenario.
        // fourCC is the character code of the box to be parsed.
        indent_inc();
        printf("\n%sParse Box Starting: %c%c%c%c\n", indent, fourCC[0], fourCC[1], fourCC[2], fourCC[3]);
    }
    else if(event_id == BMFFEventParseError) {
        // a parsing function was found, but it encountered a parsing error.
        // data will be the raw bod data in this scenario.
        // fourCC is the character code of the box that was being parsed.
        // a BMFFEventParseComplete will NOT be triggered for this box.
        indent_dec();
        printf("\nError parsing Box: %c%c%c%c\n", indent, fourCC[0], fourCC[1], fourCC[2], fourCC[3]);
    }
    else if(event_id == BMFFEventParseComplete)
    {
        // a parsing function was found, and it completed parsing successfully.
        // data will be parsed box, it will need to be cast to the correct type.
        // fourCC is the character code of the box that was parsed.
        printf("\n%sParsed Box Complete: %c%c%c%c, size: %d\n", indent, fourCC[0], fourCC[1], fourCC[2], fourCC[3], ((Box*)data)->size);
        
        // variable for keeping track of timescales
        static uint32_t media_timescale = 0;

        // print out the Box information for a number of different boxes.
        if(strncmp("ftyp", fourCC, 4) == 0) {
            FileTypeBox *box = (FileTypeBox*)data;
            printf("%s####################\n", indent);
            printf("%sFile Info:\n", indent);
            printf("%s    Major Brand: %c%c%c%c\n", indent, box->major_brand[0], box->major_brand[1], box->major_brand[2], box->major_brand[3]);
            printf("%s    Minor Version: %d\n", indent, box->minor_version);
            int i=0;
            for(; i < box->nb_compatible_brands; ++i) {
                const uint8_t *b = &box->compatible_brands[i*4];
                printf("%s    Compatible Brand (%d): %c%c%c%c\n", indent, i+1, b[0], b[1], b[2], b[3]);
            }
        }

        else if(strncmp("iods", fourCC, 4) == 0) {
            ObjectDescriptorBox *box = (ObjectDescriptorBox*)data;
            printf("%s####################\n", indent);
            printf("%sObject Descriptor:\n", indent);
            printf("%s    od tag: %d\n", indent, box->od.od_tag);
            printf("%s    od id: %d\n", indent, box->od.od_id);
            printf("%s    url flag: %d\n", indent, box->od.url_flag);
            printf("%s    include inline profile level flag: %d\n", indent, box->od.include_inline_profile_level_flag);
            printf("%s    url length: %d\n", indent, box->od.url_length);
            if(box->od.url) {
                printf("%s    od url: %s\n", indent, box->od.url);
            }
        }

        else if(strncmp("mvhd", fourCC, 4) == 0) {
            MovieHeaderBox *box = (MovieHeaderBox*)data;
            printf("%s####################\n", indent);
            printf("%sMovie Header:\n", indent);
            printf("%s    Timescale (units per second): %u\n", indent, box->timescale);
            printf("%s    Duration: %llu (in Timescale Units)\n", indent, box->duration);
            printf("%s    Duration: %f seconds\n", indent, (float)box->duration / (float)box->timescale);
            printf("%s    Preferred Playback Rate: %f\n", indent, box->rate);
            printf("%s    Preferred Playback Volume: %f\n", indent, box->volume);
            printf("%s    Next Track for this Presentation: %u\n", indent, box->next_track_id);
        }

        else if(strncmp("tkhd", fourCC, 4) == 0) {
            TrackHeaderBox *box = (TrackHeaderBox*)data;
            printf("%s####################\n", indent);
            printf("%sTrack Header:\n", indent);
            printf("%s    Track ID: %d\n", indent, box->track_id);
            printf("%s    Duration: %llu (Timescale as specified in Movie Header)\n", indent, box->duration);
            printf("%s    Alternate Group: %d\n", indent, box->alternate_group);
            printf("%s    Enabled: %s\n", indent, ((box->box.flags & 0x01) ? "yes" : "no"));
            printf("%s    Track in Movie: %s\n", indent, ((box->box.flags & 0x02) ? "yes" : "no"));
            printf("%s    Track in Preview: %s\n", indent, ((box->box.flags & 0x04) ? "yes" : "no"));
            printf("%s    Volume: %f\n", indent, box->volume);
            const char *size_txt = ((box->box.flags & 0x08) ? "Aspect Ratio" : "Pixels");
            printf("%s    Width: %f (%s)\n", indent, box->width, size_txt);
            printf("%s    Height: %f (%s)\n", indent, box->height, size_txt);
        }

        else if(strncmp("mdhd", fourCC, 4) == 0) {
            MediaHeaderBox *box = (MediaHeaderBox*)data;
            media_timescale = box->timescale;
            printf("%s####################\n", indent);
            printf("%sMedia Header:\n", indent);
            printf("%s    Timescale (units per second): %u\n", indent, box->timescale);
            printf("%s    Duration: %llu (in Timescale units)\n", indent, box->duration);
            printf("%s    Duration: %f seconds\n", indent, (float)box->duration / (float)box->timescale);
            const uint8_t *l = box->language;
            printf("%s    Language: %c%c%c (ISO-639-2/T Language Code)\n", indent, l[0], l[1], l[2]);
        }

        else if(strncmp("vmhd", fourCC, 4) == 0) {
            VideoMediaHeaderBox *box = (VideoMediaHeaderBox*)data;
            printf("%s####################\n", indent);
            printf("%sVideo Media Header:\n", indent);
            printf("%s    Graphics Mode: %d\n", indent, box->graphics_mode);
            const uint16_t *c = box->op_color;
            printf("%s    Graphics Mode Color: RGB(%d,%d,%d)\n", indent, c[0], c[1], c[2]);
        }

        else if(strncmp("smhd", fourCC, 4) == 0) {
            SoundMediaHeaderBox *box = (SoundMediaHeaderBox*)data;
            printf("%s####################\n", indent);
            printf("%sSound Media Header:\n", indent);
            printf("%s    Balance: %f\n", indent, box->balance);
        }

        else if(strncmp("stsd", fourCC, 4) == 0) {
            SampleDescriptionBox *box = (SampleDescriptionBox*)data;
            printf("%s####################\n", indent);
            printf("%sSample Description:\n", indent);
            printf("%s    Entries: %d\n", indent, box->entry_count);
            uint32_t i = 0;
            for(; i < box->entry_count; ++i) {
                const uint8_t *t = box->entries[i]->box.type;
                printf("%s    Sample Type (%d): %c%c%c%c, data reference index %d\n", indent, i, t[0], t[1], t[2], t[3], box->entries[i]->data_reference_index);
            }
        }

        else if(strncmp("vide", fourCC, 4) == 0 || strncmp("icpv", fourCC, 4) == 0) {
            VisualSampleEntry *box = (VisualSampleEntry*)data;
            printf("%s####################\n", indent);
            printf("%sVisual Sample:\n", indent);
            const uint8_t *t = box->box.type;
            printf("%s    Sample Type: %c%c%c%c\n", indent, t[0], t[1], t[2], t[3]);
            printf("%s    Width: %d pixels\n", indent, box->width);
            printf("%s    Height: %d pixels\n", indent, box->height);
            printf("%s    Horizontal Resolution: %f ppi\n", indent, box->horiz_resolution);
            printf("%s    Vertical Resolution: %f ppi\n", indent, box->vert_resolution);
            printf("%s    Frame Count: %d\n", indent, box->frame_count);
            printf("%s    Compressor Name: %s\n", indent, box->compressor_name);
        }

        else if(strncmp("soun", fourCC, 4) == 0 || strncmp("icpa", fourCC, 4) == 0) {
            AudioSampleEntry *box = (AudioSampleEntry*)data;
            printf("%s####################\n", indent);
            printf("%sAudio Sample:\n", indent);
            const uint8_t *t = box->box.type;
            printf("%s    Sample Type: %c%c%c%c\n", indent, t[0], t[1], t[2], t[3]);
            printf("%s    Channel Count: %d\n", indent, box->channel_count);
            printf("%s    Sample Size: %d\n", indent, box->sample_size);
            printf("%s    Sample Rate: %f\n", indent, box->sample_rate);
            if(NULL != box->sampling_rate) {
                printf("%s    Sampling Rate: %u\n", indent, box->sampling_rate->sampling_rate);
            }
        }

        else if(strncmp("hint", fourCC, 4) == 0 || strncmp("icph", fourCC, 4) == 0) {
            HintSampleEntry *box = (HintSampleEntry*)data;
            printf("%s####################\n", indent);
            printf("%sHint Sample:\n", indent);
            const uint8_t *t = box->box.type;
            printf("%s    Sample Type: %c%c%c%c\n", indent, t[0], t[1], t[2], t[3]);
            printf("%s    Data (first 10 bytes): ", indent);
            uint32_t c = box->data_size > 10 ? 10 : box->data_size;
            uint32_t i = 0;
            for(; i<c; ++i) {
                printf("%c", box->data[i]);
            }
            printf("\n");
        }

        else if(strncmp("stsz", fourCC, 4) == 0) {
            SampleSizeBox *box = (SampleSizeBox*)data;
            printf("%s####################\n", indent);
            printf("%sSample Size:\n", indent);
            printf("%s    Default Sample Size: %d\n", indent, box->sample_size);
            printf("%s    Sample Count: %d\n", indent, box->sample_count);

            uint32_t c = box->sample_count > 10 ? 10 : box->sample_count;
            if(c > 0) {
                printf("%s    Sample Entry Sizes (first 10): ", indent);
                uint32_t i=0;
                for(; i<c; ++i) {
                    printf("%d, ", box->entry_sizes[i]);
                }
                printf("...\n");
            }
        }

        else if(strncmp("dref", fourCC, 4) == 0) {
            DataReferenceBox *box = (DataReferenceBox*)data;
            printf("%s####################\n", indent);
            printf("%sData Reference:\n", indent);
            printf("%s    Entry Count: %d\n", indent, box->entry_count);
            uint32_t i=0;
            for(;i<box->entry_count; ++i) {
                DataEntryBox *e = box->data_entries[i];
                printf("%s    Entry Name (%d): \"%s\"\n", indent, i, (e->name ? e->name : ""));
                printf("%s    Entry Location (%d): \"%s\"\n", indent, i, (e->location ? e->location : ""));
            }
        }

        else if(strncmp("hdlr", fourCC, 4) == 0) {
            HandlerBox *box = (HandlerBox*)data;
            printf("%s####################\n", indent);
            printf("%sHandler:\n", indent);
            uint8_t *t = (uint8_t*)&box->handler_type;
            printf("%s    Handler Type: %c%c%c%c\n", indent, t[0], t[1], t[2], t[3]);
            printf("%s    Handler Name: %s\n", indent, box->name);
        }

        else if(strncmp("stts", fourCC, 4) == 0) {
            TimeToSampleBox *box = (TimeToSampleBox*)data;
            printf("%s####################\n", indent);
            printf("%sTime To Sample:\n", indent);
            printf("%s    Sample Count: %d\n", indent, box->sample_count);
            uint32_t i=0;
            for(;i<box->sample_count; ++i) {
                TimeToSample *e = &box->samples[i];
                printf("%s    Count of conseq samples with this duration (%d): %d\n", indent, i, e->count);
                printf("%s    Delta of these samples in time-scale (%d): %d\n", indent, i, e->delta);
                printf("%s    Delta in media timescale (%d): %f (samples per sec)\n", indent, i, (float)media_timescale / (float)e->delta);
            }
        }

        else if(strncmp("stsc", fourCC, 4) == 0) {
            SampleToChunkBox *box = (SampleToChunkBox*)data;
            printf("%s####################\n", indent);
            printf("%sSample To Chunk:\n", indent);
            printf("%s    Entry Count: %d\n", indent, box->entry_count);
            uint32_t i=0;
            uint32_t c = box->entry_count > 5 ? 5 : box->entry_count;
            if(c > 0) {
                printf("%s    Entires (first 5):\n", indent);
                for(;i<c; ++i) {
                    SampleToChunk *e = &box->entries[i];
                    printf("%s        First Chunk Index (%d): %d\n", indent, i, e->first_chunk);
                    printf("%s        Samples per Chunk (%d): %d\n", indent, i, e->samples_per_chunk);
                    printf("%s        Sample Description Index (%d): %d\n", indent, i, e->sample_description_index);
                }
                if(c < box->entry_count) {
                    printf("%s...\n", indent);
                }
            }
        }

        else if(strncmp("stco", fourCC, 4 == 0)) {
            ChunkOffsetBox *box = (ChunkOffsetBox*)data;
            printf("%s####################\n", indent);
            printf("%sChunk Offset:\n", indent);
            printf("%s    Entry Count: %d\n", indent, box->entry_count);
            uint32_t i=0;
            uint32_t c = box->entry_count > 10 ? 10 : box->entry_count;
            printf("%s    Chunk Offsets into the file (first 10): ", indent);
            for(;i<c; ++i) {
                printf("%d, ", box->chunk_offsets[i]);
            }
            printf("...\n");
        }

        else if(strncmp("stss", fourCC, 4) == 0) {
            SyncSampleBox *box = (SyncSampleBox*)data;
            printf("%s####################\n", indent);
            printf("%sSync Sample:\n", indent);
            printf("%s    Entry Count: %d\n", indent, box->entry_count);
            uint32_t i=0;
            uint32_t c = box->entry_count > 10 ? 10 : box->entry_count;
            printf("%s    Sample Numbers of Sync Samples (first 10): ", indent);
            for(;i<c; ++i) {
                printf("%d, ", box->sample_numbers[i]);
            }
            printf(".\n");
        }

        else if(strncmp("meta", fourCC, 4) == 0) {
            MetaBox *box = (MetaBox*)data;
            printf("%s####################\n", indent);
            printf("%sMeta:\n", indent);
            uint8_t *t = (uint8_t*)&box->handler->handler_type;
            printf("%s    Handler Type: %c%c%c%c\n", indent, t[0], t[1], t[2], t[3]);
            printf("%s    Has Primary Resource: %s\n", indent, box->primary_resource ? "true" : "false");
            printf("%s    Has File Locations: %s\n", indent, box->file_locations ? "true" : "false");
            printf("%s    Has Item Locations: %s\n", indent, box->item_locations ? "true" : "false");
            printf("%s    Has Protections: %s\n", indent, box->protections ? "true" : "false");
            printf("%s    Has Item Info: %s\n", indent, box->item_infos ? "true" : "false");
            printf("%s    Has IPMP Control: %s\n", indent, box->ipmp_control ? "true" : "false");
            printf("%s    Has Item References: %s\n", indent, box->item_refs ? "true" : "false");
            printf("%s    Has Item Data: %s\n", indent, box->item_data ? "true" : "false");
            printf("%s    Has Other Data: %s\n", indent, box->other_boxes ? "true" : "false");
            if(box->other_boxes_len > 0) {
                printf("%s    Number of Other Boxes: %d\n", indent, box->other_boxes_len);
            }
        }

        else if(strncmp("schm", fourCC, 4) == 0) {
            SchemeTypeBox *box = (SchemeTypeBox*)data;
            printf("%s####################\n", indent);
            printf("%sScheme Type:\n", indent);
            const uint8_t *t = box->scheme_type;
            printf("%s    Scheme Type: %c%c%c%c\n", indent, t[0], t[1], t[2], t[3]);
            printf("%s    Scheme Version: 0x%08X\n", indent, box->scheme_version);
            printf("%s    Scheme Type: \"%s\"\n", indent, box->scheme_uri ? box->scheme_uri : "NULL");
        }

        else if(strncmp("tenc", fourCC, 4) == 0) {
            TrackEncryptionBox *box = (TrackEncryptionBox*)data;
            printf("%s####################\n", indent);
            printf("%sTrack Encryption:\n", indent);
            printf("%s    Default Crypt Byte Block: %d\n", indent, box->default_crypt_byte_block);
            printf("%s    Default skip Byte Block: %d\n", indent, box->default_skip_byte_block);
            printf("%s    Default Is Protected: %s\n", indent, box->default_is_protected == eBooleanTrue ? "Yes" : "No");
            printf("%s    Default Per Sample IV size: %d\n", indent, box->default_per_sample_iv_size);
            printf("%s    Default KID: 0x%02X%02X...\n", indent, box->default_kid[0], box->default_kid[1]);
            printf("%s    Default Constant IV Size: %d\n", indent, box->default_constant_iv_size);
            printf("%s    Default Constant IV: 0x%02X%02X...\n", indent, box->default_constant_iv[0], box->default_constant_iv[1]);
        }

        else if(strncmp("senc", fourCC, 4) == 0) {
            SampleEncryptionBox *box = (SampleEncryptionBox*)data;
            printf("%s####################\n", indent);
            printf("%sSample Encryption:\n", indent);
            printf("%s    Sample Count: %d\n", indent, box->sample_count);
            printf("%s    Samples (first 3):\n", indent);
            int i=0;
            int ic = box->sample_count > 3 ? 3 : box->sample_count;
            if(ic > 0) {
                for(; i<ic; ++i) {
                    EncryptionSample *s = &box->samples[i];
                    printf("%s      Sample %d: IV Size: %d\n", indent, i, s->iv_size);
                    printf("%s      Sample %d: Subsample count: %d\n", indent, i, s->subsample_count);
                    int j=0;
                    int jc = s->subsample_count > 3 ? 3 : s->subsample_count;
                    if(jc > 0) {
                        printf("%s      Subsamples (first 3):\n", indent);
                        for(; j<jc; ++j) {
                            EncryptionSubsample *ss = &s->subsamples[j];
                            printf("%s        Subsample %d: Bytes of Clear Data: %d\n", indent, j, ss->bytes_of_clear_data);
                            printf("%s        Subsample %d: Bytes of Encrypted Data: %d\n", indent, j, ss->bytes_of_encrypted_data);
                        }
                    }
                }
            }
        }

        indent_dec();
    }
}

int main(int argc, char** argv)
{
    // indent initialization
    indent_count = 0;
    memset(indent, ' ', INDENT_TOTAL_SIZE);
    
    // Parsing Context.
    BMFFContext ctx;
    // Return code.
    BMFFCode res;

    // initialize the parsing context.
    // this MUST be done prior to parsing.
    bmff_context_init(&ctx);

    printf("opening file:%s\n", argv[1]);

    FILE *fp = fopen(argv[1], "rb");
    if(!fp) {
        fprintf(stderr, "failed to open file: %s\n", argv[1]);
        return 1;
    }
    uint8_t *buffer = (uint8_t*)malloc(1024*1024*5);
    size_t size = fread(buffer, 1, 1024*1024*5, fp);

    // the callback can be set at any time and gets called during bmff_parse.
    bmff_set_event_callback(&ctx, on_event);
    // parse our file which will trigger the callback.
    size_t parsed = bmff_parse(&ctx, buffer, size, &res);
    // it's possible to continue parsing parts of the file.
    // a complete Box must be parsed though, you cannot send in partial boxes to the parser.
    // bmff_parse returns the number of bytes that were sucessfully parsed.

    // end the parsing, do NOT start parsing data using the context after parse end
    // has been called.
    bmff_parse_end(&ctx);

    fclose(fp);

    return 0;
}
