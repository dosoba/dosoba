// baekjoon : https://www.acmicpc.net/problem/10799
// 내용 : 나무도막자르기와 유사한 문제, 다시 풀어볼 문제

//input
()(((()())(())()))(())

//output
17

#include <stdio.h>


char str[100001];
int stack[100001];

int main() {
	scanf("%s", str);
	int top = 0;
	int ans = 0;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '(') {
			stack[top++] = i;
		}
		else {
			if (stack[--top] == i - 1) {	//( == (인지 확인
				ans += top;
			}
			else {
				ans += 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

//타임아웃나는 해결책 1
#include <stdio.h>
#define MAX 100001

int steel[MAX][2] = { { 0, }, };
int steel_index;
int laser[MAX][2] = { { 0, }, };
int laser_index;
char data[MAX];


void setLaser();
void setSteel();
int getSteels();

int main() {
	int count = 0;
	scanf("%s", &data);
	//setLaser();
	setSteel();
	
	printf("%d\n", getSteels());
	return 0;
}

int getSteels() {
	int count;
	int sum = 0;
	for (int i = 0; i < steel_index; i++) {
		count = 0;
		for (int j = 0; j < laser_index; j++) {
			if (steel[i][0] < laser[j][0] && steel[i][1] > laser[j][1]) {
				count++;
			}
		}
		count += 1;
		sum += count;
	}

	return sum;
}

void setLaser() {
	laser_index = 0;
	for (int i = 0; data[i] != '\0'; i++) {
		if (data[i] == '(' && data[i + 1] == ')') {
			laser[laser_index][0] = i;
			laser[laser_index][1] = i + 1;
			laser_index++;
		}
	}
}

void setSteel() {
	int opened = 0;
	steel_index = 0;
	for (int i = 0; data[i] != '\0'; i++) {
		if (data[i] == '(') {
			if (data[i + 1] == ')') {
				laser[laser_index][0] = i;
				laser[laser_index][1] = i + 1;
				laser_index++;
				i += 1;
				continue;
			}
			else{
				for (int j = i; data[j] != '\0'; j++) {

					if (data[j] == '(' && data[j + 1] == ')') {
						j += 1;
						continue;
					}

					if (data[j] == '(') {
						opened += 1;
					}
					else {
						opened -= 1;
					}

					if (opened == 0) {
						steel[steel_index][0] = i;
						steel[steel_index][1] = j;
						steel_index++;
						break;
					}
				}
			}
		}
	}
}



//타임아웃나는 해결책 2
#include <stdio.h>
#define MAX 100001
int getCount(char *input, int start);
int main() {
	
	int count = 0;
	char input[MAX];
	scanf("%s", &input);

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '(') {
			count += getCount(input, i);
		}
	}

	printf("%d\n", count);

	return 0;
}


int getCount(char *input, int start) {
	int opened = 0;
	int count = 0;
	int laser_count = 0;

	for (int i = start; input[i] != '0'; i++) {
		if (i == start && input[i] == ')') return 0;//break;

		if (input[i] == '(') {
			opened += 1;
			count++;
		}
		else {
			opened -= 1;
			if (input[i - 1] == '(') {
				laser_count++;
			}
		}
		if (opened == 0) {
			break;
		}
	}

	if (count == laser_count) count = 0;
	else count = laser_count + 1;

	return count;
}

