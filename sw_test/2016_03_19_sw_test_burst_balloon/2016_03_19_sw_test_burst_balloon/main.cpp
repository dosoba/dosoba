#include <stdio.h>

#define MAXN 100	//�ִ� ���� �� 5 <= N <= 100
#define MAXK 2*MAXN	//�ִ� ǳ�� �� 1 <= K <= 2N

// ��,��,��,��
#define U 1
#define D 2
#define L 3
#define R 4

int N;	//����,���� ���� ��
int K;	//ǳ�� ��

//raw datas
int y[MAXK];
int x[MAXK];
int d[MAXK];

//current Y
int cntY[MAXN];

// max
int max;

// counts
int map[MAXN][MAXN];

void getMax();
void print_location(int time);

int main() {
	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		max = 0;

		//map �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
			}
		}

		scanf("%d %d", &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d", &y[i], &x[i], &d[i]);
			map[y[i]][x[i]] += 1;
		}

		getMax();

		//��� ���
		printf("#%d %d\n", test_case, max);
	}
	return 0;
}

void getMax() {
	int _max;
	int i;
	int j;
	int z;
	int k;
	int time;


	//0. 100�� ���� �����Ѵ�.
	for (time = 0; time <= 100; time++) {
		_max = 0;

		//�ߺ�üŷ �ʱ�ȭ
		for (k = 0; k < N; k++) {
			cntY[k] = 0;
		}

		//�浹�� ��� ���� ���� ��� �߰��Ǿ�� ��

		if (time > 0) {
			//1. �̵��Ѵ�, ���� üũ�Ѵ�.
			for (i = 0; i < K; i++) {
				if (d[i] == U) {
					map[y[i]][x[i]] -= 1;
					y[i] -= 1;  
					map[y[i]][x[i]] += 1;
					if (y[i] == 0) {
						d[i] = D;
					}
				}
				else if (d[i] == D) {
					map[y[i]][x[i]] -= 1;
					y[i] += 1;
					map[y[i]][x[i]] += 1;
					if (y[i] == N - 1) {
						d[i] = U;
					};
				}
				else if (d[i] == L) {
					map[y[i]][x[i]] -= 1;
					x[i] -= 1;
					map[y[i]][x[i]] += 1;
					if (x[i] == 0) {
						d[i] = R;
					}
				}
				else if (d[i] == R) {
					map[y[i]][x[i]] -= 1;
					x[i] += 1;
					map[y[i]][x[i]] += 1;
					if (x[i] == N - 1) {
						d[i] = L;
					}
				}
			}

			//2. �ߺ��� üũ�Ѵ�.
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (map[i][j] > 1) {
						for (k = 0; k < K; k++) {
							if (i == y[k] && j == x[k]) {
								if (d[k] == U) d[k] = D;
								else if (d[k] == D) d[k] = U;
								else if (d[k] == L) d[k] = R;
								else if (d[k] == R) d[k] = L;
							}
						}
					}
				}
			}

		}

		//3. y�� ���� ���� ����
		for (z = 0; z < K; z++) {
			cntY[y[z]]++;
		}

		//4. y�� �ִ��ΰ��� ã�´�.
		_max = cntY[0];
		for (k = 1; k < N; k++) {
			if (cntY[k] > _max) {
				_max = cntY[k];
			}
		}

		// �ִ밪
		if (max < _max) {
			max = _max;
		}
		//print_location(time);
	}
}

void print_location(int time) {
	int i;
	for (i = 0; i < K; i++) {
		printf("%d : %d %d %d, ", time, y[i], x[i], d[i]);
	}
	printf("\n");
}