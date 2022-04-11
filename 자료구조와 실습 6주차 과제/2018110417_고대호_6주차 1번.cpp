#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double RandNum(double a, double b)
{
	double k = (double)rand() / (double)RAND_MAX; //  -1 �̻� 1 ������ �������� ������ �̱� ���ؼ� �����Լ��� ����Ͽ� RAND_MAX�� ������(RAND_MAX=32767)
	k = a + (b - a) * k;  //a�� b������ ������ �̱����� k ����

	return k;
}
int main()
{
	FILE* fp1 = fopen("square.txt", "w"); // square �ؽ�Ʈ ����
	srand((unsigned int)time(NULL));
	
	for (int i = 0;i < 100;i++)
	{
		double x1 = RandNum(0, 1);
		double y1 = RandNum(0, 1);  
		fprintf(fp1, "%f %f\n", x1, y1); // ������ ������ �����Լ��� ����Ͽ� x,y���� square �ؽ�Ʈ�� ����
	}
	
	FILE* fp2 = fopen("circle.txt", "w"); // circle �ؽ�Ʈ ����
	for (int i = 0;i < 100;i++)
	{
		double x2 = RandNum(0, 1);
		double y2 = RandNum(0, 1);
		
		double p = pow((x2 - 0.5), 2.0) + pow((y2 - 0.5), 2.0);
		if (p < pow(0.5, 2.0))
		{
			fprintf(fp2, "%f %f\n", x2, y2); //���ȿ� �ִ� ��쿡 �����ؾ��ϹǷ� ���� �߽ɰ��� �Ÿ��� 0.5 ������ ��쿡�� circle �ؽ�Ʈ�� ����
		}
	}
	return 0;
}