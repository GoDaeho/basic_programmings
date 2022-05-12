#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void Creates(QueueType* q) // 큐 생성 함수
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) // 공백 상태 검출 함수
{
	return (q->front == q->rear); // front와 rear가 같으면 공백
}
int is_full(QueueType* q)  // 포화 상태 검출 함수
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // 원형큐 이기 때문에 rear+1을 size로 나눈 나머지가 front와 같으면 포화

}
void queue_print(QueueType* q) //큐 출력 함수
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;  
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE); // 첫번째항에는 front + 1번째 자리 부터 이므로 i+1을 해주고 원형큐이므로 SIZE로 나눠줌
			printf("%d | ", q->data[i]); 
			if (i == q->rear) //rear 까지 출력하면 모두 출력한 것이므로 break
				break;
		} while (i != q->front);
	}
	printf("\n");
}
void addQ(QueueType* q, element item) // 큐 삽입 함수 정의
{
	if (is_full(q))
		printf("큐가 포화상태입니다."); // 포화상태에선 삽입할 수 없음
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; 
	q->data[q->rear] = item; //rear+1 자리에 item 삽입
}
element deleteQ(QueueType* q) // 큐 삭제 함수 정의
{
	if (is_empty(q))
		printf("큐가 공백상태입니다"); //공백상태에선 삭제할 수 없음
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front]; // 삭제 함수 이므로 front값을 삭제하고 front를 front+1로 이동
}
int main(void)
{
	QueueType queue;
	int element;

	Creates(&queue);
	printf("데이터 추가단계\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하시오 : ");
		scanf("%d", &element);
		addQ(&queue, element); //삽입 함수 확인
		queue_print(&queue);  //출력 함수 확인
	}
	if(is_full)
		printf("큐는 포화상태입니다.\n\n"); // 포화 검출 함수 확인
	printf("데이터 삭제 단계\n");
	while (!is_empty(&queue))
	{
		element = deleteQ(&queue); //삭제 함수 확인
		printf("꺼내진 정수 : %d \n", element);
		queue_print(&queue);
	}
	if(is_empty)
		printf("큐는 공백상태입니다. \n"); // 공백 검출 함수 확인
	return 0;
}