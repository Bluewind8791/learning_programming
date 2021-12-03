#include <stdio.h>
#include <string.h>

int main()
{
    char temp[100];
    char word[50][100];
    int i = 0;
    int cnt = 0;

    while(1)
    {
        scanf(" %s", temp);
        if( strcmp(temp, "0") == 0 ) {
            break;
        }
        else {
            strcpy(word[i++], temp);
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(int j=0; j<cnt; j++) {
        if( (j+1)%2 != 0 ) {
            printf("%s\n", word[j]);
        }
    }

    return 0;
}