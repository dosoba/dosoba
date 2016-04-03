#include <stdio.h>
#define MAX_TIME 50 + 1
#define MAX_VISITORS 50 + 1

int beacons[3][2];
int N;
//int map[MAX_VISITORS][MAX_TIME];


int main() {
	int test_case;
	int T;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {

		//input here your solution

		//make map 
		int map[MAX_VISITORS][MAX_TIME] = {0, };

		//get N
		scanf("%d", &N);

		//get L1, L2, L3
		for (int i = 0; i < 3; i++) {
			scanf("%d", &beacons[i][0]);
		}
		//get P1, P2, P3
		for (int i = 0; i < 3; i++) {
			scanf("%d", &beacons[i][1]);
		}

		//set data for map
		for (int i = 1; i <= N; i++) {
			int A;
			int D;
			scanf("%d %d", &A, &D);

			for (int j = A; j < A + D; j++) {
				map[i][j] = 1;
			}
		}
		
		printf("#%d", test_case);
	}

	return 0;
}
