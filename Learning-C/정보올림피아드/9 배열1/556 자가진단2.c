# include <stdio.h>

int main () {
	
	int arr[10];
	int i,j;
	
	for(i=1,j=0;i<=10;i++,j++) {
		arr[j] = i;
	}
	
	for (j=0;j<10;j++) {
		printf("%d ",arr[j]);
	}
	
	return 0;
}
