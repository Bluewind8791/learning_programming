#include <stdio.h>
#include <stdlib.h>

/* 3개의 정수를 입력받아서
합계와 평균 최대값과 최소값을 출력한다
평균은 소수점 이하까지 */

int main(int argc, char *argv[]) 
{

int num1, num2, num3;
float avg;
	
	printf("Please input 3 numbers :");
	scanf(" %d %d %d", &num1, &num2, &num3);
	
	
	printf("SUM = %d\n", num1 + num2 + num3 );
	
	avg = (num1 + num2 + num3)/3;
	printf("AVERAGE = %.2f\n", avg );
	
	printf("MAX = %d\n", (num1 > num2) && (num1 > num3) ? num1 : ( (num2 > num3) ? num2 : num3 ));
	
	printf("MIN = %d\n", (num1 < num2) && (num1 < num3) ? num1 : ( (num2 < num3) ? num2 : num3 ) );
	
	
	return 0;
}
