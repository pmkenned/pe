#include "../../common/common.h"
#include <stdio.h>
#include <math.h>

#define N 6

int main()
{
    int i, j, count = 0;
    int digits[6];
    for (i = 2; i < 1000000; i++) {
        if (is_prime(i)) {
            int nd = get_digits_base(i, digits, N, 10);
            int flag = 1;
            for (j = 0; j < nd-1; j++) {
                rotate(digits, nd);
                int r = from_digits_rev(digits, nd);
                if (!is_prime(r)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
