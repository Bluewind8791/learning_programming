#include <stdio.h>

int main()
{
	int dice[6]={1,2,3,4,5,6};
	int dicecnt[6]={0,};
	int i, j;
	int thw[10]={0,};
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&thw[i]);
		for(j=0;j<6;j++)
		{
			if (dice[j]==thw[i])
			{
				dicecnt[j]++;
			}
		}
	}
	
	for(j=0; j<6; j++)
	{
		printf("%d : %d\n",j+1 ,dicecnt[j]);
	}
	
	return 0;
}

/*
승지는 주사위 놀이를 하다가 
주사위를 10번 던져서 
각 숫자가 몇 번씩 나왔는지 알아보려고 한다. 

한번 던질 때마다 나온 주사위의 숫자를 입력받아서 
각 숫자가 몇 번씩 나왔는지 
출력하는 프로그램을 작성하시오
*/
