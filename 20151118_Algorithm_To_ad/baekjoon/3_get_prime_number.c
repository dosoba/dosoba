// baekjoon : https://www.acmicpc.net/problem/1929
// 참고 site : https://ko.wikipedia.org/wiki/%EC%86%8C%EC%88%98_(%EC%88%98%EB%A1%A0)

//input
3 16

//output
3
5
7
11
13

#include <stdio.h>
#define MAX 1000001
typedef enum { FALSE = 0, TRUE = 1 }BOOL;

BOOL prime[MAX] = {TRUE, TRUE, };

int main() {
	int m, n;
	scanf("%d%d", &m, &n);

	for (int i = 2; i * i <= n; ++i) {
		if (!prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = TRUE;
			}
		}
	}

	int count = 0;
	for (int i = m; i <= n; ++i) {
		if (!prime[i]) {
			printf("%d\n", i);
		}
	}

	return 0;
}
