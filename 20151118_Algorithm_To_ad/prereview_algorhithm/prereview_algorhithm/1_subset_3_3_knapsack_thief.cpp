/*
* name : 부분집합
* contents : 가방에 넣을 수 있는 최대 무게 capacity를 넘지 않으면서 
			가치의 합이 최대가 되도록 물건을 고르는 프로그램을 작성하라.
*/

//input
10 20
2 3 3 4 4 5 7 8 8 9
3 5 7 4 3 9 2 9 5 10

//output
Max Value : 28
4 6 8 9


#include <stdio.h>
#define MAXN 100

int weight[MAXN];
int value[MAXN];

int max_set[MAXN];
int max_set_size;
int max_value;

int capacity;

void print_arr(int(*set), int set_size);
void subSet(int(*set), int set_size, int n, int index);
void evaluate_knapsack(int(*set), int set_size);

//본문
int main() {
	int N;
	int i;

	int set[MAXN];

	scanf(" %d %d", &N, &capacity);

	max_value = 0;
	max_set_size = 0;

	//get value
	for (i = 0; i < N; i++) {
		scanf(" %d", &value[i]);
	}
	//get weight
	for (i = 0; i < N; i++) {
		scanf(" %d", &weight[i]);
	}

	subSet(set, 0, N, 0);
	printf("Max Value : %d\n", max_value);
	print_arr(max_set, max_set_size);

	return 0;
}

void subSet(int(*set), int set_size, int n, int index) {
	if (index == n) {
		//print_arr(set, set_size);
		evaluate_knapsack(set, set_size);
		return;
	}

	set[set_size] = index;
	subSet(set, set_size + 1, n, index + 1);
	subSet(set, set_size, n, index + 1);
}

void evaluate_knapsack(int(*set), int set_size) {
	int cnt_value = 0;
	int cnt_weight = 0;
	int i;

	for (i = 0; i < set_size; i++) {
		cnt_weight += weight[set[i]]; //printf("weight : %d\n", cnt_weight);
		cnt_value += value[set[i]]; //printf("value : %d\n", cnt_value);
	}

	if (cnt_weight > capacity) {
		return;
	}

	if (cnt_value > max_value) {
		max_value = cnt_value;
		max_set_size = set_size;
		for (i = 0; i < set_size; i++) {
			max_set[i] = set[i];
		}
	}
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}
