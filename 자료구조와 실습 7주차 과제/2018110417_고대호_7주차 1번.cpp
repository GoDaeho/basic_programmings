#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double Average(int* arr,int a) // arr[a]���� ���� ��� ���ϴ� �Լ� ����
{
	double sum = 0;
	double avg;

	for (int i = 0; i < a + 1; i++)
		sum += arr[i];   // for���� ����Ͽ� arr[0] ���� arr[a] ������ �� ���ϱ�

	avg = sum / (a + 1); // �迭�� 0���� ���Ƿ�, ����� ���ϱ����� sum�� (a+1)�� ����
	return avg;
}

int main()
{
	int A[10];
	printf("�迭�� �Է����ּ��� : ");
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &A[i]); //�迭�� �Է¹ޱ�
	}
	
	printf("Avr ���\n");
	for (int i = 0; i < 9;i++)
	{
		printf("Avr[%d] : %.1f\n", i, Average(A, i));
	}
	return 0;
}
