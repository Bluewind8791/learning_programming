#include <stdio.h>

int main ()
{
	int array[10];
	int i,j,max,temp;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&array[i]);
	}
	
	for (i=0;i<10-1;i++) {
		max = i;
		for (j=i+1;j<10;j++) {
			if(array[max]<array[j]) {
				max = j;
			}
		}
		temp = array[max];
		array[max] = array[i];
		array[i] = temp;
	}
	
	for (i=0;i<10;i++) 
	{
		printf("%d ",array[i]);
	}
	return 0;
}

/*
 563 : �迭1 - �ڰ�����9
10���� ������ �Է¹޾� �迭�� ������ ��
������������ �����Ͽ� ����Ͻÿ�.

*/
