#include <stdio.h>

int main()
{
    int n;
    int cnt=0;

    while(1) {
        fscanf(stdin, "%d", &n);
        if(n == 0){
            break;
        }
        if(n%3==0 && n%5==0) {
            fprintf(stdout, "%d ", n);
            cnt++;
        }
    }
    if(cnt != 0) {
        fprintf(stdout, "\n%d", cnt);
    }
    else
        fprintf(stdout, "%d", 0);

    return 0;
}