#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000

int main(int argc, char *argv[]) {
	float a[N], b[N], c[N];
	int i;
		for (i = 0; i < N; i++) {
			a[i] = i * 2.0;
			b[i] = i * 3.0;
		}

	#pragma omp parallel shared(a, b, c) private(i) 
	{
		#pragma omp for
			for (i = 0; i < N; i++) {
				c[i] = a[i] + b[i];
			}
		printf("%f\n", c[10]);
	}
}
