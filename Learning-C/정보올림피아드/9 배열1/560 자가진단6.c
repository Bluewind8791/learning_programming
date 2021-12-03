#include <stdio.h>
#include <limits.h>

int main ()
{
	int array[10];
	int i, min=INT_MAX;
	
	for (i=0;i<10;i++) {
		scanf("%d",&array[i]);
	} 
	
	for (i=0;i<10;i++) {
		if (min>array[i]) {
			min = array[i];
		}
	} 
	
	printf("%d",min);
	
	return 0;
}
