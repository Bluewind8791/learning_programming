#include <stdio.h>
int main() 
{
	int num;
	
	{
	printf("number? ");
	scanf(" %d", &num);
	}
	
	
	//�ʱ��
	
	while (num != 0)
	{
		{
		if (num > 0) 
			printf("positive integer\n");
		else
			printf("negative number\n");
		}
	
		{
		printf("number? ");
		scanf(" %d", &num);
		}
	
	}
		
	return 0;
}


/*�� ���� ������ �Է¹޾� ���(positive integer)���� ����(negative number)���� 
����ϴ� �۾��� �ݺ��ϴٰ� 0�� �ԷµǸ� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.*/
