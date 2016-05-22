#include <stdio.h>
#define MAX 100

int data[MAX + 1][MAX + 1];
int visited[MAX + 1];

void clearChecked(int start, int duration){
	for (int i = start; i < start+duration; ++i){
		visited[i] = 0;
	}
}
void setChecked(int start, int duration){
	//setChecked
	for (int i = start; i < start + duration; ++i){
		visited[i] = 1;
	}
}

int checkStart(int start, int duration){

	for (int i = start; i < start + duration; ++i){
		if (visited[i] != 0) {
			return 0;
		}
	}
	return 1;
}


int main(void)
{
	int T;
	
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){

		int N, L1, L2, L3, P1, P2, P3;
		scanf("%d %d %d %d %d %d %d", &N, &L1, &L2, &L3, &P1, &P2, &P3);

		for (int i = 0; i < N; ++i){
			scanf("%d %d", &data[i][0], &data[i][1]);
		}

		/// Main Algorithm.

		int x, y, z; // start time for each advertisement
		int Answer = 0;
		for (x = 0; x <= 50; ++x){
			if (!checkStart(x, L1)) continue;
			setChecked(x, L1);
			for (y = 0; y <= 50; ++y){
				if (!checkStart(y, L2)) continue;
				setChecked(y, L2);
				for (z = 0; z <= 50; ++z){
					if (!checkStart(z, L3)) continue;
					setChecked(z, L3);
					//x,y,z 결정완료, calculate for the points.

					int point = 0;
					int totalPoint = 0;
					for (int i = 0; i < N; ++i){
						point = 0;
						if (data[i][0] <= x && (data[i][0] + data[i][1]) >= x + L1){
							if (P1 > point){
								point = P1;
							}
						}

						if (data[i][0] <= y && (data[i][0] + data[i][1]) >= y + L2){
							if (P2 > point){
								point = P2;
							}
						}

						if (data[i][0] <= z && (data[i][0] + data[i][1]) >= z + L3){
							if (P3 > point){
								point = P3;
							}
						}

						totalPoint += point;
					}

					if (totalPoint > Answer) {
						Answer = totalPoint;
					}
					clearChecked(z, L3);
				}
				clearChecked(y, L2);
			}
			clearChecked(x, L1);
		}

		printf("#%d %d\n", test_case, Answer);
	}

	return 0;
}
