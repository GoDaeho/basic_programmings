#include <stdio.h>

void func(int a, int b)
{
	int c, d;
	int k, answer;
	c = b % 10;
	d = b / 10;
	answer = a * b;

	if (b > 1 && b < 10)
		k = 1;
	else if (b >= 10 && b < 100)
		k = 2;
	else if (b >= 100 && b < 1000)
		k = 3;
	else if (b >= 1000 && b < 10000)
		k = 4;
	else
		k = 5;
	if (k > 4 || a >= 10000)
		printf("범위에 맞게 입력");
	else
		for (int i = 0; i < k; i++) {
			printf("%d\n", a * c);
			c = d % 10;
			d /= 10;
		}
	printf("%d\n", answer);

}

int com_mul(int a, int b)
{
	int limit = a * b;
	int count = 0;
	for (int i = 1; i < limit + 1; i++) // 반복문을 사용하여 i가 a로도 나눠지고 b로도 나눠지면 i가 a와 b의 공배수 이므로 공배수의 개수인 count를 +1 해준다.
		if (i % a == 0 && i % b == 0)
			count++;

	return count;
}
int com_fac(int a, int b)
{
	int limit = a * b;
	int count = 0;
	for (int i = 1; i < limit + 1; i++) //반복문을 사용하여 a가 i로도 나눠지고 b도 i로 나눠지면 i가 a와 b의 공약수 이므로 공약수의 개수인 count를 +1 해준다.
		if (a % i == 0 && b % i == 0)
			count++;

	return count;
}
int main()
{
	func(4984, 215);
	printf("공배수의 개수 : %d개\n", com_mul(75, 2136));
	printf("공약수의 개수 : %d개", com_fac(75, 2136));
	return 0;
}