#include "../../common/common.h"
#include <stdio.h>
#include <stdint.h>

int main()
{
    uint64_t i, j, k = 0;
    is_prime_backfill(1000000);
    printf("%zu\n", num_primes);
    for (i = 9; i < 1000000; i += 2) {
        if (is_prime(i))
            continue;
        /* i is odd composite */
        int flag = 0;
        for (j = 0; j < 5000; j++) {
            uint64_t j2_2 = 2*j*j;
            if (j2_2 > i) {
                flag = 1;
                break;
            }
            uint64_t sought = i - j2_2;
            for (k = 0; k < num_primes; k++) {
                if (primes[k] > sought)
                    break;
                if (primes[k] == sought)
                    goto next_i;
            }
        }
        if (flag) {
            printf("%ld\n", i);
            break;
        }
next_i:
        ;
    }

    return 0;
}
