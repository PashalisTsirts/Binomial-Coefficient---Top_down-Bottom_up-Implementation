 /*
  * @author  PashalisTsirts
  * @create  ‎5/10/2021, ‏‎11:07:41
  * @name Bf.c 
  */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 50

int A[Max][Max];

/* recursive implementation for the binominal coefficient problem */

int binomialCoeff1(int n, int k) {

	if (k > n)
		return 0;

	if (k == 0 || k == n)
		return 1;


	return binomialCoeff1(n - 1, k - 1) + binomialCoeff1(n - 1, k);
}

/* bottom-up implementation for the binominal coefficient problem */

int binomialCoeff2(int n, int k) {

	int i, j;

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k && j <= i; j++) {

			if (j == 0 || j == i)
				A[i][j] = 1;
			else
				A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
		}
	}

	return A[n][k];
}

/* top-down implementation for the binominal coefficient problem */

int binomialCoeff3(int n, int k) {

	if (k > n)
		return 0;

	if (k == 0 || k == n)
		return 1;


	if (A[n][k] != -1)
		return A[n][k];

	return A[n][k] = binomialCoeff3(n - 1, k - 1) + binomialCoeff3(n - 1, k);
}


int main()
{

	int n=20, k=5;

		clock_t begin1 = clock();
		printf("Result from recursive implementation is: %d\n", binomialCoeff1(n, k));
		clock_t end1 = clock();
		double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
		printf("Time for binomialCoeff1 is: %.16f\n\n", time_spent1);
		
	printf("\n\n");
	
		memset(A, 0, sizeof(A));
		clock_t begin2 = clock();
		printf("Result from bottom-up implementation is: %d\n", binomialCoeff2(n, k));
		clock_t end2 = clock();
		double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
		printf("Time for binomialCoeff2 is: %.16f\n\n", time_spent2);

	printf("\n\n");
	
		memset(A, -1, sizeof(A));
		clock_t begin3 = clock();
		printf("Result from top-down implementation is: %d\n", binomialCoeff3(n, k));
		clock_t end3 = clock();
		double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
		printf("Time for binomialCoeff3 is: %.16f\n\n", time_spent3);
	
	return 0;

}