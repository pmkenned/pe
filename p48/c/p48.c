#include <stdio.h>
#include <stdint.h>

#define ONE_E_TEN 10000000000

int main()
{
    uint64_t i, j;
    uint64_t sum = 0;
    for (i = 1; i <= 1000; i++) {
        uint64_t x = i;
        for (j = 1; j < i; j++) {
            x *= i;
            x %= ONE_E_TEN;
        }
        sum += x;
        sum %= ONE_E_TEN;
    }
    printf("%ld\n", sum);

    return 0;
}
