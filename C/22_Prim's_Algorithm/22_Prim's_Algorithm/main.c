#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 200001 // �ܓ��� 100,000��, ����� 200,000��

// ������ ������ ��� EDGE ����ü
typedef struct {
	int cost;
	int node;
}Edge;
void w