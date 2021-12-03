#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i,num, even_ct, odd_ct;
	
	even_ct = 0;
	odd_ct = 0;
	
	for(i=0; i<10; i++)
	{
		scanf(" %d", &num);
		
		if(num % 2 == 0)
		{even_ct++;
		}	
	
		else
		{odd_ct++;
		 } 
	
	}
	
	printf("even : %d\nodd : %d", even_ct, odd_ct);
	
	return 0;
}
