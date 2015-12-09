/**********************************
* 제목 : 이진검색(Binary Search)
* 페이지 : 91
* 코드 : c
**********************************/

#include <stdio.h>

#define SIZE 10

int arr[SIZE] = { 0, };
void SetupInput(int *(arr), int size);
int BinarySearch(int *(arr), int low, int high, int key);

int main(int argc, char argv[]) {

	int T;
	int size, searchNumber;
	int result;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {

		scanf("%d %d ", &size, &searchNumber);

		SetupInput(arr, size);

		result = BinarySearch(arr, 0, size - 1, searchNumber);

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}

void SetupInput(int *(arr), int size) {
	int i = 0;
	while (i < size) {
		scanf("%d", &arr[i]);
		i++;
	}
}

int BinarySearch(int *(arr), int low, int high, int key) {
	int mid;

	if (low > high) {
		return -1;
	}
	else {
		mid = (low + high) / 2;
		if (key == arr[mid]) {
			return mid;
		}
		else if (key < arr[mid]) {
			return BinarySearch(arr, low, mid - 1, key);
		}
		else {
			return BinarySearch(arr, mid + 1, high, key);
		}
	}
}


//input
2
9 8
1 2 3 4 5 6 7 8 9
8 70
9 19 29 39 49 59 69 79

//output
#1 7
#2 - 1