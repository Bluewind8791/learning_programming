#include <stdio.h>

int main()
{
	int a[10]={0,};
	int i, j, k;
	int temp = 0;
	
	for(i=0;i<10;i++)
	{
		scanf("%d", &a[i]);
	}
		
	for(i=0;i<9;i++)
	{
		for(j=0;j<10-1;j++)
		{
			if(a[j] < a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		
		for(k=0;k<10;k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
	}


	return 0;
}
/*
10���� ������ �Է¹޾� 
�������ķ� �������� ������ �ϸ鼭 

�ϳ��� �ܰ谡 ���� ������ 
�� ���İ���� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
