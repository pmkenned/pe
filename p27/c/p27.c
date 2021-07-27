#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main() {

    int x, a, b;
    int current_max_n = 0;
    int answer;

    for(a = -999; a<1000; a++) {
        for(b = -999; b<1000; b++) {
            int product, n;
            int x_is_prime = 1;
            for(n=0; x_is_prime; n++) {
                x = n*n + a*n + b;
                x_is_prime = is_prime(x);
            }
            product = a*b;
            if(n-1 > current_max_n) {
                current_max_n = n-1;
                answer = product;
            }
        }
    }

    printf("%d\n",answer);

    return 0;
}

int is_prime(int x) {
    int i;
    if(x < 0)
        return 0;
    if(x % 2 == 0)
        return 0;
    for(i=3; i < sqrt(x); i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}
