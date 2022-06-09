#include <setjmp.h>
#include "tlpi_hdr.h"

static jmp_buf env;

static void
f1(void)
{
    printf("Oi 1!\n");
    longjmp(env, 2);
}

static void
f2(void)
{
    printf("Oi 2!\n");
    longjmp(env, 99);
}

static void
f99(void)
{
    printf("Oi 3!\n");
    longjmp(env, 666);
}


int
main(int argc, char *argv[])
{
    int ret;
    int while_count = 0;

    ret = setjmp(env);
    while_count ++;
    if(ret == 0) {
        f1();
    }

    if(ret == 2) {
        f2();
    }

    if(ret == 99) {
        f99();
    }

    if(ret == 666) {
        printf("Rockzim top! %d\n", while_count);
    }


    exit(EXIT_SUCCESS);
}
