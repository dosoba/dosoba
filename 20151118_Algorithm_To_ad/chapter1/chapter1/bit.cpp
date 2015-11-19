/**********************************
* 제목 : 비트 연산 예제1
* 페이지 : 19 page
* 코드 : c
**********************************/

#include <iostream>
using namespace std;

void Bbit_print(char i);
int main(int argc, char argv[]) {

	char i;

	for (i = -5; i < 6; i++) {
		printf("%3d = ", i);
		Bbit_print(i);
		putchar('\n');
	}

	return 0;
}

void Bbit_print(char i) {
	for (int j = 7; j >= 0; j--) {
		putchar((i & (1 << j)) ? '1' : '0');
	}
	putchar(' ');
}

//결과
-5 = 11111011
-4 = 11111100
-3 = 11111101
-2 = 11111110
-1 = 11111111
0 = 00000000
1 = 00000001
2 = 00000010
3 = 00000011
4 = 00000100
5 = 00000101
