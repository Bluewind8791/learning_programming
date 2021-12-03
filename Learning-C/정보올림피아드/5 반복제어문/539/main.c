#include <stdio.h>
int main( ) {

int num;
int sum = 0;
int count = 0;


for (num = 0; num < 100;)
{
	scanf(" %d", &num);
	sum += num;
	count++;
}

	printf("%d\n%.1f", sum, (float)sum/count);	

	return 0;
}

/*
정수를 계속 입력받다가 100 이상의 수가 입력이 되면 마지막 
입력된 수를 포함하여 합계와 평균을 출력하는 프로그램을 작성하시오.
(평균은 반올림하여 소수 첫째자리까지 출력한다.)

*/
