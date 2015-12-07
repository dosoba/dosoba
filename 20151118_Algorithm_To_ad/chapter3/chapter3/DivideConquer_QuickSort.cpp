/**********************************
* 제목 : 병합정렬을 사용해서 정렬한다. (퀵정렬)
* 페이지 : 83
* 코드 : c
**********************************/

#include <stdio.h>
#define MAX 10

void Print_arr(int *(arr), int size);
void SetupInput(int *(arr), int size);
void QuickSort(int *(arr), int left, int right);
int Partition(int *(arr), int left, int right);
void Swap(int *src, int *dst);

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
		QuickSort(arr, 0, size - 1);
		Print_arr(arr, size);
	}

	return 0;
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

void QuickSort(int *(arr), int left, int right) {
	int split;

	if (left < right) {
		split = Partition(arr, left, right);
		QuickSort(arr, left, split - 1);
		QuickSort(arr, split + 1, right);
	}
}

int Partition(int *(arr), int left, int right) {
	int pivot = arr[left];
	int l_idx = left;
	int r_idx = right;
	while (l_idx <= r_idx) {
		while (arr[l_idx] <= pivot) {
			l_idx++;
		}
		while (arr[r_idx] > pivot) {
			r_idx--;
		}
		if (l_idx < r_idx) {
			Swap(&(arr[l_idx]), &(arr[r_idx]));
		}
	}
	Swap(&(arr[left]), &(arr[r_idx]));
	return r_idx;
}

void Swap(int *src, int *dst) {
	int temp;
	temp = *src;
	*src = *dst;
	*dst = temp;
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
