# include <stdio.h>
# include <math.h>

int main ()
{
	int arr[10];
	int i;
	int SumEven=0;
	int SumOdd=0;
	
	for (i=0; i<10; i++)
	{
		scanf("%d", &arr[i]);
		
		if ( ((i+1)%2)==0)
		{
			SumEven = arr[i] + SumEven;
		}
		else
		{
			SumOdd = arr[i] + SumOdd;
		}
	}
	
	printf("sum : %d\n", SumEven);
	printf("avg : %.1lf", (round((SumOdd/5.0)*10))/10 );
	
	return 0;
}



/*
10개의 정수를 입력받아 배열에 저장한 후 
짝수 번째 입력된 값의 합과 
홀수 번째 입력된 값의 
평균을 출력하는 프로그램을 작성하시오.

평균은 반올림하여 소수첫째자리까지 출력한다.
*/
