/**********************************
* ���� : ����Ʈ ������ ����Ʈ ĥ�ϱ� (�����, �Ķ��� ĥ)
f(1) = 2, f(2) = 3, f(8)=?
* ������ : 247
* �ڵ� : c
**********************************/

#include <stdio.h>
int fibonacci(int n);

int main() {

	printf("f(8) : %d\n", fibonacci(8));
	return 0;
}

int fibonacci(int n) {
	if (n == 1) {
		return 2;
	}
	else if (n == 2) {
		return 3;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

//input

//output
f(8) : 55