// baekjoon : https://www.acmicpc.net/problem/2751
// 참고 site : http://blog.naver.com/madplay/220397118365
// 참고 site : http://cds0915.blog.me/220522528007

//input : 
5
5
4
3
2
1
//output :
1
2
3
4
5

#include <stdio.h>
#define MAX 1000000

int getPivot(int low, int high);
void swap(int *a, int source, int target);
int partition(int *a, int left, int right);
void quicksort(int *a, int left, int right);

int main(int argc, char *argv[]) {
	int N;
	int arr[MAX] = { 0, };
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	quicksort(arr, 0, N - 1);


	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

void swap(int *a, int source, int target) {
	int temp = a[source];
	a[source] = a[target];
	a[target] = temp;
}

int getPivot(int low, int high) {
	return low + (high - low) / 2;
}

int partition(int *a, int left, int right) {
	int pivot = a[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > a[low]) {
			low++;
		}

		while (pivot < a[high]) {
			high--;
		}

		if (low <= high)
			swap(a, low, high);
	}

	swap(a, left, high);
	return high;
}

void quicksort(int *a, int left, int right) {
	if (left <= right) {
		int pivot = partition(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
	}
}
