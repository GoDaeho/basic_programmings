#include <stdio.h>

int addication(int n)
{
    if (n <= 2)      // 3�ױ��� 0,1,2 �̹Ƿ� n�� 2�����̸�
        return n;    // n�� ��ȯ��
    else
        return addication(n - 3) + addication(n - 2) + addication(n - 1); // n�� 3�̻��� ��쿡�� ���� �� ���� ���� ��ȯ�ϰ� ��
}


void func(int n)
{
    for (int i = 0; i < n;i++)
    {
        printf("%d ", addication(i)); //ù° �׺��� n�� ���� ���
    }
}

int main()
{
    func(7);
}

