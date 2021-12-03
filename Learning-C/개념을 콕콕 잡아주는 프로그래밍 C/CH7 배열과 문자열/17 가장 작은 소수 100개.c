#include <stdio.h>

int IsPrime (int n);

int main()
{
	
	int prime[100]={0,};
	int i, j, k;
	
	for(k=0, i=2; ;i++)
	{
		if( IsPrime(i) )
		{
			prime[k] = i;
			k++;
			if(k>=100)
			{
				break;
			}
		}
	}
	
	for(i=0; i<10; i++)
	{
		for (j=0; j<10; j++)
		{
		printf("%3d ", prime[i*10+j]);
		}
		printf("\n");
	}
	
	return 0;
}


int IsPrime (int n) {
	/*
	1. Description : 입력받은 인자가 소수인지 아닌지 판단하는 함수. 
	2. Function : int n (인자), x(증가변수)
	3. Return : 1 or 0 (소수라면 1, 아니면 0) 
	*/
	int x;
	for (x=2;x<=n-1;x++) {
	//x를 2부터 n-1까지 하나씩 올려가면서 나머지가 없으면 소수가 아니다 
		if (n % x == 0) 
		{
			return 0;
		}
	}
	return 1;
}


/*
정수 값을 인자로 받아서 소수인지 판단하는
IsPrime 함수를 이용하여 
가장 작은 소수 100개를 구해서

정수형 배열에 저장한 다음
구한 소수들을 한 줄에 10개씩 출력. 
*/
