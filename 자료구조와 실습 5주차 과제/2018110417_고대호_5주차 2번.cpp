#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char practice[100];
    char key;  //변수 설정

	printf("연습할 타자를 입력하세요 : ");
	fgets(practice, 100, stdin); //fgets함수를 이용해서 연습할 타자를 입력받음
    printf("타자를 입력하세요\n");

    for (int i = 0; i < strlen(practice)-1; i++)  // 입력받은 타자를 strlen을 사용하여 몇자인지 세고, practice[0]부터 시작하기 때문에 -1을 해줌
    {
        key = _getch(); //_getch()함수를 이용하여 한글자씩 입력 받음
        if (key != practice[i]) { 
            printf("\a"); 
            i--; //입력한 키가 연습할 타자와 다르면 경고음을 발생하고, 다시 입력해야 하기 때문에 i-1을 해줌
            continue;
        }
        printf("%c", key); // 맞게 입력 되었으면 입력한 키를 출력
    }
    
    printf("\n타자 연습을 완료하였습니다.");
    return 0;
}