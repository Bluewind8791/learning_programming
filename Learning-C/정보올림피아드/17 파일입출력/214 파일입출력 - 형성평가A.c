#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Compare(const void *a, const void *b)
{
    return ( strcmp((char *)a, (char *)b) );
}

int main()
{
    char str[10][100];
    char ch;
    char includeWord[10][100];

    for(int i=0; i<10; i++) {
        // fscanf(stdin, "%s", str[i]);
        fgets(str[i], 100, stdin);
    }
    fscanf(stdin, "%c", &ch);

    qsort(str, 10, sizeof(str[0]), Compare);
    
    int k = 0;

    for(int i=0; i<10; i++) {
        if( strchr(str[i], ch))
            fprintf(stdout, "%s", str[i]);
    }

    return 0;
}