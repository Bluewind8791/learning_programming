#include <stdio.h>

int main(void)
{
	int num[] = {15, 23, 7, 78, 34, 67, 45, 36, 90, 71};
	int delta;
	int *p = num;
	int i;
	
	printf("[ ����   �迭 ] ");
	for(i=0; i<sizeof(num)/sizeof(num[0]); i++) {
		printf("%4d",  *(p+i));
	}
	
	printf("\n�������� �Է��ϼ��� : ");
	scanf("%d", &delta);
	
	for(i=0; i<sizeof(num)/sizeof(num[0]); i++) {
		*(p+i) += delta;
	} 
	
	printf("[ ������ �迭 ] ");
	for(i=0; i<sizeof(num)/sizeof(num[0]); i++) {
		printf("%4d",  *(p+i));
	}
	
	return 0;
}
