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
���� �� ���� �Է¹ް� 
������ ��ũ�� �Լ��� �ۼ��Ͽ� 

�� ���� ���� ������ ���� 
���� �������� ���� 
���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

('^'�� �����ڰ� �ƴϰ� 
�ŵ������� ���ϴ� ǥ���̹Ƿ� 
�ŵ������� ������ ����ؾ���)
*/
