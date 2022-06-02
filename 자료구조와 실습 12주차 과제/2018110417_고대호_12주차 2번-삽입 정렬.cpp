#define SIZE 5
#include <stdio.h>

void Insertion_Sort(int* list) {
	int i, j, k, key;

	for (i = 1; i < SIZE;i++) {
		key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		for (j = i - 1;j >= 0 && list[j] > key; j--) { // key가 더 큰 값일 때까지
			list[j + 1] = list[j]; // 한 칸 뒤로 이동
		}
		list[j + 1] = key; //알맞은 위치에 key 삽입
		
		for (k = 0;k < SIZE;k++) {
			printf("[%d] ", list[k]);
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
	Insertion_Sort(arr);

	return 0;
}