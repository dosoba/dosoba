/**********************************
* 제목 : 연습문제2 - 16진수 문자로 이루어진 1차 배열이 주어질 때 앞에서부터 7bit씩 묶어 십진수로 변환하여 출력해 보자
* 페이지 : 27
* 코드 : c
**********************************/

#include <stdio.h>

#define NUMBER 7
#define MAX 100

void MakeBinary(char *(inputHex), int sizeInput, int *(binary));
void BinaryToDecimalPrint(int *(array), int size);

int main(int argc, char argv[]) {

	char inputHex[] = { '0', 'F', '9', '7', 'A', '3' };
	int binary[MAX];

	MakeBinary(inputHex, sizeof(inputHex) / sizeof(char), binary);
	BinaryToDecimalPrint(binary, (sizeof(inputHex) / sizeof(char)) * 4);

	return 0;
}

void MakeBinary(char *(inputHex), int sizeInput, int *(binary)) {

	int i = 0;
	int j;
	int result;
	while (i < sizeInput) {

		if (inputHex[i] >= '0' && inputHex[i] <= '9') {
			result = inputHex[i] - '0';
		}
		else if (inputHex[i] >= 'A' && inputHex[i] <= 'F') {
			result = inputHex[i] - 'A' + 10;
		}

		j = 0;
		while (j < 4) {
			binary[i * 4 + (4 - 1 - j)] = (result & (1 << j)) ? 1 : 0;
			j++;
		}
		i++;
	}
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

		start = (NUMBER * i) - 1;
		if (start > size) {
			start = size - 1;
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
//결과
input  : 0F97A3
output : 7 101 116 3

