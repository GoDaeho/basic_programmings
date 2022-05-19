#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right; 
}TreeNode;

TreeNode* search(TreeNode* node, int key) // 탐색 연산 함수
{
	if (node == NULL) // 트리가 공백이면 공백 반환
		return NULL;
	if (key == node->key)  // 주어진 키값이 노드의 키값과 같으면 탐색을 종료하고 노드값 반환
		return node;
	else if (key < node->key) //주어진 키값이 노드의 키값보다 작으면 탐색은 다시 왼쪽 부터 시작
		return search(node->left, key);
	else
		return search(node->right, key); //주어진 키값이 노드의 키값보다 크면 탐색은 다시 오른쪽 부터 시작
}
TreeNode* new_node(int item) // 동적으로 메모리를 할당하여 새로운 노드를 생성하고 반환하는 함수
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key) //삽입 연산 함수
{
	if (node == NULL)
		return new_node(key); // 트리가 공백이면 새로운 노드 반환
	if (key < node->key)
 		node->left = insert_node(node->left, key); // 트리가 공백이 아니면 순환적으로 트리를 내려감
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node; //변경된 루트 반환
}
TreeNode* min_value_node(TreeNode* node) // 최소 키값을 가지는 노드를 찾아 반환하는 함수
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) // 삭제 연산 함수
{
	if (root == NULL) 
		return root;
	if (key < root->key) 
		root->left = delete_node(root->left, key); // 키값이 루트보다 작으면 왼쪽 서브트리에 존재
	else if (key > root->key)
		root->right = delete_node(root->right, key); // 키값이 루트보다 크면 오른쪽 서브 트리에 존재
	else {
		if (root->left == NULL) {  // 삭제하려는 노드가 단말 노드인 경우
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { // 삭제하려는 노드가 하나의 서브트리만 가지고 있는 경우
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right); //삭제하려는 노드가 두개의 서브트리를 가지고 있는 경우

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
void inorder(TreeNode* root) // 중위 순회
{
	if (root) {
		inorder(root->left); // 왼쪽 서브트리 순회
		printf("[%d]", root->key); // 노드 방문
		inorder(root->right); // 오른쪽 서브트리 순회
	}
}

void preorder(TreeNode* root) // 전위 순회
{
	if (root) {
		printf("[%d]", root->key); // 노드 방문
		preorder(root->left); // 왼쪽 서브트리 순회
		preorder(root->right); // 오른쪽 서브트리 순회
	}
}

void postorder(TreeNode* root) //후위 순회
{
	if (root) {
		inorder(root->left); // 왼쪽 서브트리 순회
		inorder(root->right); // 오른쪽 서브트리 순회
		printf("[%d]", root->key); // 노드 방문
	}
}
int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 35);
	root = insert_node(root, 18);
	root = insert_node(root, 68);
	root = insert_node(root, 7);
	root = insert_node(root, 26);
	root = insert_node(root, 99);
	root = insert_node(root, 3);
	root = insert_node(root, 30);
	root = delete_node(root, 18);
	root = delete_node(root, 7);
	root = delete_node(root, 68);
	root = delete_node(root, 99);
	root = insert_node(root, 1094);
	root = delete_node(root, 35);

	printf("이진 탐색 트리 중위 순회 결과 :");
	inorder(root);
	printf("\n");
	printf("이진 탐색 트리 전위 순회 결과 :");
	preorder(root);
	printf("\n");
	printf("이진 탐색 트리 후위 순회 결과 :");
	postorder(root);
	printf("\n\n");
	if (search(root, 1094) != NULL)
		printf("이진 탐색트리에서 1094을 발견함 \n");
	else
		printf("이진 탐색트리에서 1094을 발견못함 \n");
	return 0;
}

