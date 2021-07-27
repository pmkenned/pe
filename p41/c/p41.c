#include <stdio.h>

#define NUM_INIT_PRIMES 2

void init_primes(unsigned long long ** primes) {
    *primes = malloc(sizeof(unsigned long long)*(NUM_INIT_PRIMES+1));
    (*primes)[0] = 2;
    (*primes)[1] = 3;
}

int is_prime(unsigned long long n) {
    static int max_n = 3;
    static int num_primes = NUM_INIT_PRIMES;
    static int primes_init = 0; /* initialization flag */
    static int primes_cap = NUM_INIT_PRIMES;
    int i;
    unsigned long long * primes;

    if(!primes_init) {
        init_primes(&primes);
        primes_init = 1;
    }

    if(n < max_n) {
        /* change to binary search */
        for(i=0; i<num_primes; i++) {
            if(n > primes[i])
                break;
            if(n == primes[i]) {
                return 1;
            }
        }
        return 0;
    }

    for(i=0; i<num_primes; i++) {
        if(primes[i] == 0) {
            int j;
            for(j=0; j<num_primes; j++)
                printf("%d\t",primes[j]);
            exit(1);
        }
        if(n % primes[i] == 0) {
            max_n = n;
            return 0;
        }
    }
    /* found a new prime */
    primes[num_primes++] = n;
    if(num_primes >= primes_cap) {
        primes_cap *= 2;
        primes = (unsigned long long *) realloc(sizeof(unsigned long long)*primes_cap);
    }
}

int main() {
    int n = 4;
    printf("%d: %d\n",n,is_prime(n));
    n=5;
    printf("%d: %d\n",n,is_prime(n));
    return 0;
}
