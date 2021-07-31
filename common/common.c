#include "common.h"
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

uint64_t
from_digits(int * digits, int n, int dir)
{
    uint64_t rv = 0;
    int i;
    int iv = (dir == MSD_AT_0) ? 0 : n-1;
    int fv = (dir == MSD_AT_0) ? n : -1;
    int step = (dir == MSD_AT_0) ? 1 : -1;
    for (i = iv; i != fv; i += step) {
        rv *= 10;
        rv += digits[i];
    }
    return rv;
}

/* return number of significant digits */
int
get_digits_base(int * digits, int n, int x, int b, int dir)
{
    int i;
    int iv = (dir == LSD_AT_0) ? 0 : n-1;
    int fv = (dir == LSD_AT_0) ? n : -1;
    int step = (dir == LSD_AT_0) ? 1 : -1;
    for (i = iv; i != fv; i += step) {
        digits[i] = x % b;
        x /= b;
    }
    iv = (dir == MSD_AT_0) ? 0 : n-1;
    fv = (dir == MSD_AT_0) ? n : -1;
    step = (dir == MSD_AT_0) ? 1 : -1;
    for (i = iv; i != fv; i += step)
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

static int
_permute(int * a, int n, int m, int p, int lo)
{
    static int * _a = NULL;
    static int count = 0;
    if (a != NULL) {
        _a = a;
        count = 0;
    }
    int i, j;
    if (n == 0) {
        count++;
    } else {
        for (i = lo; i < lo+n+m; i++) {
            /* look for an available number for slot m */
            for (j = 0; j < m; j++)
                if (_a[j] == i)
                    break;
            if (j != m) /* i is not available */
                continue;
            _a[m] = i;
            _permute(NULL, n-1, m+1, p, lo);
            if (count > p)
                return 0;
        }
    }
    return 1;
}


/* let n be the number of elements in the array
   return 1 if the are fewer permutations than requested */
int
permute(int * a, int n, int p, int lo)
{
    return _permute(a, n, 0, p, lo);
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
