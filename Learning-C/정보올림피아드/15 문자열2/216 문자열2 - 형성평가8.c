#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char word[20];

    while(1) {
        scanf("%s", word);
        if( strcmp(word, "END") == 0 )
            break;
        
        for(int i=strlen(word)-1; i>=0; i--) {
            printf("%c", word[i]);
        }
        printf("\n");
        
    }

    return 0;
}