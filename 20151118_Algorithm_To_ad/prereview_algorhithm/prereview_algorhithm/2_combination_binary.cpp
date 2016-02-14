/*
* name : �κ�����
* contents : n�� k�� �Է¹޾� ���� 1�� ��Ʈ�� k���� ���� n�� �������� ����ϴ� ���α׷��� �ۼ��϶�.
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
