#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

// ���Ḯ��Ʈ�� ���� ���� ����
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
		printf("���� ����÷ο찡 �߻��Ͽ����ϴ�.");
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
	printf("--- ������ �ֻ�� --- \n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ������ ���ϴ� --- \n");
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
�迭�� �̿��� ���� ����
#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1){  // size-1 = ������ �ε��� ��
		printf("���� �����÷ο찡 �߻��߽��ϴ�. \n");
		return;
	}
	stack[++top] = data; // �ε��� 0���� ����
}

void pop() {
	if (top == -1) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�. \n");
		return -INF;
	}
	return stack[top--]; //�ε����� �ٿ��ָ� ���� ������ �ε����� ���� �����ȴ�.
}

void show(){
	printf("---������ �ֻ��--- \n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("---������ ���ϴ�--- \n");
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