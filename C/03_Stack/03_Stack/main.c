#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

// 연결리스트를 통한 스택 구현
typedef struct {
	int data;
	struct Node* next; 
}Node;

typedef struct {
	Node* top;
}Stack;

void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

void pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생하였습니다.");
		return -INF;
	}

	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack* stack) {
	Node* cur = stack->top;
	printf("--- 스택의 최상단 --- \n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최하단 --- \n");
}

int main(void) {
	Stack s;
	s.top = NULL;
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 4);
	show(&s);
	system("pause");
	return 0;
}

/* 
배열을 이용한 스택 구현
#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1){  // size-1 = 마지막 인덱스 값
		printf("스택 오버플로우가 발생했습니다. \n");
		return;
	}
	stack[++top] = data; // 인덱스 0부터 시작
}

void pop() {
	if (top == -1) {
		printf("스택 언더플로우가 발생했습니다. \n");
		return -INF;
	}
	return stack[top--]; //인덱스를 줄여주면 가장 마지막 인덱스의 값이 삭제된다.
}

void show(){
	printf("---스택의 최상단--- \n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("---스택의 최하단--- \n");
}

int main(void) {
	push(3);
	push(4);
	push(5);
	push(6);
	pop();
	push(1);
	pop();
	show();
	system("pause");
	return 0;
}
*/