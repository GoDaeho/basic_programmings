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

HeapType* create() // �������� �޷θ��� ��ȯ�Ͽ� ������ �����ϴ� �Լ�
{
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) // �ʱ�ȭ �Լ�
{
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) //���� ���� �Լ� ( h�� item ����)
{
	int i;
	i = ++(h->heap_size); // ���� ũ�⸦ �ϳ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { // i�� ��Ʈ ��尡 �ƴϰ� i��° ��尡 i�� �θ� ��庸�� Ŭ ��
		h->heap[i] = h->heap[i / 2]; //i��° ���� �θ� ��带 ��ȯ
		i /= 2; //�� ���� ���� �ö�
	}
	h->heap[i] = item; //���ο� ��带 ����
}
element delete_max_heap(HeapType* h) // ���� ���� �Լ�
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; // ��Ʈ ��尪�� ��ȯ�ϱ� ���� item���� ���� �ű�
	temp = h->heap[(h->heap_size)--]; // ������ ũ�⸦ �ϳ� ����
	parent = 1;
	child = 2;
	while (child <= h->heap_size) { // ���� ����� �ڽ��� �� ū �ڽĳ�� ã��
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if ((temp.key >= h->heap[child].key))
			break;
		h->heap[parent] = h->heap[child]; // �� ���� �Ʒ��� ������
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n) // ���� ���� �Լ�
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
	printf("������ Ű : %d\n", a4.key);
	a5 = delete_max_heap(heap);
	printf("������ Ű : %d\n", a5.key);
	a6 = delete_max_heap(heap);
	printf("������ Ű : %d\n", a6.key);

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