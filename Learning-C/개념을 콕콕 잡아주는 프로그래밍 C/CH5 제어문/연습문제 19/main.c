#include <stdio.h>

int main(void) {
	
	int n, x, factorial = 1;
	
	printf("Please insert number : ");
	scanf(" %d", &n);
		

		
		for (x=0; x<=n; x++) 
		{
			if (x == 0) {
				factorial = 1;
			}
			else {
				factorial *= x;
			}					
			printf("%d! = %d\n", x, factorial);		
		}							


	

	return 0;
}

//Question number 19. 
