#include <stdio.h>

void func(int* arr, int size)
{
	double avg;
	int count = 0;
	int result = 0; //���� �ʱ�ȭ

	for (int i = 0; i < size; i++)
	{
		result += arr[i];  //for���� ����ؼ� �迭 ���� ��ü ���� ����
	}
	avg = double (result) / size; //��ü ���� �迭 ������� ���� ����� ����

	for (int i = 0; i < size; i++)
	{
		if (avg > arr[i])
			count++;  // if���� ����ؼ� ��պ��� ������ ���� count�� �߰��ؼ� ��պ��� ���� ������ ������ ��
	}
	printf("��� : %.2f, ��պ��� ���� ���� : %d", avg, count);
}

int main()
{
	int arr[] = { 2,4,8,11,15,26,31 };
	int size = sizeof(arr) / sizeof(int);

	func(arr, size);

}
