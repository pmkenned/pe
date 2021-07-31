#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>

enum { MSD_AT_0, LSD_AT_0 };

extern uint64_t * primes;
extern size_t primes_cap;
extern size_t num_primes;
extern uint64_t max_n;

void read_file(const char * filename, char * buffer, size_t n);
uint64_t from_digits(int * digits, int n, int dir);
int get_digits_base(int * digits, int n, int x, int b, int dir);
int is_prime(uint64_t n);
int is_prime_backfill(uint64_t n);
int permute(int * a, int n, int p, int lo);
int is_pandigital(const int * a, int lo, int hi);
void rotate(int * a, int n);
void reverse(int * a, int n);

#endif /* COMMON_H */
