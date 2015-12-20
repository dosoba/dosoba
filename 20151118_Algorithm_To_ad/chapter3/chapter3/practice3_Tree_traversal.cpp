/**********************************
* 제목 : 이진트리를 전/중/후위 순회하고 방문한 노드의 번호를 출력하시오.
* 페이지 : 130
* 코드 : c
**********************************/
#include <stdio.h>

#define MAX 64

int tree[MAX];

void InitTree();
int FindIndex(int target);
void MakeTree(int nodes);
void print_tree();

void PreorderTraversal(int idxNode);
void InorderTraversal(int idxNode);
void PostorderTraversal(int idxNode);
void Visit(int idxNode);

int main(int argc, char argv[]) {

	int T;
	int nodes;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &nodes);

		InitTree();
		MakeTree(nodes);

		//printf("#%d\n", test_case);
		printf("# Preorder \n");
		PreorderTraversal(1);

		printf("\n# Inorder \n");
		InorderTraversal(1);

		printf("\n# Postorder \n");
		PostorderTraversal(1);
	}

	return 0;
}

// Make tree functions
void InitTree(){
	int i = 1;

	while (i < MAX) {
		tree[i] = 0;
		i++;
	}
}

int FindIndex(int target) {
	int idx = 1;

	while (idx < MAX) {
		if (target == tree[idx]) {
			return idx;
		}
		idx++;
	}
	return idx;
}

void MakeTree(int nodes) {

	int parent;
	int child;
	int idx = 1;

	int i = 1;
	while (i < nodes) {
		scanf("%d %d ", &parent, &child);

		if (i == 1) {
			tree[idx] = parent;
		}

		idx = FindIndex(parent);
		if (tree[idx * 2] == 0) {
			tree[idx * 2] = child;
		}
		else {
			tree[idx * 2 + 1] = child;
		}

		i++;
	}
}

// printf tree except '0' values
void print_tree() {
	int i = 1;
	while (i < MAX) {
		if (tree[i] != 0) {
			printf("(%d %d) ", i, tree[i]);
		}
		i++;
	}
	putchar('\n');
}

// binary tree funtions
void PreorderTraversal(int idxNode) {
	if (idxNode < MAX) {
		Visit(idxNode);
		PreorderTraversal(idxNode * 2);
		PreorderTraversal(idxNode * 2 + 1);
	}
}

void InorderTraversal(int idxNode) {
	if (idxNode < MAX) {
		InorderTraversal(idxNode * 2);
		Visit(idxNode);
		InorderTraversal(idxNode * 2 + 1);
	}
}

void PostorderTraversal(int idxNode) {
	if (idxNode < MAX) {
		PostorderTraversal(idxNode * 2);
		PostorderTraversal(idxNode * 2 + 1);
		Visit(idxNode);
	}
}

void Visit(int idxNode) {
	if (tree[idxNode] != 0) {
		printf("%d ", tree[idxNode]);
	}
}

//input
1
13
1 2 1 3 2 4 3 5 3 6 4 7 5 8 5 9 6 10 6 11 7 12 11 13
//output
# Preorder
1 2 4 7 12 3 5 8 9 6 10 11 13
# Inorder
12 7 4 2 1 8 5 9 3 10 6 13 11
# Postorder
12 7 4 2 8 9 5 10 13 11 6 3 1