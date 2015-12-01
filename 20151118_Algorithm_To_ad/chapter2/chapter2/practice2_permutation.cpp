/**********************************
* 제목 :
* 페이지 :
* 코드 : c
**********************************/
#include <stdio.h>

#define SIZE 3

int arr[SIZE] = { 0, 1, 2 };

void permutation(int n, int r);
void swap(int *first, int *second);
void print_array();

int main(int argc, char argv[]) {
	int T;

	//scanf("%d", &T);

	//for (int test_case = 1; test_case <= T; test_case++) {

	//}
	permutation(3, 3);

	return 0;
}


void permutation(int n, int r) {
	int i;

	if (r == 0) {
		print_array();
	}
	else {
		for (i = n - 1; i >= 0; i--) {
			swap(&arr[i], &arr[n - 1]);
			permutation(n - 1, r - 1);
			swap(&arr[i], &arr[n - 1]);
		}
	}

}

void swap(int *first, int *second) {
	int temp;

	printf("Before : ");
	print_array();
	temp = *first;
	*first = *second;
	*second = temp;
	printf("after : ");
	print_array();
}

void print_array() {
	int i;

	i = 0;
	printf("result : ");
	while (i < SIZE) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

//참고
http://blog.naver.com/leojesus/80046296644 (주로 참고)
http ://blog.naver.com/zkd1750/90191952950
http ://blog.naver.com/hotspam0529/220507892374
http ://blog.naver.com/chaos_3d/220291660986
http ://ryulib.tistory.com/318
http ://blog.daum.net/shksjy/181

//결과
Before : result : 0 1 2 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 0 1 2 
result : 0 1 2 

Before : result : 0 1 2 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 1 0 2 
Before : result : 1 0 2 
after : result : 1 0 2 
result : 1 0 2 

Before : result : 1 0 2 
after : result : 1 0 2 
Before : result : 1 0 2 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 0 2 1 
Before : result : 0 2 1 
after : result : 0 2 1 
Before : result : 0 2 1 
after : result : 0 2 1 
result : 0 2 1 

Before : result : 0 2 1 
after : result : 0 2 1 
Before : result : 0 2 1 
after : result : 0 2 1 
Before : result : 0 2 1 
after : result : 2 0 1 
Before : result : 2 0 1 
after : result : 2 0 1 
result : 2 0 1 

Before : result : 2 0 1 
after : result : 2 0 1 
Before : result : 2 0 1 
after : result : 0 2 1 
Before : result : 0 2 1 
after : result : 0 1 2 
Before : result : 0 1 2 
after : result : 2 1 0 
Before : result : 2 1 0 
after : result : 2 1 0 
Before : result : 2 1 0 
after : result : 2 1 0 
result : 2 1 0 

Before : result : 2 1 0 
after : result : 2 1 0 
Before : result : 2 1 0 
after : result : 2 1 0 
Before : result : 2 1 0 
after : result : 1 2 0 
Before : result : 1 2 0 
after : result : 1 2 0 
result : 1 2 0 

Before : result : 1 2 0 
after : result : 1 2 0 
Before : result : 1 2 0 
after : result : 2 1 0 
Before : result : 2 1 0 
after : result : 0 1 2 
