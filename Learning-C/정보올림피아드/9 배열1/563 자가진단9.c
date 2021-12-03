#include <stdio.h>

int main ()
{
	int array[10];
	int i,j,max,temp;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&array[i]);
	}
	
	for (i=0;i<10-1;i++) {
		max = i;
		for (j=i+1;j<10;j++) {
			if(array[max]<array[j]) {
				max = j;
			}
		}
		temp = array[max];
		array[max] = array[i];
		array[i] = temp;
	}
	
	for (i=0;i<10;i++) 
	{
		printf("%d ",array[i]);
	}
	return 0;
}

/*
 563 : 배열1 - 자가진단9
10개의 정수를 입력받아 배열에 저장한 후
내림차순으로 정렬하여 출력하시오.

*/
