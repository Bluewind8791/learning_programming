#include <stdio.h>

int main()
{
//	int arr[5] = {1,2,3,4,5};
//	int *p = arr;
//	int i;
//	for(i=0; i<5; i++, p++)
//	{
//		printf("%d\n", *p);
//	}
	
	
//	int array[5] = {10,20,30,40,50};
//	
//	for(i=0; i<5; i++)
//	{
//		printf("%p\n", array+i);
//						//&array[i]
//	}
	

			
//	for(i=0; i<5; i++)
//	{
//		printf("%d ", *(array+i) );
//						//array[i]
//	}
		
			
	int array[5] = {10,20,30,40,50};
	int *p = array;
	int i;
	
	for(i=0; i<5; i++)
	{
		printf("array + %d = %p\n", i, array+i);
		printf("p + %d = %p\n\n", i, p+i);
	}
	
	for(i=0; i<5; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
		printf("p[%d]     = %d\n", i, p[i]);
	}
	


	
	return 0;
}

/*
arr[i] = *(arr + i)
&arr[i] = arr + i

arr[i][j] = *( *(arr+i) + j )
&arr[i][j] = (arr + i)
*/
