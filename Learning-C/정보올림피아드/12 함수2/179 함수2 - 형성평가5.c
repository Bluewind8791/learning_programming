#include <stdio.h>
#include <math.h>

int main()
{
	double fn[3];
	int i;
	double sum = 0;
	double R_sum=0;
	
	for(i=0; i<3; i++)
	{
		scanf("%lf", &fn[i]);
		sum = sum + fn[i];
		R_sum = R_sum + round(fn[i]);
	}
	
	double avg;
	avg = sum / 3;
	printf("%.lf\n", round(avg));
	
	printf("%.lf", R_sum / 3);
	
	return 0;
}
/*
세 개의 실수를 입력받아 

합계와 평균을 구하여 
평균을 반올림한 정수를 출력하고, 

다음은 입력받은 수를 
각각 먼저 반올림한 후 

합계와 평균을 구하여 
평균을 반올림한 

한 결과를 출력하는 
프로그램을 작성하시오.
*/
