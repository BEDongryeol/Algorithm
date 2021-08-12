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

void push(Stack* stack, char* data) {
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
		printf("스택 언더플로우가 발생하였습니다.\n");
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

//Stack, 문자열(37 + 5 ==> "37","+","5"), 크기
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
			if (!strcmp(s[i], "+")) z = y + x;
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
	char a[100] = "1823 + 1293 - ( 123 * 230 )";

	// 1. 수식 문자열 분리 및 input에 삽입
	// size: 1부터 시작해서 " " 개수를 count하여 문자 개수 계산
	int size = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') size++;
	}
	// 배열 a를 " "로 구분하여 문자열 생성
	char* ptr = strtok(a, " ");
	// 각 수, 연산 문자열을 담을 2차원 포인터 메모리 할당
	char** input = (char**)malloc(sizeof(char*) * size);
	// 각 문자열을 담을 인덱스에 여유롭게 메모리 할당
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
	}
	// 각 인덱스에 토큰화 된 문자열 삽입
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		// strtok를 진행하며 구분자는 NULL 값으로 변경되기 때문에 이를 다시 " "로 치환
		ptr = strtok(NULL, " ");
	}

	// 2. input을 후위 표기법으로 변경하여 b에 삽입
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("후위 표기법 %s\n", b);
	// 사이즈 초기화
	size = 1;
	// Line65에서 문자열 이후에 공백을 넣어주었기 떄문에 -1을 해줌
	for (int i = 0; i < strlen(b) - 1; i++) {
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