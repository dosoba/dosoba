// baekjoon : https://www.acmicpc.net/problem/1934
// 참고 site : https://github.com/ILyoan/MySnippets/blob/master/problem-solving/acmicpc.net/1934.cpp
// 최소 공배수는 = a * b / GCD(a,b) 결과다

//input
3
1 45000
6 10
13 17

//output
45000
30
221

#include <cstdio>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int TC;
	scanf("%d", &TC);

	for (int tc = 1; tc <= TC; ++tc) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lcm(a, b));
	}

	return 0;
}
