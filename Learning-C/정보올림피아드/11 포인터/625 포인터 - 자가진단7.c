#include <stdio.h>

int main()
{
	int size;
	scanf("%d", &size);
	
	int array[size];
	int i, j, temp=0;
	
	for(i=0; i<size; i++)
	{
		scanf("%d", &array[i]);
	}
	
	
	for(i=0; i<size-1; i++)
	{
		for(j=i+1;j<size;j++)
		{
			if( array[i] < array[j] )
			{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			}
		}
	}
		
	for(i=0; i<size; i++)
	{
		printf("%d ",array[i]);
	}
	
	return 0;
}

/*
�迭�� ũ�⸦ �Է¹޾� 
�Է¹��� ũ�⸸ŭ 
�迭�� ������ �Է¹ް� 

������������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/

