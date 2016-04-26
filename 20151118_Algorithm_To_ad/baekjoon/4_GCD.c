// baekjoon : https://www.acmicpc.net/problem/9613
// 참고 site : https://ko.wikipedia.org/wiki/%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98
//유클리트 호제법으로 해결, 재귀를 통해서

//input
3
4 10 20 30 40
3 7 5 12
3 125 15 25

//output
70
3
35

#include <stdio.h>
#define MAX 100

int datas[MAX];
int sumOfGCD;


int runGCD(int i, int j);
void getGCD(int n);

int main() {
	int t;
	int n;
	
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		sumOfGCD = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &datas[i]);
		}
		getGCD(n);
		printf("%d\n", sumOfGCD);
	}
	return 0;
}

void getGCD(int n) {
	int i;
	int j;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (i != j) {
				//getGCD
				if (datas[i] > datas[j])
					sumOfGCD += runGCD(datas[i], datas[j]);
				else
					sumOfGCD += runGCD(datas[j], datas[i]);
			}
		}
	}
}

int runGCD(int i, int j) {
	if (j == 0) return i;
	return runGCD(j, i%j);
}
