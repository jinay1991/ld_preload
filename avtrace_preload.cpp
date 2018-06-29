#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>
#include <iostream>

#include "AVTrace.hpp"

#define FUNC_START  printf("[INTERCEPT] START: %s()\n", __FUNCTION__)
#define FUNC_END    printf("[INTERCEPT] END: %s()\n", __FUNCTION__)

static void __init__(void) __attribute__((constructor));

typedef static inline void (*avTraceBegin_t)(const char *, uint32_t, std::string, uint32_t, std::string);
typedef static inline void (*avTraceEnd_t)(const char *, uint32_t, std::string, uint32_t, std::string);

void __init__(void)
{
    printf(" ### Start %s() ###\n", __FUNCTION__);
    char *error = NULL;
    dlerror();

    avTraceBegin_fn = (avTraceBegin_t)dlsym(RTLD_NEXT, "avTraceBegin");
    avTraceEnd_fn = (avTraceEnd_t)dlsym(RTLD_NEXT, "avTraceEnd");

    if ((error = dlerror()) != NULL)
    {
        printf(" *** ERROR *** %s\n", error);
    }
    else
    {
        printf("avTraceBegin_fn: %p\n", avTraceBegin_fn);
        printf("avTraceEnd_fn: %p\n", avTraceEnd_fn);
    }
}

static inline void avTraceBegin(const char *func,
                                uint32_t chan, std::string name = "",
                                uint32_t level = AV_TRACE_LEVEL_DEFAULT,
                                std::string payload = "")
{
    FUNC_START;
    avTraceBegin(func, chan, name, level, payload);
    FUNC_END;
}

static inline void avTraceEnd(const char *func,
                              uint32_t chan, std::string name = "",
                              uint32_t level = AV_TRACE_LEVEL_DEFAULT,
                              std::string payload = "")
{
    FUNC_START;
    avTraceEnd(func, chan, name, level, payload);
    FUNC_END;
}