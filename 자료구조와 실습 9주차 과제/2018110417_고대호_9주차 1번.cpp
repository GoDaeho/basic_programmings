#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void Creates(StackType *s) //스택 생성 함수
{
	s->top = -1;
}
int is_empty(StackType* s)  //스택 공백 검출 함수
{
	return (s->top == -1);  //공백이면 top이 -1
}
int is_full(StackType* s) // 스택 포화 검출 함수
{
	return (s->top == (MAX_STACK_SIZE - 1)); //포화면 top이 SIZE-1
}
void push(StackType* s, element item) //삽입 함수
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 상태\n");
		return; //포화상태에는 삽입 불가능
	}
	else
		s->data[++(s->top)] = item; // top자리에 item 삽입
}
element pop(StackType* s) //삭제 함수
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 상태\n");
		exit(1); // 공백상태에서는 삭제 불가능
	}
	else
		return s->data[(s->top)--]; // pop연산을 진행했을 때 삭제하는 원소 즉 top자리에 있는 원소를 반환
}
int main(void)
{
	StackType s;
	Creates(&s); // 스택 생성 함수를 통한 스택 생성
	if (is_empty)
		printf("공백 상태 입니다.\n"); // 공백 상태 검출 함수 확인
	push(&s, 1);
	push(&s, 3);
	push(&s, 5);
	push(&s, 7);
	push(&s, 9); //삽임 함수 확인
	if (is_full)
		printf("포화 상태 입니다.\n");  //포화 상태 검출 함수 확인
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s)); // 삭제 함수 확인
}