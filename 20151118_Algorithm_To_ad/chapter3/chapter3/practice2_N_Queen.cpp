/**********************************
* 제목 : 연습문제 2.2. N queen 문제
* 페이지 : 93
* 코드 : c
**********************************/

#include <stdio.h>

#define MAX 13

typedef enum BOOL { FALSE = 0, TRUE = 1 };

int include[MAX][2] = { { 0, 0 }, };
int idx;

BOOL CheckRule(int y, int x);
void GetNQueen(int n, int y, int x);
void Print_arr(int n);
void Print_graphic(int n);


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

			if ((y - include[i][0]) / (x - include[i][1]) == 1 && (y - include[i][0]) % (x - include[i][1]) == 0 || (y - include[i][0]) / (x - include[i][1]) == -1 && (y - include[i][0]) % (x - include[i][1]) == 0) {
				return FALSE;
			}
			i++;
		}
	}

	return result;
}

void GetNQueen(int n, int y, int x) {
	if (idx == n) {
		Print_arr(n);
		//Print_graphic(n);
	}

	for (int j = 1; j <= n; j++) {
		if (CheckRule(y, j) == TRUE) {
			include[idx + 1][0] = y;
			include[idx + 1][1] = j;
			idx++;
			GetNQueen(n, y + 1, j);
		}
		if (j == n) {
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

void Print_graphic(int n) {

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {
			if (include[i][1] == j) {
				//putchar('O');
				printf("O\t");
			}
			else {
				//putchar('X');
				printf("X\t");
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

//input
4
1
2
4
8

//output
#1
(1 1)
#2
#3
(1 2) (2 4) (3 1) (4 3)
(1 3) (2 1) (3 4) (4 2)
#4
(1 1) (2 5) (3 8) (4 6) (5 3) (6 7) (7 2) (8 4)
(1 1) (2 6) (3 8) (4 3) (5 7) (6 4) (7 2) (8 5)
(1 1) (2 7) (3 4) (4 6) (5 8) (6 2) (7 5) (8 3)
(1 1) (2 7) (3 5) (4 8) (5 2) (6 4) (7 6) (8 3)
(1 2) (2 4) (3 6) (4 8) (5 3) (6 1) (7 7) (8 5)
(1 2) (2 5) (3 7) (4 1) (5 3) (6 8) (7 6) (8 4)
(1 2) (2 5) (3 7) (4 4) (5 1) (6 8) (7 6) (8 3)
(1 2) (2 6) (3 1) (4 7) (5 4) (6 8) (7 3) (8 5)
(1 2) (2 6) (3 8) (4 3) (5 1) (6 4) (7 7) (8 5)
(1 2) (2 7) (3 3) (4 6) (5 8) (6 5) (7 1) (8 4)
(1 2) (2 7) (3 5) (4 8) (5 1) (6 4) (7 6) (8 3)
(1 2) (2 8) (3 6) (4 1) (5 3) (6 5) (7 7) (8 4)
(1 3) (2 1) (3 7) (4 5) (5 8) (6 2) (7 4) (8 6)
(1 3) (2 5) (3 2) (4 8) (5 1) (6 7) (7 4) (8 6)
(1 3) (2 5) (3 2) (4 8) (5 6) (6 4) (7 7) (8 1)
(1 3) (2 5) (3 7) (4 1) (5 4) (6 2) (7 8) (8 6)
(1 3) (2 5) (3 8) (4 4) (5 1) (6 7) (7 2) (8 6)
(1 3) (2 6) (3 2) (4 5) (5 8) (6 1) (7 7) (8 4)
(1 3) (2 6) (3 2) (4 7) (5 1) (6 4) (7 8) (8 5)
(1 3) (2 6) (3 2) (4 7) (5 5) (6 1) (7 8) (8 4)
(1 3) (2 6) (3 4) (4 1) (5 8) (6 5) (7 7) (8 2)
(1 3) (2 6) (3 4) (4 2) (5 8) (6 5) (7 7) (8 1)
(1 3) (2 6) (3 8) (4 1) (5 4) (6 7) (7 5) (8 2)
(1 3) (2 6) (3 8) (4 1) (5 5) (6 7) (7 2) (8 4)
(1 3) (2 6) (3 8) (4 2) (5 4) (6 1) (7 7) (8 5)
(1 3) (2 7) (3 2) (4 8) (5 5) (6 1) (7 4) (8 6)
(1 3) (2 7) (3 2) (4 8) (5 6) (6 4) (7 1) (8 5)
(1 3) (2 8) (3 4) (4 7) (5 1) (6 6) (7 2) (8 5)
(1 4) (2 1) (3 5) (4 8) (5 2) (6 7) (7 3) (8 6)
(1 4) (2 1) (3 5) (4 8) (5 6) (6 3) (7 7) (8 2)
(1 4) (2 2) (3 5) (4 8) (5 6) (6 1) (7 3) (8 7)
(1 4) (2 2) (3 7) (4 3) (5 6) (6 8) (7 1) (8 5)
(1 4) (2 2) (3 7) (4 3) (5 6) (6 8) (7 5) (8 1)
(1 4) (2 2) (3 7) (4 5) (5 1) (6 8) (7 6) (8 3)
(1 4) (2 2) (3 8) (4 5) (5 7) (6 1) (7 3) (8 6)
(1 4) (2 2) (3 8) (4 6) (5 1) (6 3) (7 5) (8 7)
(1 4) (2 6) (3 1) (4 5) (5 2) (6 8) (7 3) (8 7)
(1 4) (2 6) (3 8) (4 2) (5 7) (6 1) (7 3) (8 5)
(1 4) (2 6) (3 8) (4 3) (5 1) (6 7) (7 5) (8 2)
(1 4) (2 7) (3 1) (4 8) (5 5) (6 2) (7 6) (8 3)
(1 4) (2 7) (3 3) (4 8) (5 2) (6 5) (7 1) (8 6)
(1 4) (2 7) (3 5) (4 2) (5 6) (6 1) (7 3) (8 8)
(1 4) (2 7) (3 5) (4 3) (5 1) (6 6) (7 8) (8 2)
(1 4) (2 8) (3 1) (4 3) (5 6) (6 2) (7 7) (8 5)
(1 4) (2 8) (3 1) (4 5) (5 7) (6 2) (7 6) (8 3)
(1 4) (2 8) (3 5) (4 3) (5 1) (6 7) (7 2) (8 6)
(1 5) (2 1) (3 4) (4 6) (5 8) (6 2) (7 7) (8 3)
(1 5) (2 1) (3 8) (4 4) (5 2) (6 7) (7 3) (8 6)
(1 5) (2 1) (3 8) (4 6) (5 3) (6 7) (7 2) (8 4)
(1 5) (2 2) (3 4) (4 6) (5 8) (6 3) (7 1) (8 7)
(1 5) (2 2) (3 4) (4 7) (5 3) (6 8) (7 6) (8 1)
(1 5) (2 2) (3 6) (4 1) (5 7) (6 4) (7 8) (8 3)
(1 5) (2 2) (3 8) (4 1) (5 4) (6 7) (7 3) (8 6)
(1 5) (2 3) (3 1) (4 6) (5 8) (6 2) (7 4) (8 7)
(1 5) (2 3) (3 1) (4 7) (5 2) (6 8) (7 6) (8 4)
(1 5) (2 3) (3 8) (4 4) (5 7) (6 1) (7 6) (8 2)
(1 5) (2 7) (3 1) (4 3) (5 8) (6 6) (7 4) (8 2)
(1 5) (2 7) (3 1) (4 4) (5 2) (6 8) (7 6) (8 3)
(1 5) (2 7) (3 2) (4 4) (5 8) (6 1) (7 3) (8 6)
(1 5) (2 7) (3 2) (4 6) (5 3) (6 1) (7 4) (8 8)
(1 5) (2 7) (3 2) (4 6) (5 3) (6 1) (7 8) (8 4)
(1 5) (2 7) (3 4) (4 1) (5 3) (6 8) (7 6) (8 2)
(1 5) (2 8) (3 4) (4 1) (5 3) (6 6) (7 2) (8 7)
(1 5) (2 8) (3 4) (4 1) (5 7) (6 2) (7 6) (8 3)
(1 6) (2 1) (3 5) (4 2) (5 8) (6 3) (7 7) (8 4)
(1 6) (2 2) (3 7) (4 1) (5 3) (6 5) (7 8) (8 4)
(1 6) (2 2) (3 7) (4 1) (5 4) (6 8) (7 5) (8 3)
(1 6) (2 3) (3 1) (4 7) (5 5) (6 8) (7 2) (8 4)
(1 6) (2 3) (3 1) (4 8) (5 4) (6 2) (7 7) (8 5)
(1 6) (2 3) (3 1) (4 8) (5 5) (6 2) (7 4) (8 7)
(1 6) (2 3) (3 5) (4 7) (5 1) (6 4) (7 2) (8 8)
(1 6) (2 3) (3 5) (4 8) (5 1) (6 4) (7 2) (8 7)
(1 6) (2 3) (3 7) (4 2) (5 4) (6 8) (7 1) (8 5)
(1 6) (2 3) (3 7) (4 2) (5 8) (6 5) (7 1) (8 4)
(1 6) (2 3) (3 7) (4 4) (5 1) (6 8) (7 2) (8 5)
(1 6) (2 4) (3 1) (4 5) (5 8) (6 2) (7 7) (8 3)
(1 6) (2 4) (3 2) (4 8) (5 5) (6 7) (7 1) (8 3)
(1 6) (2 4) (3 7) (4 1) (5 3) (6 5) (7 2) (8 8)
(1 6) (2 4) (3 7) (4 1) (5 8) (6 2) (7 5) (8 3)
(1 6) (2 8) (3 2) (4 4) (5 1) (6 7) (7 5) (8 3)
(1 7) (2 1) (3 3) (4 8) (5 6) (6 4) (7 2) (8 5)
(1 7) (2 2) (3 4) (4 1) (5 8) (6 5) (7 3) (8 6)
(1 7) (2 2) (3 6) (4 3) (5 1) (6 4) (7 8) (8 5)
(1 7) (2 3) (3 1) (4 6) (5 8) (6 5) (7 2) (8 4)
(1 7) (2 3) (3 8) (4 2) (5 5) (6 1) (7 6) (8 4)
(1 7) (2 4) (3 2) (4 5) (5 8) (6 1) (7 3) (8 6)
(1 7) (2 4) (3 2) (4 8) (5 6) (6 1) (7 3) (8 5)
(1 7) (2 5) (3 3) (4 1) (5 6) (6 8) (7 2) (8 4)
(1 8) (2 2) (3 4) (4 1) (5 7) (6 5) (7 3) (8 6)
(1 8) (2 2) (3 5) (4 3) (5 1) (6 7) (7 4) (8 6)
(1 8) (2 3) (3 1) (4 6) (5 2) (6 5) (7 7) (8 4)
(1 8) (2 4) (3 1) (4 3) (5 6) (6 2) (7 7) (8 5)
