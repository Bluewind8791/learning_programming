#include <stdio.h>

int main()
{
	int arr[10]={0,};
	int i;
	int pluscnt=0, minuscnt=0, zerocnt=0;
	for(i=0; i<10; i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]==0)
		{
			zerocnt++;
		}
		else if (arr[i]>0)
		{
			pluscnt++;
		}
		else
		{
			minuscnt++;
		}
	}
	
	printf("����� ������ : %d\n", pluscnt);
	printf("������ ������ : %d\n", minuscnt);
	printf("0�� ������ : %d\n", zerocnt);
	
	return 0;
}

/*
�������� 10�� �Է¹޾Ƽ�
�� �� ����� ������ ������ ����
0�� ������ ����ϴ� ���α׷�
*/ 
