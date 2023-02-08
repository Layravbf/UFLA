#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
int
i, n;
float a[100], b[100], sum;
n = 100; /* Some initializations */
#pragma omp parallel for 
for (i=0; i < n; i++){
	a[i] = 1.0;
        b[i] = 2.0;
}
sum = 0.0;
#pragma omp parallel for reduction(+:sum)
for (i=0; i < n; i++)
	sum = sum + (a[i] * b[i]);
printf("Sum = %.2f\n",sum);
exit(0);
}


