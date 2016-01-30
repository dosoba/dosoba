/**********************************
* 제목 : 아파트 층별로 페이트 칠하기 (노란색, 파란색 칠)
f(1) = 2, f(2) = 3, f(8)=?
* 페이지 : 247
* 코드 : c
**********************************/

#include <stdio.h>
int fibonacci(int n);

int main() {

	printf("f(8) : %d\n", fibonacci(8));
	return 0;
}

int fibonacci(int n) {
	if (n == 1) {
		return 2;
	}
	else if (n == 2) {
		return 3;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

//input

//output
f(8) : 55