#include <stdio.h>

int main()
{
	int size;
	scanf("%d", &size);
	double f_array[size];
	double hap = 0.0;
	
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%lf", &f_array[i]);
		hap = f_array[i] + hap;
	}
	
	
	for(i=0; i<size; i++)
	{
		printf("%.2lf ", f_array[i]);
		
	}
	printf("\n");
	printf("hap : %.2lf\n", hap);
	printf("avg : %.2lf", hap/size);
	
	
	return 0;
}
/*
�迭�� ũ�⸦ �Է¹޾� 
�Է¹��� ũ�⸸ŭ 
�Ǽ� �迭�� �����ϰ� 
�迭�� ���Ҹ� �Է¹��� �� 

�Է¹��� �ڷ� �� �հ� ����� �ݿø��Ͽ� 
�Ҽ� ��°�ڸ����� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/
