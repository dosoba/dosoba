/*
* name :올바른 괄호쌍 구하기
* contents : 자연수 n을 입력받아서 n쌍의 괄호로 
			만들 수 있는 올바른 괄호 배열을 모두 출력하는 프로그램
*/

//input
3

//output
((()))
(()())
(())()
()(())
()()()


#include <stdio.h>
#define MAXN 100
#define L 0
#define R 1

void print(int arr[], int arr_size) {
	int i;
	for (i = 0; i < arr_size; i++) {
		if (arr[i] == L) {
			printf("(");
		}
		else if (arr[i] == R) {
			printf(")");
		}
	}
	printf("\n");
}

void paren(int to_open, int to_close, int arr[], int arr_size) {
	if (to_open == 0 && to_close == 0) {
		print(arr, arr_size);
		return;
	}

	if (to_open > 0) {
		arr[arr_size] = L;
		paren(to_open - 1, to_close + 1, arr, arr_size + 1);
	}

	if (to_close > 0) {
		arr[arr_size] = R;
		paren(to_open, to_close - 1, arr, arr_size + 1);
	}
}

int main() {

	int arr[MAXN];
	int n;

	scanf("%d", &n);
	paren(n, 0, arr, 0);
	return 0;
}
