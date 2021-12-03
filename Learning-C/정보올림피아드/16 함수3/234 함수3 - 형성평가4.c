#include <stdio.h>


// //-- Time Limit Exceed --//
// int Recursive(int n)
// {
//     if(n == 1)
//         return 1;
//     if(n == 2)
//         return 2;
//     return (Recursive(n-2) * Recursive(n-1)) % 100;
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%d", Recursive(n));
// }


//-- 재귀함수 사용 X -- //
int main()
{
    int array[100] = {1,2,};
    
    for(int i=2; i<100-2; i++) {
        array[i] = (array[i-2] * array[i-1]) % 100;
    }

    int n;
    scanf("%d", &n);
    printf("%d", array[n-1]);
}