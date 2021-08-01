#include "../../common/common.h"
#include <stdio.h>

int main()
{
    int i, j, count = 0, sum = 0;
    int digits[20];
    for (i = 11; 1; i++) {
        if (is_prime(i)) {
            int nd = get_digits(digits, 20, i, 10, LSD_AT_0);
            int flag = 1;
            for (j = nd-1; j > 0; j--) {
                int x = from_digits(digits, j, LSD_AT_0);
                if (!is_prime(x)) {
                    flag = 0;
                    break;
                }
            }
            for (j = 1; j < nd; j++) {
                int x = from_digits(digits+j, nd-j, LSD_AT_0);
                if (!is_prime(x)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                sum += i;
                if (++count >= 11)
                    break;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
