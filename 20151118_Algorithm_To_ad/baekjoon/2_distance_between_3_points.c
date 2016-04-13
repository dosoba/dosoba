// baekjoon : https://www.acmicpc.net/problem/1002
// 참고 site : https://github.com/ILyoan/MySnippets/blob/master/problem-solving/acmicpc.net/1002.cpp


//input
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

//output
2
1
0

#include <stdio.h>

int main() {
	int N;
	int count;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		int x1, y1, r1;
		int x2, y2, r2;

		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		int d_square = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int r1_plus_r2_square = (r1 * r1 + r2 * r2 + 2 * r1 * r2);
		int r1_minus_r2_square = (r1 * r1 + r2 * r2 - 2 * r1 * r2);

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) printf("-1\n");	//무한대
			else printf("0\n");				//불가능
		}
		else {
			if (r1_plus_r2_square == d_square || r1_minus_r2_square == d_square) {	//한점
				printf("1\n");
			}
			else if (r1_minus_r2_square > d_square || r1_plus_r2_square < d_square) {	// 불가능
				printf("0\n");
			}
			else {	//나머지 경우, 두 개의 교점이 있음
				printf("2\n");
			}
		}
	}
	return 0;
}
