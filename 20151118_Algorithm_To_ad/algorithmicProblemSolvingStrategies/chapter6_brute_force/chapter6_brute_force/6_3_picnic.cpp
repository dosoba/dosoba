/**********************************
* 力格 : 家浅 https://algospot.com/judge/problem/read/PICNIC
* 其捞瘤 : 155
* 内靛 : c
**********************************/
//input
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

//output
1
3
4

#include <stdio.h>
#define MAXN 10
#define MAXM 45

typedef enum {false = 0, true = 1}bool;
bool areFriends[MAXN][MAXN];
int n;
int m;

int countPairing(bool taken[MAXN]);
int countPairing2(bool taken[MAXN]);

int main() {

	int test_case;
	int T;
	int i;
	int pair1;
	int pair2;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf(" %d %d", &n, &m);
		bool taken[MAXN] = { 0, };
		for (i = 0; i < m; i++) {
			scanf(" %d %d", &pair1, &pair2);
			areFriends[pair1][pair2] = true;
			areFriends[pair2][pair1] = true;
		}
		//printf("%d\n", countPairing(taken));
		printf("%d\n", countPairing2(taken));

		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				areFriends[i][j] = false;
			}
		}
	}

	return 0;
}


int countPairing(bool taken[MAXN]) {
	bool finished = true;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) finished = false;
	}
	if (finished) return 1;
	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairing(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}

int countPairing2(bool taken[MAXN]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairing2(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}