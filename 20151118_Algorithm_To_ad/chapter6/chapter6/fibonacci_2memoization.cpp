/**********************************
* 力格 : fibonacci memoization 内靛
* 其捞瘤 : 248
* 内靛 : c
**********************************/

#include <stdio.h>
#define MAX 9

int memo[MAX];
void initMemo();
int fibo1(int n);

int main() {
	initMemo();
	printf("%d\n", fibo1(8));
	return 0;
}

int fibo1(int n) {
	if (n >= 2 && memo[n] == 0) {
		memo[n] = fibo1(n - 1) + fibo1(n - 2);
	}
	return memo[n];
}

void initMemo() {
	for (int i = 0; i < MAX; i++) {
		if (i == 0 || i == 1) {
			memo[i] = 1;
		}
		else {
			memo[i] = 0;
		}
	}
}

//output
34
