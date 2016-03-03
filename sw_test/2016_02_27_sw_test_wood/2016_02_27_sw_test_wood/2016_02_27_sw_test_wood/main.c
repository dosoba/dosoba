
#include <stdio.h>
#define MAX_BOX 10
#define MAX_WOOD 20

void combination(int set[], int set_size, int n, int k, int index);
void print_arr(int arr[], int arr_size);
void getMaxProfit(int set[], int set_size);
int getMaxWood(int set[], int set_size);

int c;							//Ŀ�� ���
int v;							//���� ����
int boxes[MAX_BOX];				//�ڽ� ����
int woods[MAX_BOX][MAX_WOOD];	//�����丷 ����
int maxProfit;					//�ִ� ����
int maxWood;					//�ִ���� �����丷

int main() {
	int test_case;
	int T;

	int n;				// ��ü �ڽ��� ����
	int set[MAX_BOX];	// ��ü �ڽ��� ���� �κ����� ����

	scanf("%d", &T);	// ��ü �׽�Ʈ ���̽� �Է�

	for (test_case = 1; test_case <= T; test_case++) {
		maxProfit = 0;

		scanf("%d", &n);		// ��ü �ڽ� ���� �Է�
		scanf("%d %d", &c, &v);	// Ŀ�ú��, ���� ���� �Է�

		//��ü �ڽ��� ���� �� �����丷 ���� �� �����丷 ���� �Է�
		for (int i = 0; i < n; i++) {
			scanf("%d", &boxes[i]);
			for (int j = 0; j < boxes[i]; j++) {
				scanf("%d", &woods[i][j]);
			}
		}

		combination(set, 0, n, 3, 0);
		printf("#%d %d\n", test_case, maxProfit);
	}

	return 0;
}

// 3���ڽ� �߿��� ���� ū ������ ���������� ã�� �Լ�
int getMaxWood(int set[], int set_size) {
	int i;
	int j;

	int maxWood = 0;
	for (i = 0; i < set_size; i++) {
		for (j = 0; j < boxes[set[i]]; j++) {
			if (woods[set[i]][j] > maxWood) {
				maxWood = woods[set[i]][j];
			}
		}
	}
	return maxWood;
}

// �ִ����� ã�� �Լ�
void getMaxProfit(int set[], int set_size) {
	int i;
	int j;
	int k;

	int profit;
	int counts_woods;
	int counts_costs;

	int counts_woods2;
	int profit2;

	maxWood = getMaxWood(set, set_size);

	for (i = 1; i <= maxWood; i++) {
		profit = 0;
		counts_woods = 0;
		counts_costs = 0;

		profit2 = 0;
		counts_woods2 = 0;

		for (j = 0; j < set_size; j++) {
			for (k = 0; k < boxes[set[j]]; k++) {	//1. ������ ������ ���
				counts_woods += woods[set[j]][k] / i;
				counts_costs += (woods[set[j]][k] / i) - 1;

				if ((woods[set[j]][k] % i) != 0) {
					counts_costs++;
				}
			}

			for (k = 0; k < boxes[set[j]]; k++) {	//2. ������ ������ ������ ���
				if (i == woods[set[j]][k]) {
					counts_woods2++;
				}
			}
		}
		profit = (counts_woods * i * v) - (counts_costs * c);
		profit2 = (counts_woods2 * i * v);
		//printf("unit : %d, ", i);
		//printf("profit : %d, ", profit);
		//print_arr(set, set_size);

		if (profit < profit2) {
			profit = profit2;
		}

		if (maxProfit < profit) {
			maxProfit = profit;
			//print_arr(set, set_size);
		}
	}
}

// n���� �ڽ� �߿� 3���� �����ϱ� ���ؼ� ������ ���� (nCk)
void combination(int set[], int set_size, int n, int k, int index) {
	if (k == 0) {
		//print_arr(set, set_size);
		getMaxProfit(set, set_size);
	}
	else if (index == n) {
		return;
	}
	else {
		set[set_size] = index;
		combination(set, set_size + 1, n, k - 1, index + 1);
		combination(set, set_size, n, k, index + 1);
	}
}

// ������ ����� �ۼ��� �Ǿ����� ����ϴ� �Լ�
void print_arr(int arr[], int arr_size) {
	int i;
	for (i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}