/**********************************
* 제목 : 비트 연습문제 1  - 0과 1로 이루어진 1차 배열에서 7개 byte를 묶어서 10진수로 출력하기
* 페이지 : 19
* 코드 : c
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

//결과
//입력
00000010001101
//출력
1 13