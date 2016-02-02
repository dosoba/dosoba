/**********************************
* 제목 : 막대 만들기 (1cm 파랑, 노랑, 2cm 빨간 막대를 연결해서 막대를 만들어라
* 페이지 : 254
* 코드 : c
**********************************/
#include <stdio.h>

#define MAX 10
int sticks[MAX];

int CountsHowToMakeStick(int n);
int main() {
	int T;
	int N;
	scanf("%d ", &T);

	for (int i = 2; i <= T; i++) {
		scanf("%d ", &N);
		printf("%d \n", CountsHowToMakeStick(N));
	}
	return 0;
}

int CountsHowToMakeStick(int n) {

	sticks[1] = 2;
	for (int i = 2; i <= n; i++) {
		sticks[i] = 2 * sticks[i - 1] + ((i - 1) % 2);
	}

	return sticks[n];
}

//input
5	// tc수
2	// n값
3
4
5
6
//output
5
10
21
42
85
