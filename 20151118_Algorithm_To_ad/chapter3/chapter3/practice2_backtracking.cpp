/**********************************
* 제목 : 입력받아서 부분집합의 합이 10인 경우를 출력하시오
* 페이지 : 116
* 코드 : c
**********************************/

#include <stdio.h>

#define SIZE 10 + 1
int data[SIZE];
int include[SIZE];
int counts = 0;

int GetInput(int size);
void Print_arr_except_zero_item(int size);
void GetSubSetsOfSum(int targetNumber, int size, int index, int total, int remainning);

int main(int argc, char argv[]) {

	int T;
	int size;
	int target;
	int total;

	scanf("%d ", &T);

	for (int test_case = 1; test_case <= T; test_case++) {

		scanf("%d %d ", &size, &target);
		total = GetInput(size);
		printf("#%d\n", test_case);
		GetSubSetsOfSum(target, size, 0, 0, total);
	}
	return 0;
}

int GetInput(int size) {
	int i = 1;
	int sum = 0;

	while (i < size) {
		scanf("%d ", &data[i]);
		sum += data[i];
		i++;
	}
	return sum;
}

// 50일 경우만 출력
void GetSubSetsOfSum(int targetNumber, int size, int index, int total, int remainning) {
	if (total > targetNumber) return;
	if (total + remainning < targetNumber) return;

	if (index == size - 1) {
		if (total == targetNumber) {
			Print_arr_except_zero_item(size);
		}
	}
	else {
		counts++;
		include[index + 1] = 1;
		GetSubSetsOfSum(targetNumber, size, index + 1, total + data[index + 1], remainning - data[index + 1]);
		include[index + 1] = 0;
		GetSubSetsOfSum(targetNumber, size, index + 1, total, remainning - data[index + 1]);
	}
}

//출력시 0이 부부은 제외하고 출력한다.
void Print_arr_except_zero_item(int size) {
	int i = 1;

	while (i < size) {
		if (include[i] == 1) {
			printf("%d ", data[i]);
		}
		i++;
	}

	putchar('\n');
}

// input
1						// test case 
10 10					// size condition of sum
1 2 3 4 5 6 7 8 9 10	// items

// output
#1
1 2 3 4
1 2 7
1 3 6
1 4 5
1 9
2 3 5
2 8
3 7
4 6
