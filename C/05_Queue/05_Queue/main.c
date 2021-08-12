// 1. 연결리스트를 통한 queue 생성

#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;
}Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

void pop(Queue* queue) {
	if (queue->count == 0) {
		printf("큐 언더플로우가 발생하였습니다. \n");
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;

	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}

void show(Queue* queue) {
	Node* cur = queue->front;
	printf("---큐의 앞---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---큐의 뒤---");
}

int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	system("pause");
	return 0;
}


// 2. 배열을 통한 Queue 생성
/*#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;


void push(int data) {
	if (rear >= SIZE) {
		printf("큐 오버플로우가 발생했습니다. \n");
		return;
	}
	queue[rear++] = data;
}

void pop() {
	if (front == rear) {
		printf("큐 언더플로우가 발생했습니다. \n");
		return -INF;
	}
	return queue[front++];
}

void show() {
	printf("---큐의 앞--- \n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("---큐의 뒤--- \n");
}

int main(void) {
	push(7);
	push(5);
	push(1);
	pop();
	show();
	system("pause");
	return 0;
}
*/