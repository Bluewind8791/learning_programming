# include <stdio.h>
# include <math.h> 

int main ()
{
	int i;
	double a[6];
	double sum = 0;
	
	for (i=0;i<6;i++)
	{
		scanf("%lf",&a[i]);
		sum = a[i] + sum;
		
	}

	printf("%.1lf", ( round((sum/6)*10) ) / 10 );
	return 0;
	
}


/*
6명의 몸무게를 입력받아 
몸무게의 평균을 출력하는 
프로그램을 작성하시오.

출력은 반올림하여 
소수 첫째자리까지로 한다.
*/
