/**********************************
* 제목 : 시계맞추기
* 페이지 : 168, https://algospot.com/judge/problem/read/CLOCKSYNC#
* 코드 : c
**********************************/

//input
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6

//output
2
9

#include <stdio.h>
#define SWITCHES 10
#define CLOCKS 16
#define INF 9999

typedef enum { FALSE = 0, TRUE = 1}BOOL;

char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."};

int clocks[CLOCKS];


BOOL areAll12(int *(clocks)) {
	BOOL ret = TRUE;

	for (int i = 0; i < CLOCKS; i++) {
		if (clocks[i] != 12) {
			ret = FALSE;
			break;
		}
	}

	return ret;
}

int min(int src, int dst) {
	if (src < dst) return src;
	else return dst;
}

void pushSwitch(int *(clocks), int number) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		if (linked[number][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

int solve(int *(clocks), int number) {
	if (number == SWITCHES) {
		return areAll12(clocks) ? 0 : INF;
	}

	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, number + 1));
		pushSwitch(clocks, number);
	}
	return ret;
}

int main() {

	int test_case;
	int T;
	int result;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++) {
		
		result = 0;
		for (int i = 0; i < CLOCKS; i++) {
			scanf("%d", &clocks[i]);
		}
		result = solve(clocks, 0);
		if (result == INF) result = -1;
		printf("%d\n", result);
	}

	return 0;
}
