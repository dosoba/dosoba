/**********************************
* 제목 : 병합정렬을 사용해서 정렬한다.
* 페이지 : 81
* 코드 : c
**********************************/

#include <stdio.h>
#define MAX 10

void MergeSort(int *(result), int *(arr), int left, int right);
void Merge(int *(result), int *(arr), int left, int mid, int right);
void Print_arr(int *(arr), int size);
void SetupInput(int *(arr), int size);

int main(int argc, char argv[]) {

	int T;
	int size;

	int arr[MAX] = { 0, };
	int result[MAX] = { 0, };

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &size);
		SetupInput(arr, size);
		//printf("#%d %d\n", test_case, Recursive_Power(x, n));
		printf("#%d ", test_case);
		MergeSort(result, arr, 0, size - 1);
		Print_arr(result, size);

	}

	return 0;
}

void MergeSort(int *(result), int *(arr), int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(result, arr, left, mid);
		MergeSort(result, arr, mid + 1, right);
		Merge(result, arr, left, mid, right);
	}
}

void Merge(int *(result), int *(arr), int left, int mid, int right) {
	int l_idx = left;
	int r_idx = mid + 1;
	int s_idx = left;

	int i;

	while (l_idx <= mid && r_idx <= right) {
		if (arr[l_idx] < arr[r_idx]) {
			result[s_idx++] = arr[l_idx++];
		}
		else {
			result[s_idx++] = arr[r_idx++];
		}
	}
	if (l_idx > mid) {
		while (r_idx <= right) {
			result[s_idx++] = arr[r_idx++];
		}
	}
	else {
		while (l_idx <= mid) {
			result[s_idx++] = arr[l_idx++];
		}
	}

	for (i = left; i <= right; i++) {
		arr[i] = result[i];
	}
}

void Print_arr(int *(arr), int size) {
	int i = 0;
	while (i < size) {
		printf("%d ", arr[i]);
		i++;
	}
	putchar('\n');
}

void SetupInput(int *(arr), int size) {
	int i = 0;
	while (i < size) {
		scanf("%d", &arr[i]);
		i++;
	}
}

//input
2
8
69 10 30 2 16 8 31 22
8
69 10 30 2 16 8 31 69

//output
#1 2 8 10 16 22 30 31 69
#2 2 8 10 16 30 31 69 69