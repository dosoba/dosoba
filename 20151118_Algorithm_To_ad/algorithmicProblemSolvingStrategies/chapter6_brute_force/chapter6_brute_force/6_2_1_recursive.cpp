/**********************************
* ���� : 1���� n������ ���� ����ϴ� �ݺ� �Լ��� ��� �Լ�
* ������ : �˰��� ���� �ذ� ���� 147
* �ڵ� : c
**********************************/
//input
10

//output
n������ �� : 55

#include <stdio.h>
int sum(int n);
int recursiveSum(int n);

int main() {
	int n;
	scanf("%d", &n);

	printf("n������ �� : %d \n", sum(n));
	printf("n������ �� : %d \n", recursiveSum(n));

	return 0;
}

//�ݺ��Լ�
int sum(int n) {
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++) {
		sum += i;
	}

	return sum;
}

//����Լ�
int recursiveSum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + recursiveSum(n - 1);
	}
}