#include "test.h"
#include "stdlib.h"
int main()
{
    printf("- Start %s() -\n", __FUNCTION__);
    void *buf = malloc (10);
    free(buf);
    int ret = addition(5,6);
    printf("- End %s() with result=%d -\n", __FUNCTION__, ret);
    return 0;
}
