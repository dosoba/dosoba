/**********************************
* 제목 : 게임판 덮기 https://algospot.com/judge/problem/read/BOARDCOVER
* 페이지 : 159
* 코드 : c - 수정필요
**********************************/

//input
3
3 7
#.....# 
#.....# 
##...## 
3 7
#.....# 
#.....# 
##..### 
8 10
########## 
#........# 
#........# 
#........# 
#........# 
#........# 
#........# 
########## 

//output
0
2
1514

#include <stdio.h>
#define MAXH 20
#define MAXW 20
#define MAX_EMPYT 50

typedef enum { False = 0, True = 1 }BOOL;

int map[MAXH][MAXW];

// **  **  *    *
// *    *  **  **
int coverType[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

int Answer;
int H;
int W;

int cover(int(*map)[MAXW]);
BOOL set(int(*map)[MAXW], int y, int x, int type, int delta);

int main() {
	int test_case;
	int T;

	int countEmpty;
	char temp;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		countEmpty = 0;

		scanf("%d %d", &H, &W);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf(" %c", &temp);
				if (temp == '.') {
					map[i][j] = 0;
					countEmpty++;
				}
				else {
					map[i][j] = 1;
				}
			}
		}
		if ((countEmpty % 3) == 0) {
			Answer = cover(map);
		}
		else {
			Answer = 0;
		}
		printf("%d\n", Answer);
	}
	return 0;
}

BOOL set(int(*map)[MAXW], int y, int x, int type, int delta) {
	BOOL isSet = True;

	//도형의 3점에 대한 검토
	for (int i = 0; i < 3; i++) {
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];

		//경계조건
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
			isSet = False;
		}
		//겹치거나, 검은 칸을 덮는 경우
		else if ((map[ny][nx] += delta) > 1) {
			isSet = False;
		}
	}
	return isSet;
}

int cover(int(*map)[MAXW]) {
	// 0인 지점 찾기
	int y = -1;
	int x = -1;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	//모든 칸이 채워진 경우 - 베이스 기저
	if (y == -1) return 1;

	//4가지 타입에 따라 선택 확인
	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(map, y, x, type, 1)) {
			ret += cover(map);
		}
		set(map, y, x, type, -1);
	}
	return ret;
}