#include <stdio.h>

int main() 
{
	
char ALP;

scanf(" %c", &ALP);

if ( ALP == 'A' )
	printf("Excellent");

else if ( ALP == 'B' )
	printf("Good");
	
else if ( ALP == 'C' )
	printf("Usually");

else if ( ALP == 'D' )
	printf("Effort");

else if ( ALP == 'F' )
	printf("Failure");

else
	printf("error");

	return 0;
}
