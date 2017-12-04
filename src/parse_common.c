#include "parse_common.h"

uint16_t parse_u16(const uint8_t *bytes)
{
    uint16_t val = *((uint16_t*)bytes);
#ifdef __BIG_ENDIAN__
    return val;
#else
    return ((val >> 8) & 0x00FF) | ((val << 8) & 0xFF00);
#endif
}

uint32_t parse_u32(const uint8_t *bytes)
{
    uint32_t val = *((uint32_t*)bytes);
#ifdef __BIG_ENDIAN__
    return val;
#else
    return ((val >> 24) & 0x000000FF) |
           ((val >>  8) & 0x0000FF00) |
           ((val <<  8) & 0x00FF0000) |
           ((val << 24) & 0xFF000000) ;
#endif
}

uint64_t parse_u64(const uint8_t *bytes)
{
    uint64_t val = *((uint64_t*)bytes);
#ifdef __BIG_ENDIAN__
    return val;
#else
    return ((val >> 56) & 0x00000000000000FFL) |
           ((val >> 40) & 0x000000000000FF00L) |
           ((val >> 24) & 0x0000000000FF0000L) |
           ((val >>  8) & 0x00000000FF000000L) |
           ((val <<  8) & 0x000000FF00000000L) |
           ((val << 24) & 0x0000FF0000000000L) |
           ((val << 40) & 0x00FF000000000000L) |
           ((val << 56) & 0xFF00000000000000L) ;
#endif
}

fxpt16_t parse_fp16(const uint8_t *bytes)
{
    float val = (float) ((int32_t) parse_u32(bytes));
    return val / 65536.f;
}

fxpt8_t parse_fp8(const uint8_t *bytes)
{
    float val = (float) ((int16_t) parse_u16(bytes));
    return val / 256.f;
}

uint32_t parse_var_length(const uint8_t *bytes, uint8_t length)
{
    uint32_t val = 0;

    switch(length) {
        case 1: val = bytes[0]; break;
        case 2: val = (uint32_t) parse_u16(bytes); break;
        case 3: val = (parse_u32(bytes) >> 8) & 0xFFFFFF; break;
        case 4: val = parse_u32(bytes); break;
    }

    return val;
}
