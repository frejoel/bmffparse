#include "test.h"
#include <bmff.h>

void test_parse(void);

int main(int argc, char** argv)
{
    test_parse();
    return 0;
}

void test_parse(void)
{
    test_start("test_parse");

    BMFFContext ctx;
    BMFFCode res;

    bmff_context_init(&ctx);

    FILE *fp = fopen("data/02_f.mp4", "rb");
    uint8_t *buffer = (uint8_t*)malloc(1024*1024*5);
    size_t size = fread(buffer, 1, 1024*1024*5, fp);

    bmff_parse(&ctx, buffer, size, &res);

    fclose(fp);

    test_end();
}
