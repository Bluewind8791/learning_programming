#include <stdio.h>
#define PIE 3.141592
#define AREA(X,Y) (Y)*(X)
#define POW(X) (X)*(X)

int main()
{
	double rad;
	printf("radius : ");
	scanf("%lf", &rad);
	
	double area;
	area = AREA( PIE, POW(rad) );
	
	printf("area = %.3lf", area);
	
	return 0;
}

/*
�������� 3.141592�� ��ũ�� ����� �����ϰ� 

���� ���̸� ���ϴ� ��ũ�� �Լ��� �ۼ��Ͽ� 
�������� �Է¹޾� 

���� ���̸� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�. 
(�Ҽ� ��°�ڸ����� �ݿø�)
*/
