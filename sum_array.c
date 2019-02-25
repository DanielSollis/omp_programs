#include <stdio.h>
#include <omp.h>

int main() {
	const int N = 100;
	int a[N];
	for (int i = 0; i < N; i++) {
		a[i] = i;
	}
	int local_sum;
	int sum = 0;
	#pragma omp parallel private(local_sum) shared(sum)
	{
		local_sum = 0;
		#pragma omp for
		for (int i = 0; i < N; i++) {
			local_sum += a[i];
		}	
		#pragma omp critical
			sum += local_sum;
		
	}
	printf("total = %d, should be %d\n", sum, (N*(N - 1))/2);
}
