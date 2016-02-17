/*
* name : 연회장 나누기
* contents : 0 부터 n - 1까지 어떤 사람이 누구와 친한지를 입력받아서 컷이 최소가 되도록
n명을 n/2명씩 둘로 나누는 방법과 이때의 컷을 출력하는 프로그램을 작성하라.
*/

//input
6
2 1 3
2 0 3
3 3 4 5
3 0 1 2
2 2 5
2 2 4

//output
cut : 1
	  0 0 1 0 1 1


#include <stdio.h>
#define MAXN 100

	  int friend_count[MAXN];
int friends[MAXN][MAXN];
int min_cut = MAXN * MAXN;
int min_partition[MAXN];

void combinationPartition(int(*set), int n, int k, int index);
void evaluationPartition(int(*set), int n);
void print_arr(int(*set), int set_size);

int main() {
	int set[MAXN];
	int N;
	int i;
	int j;

	scanf(" %d", &N);

	for (i = 0; i < N; i++) {
		scanf(" %d", &friend_count[i]);
		for (j = 0; j < friend_count[i]; j++) {
			scanf(" %d", &friends[i][j]);
		}
	}

	combinationPartition(set, N, N / 2, 0);

	printf("cut : %d\n", min_cut);
	print_arr(min_partition, N);

	return 0;
}

void combinationPartition(int(*bits), int n, int k, int index) {
	int i;
	if (k == 0) {
		for (i = index; i < n; i++) {
			bits[i] = 0;
		}
		//print_arr(bits, n);
		evaluationPartition(bits, n);
	}
	else if (index == n) {
		return;
	}
	else {
		bits[index] = 0;
		combinationPartition(bits, n, k, index + 1);
		bits[index] = 1;
		combinationPartition(bits, n, k - 1, index + 1);
	}
}

void evaluationPartition(int(*bits), int n) {
	int cut = 0;
	int i;
	int j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < friend_count[i]; j++) {
			if (i < friends[i][j] && bits[i] != bits[friends[i][j]]) {
				cut++;
			}
		}
	}

	if (cut < min_cut) {
		for (i = 0; i < n; i++) {
			min_partition[i] = bits[i];
		}
		min_cut = cut;
	}
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}