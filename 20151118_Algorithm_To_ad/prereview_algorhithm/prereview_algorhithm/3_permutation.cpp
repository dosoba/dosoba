////////////////////////////////////////////////// 사전순이 아닌 순으로 출력하기

/*
* name : 순열
* contents : 0, 1, ..., n-1에서 k개를 뽑아 나열하는 경우의 수는 nPk이다. 
n과 k를 입력받아서 모든 경우를 출력한느 프로그램을 작성하시오.
*/

//input
3 2

//output
0 1
0 2
1 0
1 2
2 1
2 0


#include <stdio.h>
#define MAXN 10

void print_arr(int(*set), int set_size);
void swap_arr(int(*arr), int i, int j);
void permutation(int(*arr), int len, int n, int k);

int main() {

	int arr[MAXN];
	int n;
	int k;
	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	permutation(arr, 0, n, k);
	return 0;
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}

void swap_arr(int(*arr), int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void permutation(int(*arr), int len, int n, int k) {
	int i;
	if (len == k) {
		print_arr(arr, len);
		return;
	}
	for (i = len; i < n; i++) {
		swap_arr(arr, i, len);
		permutation(arr, len + 1, n, k);
		swap_arr(arr, i, len);
	}
}

////////////////////////////////////////////////// 사전순으로 출력하기

/*
* name : 순열
* contents : 0, 1, ..., n-1에서 k개를 뽑아 나열하는 경우의 수는 nPk이다.
n과 k를 입력받아서 모든 경우를 사전순으로 출력하는 프로그램을 작성하시오.
*/

//input
3 2

//output
0 1
0 2
1 0
1 2
2 0
2 1

#include <stdio.h>
#define MAXN 10

void print_arr(int(*set), int set_size);
void right_rotate(int(*arr), int s, int t);
void left_rotate(int(*arr), int s, int t);
void permutation(int(*arr), int len, int n, int k);

int main() {

	int arr[MAXN];
	int n;
	int k;
	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	permutation(arr, 0, n, k);
	return 0;
}

void print_arr(int(*set), int set_size) {
	for (int i = 0; i < set_size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}

void swap_arr(int(*arr), int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void permutation(int(*arr), int len, int n, int k) {
	int i;
	if (len == k) {
		print_arr(arr, len);
		return;
	}
	for (i = len; i < n; i++) {
		//swap_arr(arr, i, len);
		right_rotate(arr, len, i);
		permutation(arr, len + 1, n, k);
		//swap_arr(arr, i, len);
		left_rotate(arr, len, i);
	}
}

void right_rotate(int(*arr), int s, int t) {
	int i;
	int last;
	last = arr[t];
	for (int i = t; i > s; i--) {
		arr[i] = arr[i - 1];
	}
	arr[s] = last;
}

void left_rotate(int(*arr), int s, int t) {
	int i;
	int first;
	first = arr[s];
	for (i = s; i < t; i++) {
		arr[i] = arr[i + 1];
	}
	arr[t] = first;
}
