#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100];
    char str2[100];

    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);

    if(strlen(str1) > strlen(str2)) {
        fprintf(stdout, "%s%s", str2, str1);
    }
    else {
        fprintf(stdout, "%s%s", str1, str2);
    }

    return 0;
}




/*
Love, like you've never been hurt.
Live, like today is the lost day to live.
*/