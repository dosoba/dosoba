
/**********************************
* 제목 : 연습문제 2.2. N queen 문제
* 페이지 : 93
* 코드 : c
**********************************/
/*
#include <stdio.h>

#define MAX 5

typedef enum BOOL { FALSE = 0, TRUE = 1 };

int include[MAX][2] = { { 0, 0 }, };
int idx;

BOOL CheckRule(int y, int x);
void GetNQueen(int n, int y, int x);
void Print_arr(int n);


int main(int argc, char argv[]) {

	int T;
	int N;
	scanf("%d ", &T);

	for (int test_case = 1; test_case <= T; test_case++) {

		scanf("%d ", &N);

		idx = 0;
		printf("#%d\n", test_case);
		GetNQueen(N, 1, 1);
	}

	return 0;
}

BOOL CheckRule(int y, int x) {
	BOOL result = TRUE;
	int i;

	if (y == 1 && x == 1) {
		return TRUE;
	}
	else {
		i = 1;
		while (i <= idx) {
			if (include[i][1] == x) {
				return FALSE;
			}

			if ((y - include[i][0]) / (x - include[i][1]) == 1 || (y - include[i][0]) / (x - include[i][1]) == -1) {
				return FALSE;
			}
			i++;
		}
	}

	return result;
}

void GetNQueen(int n, int y, int x) {

	if (y == 1 && x == 1) {
		include[idx + 1][0] = y;
		include[idx + 1][1] = x;
		idx++;
		GetNQueen(n, y + 1, x);
	}

	if (idx == n) {
		Print_arr(n);
	}

	for (int j = 1; j <= n; j++) {
		if (CheckRule(y, j) == TRUE) {
			include[idx + 1][0] = y;
			include[idx + 1][1] = j;
			idx++;
			GetNQueen(n, y + 1, j);
		}
		if (j == 4) {
			idx--;
		}
	}

}

void Print_arr(int n) {
	int i = 1;

	while (i <= n) {
		printf("(%d %d) ", include[i][0], include[i][1]);
		i++;
	}
	putchar('\n');
}

//input
1
4

//output
#1
(1 2) (2 4) (3 1) (4 3)
(1 3) (2 1) (3 4) (4 2)
*/