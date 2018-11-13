#include <iostream>
#include <stdio.h>
#include <math.h>

#define N 5
#define C columns
#define S strings
void show(int matrix[N][N]) {
	for (int S= 0; S < N; S++) {             
		for (int C = 0; C < N; C++) {
			printf("%d\t", matrix[S][C]);
		}
		printf("\n");
	}
	printf("\n");
}
void enter(int matrix[N][N]) {
	for (int S = 0; S < N; S++) {             
		for (int C= 0; C < N; C++) {
			printf("a[%d][%d]=", S, C);
			scanf_s("%d", &matrix[S][C]);
		}
	}
}
void sort(int matrix[N][N]) {
	for (int n = 0; n < N; n++) {
		for (int C = 0; C < N; C++) {
			for (int S = 1; S < N; S++) {
				int temp = matrix[S][C];
				if (temp > matrix[S - 1][C]) {
					matrix[S][C] = matrix[S - 1][C];       
					matrix[S - 1][C] = temp;
				}
			}
		}
	}
}
void func(int matrix[N][N]) {                
	double SUMA = 0.0;
	double product = 1.0;
	double k = 4.0;
	for (int S = 0; S < 4; S++) {
		for (int C = 0; C < N; C++) {
			if (C > S) {
				product *= matrix[S][C];
			}
		}
		if (product < 0) {
			product *= -1;
		}
		double GAV = pow(product, 1.0 / k);
		SUMA += GAV;
		printf("i = %d\t", S);
		printf("GAV = %lf\n", GAV);
		k = k - 1.0;
		product = 1.0;
	}
	printf("SUMA = %lf", SUMA);
}
int main() {
	int matrix[5][5];
	enter(matrix);
	show(matrix);
	sort(matrix);
	show(matrix);
	func(matrix);
	system("pause");
	return 0;
}