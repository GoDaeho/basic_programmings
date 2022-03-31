#include <stdio.h>

int addication(int n)
{
    if (n <= 2)      // 3항까지 0,1,2 이므로 n이 2이하이면
        return n;    // n을 반환함
    else
        return addication(n - 3) + addication(n - 2) + addication(n - 1); // n이 3이상인 경우에는 직전 세 수의 합을 반환하게 함
}


void func(int n)
{
    for (int i = 0; i < n;i++)
    {
        printf("%d ", addication(i)); //첫째 항부터 n항 까지 출력
    }
}

int main()
{
    func(7);
}

