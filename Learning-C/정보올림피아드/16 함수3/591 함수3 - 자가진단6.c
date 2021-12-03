#include <stdio.h>

int Recursive(int N)
{
    if(N==1) {
        return 1;
    }

    return Recursive(N/2) + Recursive(N-1);
}


int main()
{
    
    int n;
    scanf("%d", &n);
    printf("%d", Recursive(n));

    // for(int i=2; i<=50; i++) {
    //     array[i] = array[i/2] + array[i-1];
    // }

    // printf("%d", array[n]);

    // for(int i=1; i<=50; i++) {
    //     printf("%d ", array[i]);
    // }

    return 0;
}