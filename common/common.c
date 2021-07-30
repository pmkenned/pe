#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void
read_file(const char * filename, char * buffer, size_t n)
{
    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("error");
        exit(1);
    }

    size_t nread = fread(buffer, 1, n, fp);
    if (nread < n) {
        if (ferror(fp)) {
            perror("error");
            exit(1);
        }
    }
    if (!feof(fp)) {
        fprintf(stderr, "buffer size insufficient\n");
        exit(1);
    }
    fclose(fp);
}

enum { LO_TO_HI, HI_TO_LO };

static int
_from_digits(int * digits, int n, int dir)
{
    int i, rv = 0;
    int iv = (dir == LO_TO_HI) ? 0 : n-1;
    int fv = (dir == LO_TO_HI) ? n : -1;
    int step = (dir == LO_TO_HI) ? 1 : -1;
    for (i = iv; i != fv; i += step) {
        rv *= 10;
        rv += digits[i];
    }
    return rv;
}

int
from_digits(int * digits, int n)
{
    return _from_digits(digits, n, LO_TO_HI);
}

int
from_digits_rev(int * digits, int n)
{
    return _from_digits(digits, n, HI_TO_LO);
}

int
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

uint64_t * primes = NULL;
size_t primes_cap = 10;
size_t num_primes;
uint64_t max_n;

static int cmp_uint64(const void * a, const void * b) { return *(uint64_t *)a - *(uint64_t *)b; }

static int
_is_prime(uint64_t n, int backfill) {
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
                _is_prime(i, 1);
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

int
is_prime(uint64_t n)
{
    return _is_prime(n, 0);
}

int
is_prime_backfill(uint64_t n)
{
    return _is_prime(n, 1);
}

int
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

int
is_pandigital(const int * a, int lo, int hi)
{
    int i;
	int n = hi - lo + 1;
    int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < n; i++) {
        int c = a[i];
        if (c >= lo && c <= hi)
            digits[c]++;
        else
            return 0;
    }
    for (i = lo; i <= hi; i++) {
        if (digits[i] != 1) {
            return 0;
        }
    }
    return 1;
}

void
rotate(int * a, int n)
{
    int i, t = a[0];
    for (i = 0; i < n; i++)
        a[i] = a[i+1];
    a[n-1] = t;
}

void
reverse(int * a, int n)
{
    int i;
    for (i = 0; i < n/2; i++) {
        int t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
}
