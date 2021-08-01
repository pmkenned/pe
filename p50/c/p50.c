#include "../../common/common.h"
#include <stdio.h>

int main()
{
    int longest = 0;
    int i, j;
    uint64_t longest_sum;
    uint64_t sum;
    for (i = 1; i < 10; i++) {
        sum = nth_prime(i);
        int nterms = 1;
        for (j = 1; j <= 700; j++) {
            sum += nth_prime(i+j);
            if (sum > 1000000)
                break;
            if (is_prime(sum))
                nterms = j+1;
            if (nterms > longest) {
                longest = nterms;
                longest_sum = sum;
            }
        }
    }
    printf("%ld\n", longest_sum);

    return 0;
}
