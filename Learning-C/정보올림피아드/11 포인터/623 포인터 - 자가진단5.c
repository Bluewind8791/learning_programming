#include <stdio.h>
#include <math.h>

int main()
{
	double f_array[5];
	double *PF_array = f_array;
	int i;
	
	for (i=0; i<5; i++)
	{
		//PF_array[i] = &f_array[i];
		scanf("%lf", PF_array+i);
	}
	
	for (i=0; i<5; i++)
	{
		printf("%.1lf ", *(PF_array+i));
	}
	
	return 0;
}
/*
�Ǽ� 5���� ���ҷ� �ϴ� 
�迭�� �����ϰ� 

������ ������ �̿��Ͽ� 
�Է°� ����� �����ϴ� 
���α׷��� �ۼ��Ͻÿ� 

����� �ݿø��Ͽ� 
�Ҽ� ù°�ڸ����� ����ϴ� ������ �Ѵ�.
*/

