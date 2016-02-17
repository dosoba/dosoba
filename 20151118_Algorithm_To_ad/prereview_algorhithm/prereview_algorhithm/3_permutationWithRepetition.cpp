/*
* name : 중복순열
* contents : n과 k를 입력받아서 0, 1, ..., n - 1 중에 k개를 뽀는 중복순열(permuation with repetition)
을 모두 출력하는 프로그램을 작성하시오.
*/


//input
3 2

//output
0 0
0 1
0 2
1 0
1 1
1 2
2 0
2 1
2 2

#include <stdio.h>
#define MAXN 100

void permutationWithRepetition(int(*arr), int len, int n, int k);
void print_arr(int(*set), int set_size);

int main() {

	int arr[MAXN];
	int n;
	int k;
	scanf(" %d %d", &n, &k);
	permutationWithRepetition(arr, 0, n, k);
	return 0;
}

void permutationWithRepetition(int(*arr), int len, int n, int k) {
	int i;

	if (len == k) {
		print_arr(arr, len);
		return;
	}

	for (i = 0; i < n; i++) {
		arr[len] = i;
		permutationWithRepetition(arr, len + 1, n, k);
	}
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}