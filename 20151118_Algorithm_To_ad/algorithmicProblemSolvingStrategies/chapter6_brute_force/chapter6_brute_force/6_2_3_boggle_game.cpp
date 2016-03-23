/**********************************
* ���� : ���۰��� https://algospot.com/judge/problem/read/BOGGLE#
* ������ : 150
* �ڵ� : c
**********************************/

//input
1			//test case ��
U R L P M	//5 * 5
X P R E T
G I A E T
X T N Z Y
X O Q R S
3			//ã�� ���ڿ��� ��
PRETTY		//1��° ���ڿ�
GIRL		//2��° ���ڿ�
REPEAT		//3��° ���ڿ�

//output
PRETTY YES	//1��° ���
GIRL YES	//2��° ���
REPEAT YES	//3��° ���

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
	//1. ���� ����� ���� ���� ����
	if (y < 0 || y > MAX_LINE - 1 || x < 0 || x > MAX_LINE - 1) 
		return FALSE;

	//2. �ش� ���ڿ� ���� ������ ���� ����
	if (map[y][x] != string[index]) 
		return FALSE;

	//3. ���� ���ڰ� ���̸� �� ����
	if (string[index + 1] == '\0') 
		return TRUE;

	//4. ���� ���ڸ� ���ؼ� 8���� Ž�� ����
	for (int i = 0; i < MAX_DIR; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if ((hasWord(nextY, nextX, string, index + 1))) {
			return TRUE;
		}
	}
	return FALSE;
}