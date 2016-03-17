/**********************************
* ���� : ��ø �ݺ��� ��ü�ϱ�
		 0���� ���ʴ�� ��ȣ �Ű��� n���� ���� �� 4���� ���� ��츦 ����ϴ� �ڵ带 �ۼ�
* ������ : 148 ~ 149
* �ڵ� : c
**********************************/
//input
7 4

//output
0 1 2 3
0 1 2 4
0 1 2 5
0 1 2 6
0 1 3 4
0 1 3 5
0 1 3 6
0 1 4 5
0 1 4 6
0 1 5 6
0 2 3 4
0 2 3 5
0 2 3 6
0 2 4 5
0 2 4 6
0 2 5 6
0 3 4 5
0 3 4 6
0 3 5 6
0 4 5 6
1 2 3 4
1 2 3 5
1 2 3 6
1 2 4 5
1 2 4 6
1 2 5 6
1 3 4 5
1 3 4 6
1 3 5 6
1 4 5 6
2 3 4 5
2 3 4 6
2 3 5 6
2 4 5 6
3 4 5 6

#include <stdio.h>
#define MAX 4

void combination(int n, int r);
void combination1(int *picked, int size, int n, int toPick);
void combination2(int *picked, int size, int n, int toPick, int index);
void print_arr(int *arr, int size);


int main() {
	int n;
	int r;

	int picked[MAX];

	scanf("%d %d", &n, &r);
	combination(n, r);
	combination1(picked, 0, n, r);
	combination2(picked, 0, n, r, 0);
	
	return 0;
}


//n�� �߿��� 4���� ���� ����� ��
//4�� �̻��̸� for���� �Ѱ��� �߰��Ǿ�� �Ѵ�.
void combination(int n, int r) {
	int i;
	int j;
	int x;
	int y;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (x = j + 1; x < n; x++) {
				for (y = x + 1; y < n; y++) {
					printf("%d %d %d %d\n", i, j, x, y);
				}
			}
		}
	}
}

//for�� �Ѱ��� �Լ��� �̾Ƴ��Ͱ� �����ϴ�
//4�� �̻��̼��� �ڵ带 ������ �ʿ䰡 ����.
void combination1(int *picked, int size, int n, int toPick) {
	if (toPick == 0) {
		print_arr(picked, size);
		return;
	}

	int smallest = size == 0 ? 0 : picked[size - 1] + 1;

	for (int next = smallest; next < n; next++) {
		picked[size] = next;
		combination1(picked, size + 1, n, toPick - 1);
	}
}


//�Ϲ����� ���� �Լ�
void combination2(int *picked, int size, int n, int toPick, int index) {
	if (toPick == 0) {
		print_arr(picked, size);
	}
	else if (index == n) {
		return;
	}
	else {
		picked[size] = index;
		combination2(picked, size + 1, n, toPick - 1, index + 1);
		combination2(picked, size, n, toPick, index + 1);
	}
}

//����Լ�
void print_arr(int *arr, int size) {
	int i = 0;

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}