#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_FS 100

static int
str_is_pandigital(const char * s, int m)
{
    int i;
    int digits[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int l = (int) strlen(s);
    for (i = 0; i < l; i++) {
        char c = s[i];
        if (c >= '1' && c <= '9')
            digits[c - '1']++;
        else
            return 0;
    }
    for (i = 0; i < m; i++) {
        if (digits[i] != 1) {
            return 0;
        }
    }
    return 1;
}

static int
get_factors_below_sqrt(int n, int * f)
{
    int i;
    int j = 0;
    for (i = 2; i <= n/2; i++) {
        if (i*i > n)
            break;
        if (n % i == 0) {
            f[j++] = i;
            assert(j < MAX_FS);
        }
    }
    return j;
}

int main()
{
    char buffer[32];
    int i, n;
    int fs[MAX_FS];
    int answer = 0;
    for (n = 100; n < 100000; n++) {
        int nf = get_factors_below_sqrt(n, fs);
        for (i = 0; i < nf; i++) {
            snprintf(buffer, sizeof(buffer), "%d%d%d", fs[i], n/fs[i], n);
            if (str_is_pandigital(buffer, 9)) {
                //printf("%d * %d == %d\n", fs[i], n/fs[i], n);
                answer += n;
                break;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
