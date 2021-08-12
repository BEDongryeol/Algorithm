#include <stdio.h>
#include <stdlib.h>

/* 예외처리 추가 예정
 - 삭제할 원소가 없는데 삭제하는 경우
 - Head 노드가 잘못 할당된 경우
 */

typedef struct {  ///값과 포인터를 담을 수 있는 구조체 생성
	int data;
	struct Node* next;
} Node; 

Node* head;

void addFront(Node* root, int data) { //노드 삽입 함수
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void removeFront(Node* root) { //노드 삭제 함수
	Node* front = root->next; //기준이 되는 노드 할당
	root->next = front->next; //기준을 가리키던 포인터를 기준이 가리키는 포인터로 바꿔줌
	free(front); //메모리 해제
}

void freeAll(Node* root) { //모든 메모리 해제 함수 (HEAD 제외)
	Node* cur = head->next;
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node* root) { //존재하는 모든 노드의 데이터 출력
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node)); //동적 메모리 할당
	head->next = NULL;
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	removeFront(head);
	showAll(head);
	freeAll(head);
	system("pause");
	return 0;
}