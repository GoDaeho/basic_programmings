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
		printf("������ �°� �Է�");
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
	for (int i = 1; i < limit + 1; i++) // �ݺ����� ����Ͽ� i�� a�ε� �������� b�ε� �������� i�� a�� b�� ����� �̹Ƿ� ������� ������ count�� +1 ���ش�.
		if (i % a == 0 && i % b == 0)
			count++;

	return count;
}
int com_fac(int a, int b)
{
	int limit = a * b;
	int count = 0;
	for (int i = 1; i < limit + 1; i++) //�ݺ����� ����Ͽ� a�� i�ε� �������� b�� i�� �������� i�� a�� b�� ����� �̹Ƿ� ������� ������ count�� +1 ���ش�.
		if (a % i == 0 && b % i == 0)
			count++;

	return count;
}
int main()
{
	func(4984, 215);
	printf("������� ���� : %d��\n", com_mul(75, 2136));
	printf("������� ���� : %d��", com_fac(75, 2136));
	return 0;
}