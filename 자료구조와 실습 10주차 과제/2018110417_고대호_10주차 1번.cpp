#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right; 
}TreeNode;

TreeNode* search(TreeNode* node, int key) // Ž�� ���� �Լ�
{
	if (node == NULL) // Ʈ���� �����̸� ���� ��ȯ
		return NULL;
	if (key == node->key)  // �־��� Ű���� ����� Ű���� ������ Ž���� �����ϰ� ��尪 ��ȯ
		return node;
	else if (key < node->key) //�־��� Ű���� ����� Ű������ ������ Ž���� �ٽ� ���� ���� ����
		return search(node->left, key);
	else
		return search(node->right, key); //�־��� Ű���� ����� Ű������ ũ�� Ž���� �ٽ� ������ ���� ����
}
TreeNode* new_node(int item) // �������� �޸𸮸� �Ҵ��Ͽ� ���ο� ��带 �����ϰ� ��ȯ�ϴ� �Լ�
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key) //���� ���� �Լ�
{
	if (node == NULL)
		return new_node(key); // Ʈ���� �����̸� ���ο� ��� ��ȯ
	if (key < node->key)
 		node->left = insert_node(node->left, key); // Ʈ���� ������ �ƴϸ� ��ȯ������ Ʈ���� ������
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node; //����� ��Ʈ ��ȯ
}
TreeNode* min_value_node(TreeNode* node) // �ּ� Ű���� ������ ��带 ã�� ��ȯ�ϴ� �Լ�
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) // ���� ���� �Լ�
{
	if (root == NULL) 
		return root;
	if (key < root->key) 
		root->left = delete_node(root->left, key); // Ű���� ��Ʈ���� ������ ���� ����Ʈ���� ����
	else if (key > root->key)
		root->right = delete_node(root->right, key); // Ű���� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
	else {
		if (root->left == NULL) {  // �����Ϸ��� ��尡 �ܸ� ����� ���
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { // �����Ϸ��� ��尡 �ϳ��� ����Ʈ���� ������ �ִ� ���
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right); //�����Ϸ��� ��尡 �ΰ��� ����Ʈ���� ������ �ִ� ���

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
void inorder(TreeNode* root) // ���� ��ȸ
{
	if (root) {
		inorder(root->left); // ���� ����Ʈ�� ��ȸ
		printf("[%d]", root->key); // ��� �湮
		inorder(root->right); // ������ ����Ʈ�� ��ȸ
	}
}

void preorder(TreeNode* root) // ���� ��ȸ
{
	if (root) {
		printf("[%d]", root->key); // ��� �湮
		preorder(root->left); // ���� ����Ʈ�� ��ȸ
		preorder(root->right); // ������ ����Ʈ�� ��ȸ
	}
}

void postorder(TreeNode* root) //���� ��ȸ
{
	if (root) {
		inorder(root->left); // ���� ����Ʈ�� ��ȸ
		inorder(root->right); // ������ ����Ʈ�� ��ȸ
		printf("[%d]", root->key); // ��� �湮
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

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� :");
	inorder(root);
	printf("\n");
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� :");
	preorder(root);
	printf("\n");
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� :");
	postorder(root);
	printf("\n\n");
	if (search(root, 1094) != NULL)
		printf("���� Ž��Ʈ������ 1094�� �߰��� \n");
	else
		printf("���� Ž��Ʈ������ 1094�� �߰߸��� \n");
	return 0;
}

