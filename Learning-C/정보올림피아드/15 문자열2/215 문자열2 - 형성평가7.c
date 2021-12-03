#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[100];
    char str2[100];
    scanf("%s%s",str1, str2);

    int n1, n2;
    n1 = atoi(str1);
    n2 = atoi(str2);
    
    printf("%d", n1 * n2);

    return 0;
}