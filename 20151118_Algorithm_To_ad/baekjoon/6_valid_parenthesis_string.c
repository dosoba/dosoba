// baekjoon : https://www.acmicpc.net/problem/9012
// 내용 : valid parenthesis string

//input
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(

//output
NO
NO
YES
NO
YES
NO

#include <stdio.h>
typedef enum { FALSE = 0, TRUE = 1 }BOOL;

char input[51];


BOOL isRight() {
	BOOL re;
	int opened = 0;
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] == '(') {
			opened += 1;
		}
		else {
			opened -= 1;
		}
		if (opened < 0) {
			return FALSE;
		}
	}

	if (opened == 0) re = TRUE;
	else re = FALSE;

	return re;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%s", input);
		printf("%s\n", isRight() ? "YES" : "NO");
	}

	return 0;
}
