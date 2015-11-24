/**********************************
* 제목 : 반복을 이용한 선택 정렬
* 페이지 : 38page
* 코드 : c
**********************************/
#include <stdio.h>
#define MAX 10

void SelectionSort(int *(items), int length);
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

		SelectionSort(items, length);

		for (int j = 0; j < length; j++) {
			printf("%d ", items[j]);
		}
		putchar('\n');
	}

	return 0;
}

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