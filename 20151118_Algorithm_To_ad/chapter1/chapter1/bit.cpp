/**********************************
* 제목 : 비트 연산 예제1
* 페이지 : 19 page
* 코드 : c
**********************************/

#include <stdio.h>
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
 

/**********************************
* 제목 : 비트 연산 예제2
* 페이지 : 20page
* 코드 : c
**********************************/

#include <stdio.h>
void Bbit_print(char i);

int main(int argc, char argv[]) {

	char *p;
	char a = 0x10;
	int x = 0x01020304, i;

	printf("%d = ", a);
	p = &a;
	Bbit_print(*p);
	putchar('\n');

	printf("0%x = ", x);
	p = (char *)&x;
	for (i = 0; i < 4; i++) {
		Bbit_print(*p++);
	}
	putchar('\n');

	return 0;
}

void Bbit_print(char i) {
	for (int j = 7; j >= 0; j--) {
		putchar((i & (1 << j)) ? '1' : '0');
	}
	putchar(' ');
}

//결과
16 = 00010000
01020304 = 00000100 00000011 00000010 00000001



/**********************************
* 제목 : 비트 연산 예제3 - 엔디안 확인
* 페이지 : 21page
* 코드 : c
**********************************/

#include <stdio.h>

int main(int argc, char argv[]) {
	int n = 0x00111111;
	char *c = (char *)&n;

	if (c[0]) {
		printf("little endian");
	}
	else {
		printf("big endian");
	}

	return 0;
}

//결과
little endian


/**********************************
* 제목 : 비트 연산 예제4 - 엔디안 변환 코드
* 페이지 : 21page
* 코드 : c
**********************************/

#include <stdio.h>
void ce(int *n);

int main(int argc, char argv[]) {

	int x = 0x01020304;
	char *p = (char *)&x;

	printf("x = %d%d%d%d\n", p[0], p[1], p[2], p[3]);
	ce(&x);
	printf("x = %d%d%d%d\n", p[0], p[1], p[2], p[3]);
	return 0;
}


void ce(int *n) {
	char *p = (char *)n;
	char t;
	t = p[0], p[0] = p[3], p[3] = t;
	t = p[1], p[1] = p[2], p[2] = t;
}

//결과
x = 4321
x = 1234



/**********************************
* 제목 : 비트 연산 예제5 - structure byte padding
* 페이지 : 22page
* 코드 : c
**********************************/

#include <stdio.h>
void Bbit_print(char i);

int main(int argc, char argv[]) {

	struct {
		char a;
		char b;
		int j;

	} s;
	char *p;
	int i;

	s.a = 0x30;
	s.b = 0xff;
	s.j = 0x01020304;

	p = (char *)&s;

	for (i = 0; i < sizeof(s); i++) {
		Bbit_print(*p++);
	}
	putchar('\n');

	return 0;
}

void Bbit_print(char i) {
	for (int j = 7; j >= 0; j--) {
		putchar((i & (1 << j)) ? '1' : '0');
	}
	putchar(' ');
}

//출력
00110000 11111111 11001100 11001100 00000100 00000011 00000010 00000001
// 결론 11001100 11001100 이부분이 이상하다
// 구조체 byte allignment 해야 하는 관계로 임의의 공간이 생겼다


/**********************************
* 제목 : 비트 연산 예제6 - 비트 연산자 ^를 두번 연산하면 처음 값을 반환한다.
* 페이지 : 24page
* 코드 : c
**********************************/

#include <stdio.h>
void Bbit_print(char i);

int main(int argc, char argv[]) {

	char a = 0x86;
	char key = 0xAA;

	printf("a      ==> ");
	Bbit_print(a); putchar('\n');

	printf("a^=key ==> ");
	a ^= key;
	Bbit_print(a); putchar('\n');

	printf("a^=key ==> ");
	a ^= key;
	Bbit_print(a); putchar('\n');

	return 0;
}

void Bbit_print(char i) {
	for (int j = 7; j >= 0; j--) {
		putchar((i & (1 << j)) ? '1' : '0');
	}
	putchar(' ');
}

//결과
a == > 10000110
a ^= key == > 00101100
a ^= key == > 10000110
//결론 : 비트연산자 ^를 두번 연산하면 처음 값을 반환한다



/**********************************
* 제목 : 비트 연산 예제7 - 패킹과 언패킹 예
* 페이지 : 25page
* 코드 : c
**********************************/
#include <stdio.h>
int pack(char a, char b, char c, char d);
char unpack(int p, int k);
void Bbit_print(char i);

int main(int argc, char argv[]) {

	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';

	int result;
	char result2;
	char *p;

	result = pack(a, b, c, d);
	printf("result1 : %d", result); putchar('\n');

	p = (char *)&result;
	printf("result1 : ");
	for (int i = 0; i < 4; i++) {
		Bbit_print(*p);
	}
	putchar('\n');


	result2 = unpack(result, 3);
	printf("result2 : %c", result2); putchar('\n');


	return 0;
}


int pack(char a, char b, char c, char d){
	int p = a;
	p = (p << 8) | b;
	p = (p << 8) | c;
	p = (p << 8) | d;

	return p;
}

char unpack(int p, int k){
	int n = k * 8;
	unsigned int mask = 255;
	mask <<= n;
	return ((p & mask) >> n);
}

void Bbit_print(char i) {
	for (int j = 7; j >= 0; j--) {
		putchar((i & (1 << j)) ? '1' : '0');
	}
	putchar(' ');
}

//결과
result1: 1633837924
result1 : 01100100 01100100 01100100 01100100
result2 : a