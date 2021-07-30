#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

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

static void
print_primes()
{
    size_t i;
    for (i = 0; i < num_primes; i++) {
        printf("%ld\n", primes[i]);
    }
}

int main() {

    int i;
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
