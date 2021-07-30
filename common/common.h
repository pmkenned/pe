#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>

extern uint64_t * primes;
extern size_t primes_cap;
extern size_t num_primes;
extern uint64_t max_n;

void read_file(const char * filename, char * buffer, size_t n);
int from_digits(int * digits, int n);
int from_digits_rev(int * digits, int n);
int get_digits_base(int x, int * digits, int n, int b);
int is_prime(uint64_t n);
int is_prime_backfill(uint64_t n);
int permute(int n, int m, int * a, int which);
int is_pandigital(const int * a, int lo, int hi);
void rotate(int * a, int n);
void reverse(int * a, int n);

#endif /* COMMON_H */
