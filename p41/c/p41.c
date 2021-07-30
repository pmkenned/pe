#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

static int
from_digits(int * digits, int n)
{
    int i, rv = 0;
    for (i = 0; i < n; i++) {
        rv *= 10;
        rv += digits[i];
    }
    return rv;
}

static uint64_t * primes = NULL;
static size_t primes_cap = 10;
static size_t num_primes;
static uint64_t max_n;

static int cmp_uint64(const void * a, const void * b) { return *(uint64_t *)a - *(uint64_t *)b; }

static int
is_prime(uint64_t n, int backfill) {
    size_t i;

    if (primes == NULL) {
        primes = malloc(sizeof(*primes)*primes_cap);
        primes[0] = 2;
        primes[1] = 3;
        num_primes = 2;
        max_n = 3;
    }

    if (n <= max_n)
        return bsearch(&n, primes, num_primes, sizeof(*primes), cmp_uint64) == NULL ? 0 : 1;

    if (backfill) {
        if (n > max_n+1)
            for (i = max_n+1; i < n; i++)
                is_prime(i, 1);
        max_n = n;
    }

    /* memory is slow! just do the divisions! */
#if 0
    for (i = 0; i < num_primes; i++)
        if (n % primes[i] == 0)
            return 0;
#else
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return 0;
#endif

    if (backfill) {
        primes[num_primes++] = n;
        if (num_primes >= primes_cap) {
            primes_cap *= 2;
            primes = realloc(primes, sizeof(*primes)*primes_cap);
        }
    }

    return 1;
}

static int
permute(int n, int m, int * a, int which)
{
    static int * _a = NULL;
    static int count = 0;
    //printf(".");
    if (a != NULL) {
        _a = a;
        count = 0;
    }
    int i, j;
    if (n == 0) {
        count++;
    } else {
        for (i = 1; i <= n+m; i++) {
            /* look for an available number for slot m */
            for (j = 0; j < m; j++)
                if (_a[j] == i)
                    break;
            if (j != m) /* i is not available */
                continue;
            _a[m] = i;
            permute(n-1, m+1, NULL, which);
            if (count > which)
                return 0;
        }
    }
    return 1;
}

#define N 7

int main() {
    int j, k;
    int a[N];
    int max = 0;

    for (k = 4; k <= N; k++) {
        j = 0;
        while (1) {
            if (permute(k, 0, a, j))
                break;
            j++;
            int x = from_digits(a, k);
            if (is_prime(x, 0))
                max = x > max ? x : max;
        }
    }
    printf("%d\n", max);

    return 0;
}
