/**********************************
* 제목 : 스택을 구현해보자
* 페이지 : 155
* 코드 : c
**********************************/

#include <stdio.h>

#define SIZE 3
int stack[SIZE] = { 0, };
int top = -1;

void Push(int data);
int Pop();

int main(int argc, char argv[]) {

	Push(1);
	Push(2);
	Push(3);
	Push(4);
	printf("%d\n", Pop());
	printf("%d\n", Pop());
	printf("%d\n", Pop());
	Pop();

	return 0;
}

void Push(int data) {
	if (top >= SIZE - 1) {
		printf("Overflow !\n");
	}
	else{
		top++;
		stack[top] = data;
	}
}

int Pop(){
	int result;

	if (top == -1) {
		printf("Underflow !\n");
		result = 0;
	}
	else {
		result = stack[top];
		top--;
	}
	return result;
}


/*
void Push(int data) {
	if (top < SIZE - 1) {
		stack[++top];
	}
	else {
		return;
	}
}

int Pop() {
	if (top > -1) {
		return stack[top--];
	}
	else {
		return 0;
	}
}
*/