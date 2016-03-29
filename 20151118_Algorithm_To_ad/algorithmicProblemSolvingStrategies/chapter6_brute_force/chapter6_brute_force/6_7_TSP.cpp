/**********************************
* 제목 : 외판원 순회2
* 페이지 : 165, https://www.acmicpc.net/problem/10971
* 코드 : c
**********************************/

//input
4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0
//output
35

#include <stdio.h>
#define MAX 10
#define INF 123456789

typedef enum {FALSE = 0, TRUE = 1}BOOL;
int N;
double dist[MAX][MAX];


double min(double src, double dst);
double shortestPath(int *(path), int index, BOOL *(visited), double currentLength);
int main() {

	int path[MAX] = { -1, };
	BOOL visited[MAX] = {FALSE, };
	double currentLength = 0;
	int index = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &dist[i][j]);
		}
	}

	path[0] = 0;
	index++;
	visited[0] = TRUE;
	printf("%ld\n", shortestPath(path, index, visited, currentLength));

	return 0;
}



double min(double src, double dst) {
	if (src > dst) {
		return dst;
	}
	else
	{
		return src;
	}
}

double shortestPath(int *(path), int index, BOOL *(visited), double currentLength) {

	int count = 0;
	if (index == N) {
		/*
		for (int i = 0; i < N; i++) {
			printf("%d ", path[i]);
		}
		printf(" : %d\n", currentLength + dist[path[index - 1]][path[0]]);
		*/
		return currentLength + dist[path[index - 1]][path[0]];
	}

	double ret = INF;
	for (int next = 0; next < N; next++) {
		if (visited[next]) continue;
		int here = path[index - 1];
		path[index] = next;
		index++;
		visited[next] = TRUE;
		
		if (dist[here][next] != 0) {
			double cand = shortestPath(path, index, visited, currentLength + dist[here][next]);
			ret = min(ret, cand);
		}
		visited[next] = FALSE;
		index--;
	}

	return ret;
}