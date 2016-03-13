/**********************************
* ���� : N���� ������ ����ġ�� �־����� �Ŵ� M�� ���� �̵� ����� ����ϴ� ���α׷�
30�� �ݺ��� 12�� �ݺ��� ���̸� ��Ÿ���� ���ش�
* ������ : 95
* �ڵ� : c
**********************************/

#include <stdio.h>
#define MAXN 15

int weights[MAXN];
double avg[MAXN];

void movingAverage1(int N, int M);
void movingAverage2(int N, int M);

int main() {

	int N;
	int M;

	//intput weights
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &weights[i]);
	}
	//movingAverage1(N, M);
	movingAverage2(N, M);

	return 0;
}

// N*M - M^2 + M �� �ݺ� : 12 3 �ϰ�� �� 30�� �ݺ�
void movingAverage1(int N, int M) {
	int i;
	int j;
	double partialSum;

	for (i = M - 1; i < N; i++) {
		partialSum = 0;

		for (j = 0; j < M; j++) {
			partialSum += weights[i - j];
		}
		avg[i] = partialSum / M;
	}
}

// M - 1 + (N - M + 1) �� �ݺ� �� N�� �ݺ� : 12 3 �� ��� �� 12�� �ݺ�
void movingAverage2(int N, int M) {
	int i;
	double partialSum = 0;

	for (i = 0; i < M - 1; i++) {
		partialSum += weights[i];
	}

	for (i = M - 1; i < N; i++) {
		partialSum += weights[i];
		avg[i] = partialSum / M;
		partialSum -= weights[i - M + 1];
	}
}