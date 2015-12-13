/**********************************
* ���� : �κ������� ���� 50�� ��츸 ��� - bound �߰�
* ������ : ���� ����Ʈ ����
* �ڵ� : c
**********************************/
#include <stdio.h>

#define SIZE 5
int data[SIZE] = { 0, 40, 20, 30, 10 };
int include[SIZE];
int counts = 0;

void Print_arr_except_zero_item();
void GetSubSetsOfSum50(int index, int total, int remainning);

int main(int argc, char argv[]) {

	GetSubSetsOfSum50(0, 0, 100);
	printf("counts : %d\n", counts);

	return 0;
}

// 50�� ��츸 ���
void GetSubSetsOfSum50(int index, int total, int remainning) {
	if (total > 50) return;
	//bound �߰�
	if (total + remainning < 50) return;

	if (index == SIZE - 1) {
		if (total == 50) {
			Print_arr_except_zero_item();
		}
	}
	else {
		counts++;
		include[index + 1] = 1;
		GetSubSetsOfSum50(index + 1, total + data[index + 1], remainning - data[index + 1]);
		include[index + 1] = 0;
		GetSubSetsOfSum50(index + 1, total, remainning - data[index + 1]);
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