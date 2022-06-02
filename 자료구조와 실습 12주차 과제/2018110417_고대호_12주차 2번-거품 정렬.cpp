#include <stdio.h>
#define SIZE 5

void Bubble_Sort(int* arr) {
	int i, j, k, temp;
	for (i = 0;i < SIZE;i++) {
		for (j = 0; j < SIZE - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { //j번째와 j+1번째 비교 후 왼쪽이 더 크면 swap 
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;	
			}
		}
		for (k = 0;k < SIZE;k++) {
			printf("[%d] ", arr[k]);
		}
		printf("\n");
	}
}

int main() {
	int arr[SIZE] = { 5,2,3,1,4 };
	int i;
	for (i = 0;i < SIZE;i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");
	Bubble_Sort(arr);

	return 0;
}