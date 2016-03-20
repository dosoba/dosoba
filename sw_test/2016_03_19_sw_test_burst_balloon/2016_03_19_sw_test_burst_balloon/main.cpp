#include <stdio.h>

#define MAXN 100	//최대 라인 수 5 <= N <= 100
#define MAXK 2*MAXN	//최대 풍선 수 1 <= K <= 2N

// 상,하,좌,우
#define U 1
#define D 2
#define L 3
#define R 4

int N;	//가로,세로 라인 수
int K;	//풍선 수

//raw datas
int y[MAXK];
int x[MAXK];
int d[MAXK];

//current Y
int cntY[MAXN];

// max
int max;

void getMax();

int main() {
	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		max = 0;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d", y[i], x[i], d[i]);
		}

		getMax();

		//결과 출력
		printf("#d %d\n", test_case, max);
	}
	return 0;
}

void getMax() {
	int _max;
	int maxPerTime;
	int i;
	int j;
	int z;
	int k;
	int time;

	//0. 100초 동안 지속한다.
	for (time = 0; time <= 100; time++) {
		_max = 0;

		//충돌한 경우 방향 변경 고려 추가되어야 함

		if (time > 0) {
			//1. 이동한다, 방향 체크한다.
			for (i = 0; i < K; i++) {
				if (d[i] == U) {
					if (y[i] == 0) {
						d[i] = D;
						y[i] += 1;
					}
					else y[i] -= 1;
				}
				if (d[i] == D) {
					if (y[i] == N - 1) {
						d[i] = U;
						y[i] -= 1;
					}
					y[i] += 1;
				}
				if (d[i] == L) {
					if (x[i] == 0) {
						d[i] = R;
						x[i] += 1;
					}
					x[i] -= 1;
				}
				if (d[i] == R) {
					if (x[i] == N - 1) {
						d[i] = L;
						x[i] -= 1;
					}
					x[i] += 1;
				}
			}
		}

		//3. y가 같은 것을 센다
		for (z = 0; z < K; z++) {
			cntY[y[z]]++;
		}

		//4. y가 최대인것을 찾는다.
		_max = cntY[0];
		for (k = 1; k < N; k++) {
			if (cntY[k] > _max) {
				_max = cntY[k];
			}
		}

		// 최대값
		if (max < _max) {
			max = _max;
		}
	}
}