#include "../../common/common.h"
#include <stdio.h>
#include <assert.h>

#define MAX_DIGITS 100

int main()
{
    int i, x, n;
    int digits[MAX_DIGITS];
    int max = 0;

    for (x = 2; x < 10000; x++) {
        for (n = 2; n < 15; n++) {
            int nd = 0;
            for (i = 1; i <= n; i++) {
                int nd_i = get_digits_base(x*i, digits+nd, MAX_DIGITS-nd, 10);
                reverse(digits+nd, nd_i);
                nd += nd_i;
                assert(nd < MAX_DIGITS);
            }
            if (nd == 9 && is_pandigital(digits, 1, 9)) {
                int pd = from_digits(digits, 9);
                max = (pd > max) ? pd : max;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
