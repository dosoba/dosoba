/**********************************
* 제목 : 단순하게 모든 부분 집합을 생성하는 방법
* 페이지 : 53 page
* 코드 : c
**********************************/

#include <stdio.h>
#define SIZE 4

void print_array(int *(arr), int n);
void Subsets(int *(arr), int n);
int main(int argc, char argv[]) {

	int arr[SIZE] = { 0, };

	Subsets(arr, SIZE);

	return 0;
}

void Subsets(int *(arr), int n) {
	int i, j, k, z;

	for (i = 0; i <= 1; i++){
		arr[0] = i;
		for (j = 0; j <= 1; j++) {
			arr[1] = j;
			for (k = 0; k <= 1; k++) {
				arr[2] = k;
				for (z = 0; z <= 1; z++) {
					arr[3] = z;
					print_array(arr, n);
				}
			}
		}
	}
}

void print_array(int *(arr), int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//결과
0 0 0 0
0 0 0 1
0 0 1 0
0 0 1 1
0 1 0 0
0 1 0 1
0 1 1 0
0 1 1 1
1 0 0 0
1 0 0 1
1 0 1 0
1 0 1 1
1 1 0 0
1 1 0 1
1 1 1 0
1 1 1 1


/**********************************
* 제목 : 바이너리 카운팅을 통한 부분집합 생성 코드
* 페이지 : 54 page
* 코드 : c
**********************************/

#include <stdio.h>
#define SIZE 4

void print_array(char *(arr), int n);
void Subsets(char *(arr), int n);
int main(int argc, char argv[]) {

	char arr[SIZE] = { 'A', 'B', 'C', 'D' };
	Subsets(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}

void Subsets(char *(arr), int n) {
	int i, j;

	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				printf("%c", arr[j]);
			}
		}
		printf("\n");
	}
}

//결과

A
B
AB
C
AC
BC
ABC
D
AD
BD
ABD
CD
ACD
BCD
ABCD