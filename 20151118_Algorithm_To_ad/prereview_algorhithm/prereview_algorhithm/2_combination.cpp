/*
* name : 조합
* contents : N과 K를 입력받아서 0,1,2,...,N-1중에 K개를 뽑는 nCk 조합을 모두 출력하시오
*/

//input
4 2		//N K

//output
0 1
0 2
0 3
1 2
1 3
2 3


#include <stdio.h>
#define MAXN 100

void combination(int(*set), int set_size, int n, int k, int index);
void print_arr(int(*set), int set_size);

int main() {
	int set[MAXN];
	int N;
	int K;

	scanf(" %d %d", &N, &K);
	combination(set, 0, N, K, 0);

	return 0;
}

void combination(int(*set), int set_size, int n, int k, int index) {
	if (k == 0) {
		print_arr(set, set_size);
	}
	else if (index == n) {
		return;
	}
	else {
		set[set_size] = index;
		combination(set, set_size + 1, n, k - 1, index + 1);
		combination(set, set_size, n, k, index + 1);
	}
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}
