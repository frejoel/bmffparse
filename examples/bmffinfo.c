#include <bmff.h>
void on_event(BMFFContext *ctx, BMFFEventId event_id, void *data)
{
    if(event_id == BMFFEventFileType) {
        FileTypeBox *box = (FileTypeBox*)data;
        printf("####################\n");
        printf("File Info:\n");
        printf("    Major Brand: %c%c%c%c\n", box->major_brand[0], box->major_brand[1], box->major_brand[2], box->major_brand[3]);
        printf("    Minor Version: %d\n", box->minor_version);
        int i=0;
        for(; i < box->nb_compatible_brands; ++i) {
            const uint8_t *b = &box->compatible_brands[i*4];
            printf("    Compatible Brand (%d): %c%c%c%c\n", i+1, b[0], b[1], b[2], b[3]);
        }
    }

    if(event_id == BMFFEventObjDescriptor) {
        ObjectDescriptorBox *box = (ObjectDescriptorBox*)data;
        printf("####################\n");
        printf("Object Descriptor:\n");
        printf("    od tag: %d\n", box->od.od_tag);
        printf("    od id: %d\n", box->od.od_id);
        printf("    url flag: %d\n", box->od.url_flag);
        printf("    include inline profile level flag: %d\n", box->od.include_inline_profile_level_flag);
        printf("    url length: %d\n", box->od.url_length);
        if(box->od.url) {
            printf("    od url: %s\n", box->od.url);
        }
    }

    if(event_id == BMFFEventMovieHeader) {
        MovieHeaderBox *box = (MovieHeaderBox*)data;
        printf("####################\n");
        printf("Movie Header:\n");
        printf("    Timescale (units per second): %u\n", box->timescale);
        printf("    Duration: %llu (in Timescale Units)\n", box->duration);
        printf("    Duration: %f seconds\n", (float)box->duration / (float)box->timescale);
        printf("    Preferred Playback Rate: %f\n", box->rate);
        printf("    Preferred Playback Volume: %f\n", box->volume);
        printf("    Next Track for this Presentation: %u\n", box->next_track_id);
    }

    if(event_id == BMFFEventTrackHeader) {
        TrackHeaderBox *box = (TrackHeaderBox*)data;
        printf("####################\n");
        printf("Track Header:\n");
        printf("    Track ID: %d\n", box->track_id);
        printf("    Duration: %llu (Timescale as specified in Movie Header)\n", box->duration);
        printf("    Alternate Group: %d\n", box->alternate_group);
        printf("    Enabled: %s\n", ((box->box.flags & 0x01) ? "yes" : "no"));
        printf("    Track in Movie: %s\n", ((box->box.flags & 0x02) ? "yes" : "no"));
        printf("    Track in Preview: %s\n", ((box->box.flags & 0x04) ? "yes" : "no"));
        printf("    Volume: %f\n", box->volume);
        const char *size_txt = ((box->box.flags & 0x08) ? "Aspect Ratio" : "Pixels");
        printf("    Width: %f (%s)\n", box->width, size_txt);
        printf("    Height: %f (%s)\n", box->height, size_txt);
    }

    static uint32_t media_timescale = 0;
    if(event_id == BMFFEventMediaHeader) {
        MediaHeaderBox *box = (MediaHeaderBox*)data;
        media_timescale = box->timescale;
        printf("####################\n");
        printf("Media Header:\n");
        printf("    Timescale (units per second): %u\n", box->timescale);
        printf("    Duration: %llu (in Timescale units)\n", box->duration);
        printf("    Duration: %f seconds\n", (float)box->duration / (float)box->timescale);
        const uint8_t *l = box->language;
        printf("    Language: %c%c%c (ISO-639-2/T Language Code)\n", l[0], l[1], l[2]);
    }

    if(event_id == BMFFEventVideoMediaHeader) {
        VideoMediaHeaderBox *box = (VideoMediaHeaderBox*)data;
        printf("####################\n");
        printf("Video Media Header:\n");
        printf("    Graphics Mode: %d\n", box->graphics_mode);
        const uint16_t *c = box->op_color;
        printf("    Graphics Mode Color: RGB(%d,%d,%d)\n", c[0], c[1], c[2]);
    }

    if(event_id == BMFFEventSoundMediaHeader) {
        SoundMediaHeaderBox *box = (SoundMediaHeaderBox*)data;
        printf("####################\n");
        printf("Sound Media Header:\n");
        printf("    Balance: %f\n", box->balance);
    }

    if(event_id == BMFFEventSampleDescription) {
        SampleDescriptionBox *box = (SampleDescriptionBox*)data;
        printf("####################\n");
        printf("Sample Description:\n");
        printf("    Entries: %d\n", box->entry_count);
        uint32_t i = 0;
        for(; i < box->entry_count; ++i) {
            const uint8_t *t = box->entries[i]->box.type;
            printf("    Sample Type (%d): %c%c%c%c\n", i, t[0], t[1], t[2], t[3]);
        }
    }

    if(event_id == BMFFEventVisualSample) {
        VisualSampleEntry *box = (VisualSampleEntry*)data;
        printf("####################\n");
        printf("Visual Sample:\n");
        const uint8_t *t = box->box.type;
        printf("    Sample Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
        printf("    Width: %d pixels\n", box->width);
        printf("    Height: %d pixels\n", box->height);
        printf("    Horizontal Resolution: %f ppi\n", box->horiz_resolution);
        printf("    Vertical Resolution: %f ppi\n", box->vert_resolution);
        printf("    Frame Count: %d\n", box->frame_count);
        printf("    Compressor Name: %s\n", box->compressor_name);
    }

    if(event_id == BMFFEventAudioSample) {
        AudioSampleEntry *box = (AudioSampleEntry*)data;
        printf("####################\n");
        printf("Audio Sample:\n");
        const uint8_t *t = box->box.type;
        printf("    Sample Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
        printf("    Channel Count: %d\n", box->channel_count);
        printf("    Sample Size: %d\n", box->sample_size);
        printf("    Sample Rate: %f\n", box->sample_rate);
        if(NULL != box->sampling_rate) {
            printf("    Sampling Rate: %u\n", box->sampling_rate->sampling_rate);
        }
    }

    if(event_id == BMFFEventHintSample) {
        HintSampleEntry *box = (HintSampleEntry*)data;
        printf("####################\n");
        printf("Hint Sample:\n");
        const uint8_t *t = box->box.type;
        printf("    Sample Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
        printf("    Data (first 10 bytes): ");
        uint32_t c = box->data_size > 10 ? 10 : box->data_size;
        uint32_t i = 0;
        for(; i<c; ++i) {
            printf("%c", box->data[i]);
        }
        printf("\n");
    }

    if(event_id == BMFFEventSampleSize) {
        SampleSizeBox *box = (SampleSizeBox*)data;
        printf("####################\n");
        printf("Sample Size:\n");
        printf("    Default Sample Size: %d\n", box->sample_size);
        printf("    Sample Count: %d\n", box->sample_count);
        printf("    Sample Entry Sizes (first 10): ");
        uint32_t i=0;
        uint32_t c = box->sample_count > 10 ? 10 : box->sample_count;
        for(; i<c; ++i) {
            printf("%d, ", box->entry_sizes[i]);
        }
        printf("...\n");
    }

    if(event_id == BMFFEventDataReference) {
        DataReferenceBox *box = (DataReferenceBox*)data;
        printf("####################\n");
        printf("Data Reference:\n");
        printf("    Entry Count: %d\n", box->entry_count);
        uint32_t i=0;
        for(;i<box->entry_count; ++i) {
            DataEntryBox *e = box->data_entries[i];
            printf("    Entry Name (%d): \"%s\"\n", e->name);
            printf("    Entry Location (%d): \"%s\"\n", e->location);
        }
    }

    if(event_id == BMFFEventHandler) {
        HandlerBox *box = (HandlerBox*)data;
        printf("####################\n");
        printf("Handler:\n");
        uint8_t *t = (uint8_t*)&box->handler_type;
        printf("    Handler Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
        printf("    Handler Name: %s\n", box->name);
    }

    if(event_id == BMFFEventTimeToSample) {
        TimeToSampleBox *box = (TimeToSampleBox*)data;
        printf("####################\n");
        printf("Time To Sample:\n");
        printf("    Sample Count: %d\n", box->sample_count);
        uint32_t i=0;
        for(;i<box->sample_count; ++i) {
            TimeToSample *e = &box->samples[i];
            printf("    Count of conseq samples with this duration (%d): %d\n", i, e->count);
            printf("    Delta of these samples in time-scale (%d): %d\n", i, e->delta);
            printf("    Delta in media timescale (%d): %f (samples per sec)\n", i, (float)media_timescale / (float)e->delta);
        }
    }

    if(event_id == BMFFEventSampleToChunk) {
        SampleToChunkBox *box = (SampleToChunkBox*)data;
        printf("####################\n");
        printf("Sample To Chunk:\n");
        printf("    Entry Count: %d\n", box->entry_count);
        uint32_t i=0;
        uint32_t c = box->entry_count > 5 ? 5 : box->entry_count;
        printf("    Entires (first 5):\n");
        for(;i<c; ++i) {
            SampleToChunk *e = &box->entries[i];
            printf("        First Chunk Index (%d): %d\n", i, e->first_chunk);
            printf("        Samples per Chunk (%d): %d\n", i, e->samples_per_chunk);
            printf("        Sample Description Index (%d): %d\n", i, e->sample_description_index);
        }
        if(c < box->entry_count) {
            printf("...\n");
        }
    }

    if(event_id == BMFFEventChunkOffset) {
        ChunkOffsetBox *box = (ChunkOffsetBox*)data;
        printf("####################\n");
        printf("Chunk Offset:\n");
        printf("    Entry Count: %d\n", box->entry_count);
        uint32_t i=0;
        uint32_t c = box->entry_count > 10 ? 10 : box->entry_count;
        printf("    Chunk Offsets into the file (first 10): ");
        for(;i<c; ++i) {
            printf("%d, ", box->chunk_offsets[i]);
        }
        printf("...\n");
    }

    if(event_id == BMFFEventSyncSample) {
        SyncSampleBox *box = (SyncSampleBox*)data;
        printf("####################\n");
        printf("Sync Sample:\n");
        printf("    Entry Count: %d\n", box->entry_count);
        uint32_t i=0;
        uint32_t c = box->entry_count > 10 ? 10 : box->entry_count;
        printf("    Sample Numbers of Sync Samples (first 10): ");
        for(;i<c; ++i) {
            printf("%d, ", box->sample_numbers[i]);
        }
        printf("...\n");
    }

    if(event_id == BMFFEventMeta) {
        MetaBox *box = (MetaBox*)data;
        printf("####################\n");
        printf("Meta:\n");
        uint8_t *t = (uint8_t*)&box->handler->handler_type;
        printf("    Handler Type: %c%c%c%c\n", t[0], t[1], t[2], t[3]);
        printf("    Has Primary Resource: %s\n", box->primary_resource ? "true" : "false");
        printf("    Has File Locations: %s\n", box->file_locations ? "true" : "false");
        printf("    Has Item Locations: %s\n", box->item_locations ? "true" : "false");
        printf("    Has Protections: %s\n", box->protections ? "true" : "false");
        printf("    Has Item Info: %s\n", box->item_infos ? "true" : "false");
        printf("    Has IPMP Control: %s\n", box->ipmp_control ? "true" : "false");
        printf("    Has Item References: %s\n", box->item_refs ? "true" : "false");
        printf("    Has Item Data: %s\n", box->item_data ? "true" : "false");
        printf("    Has Other Data: %s\n", box->other_boxes ? "true" : "false");
        if(box->other_boxes_len > 0) {
            printf("    Number of Other Boxes: %d\n", box->other_boxes_len);
        }
    }
}

int main(int argc, char** argv)
{
    BMFFContext ctx;
    BMFFCode res;

    bmff_context_init(&ctx);

    printf("opening file: %s\n", argv[1]);

    FILE *fp = fopen(argv[1], "rb");
    if(!fp) {
        fprintf(stderr, "failed to open file: %s\n", argv[1]);
        return 1;
    }
    uint8_t *buffer = (uint8_t*)malloc(1024*1024*5);
    size_t size = fread(buffer, 1, 1024*1024*5, fp);

    bmff_set_event_callback(&ctx, on_event);
    bmff_parse(&ctx, buffer, size, &res);

    fclose(fp);

    return 0;
}
