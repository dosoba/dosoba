/**********************************
* 제목 : 선택정렬 - 재귀방법, 반복방법
* 제목 : 버블정렬
* 페이지 : 38page
* 코드 : c
**********************************/
#include <stdio.h>
#define MAX 10

//void SelectionSort(int *(items), int length);
void SelectionSortRecursion(int *(items), int size, int start, int end);

int main(int argc, char argv[]) {
	int T;
	int length;
	int items[MAX];

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &length);

		for (int i = 0; i < length; i++) {
			scanf("%d", &items[i]);
		}

		SelectionSortRecursion(items, length, 0, length);

		for (int j = 0; j < length; j++) {
			printf("%d ", items[j]);
		}
		putchar('\n');
	}

	return 0;
}

// 선택정렬 재귀함수
void SelectionSortRecursion(int *(items), int size, int start, int end) {
	int temp;
	int i;
	int minIndex;

	if (start == end) {
		return;
	}
	else {
		minIndex = start;
		i = start + 1;
		while (i < end) {
			if (items[minIndex] > items[i]) {
				minIndex = i;
			}
			i++;
		}
		temp = items[minIndex];
		items[minIndex] = items[start];
		items[start] = temp;

		SelectionSortRecursion(items, size, start + 1, end);
	}
}

// 선택정렬 반복
void SelectionSortIteration(int *(items), int size) {
	int minIndex;
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1) {
		minIndex = i;
		j = i + 1;
		while (j < size) {
			if (items[minIndex] > items[j]) {
				minIndex = j;
			}
			j++;
		}
		temp = items[minIndex];
		items[minIndex] = items[i];
		items[i] = temp;

		i++;
	}
}

// 버블정렬
void SelectionSort(int *(items), int length) {
	int temp;
	int i;
	int j;

	i = 0;
	while (i < length - 1) {
		j = 0;
		while (j < length - i - 1) {
			if (items[j] > items[j + 1]) {
				temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}



//입력
2
5
3 7 8 2 5
10
10 9 8 7 6 5 4 3 2 1

//출력
2 3 5 7 8
1 2 3 4 5 6 7 8 9 10
