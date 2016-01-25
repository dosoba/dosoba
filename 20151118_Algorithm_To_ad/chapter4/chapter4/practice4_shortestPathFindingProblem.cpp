/**********************************
* 제목 : Dijkstra 적용해보시오
* 페이지 : 186
* 코드 : c
**********************************/


#include <stdio.h>

#define MAX 10
#define INFINITE 999
#define mininum(x,y) (((x)>(y)) ? (y) : (x))

typedef enum { FALSE = 0, TRUE = 1 }BOOL;

BOOL visitAll();
void Dijkstra();
int getMinimum();
int getMinimumTwo(int num1, int num2);

int adjacency[MAX][MAX];
int lengthes[MAX];
int visited[MAX];
int pre[MAX];	//for tracking path

int N, M;
int start, end;

int main() {

	int T;
	int x, y, length;

	scanf("%d ", &T);

	for (int test_case = 1; test_case <= T; test_case++) {

		scanf("%d %d ", &N, &M); // vertex, edge

		//init adjacency, visited
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				if (i == j) {
					adjacency[i][j] = 0;
				}
				else {
					adjacency[i][j] = INFINITE;
				}
			}
			visited[i] = 0;
		}

		//make adjacency
		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d ", &y, &x, &length);
			adjacency[y][x] = length;
		}

		//set start point, end point
		scanf("%d %d ", &start, &end);

		//init pre
		for (int i = 0; i <= N; i++) {
			pre[i] = start;
		}

		printf("#%d ", test_case);
		Dijkstra();

		printf("\n#%d ", test_case);
		for (int i = 1; i <= N; i++) {
			printf("%d ", pre[i]);
		}
		printf("\n");
	}

	return 0;
}

void Dijkstra() {
	int vertex;
	//enqueue
	vertex = start;

	//visited start point
	visited[start] = 1;

	//update lengthes
	for (int i = 1; i <= N; i++) {
		lengthes[i] = adjacency[vertex][i];
	}

	while (visitAll() != TRUE) {
		vertex = getMinimum();
		visited[vertex] = 1;

		for (int i = 1; i <= N; i++) {
			if ((adjacency[vertex][i] < INFINITE) && (adjacency[vertex][i] > 0)) {
				if (lengthes[i] > (lengthes[vertex] + adjacency[vertex][i])) {
					//lengthes[i] = getMinimumTwo(lengthes[i], lengthes[vertex] + adjacency[vertex][i]);
					lengthes[i] = mininum((lengthes[i]), (lengthes[vertex] + adjacency[vertex][i]));
					pre[i] = vertex;	//for tracking for path
				}
			}
		}
	}
	printf("%d", lengthes[end]);
}

BOOL visitAll() {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			return FALSE;
		}
	}
	return TRUE;
}

int getMinimum() {
	int min;
	int index;

	if (lengthes[1] == 0) {
		min = INFINITE;
	}
	else {
		min = lengthes[1];
	}

	index = 0;
	for (int i = 1; i <= N; i++) {
		if (min > lengthes[i] && lengthes[i] != 0 && visited[i] != 1) {
			min = lengthes[i];
			index = i;
		}
	}

	return index;
}

int getMinimumTwo(int num1, int num2) {
	if (num1 > num2) {
		return num2;
	}
	else {
		return num1;
	}
}

//input
1		//tc number
6 10	//node edge numbers
1 2 3	// y, x, length
2 4 5
1 3 4
3 2 1
3 5 5
3 4 4
4 5 3
4 6 4
5 1 3
5 6 5
1 6		// start node, end node
//output
#1 12
#1 1 1 1 2 3 4 //경로 살펴보려고 추가됨