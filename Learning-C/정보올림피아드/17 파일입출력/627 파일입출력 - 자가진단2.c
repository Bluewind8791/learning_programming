#include <stdio.h>

int main()
{
    double fnum[10];
    
    for(int i=0; i<10; i++) {
        fscanf(stdin, "%lf ", &fnum[i]);
    }

    fprintf(stdout, "%.1lf", (fnum[0]+fnum[9])/2 );

    return 0;
}