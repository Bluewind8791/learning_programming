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
10���� ������ �Է¹޾� �迭�� ������ �� 
¦�� ��° �Էµ� ���� �հ� 
Ȧ�� ��° �Էµ� ���� 
����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �ݿø��Ͽ� �Ҽ�ù°�ڸ����� ����Ѵ�.
*/
