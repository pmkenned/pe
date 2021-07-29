#include <stdio.h>

enum {
    NUMER,
    DENOM
};

enum {
    TENS,
    ONES
};

static void
get_digits(int n, int digits[2])
{
    digits[ONES] = n % 10;
    digits[TENS] = n / 10;
}

static int
have_common_digits(int di[2], int dj[2])
{
    int rv = 0;
    rv |= di[TENS] == dj[TENS];
    rv |= di[TENS] == dj[ONES];
    rv |= di[ONES] == dj[TENS];
    rv |= di[ONES] == dj[ONES] && di[ONES] != 0;
    return rv;
}

int found[4][2];

static void
cancel_common_digits(int di[2], int dj[2], float f[2])
{
    static int fi = 0;
    float i = di[TENS]*10 + di[ONES];
    float j = dj[TENS]*10 + dj[ONES];

#define ADD_FOUND(PLACE_A, PLACE_B) \
    if (di[PLACE_A] == dj[PLACE_B]) { \
        f[NUMER] = di[PLACE_B]; \
        f[DENOM] = dj[PLACE_A]; \
        if (i/j == f[NUMER]/f[DENOM]) { \
            found[fi][NUMER] = i; \
            found[fi][DENOM] = j; \
            fi++; \
        } \
    }

    ADD_FOUND(TENS, ONES)
    ADD_FOUND(TENS, TENS)
    ADD_FOUND(ONES, TENS)
    ADD_FOUND(ONES, ONES)
#undef ADD_FOUND
}

int main()
{
    int di[2], dj[2];
    float f[2];
    int i, j, k = 0;
    for (i = 10; i <= 98; i++) {
        get_digits(i, di);
        for (j = i+i; j <= 99; j++) {
            get_digits(j, dj);
            if (have_common_digits(di, dj))
                cancel_common_digits(di, dj, f);
        }
    }
    float product = 1.0;
    for (i = 0; i < 4; i++) {
        product *= (1.0f*found[i][NUMER])/found[i][DENOM];
        //printf("%d/%d\n", found[i][0], found[i][1]);
    }
    printf("%f\n", product);

    return 0;
}
