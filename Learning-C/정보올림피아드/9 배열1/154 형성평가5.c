# include <stdio.h>
# include <math.h> 

int main ()
{
	int i;
	double a[6];
	double sum = 0;
	
	for (i=0;i<6;i++)
	{
		scanf("%lf",&a[i]);
		sum = a[i] + sum;
		
	}

	printf("%.1lf", ( round((sum/6)*10) ) / 10 );
	return 0;
	
}


/*
6���� �����Ը� �Է¹޾� 
�������� ����� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

����� �ݿø��Ͽ� 
�Ҽ� ù°�ڸ������� �Ѵ�.
*/
