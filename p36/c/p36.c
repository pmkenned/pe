#include <stdio.h>

static int
get_digits_base(int x, int * bits, int n, int b)
{
    int i;
    for (i = 0; i < n; i++) {
        bits[i] = x % b;
        x /= b;
    }
    for (i = n-1; i >= 0; i--)
        if (bits[i] != 0)
            return i+1;
    return 0;
}

static int
is_palindrome(int * a, int n)
{
    int i;
    for (i = 0; i < n/2; i++) {
        if (a[i] != a[n-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    int i, j, answer = 0;
    int digits[6], bits[20];
    for (i = 1; i < 1000000; i++) {
        int nd = get_digits_base(i, digits, 6, 10);
        int nb = get_digits_base(i, bits, 20, 2);
        if (is_palindrome(digits, nd) && is_palindrome(bits, nb))
            answer += i;
    }
    printf("%d\n", answer);

    return 0;
}
