#include <stdio.h>

int main()
{
    int sum = 0;
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    for(int i=n1; i<=n2; i++) {
        sum += i;
    }
    printf("%d", sum);

    return 0;
}