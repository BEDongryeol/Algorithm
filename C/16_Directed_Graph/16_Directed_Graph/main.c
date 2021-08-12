#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index; //(노드 번호)
	int distance; //가중치(거리)
	struct Node* next; //연결 노드
} Node;

void addFront(Node* root, int index, int distance) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf("%d(거리: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main(void) {
	// n: 노드의 개수, m: 간선의 개수
	int n, m;
	// 노드의 개수와 간선의 개수 입력 받기
	scanf("%d %d", &n, &m);
	Node** a = (Node*)malloc(sizeof(Node*) * (n + 1));

	for (int i = 1; i <= n; i++) {
		// 각 노드 공간 할당
		a[i] = (Node*)malloc(sizeof(Node));
		// 각 노드 초기화
		a[i]->next = NULL;
	}

	for (int i = 0; i < m; i++) {
		// from, to, 거리
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		// 각 노드에 목표 및 거리 할당
		addFront(a[x], y, distance);
	}

	for (int i = 1; i <= n; i++) {
		printf("원소 [%d] : ", i);
		showAll(a[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}