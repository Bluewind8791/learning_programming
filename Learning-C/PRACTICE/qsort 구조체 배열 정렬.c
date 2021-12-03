#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
char name[20];
double ave;
} STUDENT;

int CompareByName(const void *e1, const void *e2);
int CompareByAve(const void *e1, const void *e2);
void PrintStudent(const STUDENT* std, int num);

int main( )
{
	STUDENT std[5] = {
		{"이모모", 58.5},
		{"박모모", 73.9},
		{"김모모", 87.2},
		{"최모모", 96.6},
		{"나모모", 34.3}
	};
	
	printf("*** BEFORE ***\n");
	PrintStudent(std, 5);
	
	//이름 순 정렬 
	qsort(std, 5, sizeof(STUDENT), CompareByName);
	printf("*** Sort By Name ***\n");
	PrintStudent(std, 5);
	
	//평균 순 정렬 
	qsort(std, 5, sizeof(STUDENT), CompareByAve);
	printf("*** Sort By Average ***\n");
	PrintStudent(std, 5);
	
	return 0;
}

int CompareByName(const void *e1, const void *e2)
{
	STUDENT *p1 = (STUDENT *) e1;
	STUDENT *p2 = (STUDENT *) e2;
	
	return strcmp(p1->name, p2->name);
}

int CompareByAve(const void *e1, const void *e2)
{
	STUDENT *p1 = (STUDENT *) e1;
	STUDENT *p2 = (STUDENT *) e2;
	double temp = p1->ave - p2->ave;
	
	if (temp==0) {
		return 0;
	}
	if (temp > 0) {
		return 1;
	}
	return -1;
}

void PrintStudent(const STUDENT* std, int num)
{
	int i;
	for(i=0; i<5; i++)
	{
		printf("%-10s %5.1f \n", std[i].name, std[i].ave);
	}
	printf("\n");
}

	
	
	
	
