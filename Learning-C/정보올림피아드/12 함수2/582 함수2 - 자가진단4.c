#include <stdio.h>
#include <math.h>

double Radius (double area)
{
	return sqrt( (area/3.14) );
}

int main()
{
	double area=0;
	scanf("%lf",&area);
	
	printf("%.2lf", Radius(area));
	
	return 0;
}
/*
���� ���̸� �Է¹޾� 
�������� ���̸� 
�Ҽ� ��°�ڸ����� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���� = ������ * ������ * 3.14 ���� �̿��Ͻÿ�.
area = radius * rad * 3.14
radius = root(area / 3.14)
*/
