#include <stdio.h>

int main()
{
	char *charpointer;
	int *intpointer;
	double *doublepointer;
	
	printf("charpointer�� ũ�� : %d\n",sizeof(charpointer));
	printf("intpointer ũ�� : %d\n",sizeof(intpointer));
	printf("doublepointer ũ�� : %d\n",sizeof(doublepointer));
	
	printf("\n");
	
	printf("char*�� ũ�� : %d\n",sizeof(char*));
	printf("short*�� ũ�� : %d\n",sizeof(short*));
	printf("int*�� ũ�� : %d\n",sizeof(int*));
	printf("float*�� ũ�� : %d\n",sizeof(float*));
	printf("double*�� ũ�� : %d\n",sizeof(double*));
	
	return 0;
}
