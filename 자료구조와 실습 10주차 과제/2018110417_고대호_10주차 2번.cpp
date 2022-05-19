#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() // 동적으로 메로리를 반환하여 히프를 생성하는 함수
{
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) // 초기화 함수
{
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) //삽입 연산 함수 ( h에 item 삽입)
{
	int i;
	i = ++(h->heap_size); // 히프 크기를 하나 증가
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { // i가 루트 노드가 아니고 i번째 노드가 i의 부모 노드보다 클 때
		h->heap[i] = h->heap[i / 2]; //i번째 노드와 부모 노드를 교환
		i /= 2; //한 레벨 위로 올라감
	}
	h->heap[i] = item; //새로운 노드를 삽입
}
element delete_max_heap(HeapType* h) // 삭제 연산 함수
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; // 루트 노드값을 반환하기 위해 item으로 변수 옮김
	temp = h->heap[(h->heap_size)--]; // 히프의 크기를 하나 줄임
	parent = 1;
	child = 2;
	while (child <= h->heap_size) { // 현재 노드의 자식중 더 큰 자식노드 찾기
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if ((temp.key >= h->heap[child].key))
			break;
		h->heap[parent] = h->heap[child]; // 한 레벨 아래로 내려감
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n) // 정렬 연산 함수
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n;i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}

int main(void)
{
	element a1 = { 5 }, a2 = { 13 }, a3 = { 1 };
	element a4, a5, a6;
	element list1[7] = { 3, 39, 24, 7, 28, 56, 11 };
	element list2[7] = { 16, 9, 12, 2, 4, 20, 3 };
	element list3[7] = { 7, 12, 6, 88, 60, 27, 39 };

	HeapType* heap;

	heap = create();
	init(heap);
	insert_max_heap(heap, a1);
	insert_max_heap(heap, a2);
	insert_max_heap(heap, a3);
	
	a4 = delete_max_heap(heap);
	printf("삭제한 키 : %d\n", a4.key);
	a5 = delete_max_heap(heap);
	printf("삭제한 키 : %d\n", a5.key);
	a6 = delete_max_heap(heap);
	printf("삭제한 키 : %d\n", a6.key);

	heap_sort(list1, 7);
	heap_sort(list2, 7);
	heap_sort(list3, 7);
	for (int i = 0; i < 7; i ++)
		printf("%d ", list1[i].key);
	printf("\n");
	for (int i = 0; i < 7; i++)
		printf("%d ", list2[i].key);
	printf("\n");
	for (int i = 0; i < 7; i++)
		printf("%d ", list3[i].key);
	printf("\n");
	
	return 0;
}