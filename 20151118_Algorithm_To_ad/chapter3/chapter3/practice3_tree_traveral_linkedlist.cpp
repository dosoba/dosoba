/**********************************
* 제목 : 이진트리를 전/중/후위 순회하고 방문한 노드의 번호를 출력하시오. LinkedList
* 페이지 : 130
* 코드 : c
* 진행중 : DeleteAllNode() 추가필요
**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

typedef struct node{
	Node *left;
	Node *right;
	int val;
}Node;

void InitLinkedList(Node *root);
Node* GetNode();
void DeleteNode(Node *node);
void DeleteAllNode(Node *node);//추가 중
Node* FindNode(Node *root, int searchingValue);
void MakeTree(Node *root, int N);

void PreorderTraversal(Node *root);
void InorderTraversal(Node *root);
void PostorderTraversal(Node *root);

int main(int argc, char argv[]) {

	Node *root;

	int T;
	int N;

	scanf("%d ", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d ", &N);

		root = GetNode();
		MakeTree(root, N);

		printf("# Preorder\n");
		PreorderTraversal(root->left);
		putchar('\n');

		printf("# Inorder\n");
		InorderTraversal(root->left);
		putchar('\n');

		printf("# Postorder\n");
		PostorderTraversal(root->left);
		putchar('\n');

		if (root != NULL) {
			DeleteNode(root);
			//DeleteAllNode();
		}
	}

	return 0;
}

void PostorderTraversal(Node *root) {
	if (root != NULL) {
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		if (root->val != 0) {
			printf("%d ", root->val);
		}
	}
}

void InorderTraversal(Node *root) {
	if (root != NULL) {
		InorderTraversal(root->left);
		if (root->val != 0) {
			printf("%d ", root->val);
		}
		InorderTraversal(root->right);
	}
}

void PreorderTraversal(Node *root) {
	if (root != NULL) {
		//Visit();
		//
		if (root->val != 0) {
			printf("%d ", root->val);
		}
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

void InitLinkedList(Node *root) {
	root = (Node*)malloc(sizeof(Node) * 1);
	root->left = NULL;
	root->right = NULL;
	root->val = 0;
}

Node* GetNode() {
	Node *node;
	node = (Node*)malloc(sizeof(Node) * 1);
	node->left = NULL;
	node->right = NULL;
	node->val = 0;

	return node;
}

void DeleteNode(Node *node) {
	if (node != NULL) {
		node->right = NULL;
		node->left = NULL;
		node->val = 0;

		free(node);
	}
}

void DeleteAllNode(Node *node) {

}

Node* FindNode(Node *root, int searchingValue) {
	Node *result = NULL;

	if (root->val == searchingValue) {
		result = root;
		return result;
	}

	if (root->left != NULL && result == NULL) {
		result = FindNode(root->left, searchingValue);
	}
	if (root->right != NULL && result == NULL) {
		result = FindNode(root->right, searchingValue);
	}
	return result;
}

void MakeTree(Node *root, int N) {
	int i = 0;
	int parent;
	int child;

	Node *node_parent;
	Node *node_child;

	while (i < N - 1) {
		scanf("%d %d ", &parent, &child);

		if (i == 0) {
			node_parent = GetNode();
			node_parent->val = parent;
			root->left = node_parent;
		}
		else {
			node_parent = FindNode(root, parent);
		}

		node_child = GetNode();
		node_child->val = child;

		if (node_parent->left == NULL) {
			node_parent->left = node_child;
		}
		else {
			node_parent->right = node_child;
		}

		i++;
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