#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int *p1 = NULL, *p2 = NULL, *p3 = NULL;

	p1 = (int*)malloc(sizeof(int));
	//memory allocation
	p2 = malloc(sizeof(int));
	p3 = malloc(sizeof(int));
	
	scanf("%d %d",&*p1, &*p2);
	
	*p3 = abs(*p1 - *p2);
	printf("%d", *p3);
	
	free(p1);
	free(p2);
	free(p3);
	
	return 0;
}

/*
������ ������ ������ �����ϰ�
memory ������ Ȯ���Ͽ�
�� ���� �Է¹޾�

�� ���� ���� ���밪�� ������ ��
����ϴ� ���α׷� 
*/
