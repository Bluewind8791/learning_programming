#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Compare(const void *a, const void *b)
{
    float fn1 = *(float *)a;
    float fn2 = *(float *)b;

    if(fn1 > fn2) return -1;
    if(fn1 < fn2) return 1;
    if(fn1 == fn2) return 0;
}

int main()
{
    int n;
    fscanf(stdin, "%d", &n);

    int score[n][3];
    float average[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            fscanf(stdin, "%d", &score[i][j]);
        }
        for(int j=0; j<3; j++) {
            average[i] += score[i][j];
        }
        average[i] = average[i] / 3;
        average[i] = round(average[i]*10)/10;
    }

    qsort(average, sizeof(average)/sizeof(float), sizeof(float), Compare);

    for(int i=0; i<n; i++) {
        fprintf(stdout, "%.1f\n", average[i]);
    }

    return 0;
}