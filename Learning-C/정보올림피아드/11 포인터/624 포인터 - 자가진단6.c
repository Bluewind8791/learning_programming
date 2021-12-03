#include <stdio.h>

int main()
{
	int size;
	scanf("%d", &size);
	double f_array[size];
	double hap = 0.0;
	
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%lf", &f_array[i]);
		hap = f_array[i] + hap;
	}
	
	
	for(i=0; i<size; i++)
	{
		printf("%.2lf ", f_array[i]);
		
	}
	printf("\n");
	printf("hap : %.2lf\n", hap);
	printf("avg : %.2lf", hap/size);
	
	
	return 0;
}
/*
배열의 크기를 입력받아 
입력받은 크기만큼 
실수 배열을 생성하고 
배열의 원소를 입력받은 후 

입력받은 자료 및 합과 평균을 반올림하여 
소수 둘째자리까지 
출력하는 프로그램을 작성하시오.

*/
