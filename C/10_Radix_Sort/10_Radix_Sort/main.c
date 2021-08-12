#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void radixSort(int* a, int n) {
	int res[MAX], maxValue = 0;
	int exp = 1;
	// 자리 수를 구하기 위해 최대값을 찾아준다.
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}
	
	while (maxValue / exp > 0) { //최대값의 자리수만큼만 반복
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; //자리 수 계산
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; //누적계산
		for (int i = n - 1; i >= 0; i--) {
		// 누적값 -1 의 인덱스에 값을 삽입
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) a[i] = res[i];
		exp *= 10;
	}
}

int main(void) {
	int a[MAX];
	int i, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	radixSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
}