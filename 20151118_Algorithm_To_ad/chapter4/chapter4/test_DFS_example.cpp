/**********************************
* 제목 : 깊이우선 탐색을 통한 최단경로 구하기
* 페이지 : http://blog.eairship.kr/268
* 코드 : c
**********************************/
#include <stdio.h>

#define MAX 10
int N;
int min;
int map[MAX][MAX];

void DFS(int y, int x, int counts);

int main() {
	int T;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &N);

		min = N * N;//최소값 임의 지정

		//make map
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &map[i][j]);
			}
		}

		DFS(0, 0, 1);
		printf("#%d %d\n", test_case, min);
	}

	return 0;
}

void DFS(int y, int x, int counts) {
	if (x == N - 1 && y == N - 1) {
		if (min > counts) {
			min = counts;
			return;
		}
	}
	map[y][x] = 0;

	if (y > 0 && map[y - 1][x] != 0) {
		DFS(y - 1, x, counts + 1);
	}

	if (y < N - 1 && map[y + 1][x] != 0) {
		DFS(y + 1, x, counts + 1);
	}

	if (x > 0 && map[y][x - 1] != 0) {
		DFS(y, x - 1, counts + 1);
	}

	if (x < N - 1 && map[y][x + 1] != 0) {
		DFS(y, x + 1, counts + 1);
	}

	map[y][x] = 1;
}