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
���� �ѷ�(c) ������ ������ ����
c = ������ ���� * ������ = 2 * ������ * ������(3.14)
������ = circum / 3.14 / 2
*/