#include <stdio.h>
#include <math.h>

int main()
{
	double f_array[5];
	double *PF_array = f_array;
	int i;
	
	for (i=0; i<5; i++)
	{
		//PF_array[i] = &f_array[i];
		scanf("%lf", PF_array+i);
	}
	
	for (i=0; i<5; i++)
	{
		printf("%.1lf ", *(PF_array+i));
	}
	
	return 0;
}
/*
실수 5개를 원소로 하는 
배열을 선언하고 

포인터 변수를 이용하여 
입력과 출력을 실행하는 
프로그램을 작성하시오 

출력은 반올림하여 
소수 첫째자리까지 출력하는 것으로 한다.
*/

