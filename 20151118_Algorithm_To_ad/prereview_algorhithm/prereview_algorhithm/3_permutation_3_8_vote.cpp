/*
* name : ���� 147page
* contents : ���� ���� ���ſ� �⸶�ؼ� ���� mǥ, ���� nǥ�� ���, ���� �缱�Ǿ���.
��, 1<= n < m�̴�. �׷��� ��ǥ �������� ���� �׻� ���� �ռ��ٰ� �Ѵ�.
��ǥ�� ��� ��, �׶����� ���� ���� ǥ�� �׻� ���� ǥ���� ���Ҵ�.
�ڿ��� m�� n�� �Է¹޾� ���� ���� ǥ�� '+', ���� ���� ǥ�� '-'�� ǥ���Ͽ�, ������
��ǥ ������ ��� ����ϴ� ���α׷��� �ۼ��϶�.
*/

//input
4 3

//output
++++---
+++-+--
+++--+-
++-++--
++-+-+-

#include <stdio.h>
#define MAXN 100
#define L 0
#define R 1

void print(int arr[], int arr_size) {
	int i;
	for (i = 0; i < arr_size; i++) {
		if (arr[i] == L) {
			printf("+");
		}
		else if (arr[i] == R) {
			printf("-");
		}
	}
	printf("\n");
}

void paren(int to_open, int to_close, int arr[], int arr_size) {
	if (to_open == 0 && to_close == 0) {
		print(arr, arr_size);
		return;
	}

	if (to_open > 0 || to_open >= to_close) {
		arr[arr_size] = L;
		paren(to_open - 1, to_close, arr, arr_size + 1);
	}

	if (to_close > 0 && to_close > to_open) {
		arr[arr_size] = R;
		paren(to_open, to_close - 1, arr, arr_size + 1);
	}
}

int main() {

	int arr[MAXN];
	int n;
	int m;

	scanf("%d %d", &m, &n);
	paren(m, n, arr, 0);
	return 0;
}