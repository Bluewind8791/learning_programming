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
	
	//�̸�, Ű, ������ �Է¹ޱ� 
	for(i=0; i<5; i++)
	{
		scanf("%s %d %lf", &d[i].name, &d[i].tall, &d[i].weight);
	}
	
	//�̸������� �������� ����. 
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
	
	//�̸��� ��� 
	printf("name\n"); 
	for(i=0; i<5; i++)
	{
		printf("%s %d %.1lf\n", d[i].name, d[i].tall, d[i].weight);
	}
	
	//������ �������� ���� 
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
	
	//�����Լ� ��� 
	printf("\nweight\n");  
	for(i=0; i<5; i++)
	{
		printf("%s %d %.1lf\n", d[i].name, d[i].tall, d[i].weight);
	}
	
	return 0;
}

/*
5���� �̸��� Ű, �����Ը� �Է¹޾� 
�̸������� �����Ͽ� ����ϰ�, 

�����԰� ���ſ� ������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

�����Դ� �Ҽ������� 1�ڸ����� ����Ѵ�.
*/
