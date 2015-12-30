/**********************************
* 제목 : 연습문제 1 DFS - 재귀로 작성
		다음은 연결되어 있는 두 개의 정점사이의 간선을 순서대로 나열 해 놓은 것이다. 
		모든 정점을 깊이 우선 탐색하여 화면에 깊이 우선 탐색경로를 출력하시오.
		시작 정점을 1로 시작하시오.
* 페이지 : 157
* 코드 : c
**********************************/

#include <stdio.h>

#define MAX 8

int visited[MAX] = { 0, };
int graph[MAX][MAX] = { { 0, }, };

void InitVisited();
void InitGraph();
void MakeGraph(int edgeSize);
void DfsRecursive(int vertex);

int main(int argc, char argv[]) {
	int T;
	int E;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &E);

		InitVisited();
		InitGraph();
		MakeGraph(E);
		DfsRecursive(1);
	}

	return 0;
}

void InitVisited() {
	int i = 0;
	while (i < MAX) {
		visited[i] = 0;
		i++;
	}
}

void InitGraph() {
	int i = 0;
	int j = 0;
	while (i < MAX) {
		while (j < MAX) {
			graph[i][j] = 0;
			j++;
		}
		i++;
	}
}

void MakeGraph(int edgeSize) {
	int i = 0;
	int start;
	int end;

	while (i < edgeSize) {
		scanf("%d %d ", &start, &end);
		graph[start][end] = 1;
		graph[end][start] = 1;
		i++;
	}
}

void DfsRecursive(int vertex) {
	int i;

	visited[vertex] = 1;
	printf("%d ", vertex);

	for (i = 1; i < MAX; i++) {
		if (graph[vertex][i] != 0) {
			if (visited[i] != 1) {
				DfsRecursive(i);
			}
		}
	}
}

//input
1
8
1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7

//output
1 2 4 6 5 7 3