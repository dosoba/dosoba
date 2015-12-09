
/**********************************
* 제목 : 배열의 데이터를 퀵정렬하는 함수를 작성하시오. (퀵정렬 - Lomuto)
* 페이지 : 92
* 코드 : c
**********************************/

#include <stdio.h>
#define MAX 10

void Print_arr(int *(arr), int size);
void SetupInput(int *(arr), int size);
void QuickSort(int *(arr), int left, int right);
int Partition_Lomuto(int *(arr), int partition, int right);
int Partition_Lomuto_wiki(int *(arr), int left, int right);
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
		split = Partition_Lomuto(arr, left, right);
		QuickSort(arr, left, split - 1);
		QuickSort(arr, split + 1, right);
	}
}

//aps version
int Partition_Lomuto(int *(arr), int partition, int right) {
	int x = arr[right];
	int i = partition - 1;

	for (int j = partition; j < right; j++) {
		if (arr[j] <= x) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[right]);

	return i + 1;

}

//wikipedia version : use
int Partition_Lomuto_wiki(int *(arr), int left, int right) {
	int pivot = arr[right];
	int i = left;

	for (int j = left; j<right; j++) {
		if (arr[j] <= pivot) {
			Swap(&arr[i], &arr[j]);
			i++;
		}
	}
	Swap(&arr[i], &arr[right]);

	return i;
}

void Swap(int *src, int *dst) {
	int temp;
	temp = *src;
	*src = *dst;
	*dst = temp;
}

//input
3
6
11 45 23 81 28 34
10
11 45 23 81 28 34 99 22 17 8
10
1 1 1 1 1 0 0 0 0 0

//output
#1 11 23 28 34 45 81
#2 8 11 17 22 23 28 34 45 81 99
#3 0 0 0 0 0 1 1 1 1 1
