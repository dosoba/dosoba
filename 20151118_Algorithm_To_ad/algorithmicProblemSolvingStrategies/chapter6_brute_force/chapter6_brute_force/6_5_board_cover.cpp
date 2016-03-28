/**********************************
* ���� : ������ ���� https://algospot.com/judge/problem/read/BOARDCOVER
* ������ : 159
* �ڵ� : c - �����ʿ�
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

	//������ 3���� ���� ����
	for (int i = 0; i < 3; i++) {
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];

		//�������
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
			isSet = False;
		}
		//��ġ�ų�, ���� ĭ�� ���� ���
		else if ((map[ny][nx] += delta) > 1) {
			isSet = False;
		}
	}
	return isSet;
}

int cover(int(*map)[MAXW]) {
	// 0�� ���� ã��
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

	//��� ĭ�� ä���� ��� - ���̽� ����
	if (y == -1) return 1;

	//4���� Ÿ�Կ� ���� ���� Ȯ��
	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(map, y, x, type, 1)) {
			ret += cover(map);
		}
		set(map, y, x, type, -1);
	}
	return ret;
}