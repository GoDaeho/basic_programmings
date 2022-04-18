#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double Average(int* arr,int a) // arr[a]까지 누적 평균 구하는 함수 정의
{
	double sum = 0;
	double avg;

	for (int i = 0; i < a + 1; i++)
		sum += arr[i];   // for문을 사용하여 arr[0] 부터 arr[a] 까지의 합 구하기

	avg = sum / (a + 1); // 배열은 0부터 세므로, 평균을 구하기위해 sum을 (a+1)로 나눔
	return avg;
}

int main()
{
	int A[10];
	printf("배열을 입력해주세요 : ");
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &A[i]); //배열을 입력받기
	}
	
	printf("Avr 출력\n");
	for (int i = 0; i < 9;i++)
	{
		printf("Avr[%d] : %.1f\n", i, Average(A, i));
	}
	return 0;
}
