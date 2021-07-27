#include <stdio.h>

#define NELEM(x) (sizeof(x)/sizeof(x[0]))
int u[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

static int
f(int sought, int d, int n)
{
    if (d == n)
        return (sought == 0) ? 1 : 0;
    int i, count = 0;
    for (i = 0; i <= sought/u[d]; i++)
        count += f(sought - i*u[d], d+1, n);
    return count;
}

int main()
{
    printf("%d\n", f(200, 0, NELEM(u)));
    return 0;
}
