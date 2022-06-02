#include <stdio.h>
#define SIZE 8

void QuickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2]; //����� pivot ����
	int temp;
	do
	{
		while (arr[left] < pivot) //left�� pivot���� ū ���̳� pivot�� ���� �� ����
			left++;
		while (arr[right] > pivot) //right�� pivot���� ���� ���̳� pivot�� ���� �� ����
			right--;
		if (left <= right)    //left�� right���� ���ʿ� ������ swap
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp; //left ���������� ��ĭ, right �������� ��ĭ
			left++;
			right--;
		}
	} while (left <= right); 
	if (L < right) {
		QuickSort(arr, L, right); 
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
	if (left < R) {
		QuickSort(arr, left, R);
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
}

int main() {
	int i;
	int arr[SIZE] = { 5,1,6,3,4,2,8,7 };
	for (i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");

	QuickSort(arr, 0, SIZE - 1);

	return 0;
}