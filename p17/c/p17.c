#include <stdio.h>
#include <stddef.h>
#include <assert.h>

#define STRLEN(x) sizeof(#x)-1

const int len_19[] = {
    0,
    STRLEN(one),
    STRLEN(two),
    STRLEN(three),
    STRLEN(four),
    STRLEN(five),
    STRLEN(six),
    STRLEN(seven),
    STRLEN(eight),
    STRLEN(nine),
    STRLEN(ten),
    STRLEN(eleven),
    STRLEN(twelve),
    STRLEN(thirteen),
    STRLEN(fourteen),
    STRLEN(fifteen),
    STRLEN(sixteen),
    STRLEN(seventeen),
    STRLEN(eighteen),
    STRLEN(nineteen),
};

const int len_tens[] = {
    STRLEN(twenty),
    STRLEN(thirty),
    STRLEN(forty),
    STRLEN(fifty),
    STRLEN(sixty),
    STRLEN(seventy),
    STRLEN(eighty),
    STRLEN(ninety)
};

static int
number_to_length(int x)
{
    assert(x >= 0);

    if (x >= 0 && x <= 19) {
        return len_19[x];
    } else if (x >= 20 && x <= 99) {
        return len_tens[(x/10)-2] + number_to_length(x % 10);
    } else if (x >= 100 && x <= 999) {
        int n = len_19[x/100] + STRLEN(hundred);
        if (x % 100 != 0) {
            n += STRLEN(and) + number_to_length(x % 100);
        }
        return n;
    }

    return 0;
}

int main()
{
    int i;
    int sum = 0;
    for (i = 1; i <= 999; i++)
        sum += number_to_length(i);
    sum += STRLEN(onethousand);

    printf("%d\n", sum);

    return 0;
}
