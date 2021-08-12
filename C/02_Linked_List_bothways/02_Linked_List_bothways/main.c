#include <stdio.h>
#include <stdlib.h>

/* 
예외사항 추가 예정
- 삭제할 원소가 없는데 삭제하는 경우 등
*/

typedef struct {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

Node* head, * tail;

void insert(int data) {  //오름차순으로 데이터 삽입
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront() {  //헤드 다음의 노드 삭제
	Node* node = head->next; //삭제할 노드
	head->next = node->next;

	Node* next = node->next; //삭제할 노드의 다음에 위치하던 노드
	next->prev = head;
	free(node); //메모리를 해제 시켜줌
}

void show() { //리스트 내 모든 원소 출력
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head; //자기 자신을 넣어준다. (끝을 head, tail로 구분하기 때문에)
	tail->next = tail;
	tail->prev = head;
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);  //오름차순으로 삽입
	removeFront();  // head 다음의 노드 삭제 = 1
	show();
	system("pause");
	return 0;
}