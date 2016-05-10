// 미해결 문제 - 다시 풀어볼것
// baekjoon : https://www.acmicpc.net/problem/11729
// 내용 : https://ko.wikipedia.org/wiki/%ED%95%98%EB%85%B8%EC%9D%B4%EC%9D%98_%ED%83%91

//input
3

//output
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3

#include <stdio.h>

void move(int n, int from, int to, int temp) {
	printf("%d %d %d %d\n", n, from, to, temp);
	if (n == 0) {
		printf("n==0\n");
		return;
	}

	move(n - 1, from, temp, to);
	printf("%d %d\n", from, to);
	move(n - 1, temp, to, from);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	move(n, 1, 3, 2);
	return 0;
}
