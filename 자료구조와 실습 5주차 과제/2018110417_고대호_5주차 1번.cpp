#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	FILE* fp = NULL;
	int c, count = 0;
	int countspace = 0;
	int line = 1;
	char file1[100];
	char buffer[1000];

	printf("���� �̸��� �Է��Ͻÿ�:  ");
	scanf("%s", file1); // ������ ���� �Է�

	if ((fp = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);  // ������ ���ϰ� �̸��� �ٸ��� ���� ���ٰ� ���
	}
	while ((c = fgetc(fp)) != EOF)
	{
		if (isprint(c))
			count++; // ���� ������ ���� �� ����
		if (isspace(c) == 0)
			countspace++; // ���� ������ ���� �� ����
		if (c == '\n') 
			line++; // �ټ� ����
	}
	if (0 == fopen_s(&fp, file1, "rt")) {
		while (fgets(buffer, line, fp) != NULL)
			printf("%s", buffer); //�ؽ�Ʈ ���� ��ü ���� ���
		printf("\n");
	}
	printf("���� ��(��������) : %d\n���� ��(��������) : %d\n�� ��:%d", count, countspace, line);
	return 0;
}