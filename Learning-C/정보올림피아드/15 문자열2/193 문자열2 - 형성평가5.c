#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[5][100];
    char ch;
    char chs[100];
    int cnt=0;

    for(int i=0; i<5; i++) {
        scanf("%s", str[i]);
    }
    scanf(" %c", &ch);
    scanf("%s", chs);

    for(int i=0; i<5; i++) {
        for(int j=0; j<strlen(str[i]); j++) {
            if( str[i][j] == ch ) {
                printf("%s\n", str[i]);
                cnt++;
                break;
            }
            // first of string compare
            if( str[i][j] == chs[0] ) {
                // second, third ... of string compare
                for(int k=1; k<strlen(chs); k++) {
                    // if not same, 
                    if( str[i][j+k] != chs[0+k])
                        goto restart;
                }
                printf("%s\n", str[i]);
                cnt++;
                restart:
                break;
            }
        }
    }

    
    if(cnt == 0) {
        printf("none");
    }
    return 0;
}