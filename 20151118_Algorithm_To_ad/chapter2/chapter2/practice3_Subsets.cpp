/**********************************
* 제목 : 부분집합 합 문제 구하기
아래의 10개의 정수 집합에 대한 모든 부분 집합 중
원소의 합이 0이 되는 부분집합을 모두 출력하시오.
{-1, 3, -9, 6, 7, -6, 1, 5, 4, -2};
* 페이지 : 56 page
* 코드 : c
**********************************/

#include <stdio.h>

#define MAX 10

void Input(int *(arr));
void Subsets(int *(arr), int n);
int main(int argc, char argv[]) {
	int T;

	int arr[MAX] = { 0, };

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {

		Input(arr);
		printf("#%d", test_case);
		Subsets(arr, sizeof(arr) / sizeof(arr[0]));
	}

	return 0;
}

void Input(int *(arr)) {
	int i = 0;

	while (i < MAX) {
		scanf("%d", &arr[i]);
		i++;
	}
}

void Subsets(int *(arr), int n) {
	int i, j;
	int sum;

	for (i = 0; i < (1 << n); i++) {
		sum = 0;
		for (j = 0; j < n; j++) {

			if (i & (1 << j)) {
				//printf("%d ", arr[j]);
				sum += arr[j];
			}
		}
		//printf("\nsum : %d\n", sum);


		if (sum == 0){
			for (j = 0; j < n; j++) {
				if (i & (1 << j)) {
					printf("%d ", arr[j]);
				}
			}
			printf("\n");
		}

	}
}