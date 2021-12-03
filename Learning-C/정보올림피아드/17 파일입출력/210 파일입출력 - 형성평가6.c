#include <stdio.h>

int main()
{
    int n;
    fscanf(stdin, "%d", &n);

    int i, j;

    for(i=0; i<n; i++) {
        for(j=0; j<n-1-i; j++) {
            fprintf(stdout, "  ");
        }
        for(j=0; j<2*(i+1)-1; j++) {
            fprintf(stdout, "* ");
        }
        fprintf(stdout, "\n");
    }

    for(i=0; i<n; i++) {
        for(j=0; j<i+1; j++) {
            fprintf(stdout, "  ");
        }
        for(j=0; j<2*(n-i-1)-1; j++) {
            fprintf(stdout, "* ");
        }
        fprintf(stdout, "\n");
    }

}