#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	float grade;
	scanf(" %f", &grade);
	
	switch ( (int)grade )
	{
		case 4:
			printf("scholarship");
			break;

		case 3:
			printf("next semester");
			break;

		case 2:
			printf("seasonal semester");
			break;

		default:
			printf("retake");
			break;		

				
	}
	
	
	
	return 0;
}
