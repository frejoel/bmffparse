#include <memory.h>
#include <stdio.h>

#include "bmff.h"
#include "parse.h"
#include "parse_common.h"
#include "context.h"

#define BOX_TYPE_IS(d,t) ((d)[0]==(t)[0] && (d)[1]==(t)[1] && (d)[2]==(t)[2] && (d)[3]==(t)[3])
#define CALLBACK(c, e, f, d)  if((c)->callback) { (c)->callback((c), (e), (f), (void*)(d), (c)->callback_user_data); }

const char *bmff_get_version(void)
{
    return BMFF_VERSION;
}

BMFFCode bmff_context_init(BMFFContext *ctx)
{
    if(!ctx) return BMFF_INVALID_CONTEXT;

    memset(ctx, 0, sizeof(BMFFContext));
    ctx->malloc = malloc;
    ctx->calloc = calloc;
    ctx->realloc = realloc;
    ctx->free = free;

    return BMFF_OK;
}

BMFFCode bmff_context_destroy(BMFFContext *ctx)
{
    if(!ctx) return BMFF_INVALID_CONTEXT;
    memset(ctx, 0, sizeof(BMFFContext));
    return BMFF_OK;
}

BMFFCode bmff_set_event_callback(BMFFContext *ctx, bmff_on_event callback, void *user_data)
{
    if(!ctx) return BMFF_INVALID_CONTEXT;
    ctx->callback = callback;
    ctx->callback_user_data = user_data;
    return BMFF_OK;
}

size_t bmff_parse(BMFFContext *ctx, const uint8_t *data, size_t size, BMFFCode *code)
{
    if (!ctx)        return BMFF_INVALID_CONTEXT;
    if (!data)       return BMFF_INVALID_DATA;
    if (size < 20)   return BMFF_INVALID_SIZE;
    if (!code)       return BMFF_INVALID_PARAMETER;

    _init_global_parse_map();

    // parse top level boxes
    const uint8_t *ptr = data;
    const uint8_t *end = data + size;

    while(ptr + 8 < end) {

        uint64_t box_size = parse_u32(ptr);
        if(box_size == 1) {
            box_size = parse_u64(&ptr[8]);
        }
        if(box_size == 0) {
            // box goes to the end of the file
            box_size = (uint64_t)(end - ptr);
        }
        // make sure we have enough data to parse this box, otherwise exit parsing
        if(ptr + box_size > end) {
            break;
        }

        // get the numerical value of the type, making sure to keep the bytes in
        // the correct order.
        uint32_t box_type = *((uint32_t*)(ptr+4));

        //printf("%c%c%c%c, size: %d\n", ptr[4], ptr[5], ptr[6], ptr[7], box_size);

        int i=0;
        for(; i < PARSE_MAP_LEN; ++i) {
            uint32_t parser_box_type = parse_map[i].box_type_value;
            uint8_t parser_is_container_type = parse_map[i].is_container_type;
            if(parser_box_type == box_type) {
                if(parser_is_container_type == 1) {
                    bmff_context_alloc_stack_push(ctx);
                }

                Box *box;
                CALLBACK(ctx, BMFFEventParseStart, ptr+4, NULL);
                _bmff_breadcrumb_push(ctx, ptr+4);

                BMFFCode res = parse_map[i].parse_func(ctx, ptr, end-ptr, &box);
                
                if(res == BMFF_OK) {
                    _bmff_breadcrumb_pop(ctx);
                    CALLBACK(ctx, BMFFEventParseComplete, ptr+4, (void*)box);
                } else {
                    fprintf(stderr, "Error paring box: %d\n", res);
                    _bmff_breadcrumb_pop(ctx);
                    CALLBACK(ctx, BMFFEventParseError, ptr+4, (void*)ptr);
                }
                
                if(parser_is_container_type) {
                    bmff_context_alloc_stack_pop(ctx);
                }
                break;
            }
        }

        if(i == PARSE_MAP_LEN) {
            CALLBACK(ctx, BMFFEventParserNotFound, ptr+4, (void*)ptr);
        }

        ptr += box_size;
    }

    return ptr - data;
}

BMFFCode bmff_parse_end(BMFFContext *ctx)
{
    return BMFF_OK;
}
