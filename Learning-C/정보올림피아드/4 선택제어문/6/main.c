#include <stdio.h>
int main()
 {
	
	char sex;
	int age;
	
	scanf(" %c", &sex);
	scanf(" %d", &age);
	
	if (sex == 'M')
	{
		if (age >= 18) 	
			printf("MAN");
		
		else
			printf("BOY");
	} 
	
	else 
	{
		if (age >= 18) 	
			printf("WOMAN");
		
		else
			printf("GIRL");
	} 
		

	return 0;
}
