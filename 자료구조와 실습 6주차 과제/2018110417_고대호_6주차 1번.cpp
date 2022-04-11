#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double RandNum(double a, double b)
{
	double k = (double)rand() / (double)RAND_MAX; //  -1 이상 1 이하의 유리수인 난수를 뽑기 위해서 랜덤함수를 사용하여 RAND_MAX로 나눠줌(RAND_MAX=32767)
	k = a + (b - a) * k;  //a와 b사이의 난수를 뽑기위해 k 설정

	return k;
}
int main()
{
	FILE* fp1 = fopen("square.txt", "w"); // square 텍스트 오픈
	srand((unsigned int)time(NULL));
	
	for (int i = 0;i < 100;i++)
	{
		double x1 = RandNum(0, 1);
		double y1 = RandNum(0, 1);  
		fprintf(fp1, "%f %f\n", x1, y1); // 위에서 정의한 랜덤함수를 사용하여 x,y값을 square 텍스트에 저장
	}
	
	FILE* fp2 = fopen("circle.txt", "w"); // circle 텍스트 오픈
	for (int i = 0;i < 100;i++)
	{
		double x2 = RandNum(0, 1);
		double y2 = RandNum(0, 1);
		
		double p = pow((x2 - 0.5), 2.0) + pow((y2 - 0.5), 2.0);
		if (p < pow(0.5, 2.0))
		{
			fprintf(fp2, "%f %f\n", x2, y2); //원안에 있는 경우에 저장해야하므로 원의 중심과의 거리가 0.5 이하인 경우에만 circle 텍스트에 저장
		}
	}
	return 0;
}