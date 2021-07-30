#include "../../common/common.h"
#include <stdio.h>

int main()
{
    int i, j, count = 0, sum = 0;
    int digits[20];
    for (i = 11; 1; i++) {
        if (is_prime(i)) {
            int nd = get_digits_base(i, digits, 20, 10);
            int flag = 1;
            for (j = nd-1; j > 0; j--) {
                int x = from_digits_rev(digits, j);
                if (!is_prime(x)) {
                    flag = 0;
                    break;
                }
            }
            for (j = 1; j < nd; j++) {
                int x = from_digits_rev(digits+j, nd-j);
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
