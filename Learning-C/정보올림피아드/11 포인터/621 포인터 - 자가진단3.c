#include <stdio.h>

int main()
{
	int x1, x2;
	int *p1, *p2;
	p1 = &x1;
	p2 = &x2;
	
	scanf("%d %d", &*p1, &*p2);
	printf("%d + %d = %d\n", *p1, *p2, *p1 + *p2);
	printf("%d - %d = %d\n", *p1, *p2, *p1 - *p2);
	printf("%d * %d = %d\n", *p1, *p2, *p1 * *p2);
	printf("%d / %d = %d\n", *p1, *p2, *p1 / *p2);
	
	return 0;
}
/*
������ ���� �� ���� �̿��Ͽ� 
�� ���� �Է¹ް� 
��Ģ ������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
