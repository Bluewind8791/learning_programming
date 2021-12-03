#include <stdio.h>

void Recursive(int n)
{
    if(n < 1)  
        return ;                 // n이 0이 될 경우 함수 종료

    Recursive(n/2);             // 재귀함수로 n/2로 나눔 -> 100 > 50 > 25 > 12 > 6 > 3 > 1 > 0

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