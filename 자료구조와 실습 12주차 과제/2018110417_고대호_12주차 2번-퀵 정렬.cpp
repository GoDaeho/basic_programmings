#include <stdio.h>
#define SIZE 8

void QuickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2]; //가운데로 pivot 설정
	int temp;
	do
	{
		while (arr[left] < pivot) //left가 pivot보다 큰 값이나 pivot을 만날 때 까지
			left++;
		while (arr[right] > pivot) //right가 pivot보다 작은 값이나 pivot을 만날 때 까지
			right--;
		if (left <= right)    //left가 right보다 왼쪽에 있으면 swap
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp; //left 오른쪽으로 한칸, right 왼쪽으로 한칸
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