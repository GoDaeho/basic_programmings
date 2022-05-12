#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void Creates(QueueType* q) // ť ���� �Լ�
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) // ���� ���� ���� �Լ�
{
	return (q->front == q->rear); // front�� rear�� ������ ����
}
int is_full(QueueType* q)  // ��ȭ ���� ���� �Լ�
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // ����ť �̱� ������ rear+1�� size�� ���� �������� front�� ������ ��ȭ

}
void queue_print(QueueType* q) //ť ��� �Լ�
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;  
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE); // ù��°�׿��� front + 1��° �ڸ� ���� �̹Ƿ� i+1�� ���ְ� ����ť�̹Ƿ� SIZE�� ������
			printf("%d | ", q->data[i]); 
			if (i == q->rear) //rear ���� ����ϸ� ��� ����� ���̹Ƿ� break
				break;
		} while (i != q->front);
	}
	printf("\n");
}
void addQ(QueueType* q, element item) // ť ���� �Լ� ����
{
	if (is_full(q))
		printf("ť�� ��ȭ�����Դϴ�."); // ��ȭ���¿��� ������ �� ����
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; 
	q->data[q->rear] = item; //rear+1 �ڸ��� item ����
}
element deleteQ(QueueType* q) // ť ���� �Լ� ����
{
	if (is_empty(q))
		printf("ť�� ��������Դϴ�"); //������¿��� ������ �� ����
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front]; // ���� �Լ� �̹Ƿ� front���� �����ϰ� front�� front+1�� �̵�
}
int main(void)
{
	QueueType queue;
	int element;

	Creates(&queue);
	printf("������ �߰��ܰ�\n");
	while (!is_full(&queue))
	{
		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", &element);
		addQ(&queue, element); //���� �Լ� Ȯ��
		queue_print(&queue);  //��� �Լ� Ȯ��
	}
	if(is_full)
		printf("ť�� ��ȭ�����Դϴ�.\n\n"); // ��ȭ ���� �Լ� Ȯ��
	printf("������ ���� �ܰ�\n");
	while (!is_empty(&queue))
	{
		element = deleteQ(&queue); //���� �Լ� Ȯ��
		printf("������ ���� : %d \n", element);
		queue_print(&queue);
	}
	if(is_empty)
		printf("ť�� ��������Դϴ�. \n"); // ���� ���� �Լ� Ȯ��
	return 0;
}