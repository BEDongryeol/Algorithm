#include <stdio.h>
#include <stdlib.h>

/* ����ó�� �߰� ����
 - ������ ���Ұ� ���µ� �����ϴ� ���
 - Head ��尡 �߸� �Ҵ�� ���
 */

typedef struct {  ///���� �����͸� ���� �� �ִ� ����ü ����
	int data;
	struct Node* next;
} Node; 

Node* head;

void addFront(Node* root, int data) { //��� ���� �Լ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void removeFront(Node* root) { //��� ���� �Լ�
	Node* front = root->next; //������ �Ǵ� ��� �Ҵ�
	root->next = front->next; //������ ����Ű�� �����͸� ������ ����Ű�� �����ͷ� �ٲ���
	free(front); //�޸� ����
}

void freeAll(Node* root) { //��� �޸� ���� �Լ� (HEAD ����)
	Node* cur = head->next;
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node* root) { //�����ϴ� ��� ����� ������ ���
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node)); //���� �޸� �Ҵ�
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