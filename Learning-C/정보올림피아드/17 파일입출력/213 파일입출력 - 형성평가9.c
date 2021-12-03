#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    // char str[100] = "The largest organ in the body is the liver.";
    char word[20][100];
    char bigword[100] = {0,};

    fgets(str, 100, stdin);

    int len = strlen(str);
    fprintf(stdout, "%d\n", len);

    char *ptr = strtok(str, " ");
    int cnt = 0;

    for(int i=0; ;i++) {
        if(ptr == NULL) break;
        strcpy(word[i] ,ptr);
        ptr = strtok(NULL, " ");
        cnt++;
    }

    int biglen = 0;

    for(int i=0; i<cnt; i++) {
        if(biglen < strlen(word[i])) {
            biglen = strlen(word[i]);
        }
    }

    for(int i=0; i<cnt; i++) {
        if(strlen(word[i]) == biglen) {
            fprintf(stdout, "%s\n", word[i]);
        }
    }

    return 0;
}

