#include <stdio.h>

int main()
{
	int array[5];
	int *PointerArray = array;
	
	
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%d", (PointerArray+i));
	}
	
	for(i=0;i<5;i++)
	{
		if ( (i+1) % 2 != 0)
		{
			printf("%d ", *(PointerArray+i));
		}
	}
	
	return 0;
}

/*
5��¥�� ������ �迭�� �����ϰ� 
������ ������ ������ �� 

������ ������ �̿��Ͽ� �Է��� ���� �� 
Ȧ����° �Է°��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
