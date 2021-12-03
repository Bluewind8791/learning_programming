#include <stdio.h>

void Print(int n)
{
    if(n <= 0) return;

    if(n % 2 == 0) {        // if n is even number
        Print(n-2);
    }
    else {                  // if n is odd number
        Print(n-2);
    }

    printf("%d ", n);

}

int main()
{
    int n;
    scanf("%d", &n);

    //n = 16;

    Print(n);

    return 0;
}