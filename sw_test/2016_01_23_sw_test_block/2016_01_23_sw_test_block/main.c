/**********************************
* 제목 : 벽돌깨기 최대값 구하기
* 페이지 :
* 코드 : c
**********************************/

#include <stdio.h>
#define MAX 11

int input[MAX];
int items[MAX];
int used[MAX];

int N; //N <= 10
int max;

void printAll();
void Permutation(int n, int r);
void Swap(int src, int dst);
void GetScore();
int GetLeft(int start);
int GetRight(int start);
int GetIdx(int item);
void InitUsed();

int main() {
	int T;

	scanf("%d ", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &N);
		max = 0;

		//read data
		for (int i = 0; i < N; i++) {
			scanf("%d ", &items[i]);
			input[i] = items[i];
			used[i] = 0;
		}

		printf("#%d ", test_case);
		Permutation(N, N);
		printf("%d\n", max);
	}
}

void Permutation(int n, int r) {
	if (r == 0) {
		//printAll();
		InitUsed();
		GetScore();
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			Swap(i, n - 1);
			Permutation(n - 1, r - 1);
			Swap(i, n - 1);
		}
	}
}

void InitUsed() {
	for (int i = 0; i < N; i++) {
		used[i] = 0;
	}
}

void printAll() {
	for (int i = 0; i < N; i++) {
		printf("%d ", items[i]);
	}
}

void Swap(int src, int dst) {
	int temp = items[src];
	items[src] = items[dst];
	items[dst] = temp;
}

void GetScore() {
	int score = 0;
	int left;
	int right;

	int idx;

	for (int i = 0; i < N; i++) {
		idx = GetIdx(items[i]);
		used[idx] = 1;
		left = GetLeft(idx);
		right = GetRight(idx);

		if (left != -1 && right != -1) {
			score += left * right;
		}
		else if (left != -1 && right == -1) {
			score += left;
		}
		else if (left == -1 && right != -1) {
			score += right;
		}
		else {
			score += items[i];
		}
	}

	if (max < score) {
		max = score;
	}
}

int GetLeft(int start) {
	int left = -1;

	for (int i = start - 1; i >= 0; i--) {
		if (used[i] != 1) {
			return input[i];
		}
	}
	return left;
}

int GetRight(int start) {
	int right = -1;

	for (int i = start + 1; i < N; i++) {
		if (used[i] != 1) {
			return input[i];
		}
	}
	return right;
}

int GetIdx(int item) {
	int idx = -1;

	for (int i = 0; i < N; i++) {
		if (item == input[i]) {
			idx = i;
			break;
		}
	}
	return idx;
}