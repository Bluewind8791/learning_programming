#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int num1, num2;
	
	scanf(" %d %d", &num1, &num2);
	
	if (num1>num2) {
		for(;num1>=num2;num2++)
			{ printf("%d ", num2);
			}
		}
	
	else if (num1<num2)	{
		for(;num1<=num2;num1++)
			{	printf("%d ", num1);
			}
		}
	
	else
		printf("%d",num1);
	
	return 0;
}

//100 ������ �� ���� ������ �Է¹޾� 
//���� ������ ū ������ ���ʴ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

