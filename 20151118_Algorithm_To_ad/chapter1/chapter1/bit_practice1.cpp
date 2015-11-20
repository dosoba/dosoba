/**********************************
* ���� : ��Ʈ �������� 1  - 0�� 1�� �̷���� 1�� �迭���� 7�� byte�� ��� 10������ ����ϱ�
* ������ : 19
* �ڵ� : c
**********************************/
#include <stdio.h>

#define POSITION_NUMBER 7
#define MAX 70

void ConvertFromBinaryIntoDecimal(char *(binaryNumbers));

int main(int argc, char argv[]) {

	char input;
	char binaryNumbers[MAX];
	int i;

	i = 0;
	input = getchar();
	while (input != EOF) {
		binaryNumbers[i] = input;
		input = getchar();
		i++;
	}

	ConvertFromBinaryIntoDecimal(binaryNumbers);

	return 0;
}

void ConvertFromBinaryIntoDecimal(char *(binaryNumbers)) {
	int result;
	int i;
	int j;

	j = 0;
	while (binaryNumbers[j*POSITION_NUMBER] == '0' || binaryNumbers[j*POSITION_NUMBER] == '1') {
		i = 0;
		result = 0;
		while (i < POSITION_NUMBER) {
			if (binaryNumbers[j*POSITION_NUMBER + i] == '1') {
				result += (1 << (POSITION_NUMBER - 1 - i));
			}
			i++;
		}
		printf("%d ", result);
		j++;
	}
}

//���
//�Է�
00000010001101
//���
1 13