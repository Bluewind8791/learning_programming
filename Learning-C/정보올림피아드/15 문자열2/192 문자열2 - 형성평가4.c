#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Strcompare(const void *a, const void *b) {
    return strcmp(a, b);
}

int main()
{
    int n;
    scanf("%d", &n);

    char word[n][100];

    for(int i=0; i<n; i++) {
        scanf("%s", word[i]);
    }

    qsort(word, n, sizeof(word[0]), Strcompare);

    for(int i=0; i<n; i++) {
        printf("%s\n", word[i]);
    }

    return 0;
}