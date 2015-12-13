/**********************************
* 제목 : subset
* 페이지 : http://59.23.113.171/30stair/backtracking1/backtracking1.php?pname=backtracking1
* 코드 : c
**********************************/

#include <stdio.h>

#define MAX 5
int include[MAX];

void GetSubSets(int index);
void print_arr(int size);

int main(int argc, char argv[]) {

	GetSubSets(0);

	return 0;
}

//부분집합형 문제의 기본 틀 (1,2,3,4) 4개의 원소의 부분집합 구하기 문제
void GetSubSets(int index) {

	if (index == MAX - 1) {
		print_arr(MAX);
	}
	else {
		include[index + 1] = 1;
		GetSubSets(index + 1);
		include[index + 1] = 0;
		GetSubSets(index + 1);
	}
}

// 부분집합 출력하는 문제
// 1 1 1 1, 1 1 1 0, 1 1 0 1, .....
void print_arr(int size) {
	int i = 1;

	while (i < size){
		printf("%d ", include[i]);
		i++;
	}
	putchar('\n');
}

//input
none

//output
1 1 1 1
1 1 1 0
1 1 0 1
1 1 0 0
1 0 1 1
1 0 1 0
1 0 0 1
1 0 0 0
0 1 1 1
0 1 1 0
0 1 0 1
0 1 0 0
0 0 1 1
0 0 1 0
0 0 0 1
0 0 0 0
