// baekjoon :https://www.acmicpc.net/problem/11729
// 내용 : http://terms.naver.com/entry.nhn?docId=2270443&cid=51173&categoryId=51173
// 내용링크를 통해서 이해할수 있었음
// 1. 규칙 1 : 왼쪽 기둥에서 2(=n-1)개의 원판을 가운데 기둥으로 옮긴다. 이때 오른쪽 기둥을 이용한다.
// 2. 왼쪽 기둥의 원판을 오른쪽 기둥으로 옮긴다.
// 3. 가운데 기둥의 2(=n-1)개의 원판을 오른쪽 기둥으로 옮긴다. 이때 왼쪽 기둥을 이용한다.


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
void hanoi(int n, int a, int b, int c);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoi(n, 1, 2, 3);
	return 0;
}


void hanoi(int n, int a, int b, int c) {
	if (n == 0) return;
	hanoi(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	hanoi(n - 1, b, a, c);
}
