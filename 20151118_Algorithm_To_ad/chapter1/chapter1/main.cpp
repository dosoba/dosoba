
//Q : ���� ������ ǥ�� �Է����� �о� �鿩 ������ ���� �� ����Ͻÿ�.
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