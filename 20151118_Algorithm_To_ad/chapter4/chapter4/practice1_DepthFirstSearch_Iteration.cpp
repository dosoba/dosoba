/**********************************
* ���� : �������� 1 DFS - �ݺ��� �ۼ�
		������ ����Ǿ� �ִ� �� ���� ���������� ������ ������� ���� �� ���� ���̴�.
		��� ������ ���� �켱 Ž���Ͽ� ȭ�鿡 ���� �켱 Ž����θ� ����Ͻÿ�.
		���� ������ 1�� �����Ͻÿ�.
* ������ : 157
* �ڵ� : c
**********************************/
/*
#include <stdio.h>

#define MAX 8

int visited[MAX] = { 0, };
int graph[MAX][MAX] = { { 0, }, };
int stack[MAX] = { 0, };
int top;

void InitGraph();
void InitVisited();
void MakeGraph(int edgeSize);
void DfsIteration(int vertex);
void Push(int item);
int Pop();

int main(int argc, char argv[]) {
	int T;
	int E;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		top = -1;
		scanf("%d ", &E);

		InitGraph();
		InitVisited();
		MakeGraph(E);
		DfsIteration(1);
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

void InitVisited() {
	int i = 0;
	while (i < MAX) {
		visited[i] = 0;
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
		graph[end][start] = 1; //���⿡���� �ݵ�� �ʿ���
		i++;
	}
}

void Push(int item) {
	if (top >= MAX - 1) {
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}

int Pop() {
	if (top == -1) {
		return 0;
	}
	else {
		return stack[top--];
	}
}

void DfsIteration(int vertex) {
	int item;
	int i;
	Push(vertex);

	while (top != -1) {
		item = Pop();

		if (visited[item] != 1) {
			visited[item] = 1;
			printf("%d ", item);

			for (i = 1; i < MAX; i++) {
				if (i != item && graph[item][i] != 0) {//���ǹ� �ݵ�� �ʿ�
					if (visited[i] != 1) {
						Push(i);
					}
				}
			}
		}
	}
}

//input
1
8
1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7

//output
1 3 7 6 5 2 4
*/