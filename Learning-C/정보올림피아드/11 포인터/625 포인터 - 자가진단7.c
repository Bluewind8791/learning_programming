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
배열의 크기를 입력받아 
입력받은 크기만큼 
배열에 정수를 입력받고 

내림차순으로 정렬하여 
출력하는 프로그램을 작성하시오.

*/

