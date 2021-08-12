#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 200001 // 단뱡향 100,000개, 양방향 200,000개

// 간선의 정보를 담는 EDGE 구조체
typedef struct {
	int cost;
	int node;
}Edge;
void w