#include <stdio.h>
#include <assert.h>

#define MAX_DIGITS 100

static int
is_pandigital(const int * a, int n)
{
    int i;
    int digits[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < n; i++) {
        int c = a[i];
        if (c >= 1 && c <= 9)
            digits[c - 1]++;
        else
            return 0;
    }
    for (i = 0; i < n; i++) {
        if (digits[i] != 1) {
            return 0;
        }
    }
    return 1;
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

static void
reverse(int * a, int n)
{
    int i;
    for (i = 0; i < n/2; i++) {
        int t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
}

static int
get_digits_base(int x, int * digits, int n, int b)
{
    int i;
    for (i = 0; i < n; i++) {
        digits[i] = x % b;
        x /= b;
    }
    int nd = 0;
    for (i = n-1; i >= 0; i--) {
        if (digits[i] != 0) {
            nd = i+1;
            break;
        }
    }
    reverse(digits, nd);
    return nd;
}

int main()
{
    int i, x, n;
    int digits[MAX_DIGITS];
    int max = 0;

    for (x = 2; x < 10000; x++) {
        for (n = 2; n < 15; n++) {
            int nd = 0;
            for (i = 1; i <= n; i++) {
                nd += get_digits_base(x*i, digits+nd, MAX_DIGITS-nd, 10);
                assert(nd < MAX_DIGITS);
            }
            if (nd == 9 && is_pandigital(digits, 9)) {
                reverse(digits, 9);
                int pd = from_digits(digits, 9);
                max = (pd > max) ? pd : max;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
