/**********************************
* 제목 : 1부터 n까지의 합을 계산하는 반복 함수와 재귀 함수
* 페이지 : 알고리즘 문제 해결 전략 147
* 코드 : c
**********************************/
//input
10

//output
n까지의 합 : 55

#include <stdio.h>
int sum(int n);
int recursiveSum(int n);

int main() {
	int n;
	scanf("%d", &n);

	printf("n까지의 합 : %d \n", sum(n));
	printf("n까지의 합 : %d \n", recursiveSum(n));

	return 0;
}

//반복함수
int sum(int n) {
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++) {
		sum += i;
	}

	return sum;
}

//재귀함수
int recursiveSum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + recursiveSum(n - 1);
	}
}