/**********************************
* 제목 : 16진수 문자로 이루어진 1차 배열이 주어질 때 암호비트 패턴을 찾아 차례대로 출력하시오. 암호는 연속되어 있다.
* 페이지 : 32
* 코드 : c
**********************************/

#include <stdio.h>

#define NUMBER 6
#define MAX 100
#define SECURITY_SIZE 10
#define LENGTH 6

typedef enum BOOL { FALSE = 0, TRUE = 1 };

void MakeBinary(char *(inputHex), int sizeInput, int *(binary), int *sizeBinary);
BOOL FindSecurityNumbers(int *(codes), int *indexCodes, int *(securityCodes), int decimal);
void MatchSecurityCodes(int *(codes), int *(indexCodes), int *(binary), int sizeBinary, int *(securityCodes));

int main(int argc, char argv[]) {

	int T;
	int input_size;
	char inputHex[10];

	int binary[MAX];
	int sizeBinary;
	int codes[MAX];
	int indexCodes;

	int securityCodes[] = { 13, 19, 59, 49, 35, 55, 11, 61, 25, 47 };

	scanf("%d ", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &input_size);

		for (int i = 0; i < input_size; i++) {
			inputHex[i] = getchar();
		}

		indexCodes = 0;
		sizeBinary = 0;
		MakeBinary(inputHex, input_size, binary, &sizeBinary);
		MatchSecurityCodes(codes, &indexCodes, binary, sizeBinary, securityCodes);

		printf("#%d ", test_case);
		for (int j = 0; j < indexCodes; j++) {
			printf("%d ", codes[j]);
		}
		putchar('\n');
	}

	return 0;
}

void MakeBinary(char *(inputHex), int sizeInput, int *(binary), int *sizeBinary) {

	int i = 0;
	int j;
	int result = 0;
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
			(*sizeBinary)++;
			j++;
		}
		i++;
	}
}

BOOL FindSecurityNumbers(int *(codes), int *indexCodes, int *(securityCodes), int decimal) {
	int i;
	BOOL result = FALSE;

	i = 0;
	while (i < SECURITY_SIZE) {
		if (decimal == securityCodes[i]) {
			codes[*indexCodes] = i;
			(*indexCodes)++;
			result = TRUE;
		}
		i++;
	}
	return result;
}

void MatchSecurityCodes(int *(codes), int *(indexCodes), int *(binary), int sizeBinary, int *(securityCodes)) {
	int start;
	int end;
	int decimal;
	int i;

	start = NUMBER - 1;
	end = 0;

	while (start <= sizeBinary) {
		decimal = 0;
		i = start;
		while (i >= end) {
			if (binary[i] == 1) {
				decimal += (1 << (start - i));
			}
			i--;
		}
		if (FindSecurityNumbers(codes, indexCodes, securityCodes, decimal) == TRUE) {
			start += 6;
			end += 6;
		}
		else {
			start++;
			end++;
		}
	}

}

//input.txt
2
4
0DEC
10
0269FAC9A0

//output.txt
#1 0 2
#2 1 1 7 8 0