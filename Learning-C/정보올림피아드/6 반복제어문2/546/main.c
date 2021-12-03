#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int n;
	int point, count, sum;
	float avg;
	
	scanf(" %d", &n);

	count = 1;
	sum = 0;
	
	while(1)
	{
		scanf(" %d", &point);	
		
		sum = point + sum;		
		
		count++;
		if(count > n)
			break;
	}
	
	avg = (float)sum / n;
	printf("avg : %.1f\n", avg);
	
	if ( avg >= 80 && avg <= 100 )
		printf("pass");
	
	else
		printf("fail");	
	
	return 0;
}

//10 이하의 과목수 n이 주어진다.

//정수로 주어진 n개 과목의 점수를 입력받아서 
//실수 평균을 구하여 출력하고 

//평균이 80점이상이면 "pass", 
//80점 미만이면 "fail"이라고 출력하는 프로그램을 작성하시오.

//평균은 반올림하여 소수 첫째자리까지 출력한다.
