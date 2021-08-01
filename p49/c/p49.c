#include "../../common/common.h"
#include <stdio.h>
#include <string.h>

/* counts must be at least 10 ints in size */
static void
count_digits(int x, int * counts)
{
    int i;
    int digits[20];
    memset(counts, 0, sizeof(*counts)*10);
    int nd = get_digits(digits, NELEM(digits), x, 10, LSD_AT_0);
    for (i = 0; i < nd; i++)
        counts[digits[i]]++;
}

int main()
{
    int counts0[10], counts1[10];
    int x0, j;
    for (x0 = 1000; x0 < 10000; x0++) {
        if (x0 == 1487) /* skip the given solution */
            continue;
        if (!is_prime(x0))
            continue;
        count_digits(x0, counts0);
        for (j = 1; j < 9000; j++) {
            int x1 = x0 + j;
            int x2 = x0 + 2*j;
            if (!is_prime(x1) || !is_prime(x2))
                continue;
            count_digits(x1, counts1);
            if (memcmp(counts0, counts1, sizeof(counts0)) != 0)
                continue;
            count_digits(x2, counts1);
            if (memcmp(counts0, counts1, sizeof(counts0)) != 0)
                continue;
            printf("%d%d%d\n", x0, x1, x2);
            return 0;
        }
    }
    return 0;
}
