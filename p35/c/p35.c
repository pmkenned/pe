#include <stdio.h>
#include <math.h>

#define N 6

static void
rotate(int * a, int n)
{
    int i, t = a[0];
    for (i = 0; i < n; i++)
        a[i] = a[i+1];
    a[n-1] = t;
}

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
get_digits(int x, int * digits, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        digits[i] = x % 10;
        x /= 10;
    }
    for (i = n-1; i >= 0; i--)
        if (digits[i] != 0)
            return i+1;
    return 0;
}

static int
is_prime(int n)
{
    int i, hi = (int) sqrt(n);
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (i = 3; i <= hi; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int i, j, count = 0;
    int digits[6];
    for (i = 2; i < 1000000; i++) {
        if (is_prime(i)) {
            int nd = get_digits(i, digits, N);
            int flag = 1;
            for (j = 0; j < nd-1; j++) {
                rotate(digits, nd);
                int r = from_digits(digits, nd);
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
