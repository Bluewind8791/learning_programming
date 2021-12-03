#include <stdio.h>
#define ASD 0
#define DES 1

typedef struct _person
{
	char name[20];
	int tall;
	double weight;
}PERSON;

void Sorting(PERSON *arr, int type);
void Printing(PERSON *arr);

int main()
{
	PERSON d[5] = {
	{"Lee", 150, 35.6},	{"Kim", 155, 28.9},
	{"Sin", 148, 32.7}, {"Jung", 160, 41.2}, {"Park", 165, 38.7}
	};
	
	PERSON temp;
	int i, j;

	Sorting(d, ASD);			//�̸������� �������� ����. 
	
	printf("name\n"); 
	Printing(d);				//�̸��� ��� 

	
	//������ �������� ���� 
//	for(i=0; i<5-1; i++)	{
//		for (j=0; j<5-i-1; j++) {
//			if (d[j].weight < d[j+1].weight) {
//			temp = d[j];
//			d[j] = d[j+1];
//			d[j+1] = temp;
//			}
//		}
//	}
	Sorting(d, DES);
	
	printf("\nweight\n");  
	Printing(d);				//�����Լ� ��� 
	
	return 0;
}

void Printing (PERSON *arr) {
	int i;
	for(i=0; i<5; i++)
	{
		printf("%s %d %.1lf\n", arr[i].name, arr[i].tall, (arr+i)->weight);
	}
}


void Sorting(PERSON *arr, int type) {
	int i, j;
	PERSON temp;
	for(i=0; i<5-1; i++)
	{
		for (j=0; j<5-i-1; j++) 
		{
			if (type == 0) {
				if ((int)arr[j].name[0] > (int)arr[j+1].name[0]) 
				{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				}
			}
			else if (type == 1) {
				if ((int)arr[j].weight < (int)arr[j+1].weight) 
				{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				}
			}
		}
	}
}


/*
5���� �̸��� Ű, �����Ը� �Է¹޾� 
�̸������� �����Ͽ� ����ϰ�, 

�����԰� ���ſ� ������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

�����Դ� �Ҽ������� 1�ڸ����� ����Ѵ�.
*/
