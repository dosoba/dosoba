/*
* name : 투포 147page
* contents : 갑과 을이 선거에 출마해서 값이 m표, 을이 n표를 얻어, 갑이 당선되었다.
즉, 1<= n < m이다. 그런데 개표 과정에서 갑이 항상 을을 앞섰다고 한다.
한표씩 열어볼 때, 그때까지 나온 값의 표가 항상 을의 표보다 많았다.
자연수 m과 n을 입력받아 갑이 얻은 표를 '+', 을이 얻은 표를 '-'로 표시하여, 가능한
개표 과정을 모두 출력하는 프로그램을 작성하라.
*/

//input
4 3

//output
++++---
+++-+--
+++--+-
++-++--
++-+-+-

#include <stdio.h>
#define MAXN 100
#define L 0
#define R 1

void print(int arr[], int arr_size) {
	int i;
	for (i = 0; i < arr_size; i++) {
		if (arr[i] == L) {
			printf("+");
		}
		else if (arr[i] == R) {
			printf("-");
		}
	}
	printf("\n");
}

void paren(int to_open, int to_close, int arr[], int arr_size) {
	if (to_open == 0 && to_close == 0) {
		print(arr, arr_size);
		return;
	}

	if (to_open > 0 || to_open >= to_close) {
		arr[arr_size] = L;
		paren(to_open - 1, to_close, arr, arr_size + 1);
	}

	if (to_close > 0 && to_close > to_open) {
		arr[arr_size] = R;
		paren(to_open, to_close - 1, arr, arr_size + 1);
	}
}

int main() {

	int arr[MAXN];
	int n;
	int m;

	scanf("%d %d", &m, &n);
	paren(m, n, arr, 0);
	return 0;
}