/**********************************
* 제목 : 파일 입출력
* 페이지 : 14 ~ 17
* 코드 : c / c++
* Q : 다음 내용을 표준 입력으로 읽어 들여 변수에 저장 후 출력하시오.
* 주의점 : c로 코드 작성시 scanf(" %c", &ary[i][j]);
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