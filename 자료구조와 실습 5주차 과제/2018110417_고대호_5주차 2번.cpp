#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char practice[100];
    char key;  //���� ����

	printf("������ Ÿ�ڸ� �Է��ϼ��� : ");
	fgets(practice, 100, stdin); //fgets�Լ��� �̿��ؼ� ������ Ÿ�ڸ� �Է¹���
    printf("Ÿ�ڸ� �Է��ϼ���\n");

    for (int i = 0; i < strlen(practice)-1; i++)  // �Է¹��� Ÿ�ڸ� strlen�� ����Ͽ� �������� ����, practice[0]���� �����ϱ� ������ -1�� ����
    {
        key = _getch(); //_getch()�Լ��� �̿��Ͽ� �ѱ��ھ� �Է� ����
        if (key != practice[i]) { 
            printf("\a"); 
            i--; //�Է��� Ű�� ������ Ÿ�ڿ� �ٸ��� ������� �߻��ϰ�, �ٽ� �Է��ؾ� �ϱ� ������ i-1�� ����
            continue;
        }
        printf("%c", key); // �°� �Է� �Ǿ����� �Է��� Ű�� ���
    }
    
    printf("\nŸ�� ������ �Ϸ��Ͽ����ϴ�.");
    return 0;
}