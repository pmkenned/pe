#include <stdio.h>
#include <math.h>
#include <stdint.h>

static int
is_triangle(int64_t x)
{
    int64_t i, lo = sqrt(x*2);
    for (i = lo; i < lo+2; i++)
        if (i*(i+1)/2 == x)
            return 1;
    return 0;
}

static int
is_pentagonal(int64_t x)
{
    int64_t i, lo = sqrt(x*2/3.0);
    for (i = lo; i < lo+2; i++)
        if (i*(3*i-1)/2 == x)
            return 1;
    return 0;
}

static int
is_hexagonal(int64_t x)
{
    int64_t i, lo = sqrt(x/2);
    for (i = lo; i < lo+2; i++)
        if (i*(2*i-1) == x)
            return 1;
    return 0;
}

int main()
{
    int64_t i;
    for (i = 40756; i < 2000000000; i++)
        if (is_triangle(i) && is_pentagonal(i) && is_hexagonal(i))
            break;
    printf("%lu\n", i);
    return 0;
}
