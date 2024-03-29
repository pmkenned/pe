#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define MAX_DEPTH 10000

#if 0
typedef struct {
    uint64_t x;
    int valid;
} set_item_t;

typedef struct {
    set_item_t arr[100];
    size_t cap;
} set_t;

static set_t *
set_create()
{
    size_t i;
    set_t * s = malloc(sizeof(set_t));
    for (i = 0; i < s->cap; i++) {
        s->arr[i].valid = 0;
    }
    return s;
}

static size_t
set_hash(uint64_t x)
{
    size_t hash = 5381;
    int c;
    while ((c = *s++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

static size_t
set_get_idx()
{
}

static void
set_add(set_t * s, int x)
{
    size_t idx = set_hash(x);
    if (s->arr[idx].valid) {
        if (s->arr[idx]
    }
}

static int
set_check(set_t * s)
{
    return 0;
}
#endif

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

    uint64_t sr = sqrt(n);
    for (i = 0; i < num_primes; i++) {
        if (primes[i] > sr)
            break;
        if (n % primes[i] == 0)
            return 0;
    }
    for (i = primes[num_primes-1]+2; i <= sr; i += 2)
        if (n % i == 0)
            return 0;

    if (backfill) {
        primes[num_primes++] = n;
        if (num_primes >= primes_cap) {
            primes_cap *= 2;
            primes = realloc(primes, sizeof(*primes)*primes_cap);
        }
    }

    return 1;
}

#if 1
size_t sieve_cap = 0;
char * sieve_arr = NULL;

static int
sieve(uint64_t x)
{
    if (x >= sieve_cap) {
        sieve_cap = x+1;
        sieve_arr = realloc(sieve_arr, sizeof(*sieve_arr)*sieve_cap);
        memset(sieve_arr, 1, sizeof(*sieve_arr)*sieve_cap);

        size_t p, i;
        for (p = 2; p*p <= x; p++)
            if (sieve_arr[p])
                for (i = p*p; i <= x; i += p)
                    sieve_arr[i] = 0;
    }
    return sieve_arr[x];
}
#endif

static void
print_primes()
{
    size_t i;
    for (i = 0; i < num_primes; i++) {
        printf("%ld\n", primes[i]);
    }
}

int main() {

    size_t i;
#if 1
    sieve(100000000);
    for (i = sieve_cap-300; i < sieve_cap; i++)
        if (sieve_arr[i])
            printf("%ld ", i);
    printf("\n");
    return 0;
#endif

    for (i = 0; i < 10000000; i++) {
        is_prime(i, 1);
        if (i % 100000 == 0) {
            printf(".");
            fflush(stdout);
        }
    }
    printf("\n");
    printf("%zu\n", num_primes);
    //print_primes();

    for (i = 0; i < 10000000; i++) {
        int r = rand() % 10000000;
        is_prime(r, 0);
        if (i % 100000 == 0) {
            printf(".");
            fflush(stdout);
        }
    }
    printf("\n");

    return 0;
}
