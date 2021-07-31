#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define ABS(x) ((x) >= 0 ? (x) : -(x))

static int64_t nth_pentagonal(int n) { return n*(3*n-1)/2; }

static int
is_pentagonal(int64_t x)
{
    int i;
    int64_t lo = sqrt(x*2/3.0);
    for (i = lo; i < lo+2; i++)
        if (nth_pentagonal(i) == x)
            return 1;
    return 0;
}

int main()
{
    int i, j;
    int64_t d, min_d = INT64_MAX;
    int64_t p_i, p_j;
    int64_t sum, diff;
    for (i = 1; i < 20000; i++) {
        p_i = nth_pentagonal(i);
        for (j = 1; j < 20000; j++) {
            if (i == j)
                continue;
            p_j = nth_pentagonal(j);
            sum  = p_i + p_j;
            diff = p_i - p_j;
            if (is_pentagonal(sum) && is_pentagonal(diff)) {
                d = ABS(diff);
                min_d = (d < min_d) ? d : min_d;
            }
        }
    }
    printf("%ld\n", min_d);
    return 0;
}
