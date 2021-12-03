#include <stdio.h>

int main()
{
	int a[19][19]={0,};
	int i, j, k, n, x, y;
	
	for(i=0; i<19; i++) {
		for(j=0; j<19; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	scanf("%d", &n);
		
	for(k=0; k<n; k++) {
		scanf("%d %d", &x, &y);
		for(i=0; i<19; i++)	{
			for(j=0; j<19; j++) {
				if (a[x-1][j] == 0 ) {
					a[x-1][j] = 1;
				}
				else {
					a[x-1][j] = 0;
				}
			}
			for(j=0; j<19; j++) {
				if (a[i][y-1] == 0 ) {
					a[i][y-1] = 1;
				}
				else {
					a[i][y-1] = 0;
				}
			}
		}
	}
	
	for(i=0; i<19; i++) {
		for(j=0; j<19; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*

*/
