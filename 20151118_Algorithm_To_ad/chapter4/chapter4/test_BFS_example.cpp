
/**********************************
* 제목 : BFS를 통한 최단 경로 길이 구하기
* 페이지 : http://blog.eairship.kr/269
* 코드 : c
**********************************/


#include <stdio.h>
#define MAX 100

int N;
int map[MAX][MAX];
int yPos[MAX];
int xPos[MAX];
int length[MAX];

//queue
int front;
int rear;

void EnQueue(int y, int x, int l);
void DeQueue();
void BFS(int y, int x);
void initValue();

int main() {
	int T;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &N);

		front = -1;
		rear = -1;

		//init position and length
		initValue();

		//make map
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &map[i][j]);
			}
		}

		printf("#%d ", test_case);
		//call BFS
		BFS(0, 0);
		printf("\n");
	}

	return 0;
}

void initValue() {
	int i = 0;
	int j = 0;

	while (j < MAX) {
		i = 0;
		while (i < MAX) {
			map[j][i] = 0;
			i++;
		}
		yPos[j] = 0;
		xPos[j] = 0;
		length[j] = 0;
		j++;
	}
}

void EnQueue(int y, int x, int l) {
	rear++;
	yPos[rear] = y;
	xPos[rear] = x;
	length[rear] = l;
}

void DeQueue() {
	front++;
	//yPos[front]
	//xPos[front]
	//length[front]
}

void BFS(int y, int x) {
	EnQueue(y, x, 1);
	map[yPos[y]][xPos[x]] = 0;

	while (front != rear) {

		front++;
		if (yPos[front] == N - 1 && xPos[front] == N - 1) {
			break;
		}

		if (yPos[front] > 0 && map[yPos[front] - 1][xPos[front]] == 1) {
			EnQueue(yPos[front] - 1, xPos[front], length[front] + 1);
			map[yPos[front] - 1][xPos[front]] = 0;
		}

		if (yPos[front] < N - 1 && map[yPos[front] + 1][xPos[front]] == 1) {
			EnQueue(yPos[front] + 1, xPos[front], length[front] + 1);
			map[yPos[front] + 1][xPos[front]] = 0;
		}

		if (xPos[front] > 0 && map[yPos[front]][xPos[front] - 1] == 1) {
			EnQueue(yPos[front], xPos[front] - 1, length[front] + 1);
			map[yPos[front]][xPos[front] - 1] = 0;
		}

		if (xPos[front] < N - 1 && map[yPos[front]][xPos[front] + 1] == 1) {
			EnQueue(yPos[front], xPos[front] + 1, length[front] + 1);
			map[yPos[front]][xPos[front] + 1] = 0;
		}
	}

	if (front <= rear) {
		printf("%d ", length[front]);
	}
}

//input
2
6
1 1 1 1 1 1
0 0 1 0 0 1
1 1 1 0 1 1
1 0 0 0 1 0
1 1 1 0 1 0
0 0 1 1 1 1
5
1 1 1 1 1
0 0 0 0 1
1 1 1 1 1
1 0 1 1 0
1 1 1 1 1


//output
#1 13
#2 11
