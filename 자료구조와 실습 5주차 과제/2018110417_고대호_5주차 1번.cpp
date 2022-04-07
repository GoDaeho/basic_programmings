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

	printf("파일 이름을 입력하시오:  ");
	scanf("%s", file1); // 실행할 파일 입력

	if ((fp = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "원본 파일 %s을 열 수 없습니다.\n", file1);
		exit(1);  // 실행할 파일과 이름이 다르면 열수 없다고 출력
	}
	while ((c = fgetc(fp)) != EOF)
	{
		if (isprint(c))
			count++; // 공백 포함한 문자 수 세기
		if (isspace(c) == 0)
			countspace++; // 공백 제외한 문자 수 세기
		if (c == '\n') 
			line++; // 줄수 세기
	}
	if (0 == fopen_s(&fp, file1, "rt")) {
		while (fgets(buffer, line, fp) != NULL)
			printf("%s", buffer); //텍스트 파일 전체 내용 출력
		printf("\n");
	}
	printf("문자 수(공백포함) : %d\n문자 수(공백제외) : %d\n줄 수:%d", count, countspace, line);
	return 0;
}