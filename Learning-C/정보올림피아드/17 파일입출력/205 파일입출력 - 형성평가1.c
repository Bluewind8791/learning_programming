#include <stdio.h>
#include <math.h>

int main()
{
    float fn1, fn2, fsum;

    fscanf(stdin, "%f %f", &fn1, &fn2);

    fsum = roundf((fn1+fn2)*100)/100;
    fn1 = roundf(fn1*100)/100;
    fn2 = roundf(fn2*100)/100;

    fprintf(stdout, "%.2f %.2f %.2f", fn1, fn2, fsum);


    return 0;
}