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

int main() {

	double array[N];
	int size, i, beg = 0, end = 0;
	double interval_from = 2, element;
	double accumPositive = 0, accumNegative = 0, numberPos = 0, numberNeg = 0;

	setlocale(LC_ALL, "rus");
	printf("������� ������ �������: ");
	scanf("%d", &size);

	full_elements(array, size);
	put_elements(array, size);
	calc_elements(array, size);
	put_elements(array, size);

	printf("������� ������ 'Begin' ��� ������������ ��������� �������:\n");
	scanf("%d", &beg);
	printf("������� ������ 'End' ��� ������������ ��������� �������:\n");
	scanf("%d", &end);

	printf("����� ��������� ������� �� ������� �� %d �� %d = %.2lf\n", beg, end, sum_elements(array, beg, end));

	printf("������� �������, ������ �������� ���� �����:\n");
	scanf("%lf", &element);
	printf("�������� %lf ����������� ������ %d\n", element, find_element(array, size, element));

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
		printf("%lf\n", ptr_array[i]);
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