#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char ch_n[5];
    fgets(ch_n, 5, stdin);
    //fscanf(stdin, "%d", &n);
    n = atoi(ch_n);

    char str[n][100];
    for(int i=0; i<n; i++) {
        fgets(str[i], 100, stdin);
    }

    for(int i=n-1; i>=0; i--) {
        fprintf(stdout, "%s", str[i]);
    }

    return 0;
}

/*
3
I love korea.
My name is chulgi.
I'm happy.
*/
