#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>

// /* lcheck() is for memory leak check; its code is not shown
//  here */
// void lcheck(void);
// void *malloc(size_t size)
// {
//     static void *(*my_malloc)(size_t) = NULL;
//     printf("inside shared object...\n");
//     if (!my_malloc)
//         my_malloc = dlsym(RTLD_NEXT, "malloc"); /* returns the object reference for malloc */
//     void *p = my_malloc(size);                  /* call malloc() using function pointer my_malloc */
//     printf("malloc(%d) = %p\n", (int)size, p);
//     lcheck(); /* calling do_your_stuff function */
//     printf("returning from shared object...\n");
//     return p;
// }
// void lcheck(void)
// {
//     printf("displaying memory leaks...\n");
//     /* do required stuff here */
// }
typedef int (*function_t)(int , int );

static void __init__(void) __attribute__((constructor));
function_t original_addition = NULL;
function_t intercepted_addition = NULL;

int addition(int a, int b)
{
    printf(" === Successfully intercepted %s() ===\n", __FUNCTION__);
    printf(" ### Start: %s() ###\n", __FUNCTION__);
    int ret = -1;
    if (original_addition != NULL)
        ret = (*original_addition)(a, b);
    printf(" ### End: %s() ###\n", __FUNCTION__);
    printf("---- Returned: %d ----\n", ret);
    return ret;
}

void __init__(void)
{
    printf(" ### Start %s() ###\n", __FUNCTION__);
    char *error = NULL;
    dlerror(); /* clear previous errors */
    // read environment vairable TARGET_FUNCTION_NAME_MANGLED */
    for(int i =0 ; i <len(TAGR);i++)
    original_addition = (function_t) dlsym(RTLD_NEXT, "addition");
    if ((error = dlerror()) != NULL) /* check for errors of dlsym */
    {
        printf("ERR: %s\n", error);
    }
    printf("DBG: original_addition: %p\n", original_addition);
}
