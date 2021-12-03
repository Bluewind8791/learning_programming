#include <stdio.h>

int main()
{
    int arr[3];
    int sum;
    int average;
    int rest;
    fscanf(stdin, "%d %d %d", &arr[0], &arr[1], &arr[2]);
    
    sum = arr[0] + arr[1] + arr[2];
    average = sum / 3;
    rest = sum % 3;

    fprintf(stdout, "%d %d...%d", sum, average, rest);

    return 0;
}