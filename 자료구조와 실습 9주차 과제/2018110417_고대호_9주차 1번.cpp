#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void Creates(StackType *s) //���� ���� �Լ�
{
	s->top = -1;
}
int is_empty(StackType* s)  //���� ���� ���� �Լ�
{
	return (s->top == -1);  //�����̸� top�� -1
}
int is_full(StackType* s) // ���� ��ȭ ���� �Լ�
{
	return (s->top == (MAX_STACK_SIZE - 1)); //��ȭ�� top�� SIZE-1
}
void push(StackType* s, element item) //���� �Լ�
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return; //��ȭ���¿��� ���� �Ұ���
	}
	else
		s->data[++(s->top)] = item; // top�ڸ��� item ����
}
element pop(StackType* s) //���� �Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); // ������¿����� ���� �Ұ���
	}
	else
		return s->data[(s->top)--]; // pop������ �������� �� �����ϴ� ���� �� top�ڸ��� �ִ� ���Ҹ� ��ȯ
}
int main(void)
{
	StackType s;
	Creates(&s); // ���� ���� �Լ��� ���� ���� ����
	if (is_empty)
		printf("���� ���� �Դϴ�.\n"); // ���� ���� ���� �Լ� Ȯ��
	push(&s, 1);
	push(&s, 3);
	push(&s, 5);
	push(&s, 7);
	push(&s, 9); //���� �Լ� Ȯ��
	if (is_full)
		printf("��ȭ ���� �Դϴ�.\n");  //��ȭ ���� ���� �Լ� Ȯ��
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s)); // ���� �Լ� Ȯ��
}