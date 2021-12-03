#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    // int n = 3;
    // char temp1[100] = "banana";
    // char temp2[100] = "apple";
    char word1[100];
    char word2[100];
    char temp1[100];
    char temp2[100];
    
    scanf("%s %s", temp1, temp2);
    scanf("%d", &n);

    // complete word1
    strcpy(word1, temp1);
    strcat(word1, temp2);

    // complete word2
    strcpy(word2, temp2);
    strncpy(word2, word1, n);

    printf("%s\n%s", word1, word2);

    return 0;
}