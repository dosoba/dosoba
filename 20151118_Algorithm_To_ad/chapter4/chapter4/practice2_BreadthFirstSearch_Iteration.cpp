/**********************************
* 제목 : 연습문제 2 - BFS
다음은 연결되어 있는 두 개의 정점사이의 간선을 순서대로 나열 해 놓은 것이다.
모든 정점을 너비 우선 탐색하여 화면에 너비 우선탐색 경로를 출력하시오.
시작 정점을 1로 시작하시오.
1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7
출력 결과의 예는 다음과 같다.
1-2-3-4-5-7-6
* 페이지 : 164
* 코드 : c
**********************************/
#include <stdio.h>

#define MAX 8
int visited[MAX] = { 0, };
int adjacency[MAX][MAX] = { { 0, }, };
int queue[MAX] = { 0, };
int front;
int rear;

//for init
void InitVisited(int edgeSize);
void InitAdjacency(int edgeSize);

//for BFS
void MakeAdjacency(int edgeSize);
void BfsIteration(int vertex);

//for Queue
void EnQueue(int item);
int DeQueue();


int main() {
	int T;
	int E;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &E);
		// implementation
		front = -1;
		rear = -1;
		InitVisited(E);
		InitAdjacency(E);
		MakeAdjacency(E);
		BfsIteration(1);
	}

	return 0;
}

void InitVisited(int edgeSize) {
	int i = 0;
	while (i < edgeSize) {
		visited[i] = 0;
		i++;
	}
}

void InitAdjacency(int edgeSize) {
	int i;
	int j;

	i = 0;
	while (i < edgeSize) {
		j = 0;
		while (j < edgeSize) {
			adjacency[i][j] = 0;
			adjacency[j][i] = 0;
			j++;
		}
		i++;
	}
}

void MakeAdjacency(int edgeSize) {
	int i;
	int parent;
	int child;

	i = 0;
	while (i < edgeSize) {
		scanf("%d %d ", &parent, &child);
		adjacency[parent][child] = 1;
		adjacency[child][parent] = 1;
		i++;
	}
}

void EnQueue(int item) {
	//check overflow
	if (rear == MAX - 1) {
		return;
	}
	else {
		rear++;
		queue[rear] = item;
	}
}

int DeQueue() {
	//check underflow
	if (front == rear) {
		return 0;
	}
	else {
		front++;
		return queue[front];
	}
}

void BfsIteration(int vertex) {
	int item;

	EnQueue(vertex);
	visited[vertex] = 1;

	while (front != rear) {
		item = DeQueue();
		printf("%d ", item);

		for (int i = 1; i < MAX; i++) {
			if (adjacency[item][i] == 1 && visited[i] != 1) {
				EnQueue(i);
				visited[i] = 1;
			}
		}
	}
}

//input
1
8
1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7

//output
1 2 3 4 5 7 6