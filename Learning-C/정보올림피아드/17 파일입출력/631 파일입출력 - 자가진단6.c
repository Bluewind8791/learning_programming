#include <stdio.h>

int main()
{
    while(1)
    {
        float circum;
        float radius;
        fscanf(stdin, "%f", &circum);
        if(circum == 0) break;
        radius = circum / 3.14 / 2;
        fprintf(stdout, "%.2f\n", radius);
    }


    return 0;
}

/*
원의 둘레(c) 공식은 다음과 같다
c = 지름의 길이 * 원주율 = 2 * 반지름 * 원주율(3.14)
반지름 = circum / 3.14 / 2
*/