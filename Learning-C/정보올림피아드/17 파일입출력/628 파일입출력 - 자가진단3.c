#include <stdio.h>
#include <stdlib.h>

typedef struct _class {
    char name[20];
    int score;
    int rank;
} Class;

int Compare(const void *a, const void *b)
{
    if(*(int*)a > *(int*)b)     return -1;
    if(*(int*)a < *(int*)b)     return 1;
    if(*(int*)a == *(int*)b)     return 0;
}

int main()
{
    Class CI[10] = {0,};

    for(int i=0; i<10; i++) {
        fscanf(stdin, "%s", CI[i].name);
        fscanf(stdin, "%d", &CI[i].score);
        CI[i].rank = 1;
    }


    // numbering ranking
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(CI[i].score < CI[j].score) {
                CI[i].rank++;
            }
        }
        
    }


    // print
    fprintf(stdout, "%4s %5s %4s\n","Name" ,"Score", "Rank");
    for(int i=0; i<10; i++) {
        fprintf(stdout, "%4s %5d %4d\n", CI[i].name, CI[i].score, CI[i].rank);
    }

    return 0;
}



/*
Hong 90
Lim 85
Park 88
Gong 75
Lee 100
Seo 90
Jang 75
Song 90
Kim 95
Sung 60
*/