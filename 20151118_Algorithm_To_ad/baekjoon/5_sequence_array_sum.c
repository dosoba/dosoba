// baekjoon : https://www.acmicpc.net/problem/11659
// 내용 : 구간 합 구하기 - 타임아웃 조심

//input
5 3
5 4 3 2 1
1 3
2 4
5 5

//output
12
9
1

#include <stdio.h>
#define MAX 100001

int sum[MAX] = { 0, };

int main() {
	int n;
	int m;
	int number;
	int s;
	int e;

	scanf("%d %d", &n, &m);

	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &number);
		sum[i] = sum[i - 1] + number;
	}

	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &e);

		printf("%d\n", sum[e] - sum[s - 1]);
	}
	return 0;
}
