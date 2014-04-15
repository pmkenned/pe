#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100000

// THIS PROGRAM DOES NOT PROVIDE THE CORRECT ANSWER

int cmp(const void * x, const void * y) {
	if (*((double*)x) > *((double*)y))
		return -1;
	if (*((double*)x) == *((double*)y))
		return 0;
	if (*((double*)x) < *((double*)y))
		return 1;
}

int main(int argc, char ** argv) {

	int i, j;
	long long a, b, x;
	double array[MAX];
	int count = 0;

	for(i=0; i<MAX; i++)
		array[i] = 0;

	for(a=2; a<=100; a++) {
		for(b=2; b<=100; b++) {
			int found = 0;
			x = pow(a, b);
			for(j=0; j<count; j++) {
				if(x == array[j]) {
					found=1;
					break;
				}
			}
			if(!found)
				array[count++] = x;
			assert(count < MAX);
		}
	}

	qsort(array, count, sizeof(double), cmp);

	for(i=0; i<count; i++)
		printf("%f ", array[i]);

	printf("count: %d\n", count);
	
	return 0;
}
