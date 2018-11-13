#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
void show(int matrix[5][5]) {
	for (int i = 0; i < 5; i++) {             //Виведення функції
		for (int j = 0; j < 5; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void enter(int matrix[5][5]) {
	for (int i = 0; i < 5; i++) {             //Введення функції
		for (int j = 0; j < 5; j++) {
			printf("a[%d][%d]=", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void sort(int matrix[5][5]) {
	for (int n = 0; n < 5; n++) {
		for (int j = 0; j < 5; j++) {
			for (int i = 1; i < 5; i++) {
				int temp = matrix[i][j];
				if (temp > matrix[i - 1][j]) {
					matrix[i][j] = matrix[i - 1][j];        //Сортуємо матрицю.
					matrix[i - 1][j] = temp;
				}
			}
		}
	}
}
void func(int matrix[5][5]) {                 //Обчислення функій
	double SUMA = 0.0;
	double product = 1.0;
	double k = 4.0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (j > i) {
				product *= matrix[i][j];
			}
		}
		if (product < 0) {
			product *= -1;
		}
		double GAV = pow(product, 1.0 / k);
		SUMA += GAV;
		printf("i = %d\t", i);
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
	return 0;
}
