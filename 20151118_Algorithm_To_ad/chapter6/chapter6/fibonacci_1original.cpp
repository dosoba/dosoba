/**********************************
* 力格 : fibonacci basic code
* 其捞瘤 :
* 内靛 : c
**********************************/

#include <stdio.h>
#define MAX 9

int fibo0(int n);

int main() {
	printf("%d\n", fibo0(8));
	return 0;
}

int fibo0(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return fibo0(n - 1) + fibo0(n - 2);
	}	
}

//output
34