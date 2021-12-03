
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define NO_FUNCTION
#define USING_FUNCTION

#define SIZE 100

#ifdef NO_FUNCTION
int main(void)
{
	int *pi = NULL;
	
	pi = malloc(sizeof(int));
	
	*pi = 10;
	printf("%d\n", *pi);
	
	return 0;
}
#endif

#ifdef USING_FUNCTION
//void AllocMemory(int **p, int size);
void AllocMemory(int *p, int size);

int main(void)
{
	int *pi = NULL;
	
//	AllocMemory(&pi, sizeof(int));
	AllocMemory(pi, sizeof(int));
	
	*pi = 10;
	printf("%d\n", *pi);
	
	return 0;
}

//void AllocMemory(int **p, int size)
void AllocMemory(int *p, int size)
{
//	*p = malloc(size);
	p = malloc(size);
}
#endif






