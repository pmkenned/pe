#include "../../common/common.h"
#include <stdio.h>

#define N 7

int main() {
    int j, k;
    int a[N];
    int max = 0;

    for (k = 4; k <= N; k++) {
        j = 0;
        while (1) {
            if (permute(a, k, j, 1))
                break;
            j++;
            int x = from_digits(a, k, MSD_AT_0);
            if (is_prime(x))
                max = x > max ? x : max;
        }
    }
    printf("%d\n", max);

    return 0;
}
