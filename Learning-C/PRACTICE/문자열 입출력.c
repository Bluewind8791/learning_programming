#include <stdio.h>
#include <string.h>

int main()
{
	char name[20];
	char msg[40];
	
	printf("Scream your name : ");
	gets(name);
	printf("Hello, %s?\n",name);
	
	sprintf(msg,"Hello, %s!", name);
	puts(msg);
	
	////////////////////////////////////////////////////////////////////////////
	printf("\n\n");
	////////////////////////////////////////////////////////////////////////////

	char s[3][5];
	int i;
	
	strcpy(s[0],"ab");
	strcpy(s[1],"cdqdfasdfasdf");
	strcpy(s[2],"ef");
	
	for(i=0;i<3;i++)
	{
		printf("length : %d, ¹®ÀÚ¿­ : %s\n",strlen(s[i]),s[i] );
	}
	
	
	return 0;
}
