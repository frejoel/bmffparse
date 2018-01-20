#include <memory.h>
#include <stdio.h>

#include "bmff.h"
#include "parse.h"
#include "parse_common.h"
#include "context.h"

#define BOX_TYPE_IS(d,t) ((d)[0]==(t)[0] && (d)[1]==(t)[1] && (d)[2]==(t)[2] && (d)[3]==(t)[3])

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

BMFFCode bmff_set_event_callback(BMFFContext *ctx, bmff_on_event callback)
{
    if(!ctx) return BMFF_INVALID_CONTEXT;
    ctx->callback = callback;
    return BMFF_OK;
}

size_t bmff_parse(BMFFContext *ctx, const uint8_t *data, size_t size, BMFFCode *code)
{
    if(!ctx)        return BMFF_INVALID_CONTEXT;
    if(!data)       return BMFF_INVALID_DATA;
    if(size < 20)   return BMFF_INVALID_SIZE;
    if(!code)       return BMFF_INVALID_PARAMETER;

    // parse top level boxes
    const uint8_t *ptr = data;
    const uint8_t *end = data + size;

    while(ptr + 8 < end) {

        uint32_t box_size = parse_u32(ptr);
        // get the numerical value of the type, making sure to keep the bytes in
        // the correct order.
        uint32_t box_type = *((uint32_t*)(ptr+4));

        //printf("%c%c%c%c, size: %d\n", ptr[4], ptr[5], ptr[6], ptr[7], box_size);

        int i=0;
        for(; i<13; ++i) {
            uint32_t parser_box_type = parse_map[i].box_type_value;
            uint8_t parser_is_container_type = parse_map[i].is_container_type;
            if(parser_box_type == box_type) {
                if(parser_is_container_type == 1) {
                    bmff_context_alloc_stack_push(ctx);
                }
                Box *box;
                BMFFCode res = parse_map[i].parse_func(ctx, ptr, end-ptr, &box);
                if(res == BMFF_OK) {
                    if(ctx->callback) {
                        ctx->callback(ctx, BMFFEventParsed, ptr+4, (void*)box);
                    }
                    //printf("%c%c%c%c\n", box->type[0], box->type[1], box->type[2], box->type[3]);
                } else {
                    fprintf(stderr, "Error paring box: %d\n", res);
                    if(ctx->callback) {
                        ctx->callback(ctx, BMFFEventParseError, ptr+4, (void*)ptr);
                    }
                }
                if(parser_is_container_type) {
                    bmff_context_alloc_stack_pop(ctx);
                }
                break;
            }
        }

        ptr += box_size;
    }

    return end - ptr;
}

BMFFCode bmff_parse_end(BMFFContext *ctx)
{
    return BMFF_OK;
}
