#include <stdio.h>

void Recursive(int n)
{
    if(n < 1)  
        return ;                 // n�� 0�� �� ��� �Լ� ����

    Recursive(n/2);             // ����Լ��� n/2�� ���� -> 100 > 50 > 25 > 12 > 6 > 3 > 1 > 0

    printf("%d ", n);

}


int main()
{
    int n;
    //scanf("%d", &n);
    n = 100;

    Recursive(n);
    return 0;
}