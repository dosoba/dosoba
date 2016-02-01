/**********************************
* 力格 : fibonacci DP 内靛
* 其捞瘤 : 253
* 内靛 : c
**********************************/
#include <stdio.h>
#define MAX 9

int Fibonacci_DP(int n);

int f[MAX];

int main() {
	printf("%d \n", Fibonacci_DP(8));
	return 0;
}

int Fibonacci_DP(int n) {

	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}