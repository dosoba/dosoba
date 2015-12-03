/**********************************
* ���� : �κ����� �� ���� ���ϱ�
�Ʒ��� 10���� ���� ���տ� ���� ��� �κ� ���� ��
������ ���� 0�� �Ǵ� �κ������� ��� ����Ͻÿ�.
{-1, 3, -9, 6, 7, -6, 1, 5, 4, -2};
* ������ : 56 page
* �ڵ� : c
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

//�Է�
1
- 1 3 - 9 6 7 - 6 1 5 4 - 2

//���
#1
3 - 9 6
- 1 3 - 9 7
6 - 6
- 1 7 - 6
- 1 3 - 9 6 7 - 6
- 1 1
- 1 3 - 9 6 1
- 1 6 - 6 1
3 - 9 7 - 6 5
3 - 9 1 5
- 6 1 5
3 - 9 6 - 6 1 5
- 1 3 - 9 7 - 6 1 5
- 1 - 9 6 4
- 1 3 - 6 4
3 - 9 7 - 6 1 4
- 9 5 4
- 9 6 - 6 5 4
- 1 - 9 7 - 6 5 4
- 1 - 9 1 5 4
- 1 - 9 6 - 6 1 5 4
- 1 3 - 2
- 1 3 6 - 6 - 2
3 - 9 7 1 - 2
7 - 6 1 - 2
3 - 9 6 7 - 6 1 - 2
- 9 6 5 - 2
- 1 - 9 7 5 - 2
3 - 6 5 - 2
- 1 - 9 6 7 - 6 5 - 2
- 1 - 9 6 1 5 - 2
- 1 3 - 6 1 5 - 2
- 9 7 4 - 2
- 9 6 7 - 6 4 - 2
- 9 6 1 4 - 2
- 1 - 9 7 1 4 - 2
3 - 6 1 4 - 2
- 1 - 9 6 7 - 6 1 4 - 2
- 1 3 - 9 5 4 - 2
- 1 - 6 5 4 - 2
- 1 3 - 9 6 - 6 5 4 - 2
- 9 7 - 6 1 5 4 - 2
