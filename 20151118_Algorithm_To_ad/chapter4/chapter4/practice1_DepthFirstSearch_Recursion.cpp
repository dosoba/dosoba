/**********************************
* ���� : �������� 1 DFS - ��ͷ� �ۼ�
		������ ����Ǿ� �ִ� �� ���� ���������� ������ ������� ���� �� ���� ���̴�. 
		��� ������ ���� �켱 Ž���Ͽ� ȭ�鿡 ���� �켱 Ž����θ� ����Ͻÿ�.
		���� ������ 1�� �����Ͻÿ�.
* ������ : 157
* �ڵ� : c
**********************************/

#include <stdio.h>

#define MAX 8

int visited[MAX] = { 0, };
int graph[MAX][MAX] = { { 0, }, };
//int counts;

void InitGraph();
void MakeGraph(int edgeSize);
void DfsRecursive(int vertex);

int main(int argc, char argv[]) {
	int T;
	int E;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//counts = 0;
		scanf("%d ", &E);

		InitGraph();
		MakeGraph(E);
		DfsRecursive(1);
		//printf("\ncounts : %d\n", counts);
	}

	return 0;
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
	//counts++;

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