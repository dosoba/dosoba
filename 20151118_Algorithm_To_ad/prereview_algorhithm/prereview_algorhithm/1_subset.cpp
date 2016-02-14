/*
* name : �κ�����
* contents : 1. ����Լ�, 2. �ݺ���
* 
*/

//input
3	//N

//output
0 1 2
0 1
0 2
0 
1 2
1
2

#include <stdio.h>
#define MAXN 100

void subSet(int(*set), int set_size, int N, int index);
void subSet2(int(*set), int n);
void print_arr(int(*set), int set_size);

//����
int main() {
	int set[MAXN];
	int N;

	scanf(" %d", &N);
	subSet(set, 0, N, 0);
	subSet2(set, N);

	return 0;
}

// ����Լ�
void subSet(int(*set), int set_size, int N, int index) {
	if (index == N) {
		print_arr(set, set_size);
		return;
	}
	set[set_size] = index;
	subSet(set, set_size + 1, N, index + 1);
	subSet(set, set_size, N, index + 1);
}

// �ݺ���
void subSet2(int(*set), int n) {
	int i;
	int j;

	for (i = 0; i < n; i++) {
		set[i] = i;
	}

	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				printf("%d ", set[j]);
			}
		}
		printf("\n");
	}
}

//����Լ�
void print_arr(int(*set), int set_size) {

	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}
