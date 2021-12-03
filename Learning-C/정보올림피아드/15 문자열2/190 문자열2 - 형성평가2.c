#include <stdio.h>
#include <string.h>

int main()
{
    char word[5][20];
    strcpy(word[0], "flower");
    strcpy(word[1], "rose");
    strcpy(word[2], "lily");
    strcpy(word[3], "daffodil");
    strcpy(word[4], "azalea");

    char ch;
    scanf(" %c", &ch);

    int cnt=0;


    for(int j=0; j<5; j++) {
        for(int i=1; i<3; i++) {
            if(word[j][i] == ch) {
                printf("%s\n", word[j]);
                cnt++;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}