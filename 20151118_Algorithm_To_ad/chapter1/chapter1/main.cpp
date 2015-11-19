
//Q : 다음 내용을 표준 입력으로 읽어 들여 변수에 저장 후 출력하시오.
// c++
#include <iostream>
using namespace std;

int main(int argc, char argv[]) {
	char input;

	input = getchar();
	while (input != EOF) {
		cout << input;
		input = getchar();
	}
	
	return 0;
}


//c
#include <stdio.h>

int main(int argc, char argv[]) {
	char input;

	input = getchar();
	while (input != EOF) {
		printf("%d", input);
		input = getchar();
	}

	return 0;
}