#include <stdio.h>

int main ()
{
	char str[3][5]={0,};
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf(" %c",&str[i][j]);
			str[i][j] = str[i][j] + 32;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
/*
3�� 5���� 2���� ���ڹ迭 ������ �빮�ڵ��� �Է� ���� �� 

�ҹ��ڷ� �ٲپ �������� �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/

