// baekjoon : https://www.acmicpc.net/problem/10799
// 내용 : 나무도막자르기와 유사한 문제, 다시 풀어볼 문제

//input
()(((()())(())()))(())

//output
17

#include <stdio.h>


char str[100001];
int stack[100001];

int main() {
	scanf("%s", str);
	int top = 0;
	int ans = 0;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '(') {
			stack[top++] = i;
		}
		else {
			if (stack[--top] == i - 1) {	//( == (인지 확인
				ans += top;
			}
			else {
				ans += 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
