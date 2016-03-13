/**********************************
* 제목 : N개의 몸무게 측정치가 주어질때 매달 M달 간의 이동 평균을 계산하는 프로그램
30번 반복과 12번 반복의 차이를 나타나게 해준다
* 페이지 : 95
* 코드 : c
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

// N*M - M^2 + M 번 반복 : 12 3 일경우 총 30번 반복
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

// M - 1 + (N - M + 1) 번 반복 즉 N번 반복 : 12 3 일 경우 총 12번 반복
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