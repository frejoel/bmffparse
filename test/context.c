#include "test.h"
#include <bmff.h>

void test_init(void);
void test_destroy(void);

int main(int argc, char** argv)
{
    test_init();
    test_destroy();
    return 0;
}

void test_init(void)
{
    test_start("test_init");

    BMFFContext ctx;
    BMFFCode res;

    res = bmff_context_init(NULL);
    test_assert_equal(res, BMFF_INVALID_CONTEXT, "invalid context");

    res = bmff_context_init(&ctx);
    test_assert_equal(res, BMFF_OK, "success");

    test_end();
}

void test_destroy(void)
{
    test_start("test_destroy");

    BMFFContext ctx;
    BMFFCode res;

    res = bmff_context_destroy(NULL);
    test_assert_equal(res, BMFF_INVALID_CONTEXT, "invalid context");

    bmff_context_init(&ctx);
    res = bmff_context_destroy(&ctx);
    test_assert_equal(res, BMFF_OK, "success");

    test_end();
}
