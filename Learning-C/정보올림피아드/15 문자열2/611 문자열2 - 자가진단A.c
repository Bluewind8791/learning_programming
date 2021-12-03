#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[20];

    scanf("%s", string);

    int intnum = atoi(string);
    printf("%d\n", intnum*2);
    
    double doublenum = atof(string);
    printf("%.2lf\n", doublenum);

    return 0;
}

// 20자 이하인 한 개의 문자열을 입력받아서 
// 첫 줄에는 정수로 변환하여 2배한 값을 출력하고, 
// 다음 줄에는 실수로 변환한 값을 반올림하여 
// 소수 둘째자리까지 출력하는 프로그램을 작성하시오.