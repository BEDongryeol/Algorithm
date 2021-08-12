#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1001][1001];
// n: 노드의 개수, m: 간선의 개수
int n, m;

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		// 1, 2을 삽입할 경우 1과 2가 연결이 되어있다는 의미
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}

	for (int i = 1 ; i<=n; i++){
		for (int j = 1; j <= n; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}