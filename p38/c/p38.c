#include "../../common/common.h"
#include <stdio.h>
#include <assert.h>

#define MAX_DIGITS 100

int main()
{
    int i, x, n;
    int digits[MAX_DIGITS];
    uint64_t max = 0;

    for (x = 2; x < 10000; x++) {
        for (n = 2; n < 15; n++) {
            int nd = 0;
            for (i = 1; i <= n; i++) {
                int nd_i = get_digits_base(digits+nd, MAX_DIGITS-nd, x*i, 10, LSD_AT_0);
                reverse(digits+nd, nd_i);
                nd += nd_i;
                assert(nd < MAX_DIGITS);
            }
            if (nd == 9 && is_pandigital(digits, 1, 9)) {
                uint64_t pd = from_digits(digits, 9, MSD_AT_0);
                max = (pd > max) ? pd : max;
            }
        }
    }
    printf("%ld\n", max);
    return 0;
}
