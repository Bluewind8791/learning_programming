#include <stdio.h>

int main()
{
	char *charpointer;
	int *intpointer;
	double *doublepointer;
	
	printf("charpointer의 크기 : %d\n",sizeof(charpointer));
	printf("intpointer 크기 : %d\n",sizeof(intpointer));
	printf("doublepointer 크기 : %d\n",sizeof(doublepointer));
	
	printf("\n");
	
	printf("char*의 크기 : %d\n",sizeof(char*));
	printf("short*의 크기 : %d\n",sizeof(short*));
	printf("int*의 크기 : %d\n",sizeof(int*));
	printf("float*의 크기 : %d\n",sizeof(float*));
	printf("double*의 크기 : %d\n",sizeof(double*));
	
	return 0;
}
