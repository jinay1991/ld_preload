#include "test.h"

int addition(int a, int b)
{
    printf(" -- %s() is adding %d and %d -- \n", __FUNCTION__, a, b);
    return a + b;
}
