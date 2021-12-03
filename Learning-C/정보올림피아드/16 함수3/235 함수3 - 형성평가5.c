#include <stdio.h>

int cnt = 0;

void Rec(int n)
{
    if(n == 1) {
        printf("%d", cnt);
        return ;
    }

    if(n % 2 == 0) {
        cnt++;
        Rec(n / 2);
    }
    else if(n % 2 != 0) {
        cnt++;
        Rec(n / 3);
    }
}

int main()
{
    long n;
    scanf("%d", &n);
    Rec(n);

    return 0;
}