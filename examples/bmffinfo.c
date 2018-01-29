#include <stdio.h>
#include <bmff.h>
#include <string.h>

// indenting info
int indent_count;
char bread_crumb[1024];

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
        printf("\nParser Not Found: %c%c%c%c\n\n", fourCC[0], fourCC[1], fourCC[2], fourCC[3]);
    }
    else if(event_id == BMFFEventParseStart) {
        // a parsing function was found, and it will now start parsing.
        // data will be NULL in this scenario.
        // fourCC is the character code of the box to be parsed.
        char* crumb = &bread_crumb[indent_count * 5];
        if(indent_count > 0) {
            bread_crumb[(indent_count * 5)-1] = '>';
        }
        memcpy(crumb, fourCC, 4);
        crumb[4] = 0x00;
        indent_count++;
    }
    else if(event_id == BMFFEventParseError) {
        // a parsing function was found, but it encountered a parsing error.
        // data will be the raw bod data in this scenario.
        // fourCC is the character code of the box that was being parsed.
        // a BMFFEventParseComplete will NOT be triggered for this box.
        indent_count--;
        printf("---------------------\n");
        printf("###### ERROR parsing Box: %s\n", bread_crumb);
        printf("---------------------\n");
    }
    else if(event_id == BMFFEventParseComplete)
    {
        // a parsing function was found, and it completed parsing successfully.
        // data will be parsed box, it will need to be cast to the correct type.
        // fourCC is the character code of the box that was parsed.
        printf("------------------------------------\n");
        printf("| box: %s, size: %d\n", bread_crumb, ((Box*)data)->size);
        
        // variable for keeping track of timescales
        static uint32_t media_timescale = 0;

        // print out the Box information for a number of different boxes.
        if(strncmp("ftyp", fourCC, 4) == 0) {
            FileTypeBox *box = (FileTypeBox*)data;
            printf("|---------------------\n");
            printf("| File Info:\n");
            printf("|    Major Brand: %c%c%c%c\n", box->major_brand[0], box->major_brand[1], box->major_brand[2], box->major_brand[3]);
            printf("|    Minor Version: %d\n", box->minor_version);
            int i=0;
            for(; i < box->nb_compatible_brands; ++i) {
                const uint8_t *b = &box->compatible_brands[i*4];
                printf("|    Compatible Brand (%d): %c%c%c%c\n", i+1, b[0], b[1], b[2], b[3]);
            }
        }

        else if(strncmp("iods", fourCC, 4) == 0) {
            ObjectDescriptorBox *box = (ObjectDescriptorBox*)data;
            printf("|---------------------\n");
            printf("| Object Descriptor:\n");
            printf("|     od tag: %d\n", box->od.od_tag);
            printf("|     od id: %d\n", box->od.od_id);
            printf("|     url flag: %d\n", box->od.url_flag);
            printf("|     include inline profile level flag: %d\n", box->od.include_inline_profile_level_flag);
            printf("|     url length: %d\n", box->od.url_length);
            if(box->od.url) {
                printf("|     od url: %s\n", box->od.url);
            }
        }

        else if(strncmp("mvhd", fourCC, 4) == 0) {
            MovieHeaderBox *box = (MovieHeaderBox*)data;
            printf("|---------------------\n");
            printf("| Movie Header:\n");
            printf("|     Timescale (units per second): %u\n", box->timescale);
            printf("|     Duration: %llu (in Timescale Units)\n", box->duration);
            printf("|     Duration: %f seconds\n", (float)box->duration / (float)box->timescale);
            printf("|     Preferred Playback Rate: %f\n", box->rate);
            printf("|     Preferred Playback Volume: %f\n", box->volume);
            printf("|     Next Track for this Presentation: %u\n", box->next_track_id);
        }

        else if(strncmp("tkhd", fourCC, 4) == 0) {
            TrackHeaderBox *box = (TrackHeaderBox*)data;
            printf("|---------------------\n");
            printf("| Track Header:\n");
            printf("|     Track ID: %d\n", box->track_id);
            printf("|     Duration: %llu (Timescale as specified in Movie Header)\n", box->duration);
            printf("|     Alternate Group: %d\n", box->alternate_group);
            printf("|     Enabled: %s\n", ((box->box.flags & 0x01) ? "yes" : "no"));
            printf("|     Track in Movie: %s\n", ((box->box.flags & 0x02) ? "yes" : "no"));
            printf("|     Track in Preview: %s\n", ((box->box.flags & 0x04) ? "yes" : "no"));
            printf("|     Volume: %f\n", box->volume);
            const char *size_txt = ((box->box.flags & 0x08) ? "Aspect Ratio" : "Pixels");
            printf("|     Width: %f (%s)\n", box->width, size_txt);
            printf("|     Height: %f (%s)\n", box->height, size_txt);
        }

        else if(strncmp("mdhd", fourCC, 4) == 0) {
            MediaHeaderBox *box = (MediaHeaderBox*)data;
            media_timescale = box->timescale;
            printf("|---------------------\n");
            printf("| Media Header:\n");
            printf("|     Timescale (units per second): %u\n", box->timescale);
            printf("|     Duration: %llu (in Timescale units)\n", box->duration);
            printf("|     Duration: %f seconds\n", (float)box->duration / (float)box->timescale);
            const uint8_t *l = box->language;
            printf("|     Language: %c%c%c (ISO-639-2/T Language Code)\n", l[0], l[1], l[2]);
        }

        else if(strncmp("vmhd", fourCC, 4) == 0) {
            VideoMediaHeaderBox *box = (VideoMediaHeaderBox*)data;
            printf("|---------------------\n");
            printf("| Video Media Header:\n");
            printf("|     Graphics Mode: %d\n", box->graphics_mode);
            const uint16_t *c = box->op_color;
            printf("|     Graphics Mode Color: RGB(%d,%d,%d)\n", c[0], c[1], c[2]);
        }

        else if(strncmp("smhd", fourCC, 4) == 0) {
            SoundMediaHeaderBox *box = (SoundMediaHeaderBox*)data;
            printf("|---------------------\n");
            printf("| Sound Media Header:\n");
            printf("|     Balance: %f\n", box->balance);
        }

        else if(strncmp("stsd", fourCC, 4) == 0) {
            SampleDescriptionBox *box = (SampleDescriptionBox*)data;
            printf("|---------------------\n");
            printf("| Sample Description:\n");
            printf("|     Entries: %d\n", box->entry_count);
            uint32_t i = 0;
            for(; i < box->entry_count; ++i) {
                const uint8_t *t = box->entries[i]->box.type;
                printf("|     Sample Type (%d): %c%c%c%c, data reference index %d\n", i, t[0], t[1], t[2], t[3], box->entries[i]->data_reference_index);
            }
        }

        else if(strncmp("vide", fourCC, 4) == 0 || strncmp("icpv", fourCC, 4) == 0) {
            VisualSampleEntry *box = (VisualSampleEntry*)data;
            printf("|---------------------\n");
            printf("| Visual Sample:\n");
            const uint8_t *t = box->box.type;
            printf("|     Sample Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
            printf("|     Width: %d pixels\n", box->width);
            printf("|     Height: %d pixels\n", box->height);
            printf("|     Horizontal Resolution: %f ppi\n", box->horiz_resolution);
            printf("|     Vertical Resolution: %f ppi\n", box->vert_resolution);
            printf("|     Frame Count: %d\n", box->frame_count);
            printf("|     Compressor Name: %s\n", box->compressor_name);
        }

        else if(strncmp("soun", fourCC, 4) == 0 || strncmp("icpa", fourCC, 4) == 0) {
            AudioSampleEntry *box = (AudioSampleEntry*)data;
            printf("|---------------------\n");
            printf("| Audio Sample:\n");
            const uint8_t *t = box->box.type;
            printf("|     Sample Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
            printf("|     Channel Count: %d\n", box->channel_count);
            printf("|     Sample Size: %d\n", box->sample_size);
            printf("|     Sample Rate: %f\n", box->sample_rate);
            if(NULL != box->sampling_rate) {
                printf("|     Sampling Rate: %u\n", box->sampling_rate->sampling_rate);
            }
        }

        else if(strncmp("hint", fourCC, 4) == 0 || strncmp("icph", fourCC, 4) == 0) {
            HintSampleEntry *box = (HintSampleEntry*)data;
            printf("|---------------------\n");
            printf("| Hint Sample:\n");
            const uint8_t *t = box->box.type;
            printf("|     Sample Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
            printf("|     Data (first 10 bytes): ");
            uint32_t c = box->data_size > 10 ? 10 : box->data_size;
            uint32_t i = 0;
            for(; i<c; ++i) {
                printf("%c", box->data[i]);
            }
            printf("\n");
        }

        else if(strncmp("stsz", fourCC, 4) == 0) {
            SampleSizeBox *box = (SampleSizeBox*)data;
            printf("|---------------------\n");
            printf("| Sample Size:\n");
            printf("|     Default Sample Size: %d\n", box->sample_size);
            printf("|     Sample Count: %d\n", box->sample_count);

            uint32_t c = box->sample_count > 10 ? 10 : box->sample_count;
            if(c > 0) {
                printf("|     Sample Entry Sizes (first 10): ");
                uint32_t i=0;
                for(; i<c; ++i) {
                    printf("%d, ", box->entry_sizes[i]);
                }
                printf("...\n");
            }
        }

        else if(strncmp("dref", fourCC, 4) == 0) {
            DataReferenceBox *box = (DataReferenceBox*)data;
            printf("|---------------------\n");
            printf("| Data Reference:\n");
            printf("|     Entry Count: %d\n", box->entry_count);
            uint32_t i=0;
            for(;i<box->entry_count; ++i) {
                DataEntryBox *e = box->data_entries[i];
                printf("|     Entry Name (%d): \"%s\"\n", i, (e->name ? e->name : ""));
                printf("|     Entry Location (%d): \"%s\"\n", i, (e->location ? e->location : ""));
            }
        }

        else if(strncmp("hdlr", fourCC, 4) == 0) {
            HandlerBox *box = (HandlerBox*)data;
            printf("|---------------------\n");
            printf("| Handler:\n");
            uint8_t *t = (uint8_t*)&box->handler_type;
            printf("|     Handler Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
            printf("|     Handler Name: %s\n", box->name);
        }

        else if(strncmp("stts", fourCC, 4) == 0) {
            TimeToSampleBox *box = (TimeToSampleBox*)data;
            printf("|---------------------\n");
            printf("| Time To Sample:\n");
            printf("|     Sample Count: %d\n", box->sample_count);
            uint32_t i=0;
            for(;i<box->sample_count; ++i) {
                TimeToSample *e = &box->samples[i];
                printf("|     Count of conseq samples with this duration (%d): %d\n", i, e->count);
                printf("|     Delta of these samples in time-scale (%d): %d\n", i, e->delta);
                printf("|     Delta in media timescale (%d): %f (samples per sec)\n", i, (float)media_timescale / (float)e->delta);
            }
        }

        else if(strncmp("stsc", fourCC, 4) == 0) {
            SampleToChunkBox *box = (SampleToChunkBox*)data;
            printf("|---------------------\n");
            printf("| Sample To Chunk:\n");
            printf("|     Entry Count: %d\n", box->entry_count);
            uint32_t i=0;
            uint32_t c = box->entry_count > 5 ? 5 : box->entry_count;
            if(c > 0) {
                printf("|     Entires (first 5):\n");
                for(;i<c; ++i) {
                    SampleToChunk *e = &box->entries[i];
                    printf("|         First Chunk Index (%d): %d\n", i, e->first_chunk);
                    printf("|         Samples per Chunk (%d): %d\n", i, e->samples_per_chunk);
                    printf("|         Sample Description Index (%d): %d\n", i, e->sample_description_index);
                }
                if(c < box->entry_count) {
                    printf("| ...\n");
                }
            }
        }

        else if(strncmp("stco", fourCC, 4 == 0)) {
            ChunkOffsetBox *box = (ChunkOffsetBox*)data;
            printf("|---------------------\n");
            printf("| Chunk Offset:\n");
            printf("|     Entry Count: %d\n", box->entry_count);
            uint32_t i=0;
            uint32_t c = box->entry_count > 10 ? 10 : box->entry_count;
            printf("|     Chunk Offsets into the file (first 10): ");
            for(;i<c; ++i) {
                printf("%d, ", box->chunk_offsets[i]);
            }
            printf("...\n");
        }

        else if(strncmp("stss", fourCC, 4) == 0) {
            SyncSampleBox *box = (SyncSampleBox*)data;
            printf("|---------------------\n");
            printf("| Sync Sample:\n");
            printf("|     Entry Count: %d\n", box->entry_count);
            uint32_t i=0;
            uint32_t c = box->entry_count > 10 ? 10 : box->entry_count;
            printf("|     Sample Numbers of Sync Samples (first 10): ");
            for(;i<c; ++i) {
                printf("%d, ", box->sample_numbers[i]);
            }
            printf(".\n");
        }

        else if(strncmp("meta", fourCC, 4) == 0) {
            MetaBox *box = (MetaBox*)data;
            printf("|---------------------\n");
            printf("| Meta:\n");
            uint8_t *t = (uint8_t*)&box->handler->handler_type;
            printf("|     Handler Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
            printf("|     Has Primary Resource: %s\n", box->primary_resource ? "true" : "false");
            printf("|     Has File Locations: %s\n", box->file_locations ? "true" : "false");
            printf("|     Has Item Locations: %s\n", box->item_locations ? "true" : "false");
            printf("|     Has Protections: %s\n", box->protections ? "true" : "false");
            printf("|     Has Item Info: %s\n", box->item_infos ? "true" : "false");
            printf("|     Has IPMP Control: %s\n", box->ipmp_control ? "true" : "false");
            printf("|     Has Item References: %s\n", box->item_refs ? "true" : "false");
            printf("|     Has Item Data: %s\n", box->item_data ? "true" : "false");
            printf("|     Has Other Data: %s\n", box->other_boxes ? "true" : "false");
            if(box->other_boxes_len > 0) {
                printf("|     Number of Other Boxes: %d\n", box->other_boxes_len);
            }
        }

        else if(strncmp("schm", fourCC, 4) == 0) {
            SchemeTypeBox *box = (SchemeTypeBox*)data;
            printf("|---------------------\n");
            printf("| Scheme Type:\n");
            const uint8_t *t = box->scheme_type;
            printf("|     Scheme Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
            printf("|     Scheme Version: 0x%08X\n", box->scheme_version);
            printf("|     Scheme Type: \"%s\"\n", box->scheme_uri ? box->scheme_uri : "NULL");
        }

        else if(strncmp("tenc", fourCC, 4) == 0) {
            TrackEncryptionBox *box = (TrackEncryptionBox*)data;
            printf("|---------------------\n");
            printf("| Track Encryption:\n");
            printf("|     Default Crypt Byte Block: %d\n", box->default_crypt_byte_block);
            printf("|     Default skip Byte Block: %d\n", box->default_skip_byte_block);
            printf("|     Default Is Protected: %s\n", box->default_is_protected == eBooleanTrue ? "Yes" : "No");
            printf("|     Default Per Sample IV size: %d\n", box->default_per_sample_iv_size);
            printf("|     Default KID: 0x%02X%02X...\n", box->default_kid[0], box->default_kid[1]);
            printf("|     Default Constant IV Size: %d\n", box->default_constant_iv_size);
            printf("|     Default Constant IV: 0x%02X%02X...\n", box->default_constant_iv[0], box->default_constant_iv[1]);
        }

        else if(strncmp("senc", fourCC, 4) == 0) {
            SampleEncryptionBox *box = (SampleEncryptionBox*)data;
            printf("|---------------------\n");
            printf("| Sample Encryption:\n");
            printf("|     Sample Count: %d\n", box->sample_count);
            printf("|     Samples (first 3):\n");
            int i=0;
            int ic = box->sample_count > 3 ? 3 : box->sample_count;
            if(ic > 0) {
                for(; i<ic; ++i) {
                    EncryptionSample *s = &box->samples[i];
                    printf("|       Sample %d: IV Size: %d\n", i, s->iv_size);
                    printf("|       Sample %d: Subsample count: %d\n", i, s->subsample_count);
                    int j=0;
                    int jc = s->subsample_count > 3 ? 3 : s->subsample_count;
                    if(jc > 0) {
                        printf("|       Subsamples (first 3):\n");
                        for(; j<jc; ++j) {
                            EncryptionSubsample *ss = &s->subsamples[j];
                            printf("|         Subsample %d: Bytes of Clear Data: %d\n", j, ss->bytes_of_clear_data);
                            printf("|         Subsample %d: Bytes of Encrypted Data: %d\n", j, ss->bytes_of_encrypted_data);
                        }
                    }
                }
            }
        }

        else if(strncmp("pssh", fourCC, 4) == 0) {
            ProtectionSystemSpecificHeaderBox *box = (ProtectionSystemSpecificHeaderBox*)data;
            printf("|---------------------\n");
            printf("| Protection System Specific Header:\n");
            printf("|     system id: 0x");
            int i=0;
            for(;i<16;++i) {
                printf("%02X", box->system_id[i]);
            }
            printf("\n|     kid count: %d\n", box->kid_count);
            for(i=0;i<box->kid_count;++i) {
                printf("|     kid %d: ", i);
                int j=0;
                for(;j<16;++j) {
                    printf("%02X", box->kids[(i*16)+j]);
                }
                printf("\n");
            }
            printf("|     data size: %d\n", box->data_size);
        }

        printf("------------------------------------\n");

        indent_count--;
        bread_crumb[(indent_count * 5)-1] = 0x00;
    }
}

int main(int argc, char** argv)
{
    // indent initialization
    indent_count = 0;
    
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

    // the callback can be set at any time and gets called during bmff_parse.
    bmff_set_event_callback(&ctx, on_event);

    size_t buffer_size = 1024*1024;
    uint8_t *buffer = (uint8_t*)malloc(buffer_size);
    size_t size = fread(buffer, 1, buffer_size, fp);

    while(size > 0) {
        // parse our file which will trigger the callback.
        size_t parsed = bmff_parse(&ctx, buffer, size, &res);
        // it's possible to continue parsing parts of the file.
        // a complete Box must be parsed though, you cannot send in partial boxes to the parser.
        // bmff_parse returns the number of bytes that were sucessfully parsed.
        if(parsed < size) {
            memmove(buffer, &buffer[parsed], size-parsed);
        }
        size = fread(&buffer[parsed], 1, buffer_size-parsed, fp);
    };

    // end the parsing, do NOT start parsing data using the context after parse end
    // has been called.
    bmff_parse_end(&ctx);
    // destroy the context
    bmff_context_destroy(&ctx);

    fclose(fp);

    return 0;
}
