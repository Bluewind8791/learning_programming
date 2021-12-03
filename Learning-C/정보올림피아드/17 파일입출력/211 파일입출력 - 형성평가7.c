#include <stdio.h>

int IsLeapYear(int y);


int main()
{
    int startYear, lastYear;
    int LeapYearCnt = 0;

    fscanf(stdin, "%d %d", &startYear, &lastYear);

    for(int i=0; i<=lastYear-startYear; i++) {
        if( IsLeapYear(startYear + i) == 1) {
            LeapYearCnt++;
        }
    }

    fprintf(stdout, "%d", LeapYearCnt);

    return 0;
}

int IsLeapYear(int y)
{
    if ((y%4==0 && y%100!=0)||y%400==0)
        return 1;
    else
        return 0;
}