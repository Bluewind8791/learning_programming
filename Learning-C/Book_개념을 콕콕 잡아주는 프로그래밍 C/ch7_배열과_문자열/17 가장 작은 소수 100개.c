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
	1. Description : �Է¹��� ���ڰ� �Ҽ����� �ƴ��� �Ǵ��ϴ� �Լ�. 
	2. Function : int n (����), x(��������)
	3. Return : 1 or 0 (�Ҽ���� 1, �ƴϸ� 0) 
	*/
	int x;
	for (x=2;x<=n-1;x++) {
	//x�� 2���� n-1���� �ϳ��� �÷����鼭 �������� ������ �Ҽ��� �ƴϴ� 
		if (n % x == 0) 
		{
			return 0;
		}
	}
	return 1;
}


/*
���� ���� ���ڷ� �޾Ƽ� �Ҽ����� �Ǵ��ϴ�
IsPrime �Լ��� �̿��Ͽ� 
���� ���� �Ҽ� 100���� ���ؼ�

������ �迭�� ������ ����
���� �Ҽ����� �� �ٿ� 10���� ���. 
*/
