#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
	char data[100];
	struct Node* next;
} Node;

typedef struct Stack {
	Node* top;
} Stack;

void push(Stack* stack, char *data) {
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}

char* getTop(Stack* stack) {
	Node* top = stack->top;
	return top->data;
}

char* pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��Ͽ����ϴ�.\n");
		return NULL;
	}
	Node* node = stack->top;
	char* data = (char*)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	free(node);
	return data;
}

int getPriority(char* i) {
	if (!strcmp(i, "(")) return 0;
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
}

//Stack, ���ڿ�(37 + 5 ==> "37","+","5"), ũ��
char* transition(Stack* stack, char** s, int size) {
	char res[1000] = "";
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "/") || !strcmp(s[i], "*")) {
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			push(stack, s[i]);
		}
		else if (!strcmp(s[i], "(")) push(stack, s[i]);
		else if (!strcmp(s[i], ")")) {
			while (strcmp(getTop(stack), "(")) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			pop(stack);
		}
		else { strcat(res, s[i]); strcat(res, " "); }
	}
	while (stack->top != NULL) {
		strcat(res, pop(stack)); strcat(res, " ");
	}
	return res;
}

void calculate(Stack* stack, char** s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));
			if (!strcmp(s[i], "+")) z = y + x ;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);
		}
		else {
			push(stack, s[i]);
		}
	}
	printf("%s\n", pop(stack));
}

int main(void) {
	Stack stack;
	stack.top = NULL;
	char a[100] = "1823 + 1293 - ( 123 * 230 )" ;

	// 1. ���� ���ڿ� �и� �� input�� ����
	// size: 1���� �����ؼ� " " ������ count�Ͽ� ���� ���� ���
	int size = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') size++;
	}
	// �迭 a�� " "�� �����Ͽ� ���ڿ� ����
	char* ptr = strtok(a, " ");
	// �� ��, ���� ���ڿ��� ���� 2���� ������ �޸� �Ҵ�
	char** input = (char**)malloc(sizeof(char*) * size);
	// �� ���ڿ��� ���� �ε����� �����Ӱ� �޸� �Ҵ�
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
	}
	// �� �ε����� ��ūȭ �� ���ڿ� ����
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		// strtok�� �����ϸ� �����ڴ� NULL ������ ����Ǳ� ������ �̸� �ٽ� " "�� ġȯ
		ptr = strtok(NULL, " ");
	}

	// 2. input�� ���� ǥ������� �����Ͽ� b�� ����
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("���� ǥ��� %s\n", b);
	// ������ �ʱ�ȭ
	size = 1;
	// Line65���� ���ڿ� ���Ŀ� ������ �־��־��� ������ -1�� ����
	for (int i = 0; i < strlen(b)-1; i++) {
		if (b[i] == ' ') size++;
	}

	char* ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);
	system("pause");
	return 0;
}