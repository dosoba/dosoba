/**********************************
* ���� : ���� ����� (1cm �Ķ�, ���, 2cm ���� ���븦 �����ؼ� ���븦 ������
* ������ : 254
* �ڵ� : c
**********************************/


#include <stdio.h>

#define MAX 10
int sticks[MAX];

int CountsHowToMakeStick(int n);
int main() {
	int T;
	int N;
	scanf("%d ", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d ", &N);
		printf("%d \n", CountsHowToMakeStick(N));
	}
	return 0;
}

int CountsHowToMakeStick(int n) {

	sticks[1] = 2;
	sticks[2] = 5;
	for (int i = 3; i <= n; i++) {
		sticks[i] = 2 * sticks[i - 1] + sticks[i - 2];
	}

	return sticks[n];
}

//input
5	// tc��
2	// n��
3
4
5
6
//output
5
12
29
70
169
