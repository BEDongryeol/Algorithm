#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int start, int end) {
	// 좌우 분할하여 재정렬을 위해 엇갈리는 순간 저장 
	if (start >= end) return;
	int key = start, i = start + 1, j = end, temp;
	while (i <= j) { // 엇갈릴 때까지 수행
		while (i <= end && a[i] <= a[key]) i++;
		while (j >= start && a[j] >= a[key]) j--;
		if (i > j) swap(&a[key], &a[j]);
		else swap(&a[j], &a[i]);
	}
	// 좌우 각각 quickSort 재 실행
	quickSort(start, j - 1);
	quickSort(j + 1, end);
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
		system("pause");
	return 0;
}