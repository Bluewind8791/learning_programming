#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i, j;
	
	for(j=2;j<5;j++)
	{
	
		for(i=1;i<6;i++)
		{
			printf("%d * %d =%3d   ",j, i, i*j);
			
		}
		printf("\n");
	}
	
	return 0;
}

/*
구구단의 일부를 다음과 같이 출력하는 프로그램을 작성하시오.

곱셈의 결과는 오른쪽으로 맞추어 출력을 하고
결과값 사이의 공백은 3칸으로 한다.

출력형식
ex) 2_*_1_=__2___ 
(_는 공백을 나타내는 것임)
*/
