#include <stdio.h>

int main()
{
	int array[10] = {0,};
	int *p_array[10] = {0,};
	
	int i;
	int evencnt=0, oddcnt=0;
	
	for(i=0; i<10; i++)
	{
		p_array[i] = &array[i];
		scanf("%d", &*p_array[i]);
		if(*p_array[i] % 2 == 0)
		{
			evencnt++;
		}
		else 
		{
			oddcnt++;
		}
	}
	
	printf("odd : %d\neven : %d", oddcnt, evencnt);
	
	return 0;
}

/*
10���� ���Ҹ� ������ �� �ִ�
�迭�� ������ ��

������ ������ �̿��Ͽ� �ڷḦ �Է¹޾�
Ȧ���� ������ ¦���� ������ 
����ϴ� ���α׷� 
*/
