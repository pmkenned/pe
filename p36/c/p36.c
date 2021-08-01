#include "../../common/common.h"
#include <stdio.h>

int main()
{
    int i, answer = 0;
    int digits[6], bits[20];
    for (i = 1; i < 1000000; i++) {
        int nd = get_digits(digits, 6, i,  10, LSD_AT_0);
        int nb = get_digits(bits, 20, i, 2, LSD_AT_0);
        if (is_palindrome(digits, nd) && is_palindrome(bits, nb))
            answer += i;
    }
    printf("%d\n", answer);

    return 0;
}
