#include <stdio.h>

int main()
{
	
	int i;
	int num;
	int sum = 0;
	//�����ϴ°��� �ƴϱ� ������ �ʱⰪ�� �ʿ��ϴ� 
	
	scanf(" %d", &num);
	
	
	i = 1;
	while ( i <= num )
	{
	
		sum += i;
		i++;
	
	}
	
	printf("%d", sum);
	
	return 0;
}

//100 ������ ���� ������ �Էµȴ�.
//while ���� �̿��Ͽ� 1���� �Է¹��� ���������� 
//���� ���Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
