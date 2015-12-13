/**********************************
* ���� : �κ������� ���� 50�� ��츸 ���
* ������ : ���� ����Ʈ ����
* �ڵ� : c
**********************************/

#include <stdio.h>

#define SIZE 5
int data[SIZE] = { 0, 40, 20, 30, 10 };
int include[SIZE];

void Print_arr_except_zero_item();
void GetSubSetsOfSum50(int index, int total);

int main(int argc, char argv[]) {

	GetSubSetsOfSum50(0, 0);

	return 0;
}

// 50�� ��츸 ���
void GetSubSetsOfSum50(int index, int total) {
	if (index == SIZE - 1) {
		if (total == 50) {
			Print_arr_except_zero_item();
		}
	}
	else {
		include[index + 1] = 1;
		GetSubSetsOfSum50(index + 1, total + data[index + 1]);
		include[index + 1] = 0;
		GetSubSetsOfSum50(index + 1, total);
	}
}

//��½� 0�� �κ��� �����ϰ� ����Ѵ�.
void Print_arr_except_zero_item() {
	int i = 1;

	while (i < SIZE) {
		if (include[i] == 1) {
			printf("%d ", data[i]);
		}
		i++;
	}

	putchar('\n');
}

//input
none

//output
40 10
20 30