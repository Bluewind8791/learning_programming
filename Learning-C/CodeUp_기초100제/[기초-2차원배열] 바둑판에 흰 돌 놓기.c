#include <stdio.h>

int main()
{
	int a[19][19]={0,};
	int i, j, n, x, y;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%d %d", &x, &y);
		a[x-1][y-1] += 1;
	}
	
	for(i=0; i<19; i++) {
		for(j=0; j<19; j++) {
			if (a[i][j] > 1) {
				printf("1 ");
			}
			else {
				printf("%d ", a[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
