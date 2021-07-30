#include <stdio.h>
#include <math.h>

static int
from_digits(int * digits, int n)
{
    int i, rv = 0;
    for (i = n-1; i >= 0; i--) {
        rv *= 10;
        rv += digits[i];
    }
    return rv;
}

static int
get_digits_base(int x, int * digits, int n, int b)
{
    int i;
    for (i = 0; i < n; i++) {
        digits[i] = x % b;
        x /= b;
    }
    for (i = n-1; i >= 0; i--)
        if (digits[i] != 0)
            return i+1;
    return 0;
}

// TODO: memoize
static int
is_prime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    int i, hi = (int) sqrt(n);
    for (i = 3; i <= hi; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int i, j, count = 0, sum = 0;
    int digits[20];
    for (i = 11; 1; i++) {
        if (is_prime(i)) {
            int nd = get_digits_base(i, digits, 20, 10);
            int flag = 1;
            for (j = nd-1; j > 0; j--) {
                int x = from_digits(digits, j);
                if (!is_prime(x)) {
                    flag = 0;
                    break;
                }
            }
            for (j = 1; j < nd; j++) {
                int x = from_digits(digits+j, nd-j);
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
    printf("sum: %d\n", sum);
    return 0;
}
