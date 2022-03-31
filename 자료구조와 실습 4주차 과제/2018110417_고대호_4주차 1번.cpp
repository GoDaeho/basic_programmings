#include <stdio.h>

void func(int* arr, int size)
{
	double avg;
	int count = 0;
	int result = 0; //변수 초기화

	for (int i = 0; i < size; i++)
	{
		result += arr[i];  //for문을 사용해서 배열 값의 전체 합을 구함
	}
	avg = double (result) / size; //전체 합을 배열 사이즈로 나눠 평균을 구함

	for (int i = 0; i < size; i++)
	{
		if (avg > arr[i])
			count++;  // if문을 사용해서 평균보다 작을때 마다 count를 추가해서 평균보다 작은 원소의 개수를 셈
	}
	printf("평균 : %.2f, 평균보다 작은 원소 : %d", avg, count);
}

int main()
{
	int arr[] = { 2,4,8,11,15,26,31 };
	int size = sizeof(arr) / sizeof(int);

	func(arr, size);

}
