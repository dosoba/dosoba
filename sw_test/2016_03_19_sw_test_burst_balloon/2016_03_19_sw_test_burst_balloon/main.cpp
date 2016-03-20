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

		//��� ���
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

	//0. 100�� ���� �����Ѵ�.
	for (time = 0; time <= 100; time++) {
		_max = 0;

		//�浹�� ��� ���� ���� ��� �߰��Ǿ�� ��

		if (time > 0) {
			//1. �̵��Ѵ�, ���� üũ�Ѵ�.
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
	}
}