#include <stdio.h>

int main()
{
	int n, i, j;
	
	scanf("%d", &n);
	int arr[100]={100,n,0,};
	
	for(i=0; ; i++)
	{
		arr[i+2]= arr[i]-arr[i+1];
		//5 = 3 - 4
		if(arr[i+2]<0)
		{
			break;
		}
	}
	
	for(j=0; j<i+3; j++)
	{
	printf("%d ", arr[j]);
	}
	
	
	return 0;
}

/*
100 이하의 자연수를 입력받아 
첫 번째 항은 100으로 
두 번째 항은 입력받은 수로 초기화하고 

다음 항부터는 전전항에서 전항을 뺀 수로 
채워나가는 수열을 작성하여 

그 수가 음수가 나올 때까지 
출력하는 프로그램을 작성하시오.

*/

