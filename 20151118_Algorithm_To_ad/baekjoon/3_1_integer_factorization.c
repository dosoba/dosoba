// baekjoon : https://www.acmicpc.net/problem/11653
// 참고 site : https://github.com/ILyoan/MySnippets/blob/master/problem-solving/acmicpc.net/11653.cpp
//			 : https://ko.wikipedia.org/wiki/%EC%86%8C%EC%9D%B8%EC%88%98%EB%B6%84%ED%95%B4
//input
72

//output
2
2
2
3
3

#include <stdio.h>

// prime_factor[i] is a smallest prime number that divides i.
int prime_factor[10000001];

int main() {
	int n;
	scanf("%d", &n);

	prime_factor[0] = 0;
	prime_factor[1] = 0;

	for (int i = 2; i <= n; ++i) {
		prime_factor[i] = i;
	}

	for (int i = 2; i * i <= n; ++i) {
		if (prime_factor[i] == i) {
			prime_factor[i] = i;
			for (int j = i * i; j <= n; j += i) {
				if (prime_factor[j] == j) {
					prime_factor[j] = i;
				}
			}
		}
	}

	while (n > 1) {
		printf("%d\n", prime_factor[n]);
		n = n / prime_factor[n];
	}

	return 0;
}
