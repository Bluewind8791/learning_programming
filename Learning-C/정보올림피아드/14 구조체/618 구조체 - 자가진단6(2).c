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

	Sorting(d, ASD);			//이름순으로 오름차순 정렬. 
	
	printf("name\n"); 
	Printing(d);				//이름순 출력 

	
	//몸무게 내림차순 정렬 
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
	Printing(d);				//몸무게순 출력 
	
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
5명의 이름과 키, 몸무게를 입력받아 
이름순으로 정렬하여 출력하고, 

몸무게가 무거운 순으로 정렬하여 
출력하는 프로그램을 작성하시오. 

몸무게는 소수점이하 1자리까지 출력한다.
*/
