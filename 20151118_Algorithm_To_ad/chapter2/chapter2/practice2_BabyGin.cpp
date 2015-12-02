/**********************************
* 제목 : 완전 검색을 통해서 BabyGin을 판단하시오
* 페이지 :52
* 코드 : c
**********************************/
#include <stdio.h>

#define SIZE 6
int arr[SIZE] = { 0, };
typedef enum BOOL { FALSE = 0, TRUE = 1 };
BOOL result;

void permutation(int n, int r);
void swap(int *first, int *second);
void print_array();
void DivideNumber(int number);
void IsBabyGin();

int main(int argc, char argv[]) {
	int T;
	int number;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		result = FALSE;
		scanf("%d", &number);
		DivideNumber(number);
		permutation(SIZE, SIZE);

		printf("#%d ", test_case);
		if (result == TRUE) {
			printf("BabyGin\n");
		}
		else {
			printf("Not BabyGin\n");
		}
	}

	return 0;
}


void permutation(int n, int r) {
	int i;

	if (r == 0) {
		IsBabyGin();
	}
	else {
		for (i = n - 1; i >= 0; i--) {
			swap(&arr[i], &arr[n - 1]);
			permutation(n - 1, r - 1);
			swap(&arr[i], &arr[n - 1]);
		}
	}

}

void swap(int *first, int *second) {
	int temp;

	printf("swap Before : ");
	print_array();
	temp = *first;
	*first = *second;
	*second = temp;
	printf("swap after  : ");
	print_array();
}

void print_array() {
	int i;

	i = 0;
	printf("result : ");
	while (i < SIZE) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void DivideNumber(int number) {
	int divide = 100000;
	int index = 0;

	while (divide >= 1) {

		arr[index] = number / divide;
		number -= (arr[index] * divide);

		index++;
		divide /= 10;
	}
}

void IsBabyGin() {

	int i = 0;
	int index = 0;
	int count = 0;

	while (i < 2) {
		if (arr[index] == arr[index + 1] && arr[index] == arr[index + 2]) {
			count++;
		}

		else if ((arr[index] + 1) == arr[index + 1] && (arr[index + 1] + 1) == arr[index + 2]) {
			count++;
		}
		index += 3;
		i++;
	}

	if (count == 2) {
		result = TRUE;
	}
}

//입력
3
666777
123456

//출력
#1 BabyGin
#2 Not BabyGin