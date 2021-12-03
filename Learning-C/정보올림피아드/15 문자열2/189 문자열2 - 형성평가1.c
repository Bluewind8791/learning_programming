#include <stdio.h>
#include <string.h>

int main()
{

    char str[100];
    gets(str);
    //printf("%s\n\n", str);
    
    char word[10][20];
    char *temp = strtok(str, " ");
    int nWord = 0;

    

    for(int i=0; temp != NULL; i++) {
        strcpy(word[i], temp);
        temp = strtok(NULL, " ");
        nWord++;
    }

    for(int j=nWord-1; j>=0; j--) {
        printf("%s\n", word[j]);
    }


    return 0;
}