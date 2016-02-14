/*
* name : 부분집합
* contents : n과 k를 입력받아 값이 1인 비트가 k개인 길이 n인 이진수를 출력하는 프로그램을 작성하라.
*/

//input
5 3
//output
0 0 1 1 1
0 1 0 1 1
0 1 1 0 1
0 1 1 1 0
1 0 0 1 1
1 0 1 0 1
1 0 1 1 0
1 1 0 0 1
1 1 0 1 0
1 1 1 0 0

#include <stdio.h>
#define MAXN 100

void print_arr(int(*set), int set_size);
void combination2(int(*bits), int n, int k, int index);

int main() {
	int set[MAXN];
	int N;
	int K;

	scanf(" %d %d", &N, &K);
	combination2(set, N, K, 0);

	return 0;
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}

void combination2(int(*bits), int n, int k, int index) {
	int i;

	if (k == 0) {
		for (i = index; i < n; i++) {
			bits[i] = 0;
		}
		print_arr(bits, n);
	}
	else if (index == n) {
		return;
	}
	else {
		bits[index] = 0;
		combination2(bits, n, k, index + 1);
		bits[index] = 1;
		combination2(bits, n, k - 1, index + 1);
	}
}
