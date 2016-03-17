/**********************************
* 제목 : 중첩 반복문 대체하기
		 0부터 차례대로 번호 매겨진 n개의 원소 중 4개를 고르는 경우를 출력하는 코드를 작성
* 페이지 : 148 ~ 149
* 코드 : c
**********************************/
//input
7 4

//output
0 1 2 3
0 1 2 4
0 1 2 5
0 1 2 6
0 1 3 4
0 1 3 5
0 1 3 6
0 1 4 5
0 1 4 6
0 1 5 6
0 2 3 4
0 2 3 5
0 2 3 6
0 2 4 5
0 2 4 6
0 2 5 6
0 3 4 5
0 3 4 6
0 3 5 6
0 4 5 6
1 2 3 4
1 2 3 5
1 2 3 6
1 2 4 5
1 2 4 6
1 2 5 6
1 3 4 5
1 3 4 6
1 3 5 6
1 4 5 6
2 3 4 5
2 3 4 6
2 3 5 6
2 4 5 6
3 4 5 6

#include <stdio.h>
#define MAX 4

void combination(int n, int r);
void combination1(int *picked, int size, int n, int toPick);
void combination2(int *picked, int size, int n, int toPick, int index);
void print_arr(int *arr, int size);


int main() {
	int n;
	int r;

	int picked[MAX];

	scanf("%d %d", &n, &r);
	combination(n, r);
	combination1(picked, 0, n, r);
	combination2(picked, 0, n, r, 0);
	
	return 0;
}


//n개 중에서 4개를 고르는 경우의 수
//4개 이상이면 for문이 한개씩 추가되어야 한다.
void combination(int n, int r) {
	int i;
	int j;
	int x;
	int y;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (x = j + 1; x < n; x++) {
				for (y = x + 1; y < n; y++) {
					printf("%d %d %d %d\n", i, j, x, y);
				}
			}
		}
	}
}

//for문 한개를 함수로 뽑아낸것과 동일하다
//4개 이상이서도 코드를 수정할 필요가 없다.
void combination1(int *picked, int size, int n, int toPick) {
	if (toPick == 0) {
		print_arr(picked, size);
		return;
	}

	int smallest = size == 0 ? 0 : picked[size - 1] + 1;

	for (int next = smallest; next < n; next++) {
		picked[size] = next;
		combination1(picked, size + 1, n, toPick - 1);
	}
}


//일반적인 조합 함수
void combination2(int *picked, int size, int n, int toPick, int index) {
	if (toPick == 0) {
		print_arr(picked, size);
	}
	else if (index == n) {
		return;
	}
	else {
		picked[size] = index;
		combination2(picked, size + 1, n, toPick - 1, index + 1);
		combination2(picked, size, n, toPick, index + 1);
	}
}

//출력함수
void print_arr(int *arr, int size) {
	int i = 0;

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}