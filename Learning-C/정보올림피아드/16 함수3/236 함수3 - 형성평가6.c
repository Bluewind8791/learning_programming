#include <stdio.h>

int Recursive(int n)
{
    if(n == 0) return 1;

    int step = n % 10;

    if(step == 0)
        step = 1;

    n /= 10;

    return Recursive(n) * step;
}

int main()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    int times;
    times = n1*n2*n3;

    printf("%d", Recursive(times));

    return 0;
}

// //-- no use recursive func --//
// int main()
// {
    
//     int n1, n2, n3;
//     // scanf("%d %d %d", &n1, &n2, &n3);
//     n1 = 761;
//     n2 = 535;
//     n3 = 593;
//     int times = n1*n2*n3;
//     int temp = 1;
    
//     for(int i=100; i<=1000000000; i*=10) {
//         if((times%i)/(i/10)==0) {
//             temp *= 1;
//         }
//         else {
//             temp *= ((times%i)/(i/10));
//         }
//     }
//     printf("%d", temp);

//     return 0;
// }