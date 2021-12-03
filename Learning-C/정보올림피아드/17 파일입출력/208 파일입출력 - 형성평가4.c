#include <stdio.h>

// int Factorial(int num)
// {
//     if(num == 1) return 1;

//     return num * Factorial(num-1);
// }

int main()
{
    int n;
    int fact;

    fscanf(stdin, "%d", &n);

    // fact = Factorial(num);
    if(n != 0) {
        for(int i=n-1; i>=1; i--) {
            n *= i;
        }
    }
    else
        n = 1;

    fprintf(stdout, "%d", n);

    return 0;
}