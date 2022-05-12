#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { 
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) //이중 연결 리스트 초기화 함수
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_doubly_list(DListNode* phead) // 이중 연결 리스트의 노드를 출력
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void Insert(DListNode* before, element data) // 삽입 함수(before 노드의 오른쪽에 data 삽입)
{
	DListNode* newnode = (DListNode*)(malloc(sizeof(DListNode)));
	newnode->data = data;
	newnode->llink = before;
	newnode -> rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void Delete(DListNode* head, DListNode* removed) //삭제 함수(removed 노드 삭제)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void search(DListNode* head, element data) //탐색 함수
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
		printf("찾으려고 하는 원소 존재");
	else
		printf("찾으려고 하는 원소 존재하지 않음");
	
}
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5;i++) {
		Insert(head, i); // 삽입 함수 확인
		print_doubly_list(head); 
	}
	search(head, 4); // 탐색 함수 확인
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_doubly_list(head);
		Delete(head, head->rlink); // 삭제 함수 확인
	}
	free(head);
	return 0;
}