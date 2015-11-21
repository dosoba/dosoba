/**********************************
* ���� : ��Ʈ �������� 1  - 0�� 1�� �̷���� 1�� �迭���� 7�� byte�� ��� 10������ ����ϱ�
* ������ : 19
* �ڵ� : c
* �ۼ� : 2015-11-21
**********************************/

#include <stdio.h>

#define NUMBER 7

void BinaryToDecimalPrint(int *(array), int size);

int main(int argc, char argv[]) {

	//int array[] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1 };
	int array[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1};
	int size;

	size = sizeof(array) / sizeof(int);

	BinaryToDecimalPrint(array, size);
	return 0;
}

void BinaryToDecimalPrint(int *(array), int size) {
	int decimal;
	int start;
	int end;
	int i = 1;
	int j;
	int repeat;

	if (size%NUMBER != 0) {
		repeat = (size / NUMBER) + 1;
	}
	else {
		repeat = (size / NUMBER);
	}


	while (i <= repeat) {

		start = (NUMBER) * i - 1;
		if (start > size) {
		start = size;
		}

		end = NUMBER * (i - 1);
		decimal = 0;

		j = start;
		while (j >= end && start != end) {
			if (array[j] == 1) {
				decimal += (1 << (start - j));
			}
			j--;
		}
		printf("%d ", decimal);

		i++;
	}

}

// ���
input  : 0000000111100000011000000111100110000110000111100111100111111001100111
output : 0 120 12 7 76 24 60 121 124 103

input  : 00000010001101
output : 1 13

