#include "../../common/common.h"
#include <stdio.h>
#include <stddef.h>

int main()
{
    int i, counter = 0;
    int pf[20];
    for (i = 646; 1; i++) {
        size_t npf = get_prime_factors(i, pf, NELEM(pf));
        if (uniq(pf, npf) == 4)
            counter++;
        else
            counter = 0;
        if (counter == 4)
            break;
    }
    printf("%d\n", i-3);
    return 0;
}
