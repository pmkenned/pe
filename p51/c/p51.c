#include "../../common/common.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    int i, j, k, l;
    int pi;
    int digits_x0[10];
    int digits[10];

    for (pi = 1; pi < 100000; pi++) {

        uint64_t p = nth_prime(pi);
        if (p < 100)
            continue;

        int nd = get_digits(digits_x0, NELEM(digits_x0), p, 10, LSD_AT_0);

        int count;
        for (j = 2; j < nd; j++) {
            for (k = 1; k < j; k++) {
                for (l = 0; l < k; l++) {
                    memcpy(digits, digits_x0, sizeof(digits_x0));
                    count = 0;
                    for (i = 9; i >= 0; i--) {
                        if (j == nd-1 && i == 0)
                            continue;
                        digits[l] = i;
                        digits[k] = i;
                        digits[j] = i;
                        uint64_t x1 = from_digits(digits, nd, LSD_AT_0);
                        count += is_prime(x1); 
#if 1
                        if (count >= 8) {
                            printf("%ld\n", x1);
                            return 0;
                        }
#endif
                    }
#if 1
                    if (count >= 8) {
                        for (i = nd-1; i >= 0; i--) {
                            if (i == j || i == k || i == l)
                                printf("*");
                            else
                                printf("%d", digits[i]);
                        }
                        printf("\n");
                        return 0;
                    }
#endif
                }
            }
        }
    }

    return 0;
}
