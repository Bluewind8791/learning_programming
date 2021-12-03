#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int intn;
    double floatn;
    char str[30];
    char complete_str[50];
    char temp;

    scanf("%d%lf%s", &intn, &floatn, str);

    sprintf(complete_str, "%d%.3lf%s", intn, floatn,str);

    // printf(complete_str);
    // printf("\n\n");
    
    int half_len = ceil( (double)strlen(complete_str)/2 ) ;
    // printf("%d\n\n", half_len );

    for(int i=0; i<half_len; i++) {
        printf("%c", complete_str[i]);
    }
    printf("\n");
    for(int i=half_len; i<strlen(complete_str); i++) {
        printf("%c", complete_str[i]);
    }

    return 0;
}