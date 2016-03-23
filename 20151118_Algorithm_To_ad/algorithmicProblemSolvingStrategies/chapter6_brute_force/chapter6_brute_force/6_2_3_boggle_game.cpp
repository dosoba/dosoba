/**********************************
* 제목 : 보글게임 https://algospot.com/judge/problem/read/BOGGLE#
* 페이지 : 150
* 코드 : c
**********************************/

//input
1			//test case 수
U R L P M	//5 * 5
X P R E T
G I A E T
X T N Z Y
X O Q R S
3			//찾을 문자열의 수
PRETTY		//1번째 문자열
GIRL		//2번째 문자열
REPEAT		//3번째 문자열

//output
PRETTY YES	//1번째 결과
GIRL YES	//2번째 결과
REPEAT YES	//3번째 결과

#include <stdio.h>
#define MAX_LINE 5
#define MAXN 10
#define MAX_STRING 10 + 1
#define MAX_DIR 8

typedef enum { FALSE = 0, TRUE = 1 }BOOL;

int dx[8] = { -1, -1, -1,  1,  1,  1,  0,  0 };
int dy[8] = { -1,  0,  1, -1,  0,  1, -1,  1 };

char map[MAXN][MAXN];
char words[MAXN][MAX_STRING];
BOOL hasWord(int y, int x, char *string, int index);

int main() {

	int test_case;
	int T;
	int N;
	BOOL result = FALSE;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {

		//get information
		for (int i = 0; i < MAX_LINE; i++) {
			for (int j = 0; j < MAX_LINE; j++) {
				scanf(" %c", &map[i][j]);
			}
		}

		//get strings
		scanf(" %d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", &words[i]);
		}

		//diff string
		for (int k = 0; k < N; k++) {
			printf("%s ", words[k]);
			result = FALSE;
			for (int i = 0; i < MAX_LINE; i++) {
				for (int j = 0; j < MAX_LINE; j++) {
					result = hasWord(i, j, words[k], 0) ;
					if (result) {
						break;
					}
				}
				if (result) {
					break;
				}
			}
			if (result) printf("YES\n");
			else printf("NO\n");
			
		}
		
	}


	return 0;
}

BOOL hasWord(int y, int x, char *string, int index) {
	//1. 범위 벗어나면 거짓 거짓 리턴
	if (y < 0 || y > MAX_LINE - 1 || x < 0 || x > MAX_LINE - 1) 
		return FALSE;

	//2. 해당 글자와 같지 않으면 거짓 리턴
	if (map[y][x] != string[index]) 
		return FALSE;

	//3. 다음 글자가 널이면 참 리턴
	if (string[index + 1] == '\0') 
		return TRUE;

	//4. 다음 글자를 위해서 8방향 탐색 시작
	for (int i = 0; i < MAX_DIR; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if ((hasWord(nextY, nextX, string, index + 1))) {
			return TRUE;
		}
	}
	return FALSE;
}