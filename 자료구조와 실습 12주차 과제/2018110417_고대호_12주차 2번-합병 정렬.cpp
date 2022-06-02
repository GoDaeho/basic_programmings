#include <stdio.h>
#define SIZE 8

int sorted[SIZE]; // ������ �迭 ������ �߰� ����

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
	} // ���� ���ĵ� �迭 �պ�

	if (i > mid) {
		for (l = j; l <= right;l++) {
			sorted[k++] = arr[l];
		}
	}
	else {
		for (l = i;l <= mid;l++)
			sorted[k++] = arr[l];
	}// ���� �ִ� ���� ����
	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void MergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //�߰� ��ġ�� ����Ͽ� �迭 ����
		MergeSort(arr, left, mid); //�� �迭 ����
		MergeSort(arr, mid + 1, right); // �� �迭 ����
		Merge(arr, left, mid, right); // ���ĵ� �迭 ����
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
}//�պ�����

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