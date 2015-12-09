/**********************************
* 제목 : 병합정렬을 사용해서 정렬한다. (퀵정렬 - Lomuto)
* 페이지 : 87
* 코드 : c
**********************************/

#include <stdio.h>
#define MAX 10

void Print_arr(int *(arr), int size);
void SetupInput(int *(arr), int size);
void QuickSort(int *(arr), int left, int right);
int Partition_Lomuto(int *(arr), int partition, int right);
int Partition_Lomuto_wiki (int *(arr), int left, int right);
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
int Partition_Lomuto_wiki (int *(arr), int left, int right) {
	int pivot = arr[right];
	int i = left;

	for (int j = left; j<right; j++) {
		if(arr[j] <= pivot) {
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
2
9
3 2 4 6 9 1 8 7 5
8
69 10 30 2 16 8 31 69

//output
#1 1 2 3 4 5 6 7 8 9
#2 2 8 10 16 30 31 69 69

//debug
3	2	4	6	9	1	8	7	5
l								r
p
i
j
3									swap
i
j
2								swap
i
j
4							swap
i
j
j
j
1		6				swap
i
j
j
j
5				9	swap
s
3	2	4	1	5	6	8	7	9
l			r
l			r
p
i
j
j
j
j
1			3						swap
s
1	2	4	3
l
r										skip
l		r
l		r
p
i
j
2
i
j
j
3	4						swap
s
l
r								skip
l
r						skip
1	2	3	4	5	6	8	7	9
l			r
l			r
p
i
j
6
i			swap
j
8			swap
i
j
7		swap
i
j
9	swap
s
6	8	7
l		r
l		r
p
i
j
6				swap
i
j
j
7	8		swap
s
6
i
j				skip
8
i
j		skip
6	7	8
1	2	3	4	5	6	7	8	9	결과
