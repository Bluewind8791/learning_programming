#include <stdio.h>

typedef struct Person
{
	char name[20];
	int tall;
	double weight;
}person;

int main()
{
	person d[5] = {0};
	person temp;
	int i, j;
	
	//이름, 키, 몸무게 입력받기 
	for(i=0; i<5; i++)
	{
		scanf("%s %d %lf", &d[i].name, &d[i].tall, &d[i].weight);
	}
	
	//이름순으로 오름차순 정렬. 
	for(i=0; i<5-1; i++)
	{
		for (j=0; j<5-i-1; j++) 
		{
			if ((int)d[j].name[0] > (int)d[j+1].name[0]) 
			{
			temp = d[j];
			d[j] = d[j+1];
			d[j+1] = temp;
			}
		}
	}
	
	//이름순 출력 
	printf("name\n"); 
	for(i=0; i<5; i++)
	{
		printf("%s %d %.1lf\n", d[i].name, d[i].tall, d[i].weight);
	}
	
	//몸무게 내림차순 정렬 
	for(i=0; i<5-1; i++)
	{
		for (j=0; j<5-i-1; j++) 
		{
			if (d[j].weight < d[j+1].weight) 
			{
			temp = d[j];
			d[j] = d[j+1];
			d[j+1] = temp;
			}
		}
	}
	
	//몸무게순 출력 
	printf("\nweight\n");  
	for(i=0; i<5; i++)
	{
		printf("%s %d %.1lf\n", d[i].name, d[i].tall, d[i].weight);
	}
	
	return 0;
}

/*
5명의 이름과 키, 몸무게를 입력받아 
이름순으로 정렬하여 출력하고, 

몸무게가 무거운 순으로 정렬하여 
출력하는 프로그램을 작성하시오. 

몸무게는 소수점이하 1자리까지 출력한다.
*/
