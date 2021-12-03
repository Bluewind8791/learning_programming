#include <stdio.h>
#include <math.h>
#define MINUS(X,Y) (X)-(Y)
#define PLUS(X,Y) (X)+(Y)
#define POW(X) (X)*(X)
#define POW3(X) (X)*(X)*(X)

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	
	printf("(%d - %d) ^ 2 = %d\n", n1, n2, POW( abs(MINUS(n1,n2)) ));
	printf("(%d + %d) ^ 3 = %d\n", n1, n2, POW3( PLUS(n1,n2) ) );
	
	return 0;
}
/*
정수 두 개를 입력받고 
계산식을 매크로 함수로 작성하여 

두 수의 차를 제곱한 값과 
합을 세제곱한 값을 
각각 출력하는 프로그램을 작성하시오.

('^'는 연산자가 아니고 
거듭제곱을 뜻하는 표시이므로 
거듭제곱은 별도로 계산해야함)
*/
