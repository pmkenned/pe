#include <stdio.h>
#include <stdlib.h>

#define N 10
#define WHICH 1000000

static void
f(int n, int m, int * a)
{
    static int count = 0;
    int i, j;
    if (n == 0) {
        if (++count >= WHICH) {
            for (i = 0; i < n+m; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            exit(0);
        }
    } else {
        for (i = 0; i < n+m; i++) {
            int valid = 1;
            for (j = 0; j < m; j++) {
                if (a[j] == i) {
                    valid = 0;
                }
            }
            if (!valid)
                continue;
            a[m] = i;
            f(n-1, m+1, a);
        }
    }
}

/*
   A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
   If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
   The lexicographic permutations of 0, 1 and 2 are: 012   021   102   120   201   210
   What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
int main()
{
    int a[N];
    f(N, 0, a);
    return 0;
}
