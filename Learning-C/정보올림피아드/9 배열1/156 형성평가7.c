#include <stdio.h>

int main ()
{
	int a[100];
	int i;
	int max=0;
	int min=999;
	
	for(i=0; ;i++)
	{
				scanf("%d",&a[i]);
		if (a[i]==999)
		{
			break;
		}
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	printf("max : %d\nmin : %d",max,min);
	return 0;
}

/*
�� �ڸ� ������ ������ 
���ʷ� �Է� �޴ٰ� 

999�� �ԷµǸ� 
���α׷��� �����ϰ� 
�� ������ �Էµ� �ִ밪�� �ּҰ��� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

�Է¹޴� ������ 100�� �����̴�.

*/
