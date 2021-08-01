#include "../../common/common.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

static int
in_list(int * a, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (x == a[i])
            return 1;
    return 0;
}

int main()
{
    int d[10];
    uint64_t x;
    uint64_t answer = 0;
    for (d[0] = 0; d[0] <= 9; d[0]++) {
        for (d[1] = 0; d[1] <= 9; d[1]++) {
            if (d[1] == d[0]) continue;
            for (d[2] = 0; d[2] <= 9; d[2]++) {
                if (in_list(d, 2, d[2])) continue;
                for (d[3] = 0; d[3] <= 8; d[3] += 2) {
                    if (in_list(d, 3, d[3])) continue;
                    for (d[4] = 0; d[4] <= 9; d[4]++) {
                        if (in_list(d, 4, d[4])) continue;
                        if ((d[2] + d[3] + d[4]) % 3 != 0) continue;
                        for (d[5] = 0; d[5] <= 5; d[5] += 5) {
                            if (in_list(d, 5, d[5])) continue;
                            for (d[6] = 0; d[6] <= 9; d[6]++) {
                                if (in_list(d, 6, d[6])) continue;
                                x = from_digits(d+4, 3, MSD_AT_0);
                                if (x % 7 != 0) continue;
                                for (d[7] = 0; d[7] <= 9; d[7]++) {
                                    if (in_list(d, 7, d[7])) continue;
                                    x = from_digits(d+5, 3, MSD_AT_0);
                                    if (x % 11 != 0) continue;
                                    for (d[8] = 0; d[8] <= 9; d[8]++) {
                                        if (in_list(d, 8, d[8])) continue;
                                        x = from_digits(d+6, 3, MSD_AT_0);
                                        if (x % 13 != 0) continue;
                                        for (d[9] = 0; d[9] <= 9; d[9]++) {
                                            if (in_list(d, 9, d[9])) continue;
                                            x = from_digits(d+7, 3, MSD_AT_0);
                                            if (x % 17 != 0) continue;
                                            x = from_digits(d, 10, MSD_AT_0);
                                            answer += x;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%ld\n", answer);
    return 0;
}
