

#include <stdio.h>

int main(void)
{
	int year;
	int is_leaf;
	
	printf("Input year : ");
	scanf("%d", &year);
	
	is_leaf = ((year%4) == 0) && ((year%100) != 0) || ((year%400) == 0);
	
	(is_leaf)? printf("%d is leaf year.\n", year) : printf("%d is not leaf year.\n", year);
	
	return 0;
}
