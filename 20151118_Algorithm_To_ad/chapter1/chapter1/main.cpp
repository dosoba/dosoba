/**********************************
* ���� : ���� �����
* ������ : 14 ~ 17
* �ڵ� : c / c++
* Q : ���� ������ ǥ�� �Է����� �о� �鿩 ������ ���� �� ����Ͻÿ�.
* ������ : c�� �ڵ� �ۼ��� scanf(" %c", &ary[i][j]);
**********************************/

// c
#include <stdio.h>

int main(int argc, char argv[]) {

	int T, r, c;
	char ary[100][100];

	scanf("%d", &T);
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &ary[i][j]);
		}
	}

	printf("%d\n%d %d\n", T, r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", ary[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// c++
#include <iostream>
using namespace std;
int main(int argc, char argv[]) {

	int T, r, c;
	char ary[100][100];

	cin >> T >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ary[i][j];
		}
	}

	cout << T << endl << r << " " << c << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << ary[i][j];
		}
		cout << endl;
	}

	return 0;
}