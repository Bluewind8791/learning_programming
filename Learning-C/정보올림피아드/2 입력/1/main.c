#include <stdio.h>
int main(void)
{
	
	int num;
	num = -100;
	printf("%d\n\n", num);
	
	

	int num1, num2;
	scanf("%d", &num1);
	scanf("%d", &num2);
	num1 = -1;
	num2 = 100;
	printf("%d\n%d\n\n", num1, num2);
	
	

	int ex1, ex2;
	scanf("%d %d", &ex1, &ex2);	
	ex1 = 55;
	ex2 = 10;
	printf("%d - %d = %d\n", ex1, ex2, ex1-ex2); 
	int ex3, ex4;
	scanf("%d %d", &ex3, &ex4);	
	ex3 = 2008;
	ex4 = 1999;
	printf("%d - %d = %d\n", ex3, ex4, ex3-ex4); 

	

	int chu;
	float gravity;
	scanf("%d %f", &chu, &gravity);
	chu = 49;
	gravity = 0.2683;
	printf("%d * %f = %f\n\n", chu, gravity, chu*gravity);
	
		
	
	
	return 0;
}
