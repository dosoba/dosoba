/**********************************
* 力格 : queue 备泅
* 其捞瘤 : 162
* 内靛 : c
**********************************/
#include <stdio.h>
#define SIZE 8
typedef enum { FALSE = 0, TRUE = 1 }BOOL;

void EnQueue(int item);
int DeQueue();
BOOL IsEmpty();
BOOL IsFull();

int queue[SIZE] = { 0, };
int front = -1;
int rear = -1;

int main() {

	EnQueue(1);
	EnQueue(2);
	EnQueue(3);

	printf("%d ", DeQueue());
	printf("%d ", DeQueue());
	printf("%d ", DeQueue());
	printf("\n");
	return 0;
}

void EnQueue(int item) {
	if (IsFull() == TRUE) {
		return;
	}
	else {
		rear++;
		queue[rear] = item;
	}
}

int DeQueue() {
	if (IsEmpty() == TRUE) {
		return 0;
	}
	else {
		front++;
		return queue[front];
	}
}

BOOL IsEmpty() {
	BOOL isEmpty = FALSE;
	if (front == rear) {
		isEmpty = TRUE;
	}
	return isEmpty;
}

BOOL IsFull() {
	BOOL isFull = FALSE;
	if (rear == SIZE - 1) {
		isFull = TRUE;
	}
	return isFull;
}

//output
1 2 3