#include <stdio.h>
#define SIZE 8

int sorted[SIZE]; // 분할한 배열 저장할 추가 공간

void Merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];;
	} // 분할 정렬된 배열 합병

	if (i > mid) {
		for (l = j; l <= right;l++) {
			sorted[k++] = arr[l];
		}
	}
	else {
		for (l = i;l <= mid;l++)
			sorted[k++] = arr[l];
	}// 남아 있는 값들 복사
	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void MergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //중간 위치를 계산하여 배열 분할
		MergeSort(arr, left, mid); //앞 배열 정렬
		MergeSort(arr, mid + 1, right); // 뒤 배열 정렬
		Merge(arr, left, mid, right); // 정렬된 배열 결합
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
}//합병정렬

int main() {
	int i;
	int arr[SIZE] = { 5,1,6,3,4,2,8,7 };;
	for (i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");

	MergeSort(arr, 0, SIZE - 1);
	for (i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}

	return 0;
}