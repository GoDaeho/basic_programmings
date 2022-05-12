#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { 
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) //���� ���� ����Ʈ �ʱ�ȭ �Լ�
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_doubly_list(DListNode* phead) // ���� ���� ����Ʈ�� ��带 ���
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void Insert(DListNode* before, element data) // ���� �Լ�(before ����� �����ʿ� data ����)
{
	DListNode* newnode = (DListNode*)(malloc(sizeof(DListNode)));
	newnode->data = data;
	newnode->llink = before;
	newnode -> rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void Delete(DListNode* head, DListNode* removed) //���� �Լ�(removed ��� ����)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void search(DListNode* head, element data) //Ž�� �Լ�
{
	DListNode* p;
	int k = 0;
	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data)
		{
			k = 1;
			break;
		}
	}
	if (k == 1)
		printf("ã������ �ϴ� ���� ����");
	else
		printf("ã������ �ϴ� ���� �������� ����");
	
}
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");
	for (int i = 0; i < 5;i++) {
		Insert(head, i); // ���� �Լ� Ȯ��
		print_doubly_list(head); 
	}
	search(head, 4); // Ž�� �Լ� Ȯ��
	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_doubly_list(head);
		Delete(head, head->rlink); // ���� �Լ� Ȯ��
	}
	free(head);
	return 0;
}