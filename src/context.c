#include "context.h"
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#	define SNPRINTF	sprintf_s
#else
#	define SNPRINTF	snprintf
#endif

void bmff_context_alloc_stack_push(BMFFContext *ctx)
{
    if(ctx) {
        MemList *new_list = (MemList*) ctx->malloc(sizeof(MemList));
        new_list->count = 8;
        new_list->addresses = (size_t*) ctx->malloc(sizeof(size_t) * new_list->count);
        new_list->used = 0;
        new_list->next = ctx->allocs_stack;
        ctx->allocs_stack = new_list;
    }
}

void bmff_context_alloc_stack_pop(BMFFContext *ctx) {
    if(ctx && ctx->allocs_stack) {
        MemList *old_list = ctx->allocs_stack;
        ctx->allocs_stack = ctx->allocs_stack->next;

        uint32_t i=old_list->used;
        for(; i > 0; --i) {
            ctx->free((void*)old_list->addresses[i-1]);
        }
        ctx->free(old_list->addresses);
        ctx->free(old_list);
    }
}

void * bmff_context_alloc_on_stack(BMFFContext *ctx, size_t size)
{
    if(ctx) {
        void *mem = ctx->malloc(size);

        if(ctx->allocs_stack) {
            // extend address space so we can add it to the stack.
            if(ctx->allocs_stack->used == ctx->allocs_stack->count) {
                // extend address space so we can add it to the stack.
                uint32_t new_count = ctx->allocs_stack->count + 8;
                size_t *new_addresses = ctx->malloc(sizeof(size_t) * new_count);
                // copy old addresses into new list
                uint32_t i=0;
                for(; i < ctx->allocs_stack->used; ++i) {
                    new_addresses[i] = ctx->allocs_stack->addresses[i];
                }
                // adjust count and free old address space
                ctx->allocs_stack->count = new_count;
                ctx->free(ctx->allocs_stack->addresses);
                ctx->allocs_stack->addresses = new_addresses;
            }
            // add allocation to the stack.
            ctx->allocs_stack->addresses[ctx->allocs_stack->used] = (size_t)mem;
            ctx->allocs_stack->used++;
        }
        return mem;
    }
    return NULL;
}

void _bmff_breadcrumb_push(BMFFContext *ctx, const uint8_t *crumb)
{
    size_t len = strlen(ctx->breadcrumb);
    if(len < BMFF_BREADCRUMB_SIZE - 5)
    {
        const char *format = len == 0 ? "%c%c%c%c" : ".%c%c%c%c";
		SNPRINTF(&ctx->breadcrumb[len], BMFF_BREADCRUMB_SIZE - 5 - len, format, crumb[0], crumb[1], crumb[2], crumb[3]);
    }
}

void _bmff_breadcrumb_pop(BMFFContext *ctx)
{
    size_t len = strlen(ctx->breadcrumb);
    if(len > 4) {
        ctx->breadcrumb[len-5] = '\00';        
    }else{
        ctx->breadcrumb[0] = '\00';
    }
}

const char * bmff_get_breadcrumb(BMFFContext *ctx)
{
    if(ctx) {
        return ctx->breadcrumb;
    }
    return NULL;
}