# include <stdio.h>

int main () {
	
	int array[100];
	int i, count;
	
	for (i=0;i<100;i++) {
		scanf("%d",&array[i]);
		if (array[i] == 0) {
			break;
		}
		count = i;
	}
	
	for (i=count;i>=0;i--) {
		printf("%d ", array[i]);
	}
	
	
	return 0;
}


