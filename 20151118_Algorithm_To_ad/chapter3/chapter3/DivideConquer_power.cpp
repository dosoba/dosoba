/**********************************
* 제목 : 거듭제곱 반복과 분할정복으로 구하기
* 페이지 : 78 ~ 79
* 코드 : c
**********************************/

#include <stdio.h>
int Iterative_Power(int x, int n);
int Recursive_Power(int x, int n);
int main(int argc, char argv[]) {

	int T;
	int x;
	int n;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d ", &x, &n);

		//printf("#%d %d\n", test_case, Iterative_Power(x,n));
		printf("#%d %d\n", test_case, Recursive_Power(x, n));

	}

	return 0;
}

int Iterative_Power(int x, int n){
	int result = 1;
	int i;

	for (i = 1; i <= n; i++) {
		result *= x;
	}

	return result;
}

int Recursive_Power(int x, int n){
	int result;
	if (n == 1) {
		return x;
	}

	if (n % 2 == 0) {
		result = Recursive_Power(x, n / 2);
		return result * result;
	}
	else {
		result = Recursive_Power(x, (n - 1) / 2);
		return x * result * result;
	}
}

//입력
2
2 3
3 3

//출력
#1 8
#2 27