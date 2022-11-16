#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 50


double function(double a);
double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
int MaxValue(double* ptr_array, int k);
int firstNumber(double* ptr_array, int A);

int main() {

	double array[N];
	int size, i, beg = 0, end = 0;
	double interval_from = 2, element;
	double accumPositive = 0, accumNegative = 0, numberPos = 0, numberNeg = 0;

	setlocale(LC_ALL, "rus");
	printf("Введите размер массива: ");
	scanf("%d", &size);

	full_elements(array, size);
	put_elements(array, size);
	calc_elements(array, size);
	put_elements(array, size);

	printf("Введите индекс 'Begin' для суммирования элементов массива:\n");
	scanf("%d", &beg);
	printf("Введите индекс 'End' для суммирования элементов массива:\n");
	scanf("%d", &end);

	printf("Сумма элементов массива на отрезке от %d до %d = %.2lf\n", beg, end, sum_elements(array, beg, end));

	printf("Введите элемент, индекс которого надо найти:\n");
	scanf("%lf", &element);
	printf("Элементу %lf принадлежит индекс %d\n", element, find_element(array, size, element));
	int k;
	printf("Введите значение K\n");
	scanf("%d", &k);
	printf("Максимальное значение элемента массива, находящегося до заданной позиции K включительно =  %d\n", MaxValue(array, k));
	
	int A;
	printf("Введите значение A\n");
	scanf("%d", &A);
	printf("Первый порядковый номер элемента не равного А - %d\n", firstNumber(array, A));
}


double function(double a) {
	double b;
	b = pow(2, a) - pow(2 * a, 2) - 1;
	return b;
}

double* full_elements(double* ptr_array, int n) {

	double interval_from = 2;

	for (int i = 0; i < n; i++) {
		interval_from += 1;
		ptr_array[i] = function(interval_from);
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {
		printf("[%d] = %lf\n",i, ptr_array[i]);
	}
}

double* calc_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {
		ptr_array[i] = pow(ptr_array[i], 2);
	}
	return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end) {
	double sum;
	for (sum = 0; begin < end; begin++) {
		sum += ptr_array[begin];
	}
	return sum;
}

int find_element(double* ptr_array, int n, double element) {
	int i = 0;
	for (; i < n; i++) {
		int g = ptr_array[i];
		if (g == element) {
			return i;
		}
	}
	return -1;
}

int MaxValue(double* ptr_array, int k) {
	double max = 0;
	int i = 0;
	for (; i <= k; i++) {
		if (ptr_array[i] > max) {
			max = ptr_array[i];
		}
	}
	return max;
}

int firstNumber(double* ptr_array, int A) {
	int i = 0;
	for (; ptr_array[i] != A; i++) {

		return i;
	}
}
