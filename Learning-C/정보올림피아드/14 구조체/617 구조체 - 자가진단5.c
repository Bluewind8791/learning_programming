#include <stdio.h>

typedef struct Tall {
	char name[20];
	int tall;
}tall;

int main()
{
	tall p[5] = {0};
	int i;
	int max = 300;
	int max_i = 0;
	
	
	for(i=0; i<5; i++)
	{
		scanf("%s %d", &p[i].name, &p[i].tall);
		if (max > p[i].tall)
		{
			max = p[i].tall;
			max_i = i;
		}
	}
	
	printf("%s %d", p[max_i].name, p[max_i].tall);
	
	return 0;
}

/*
5���� �̸��� Ű�� �Է¹޾� 

Ű�� ���� ���� ����� 
�̸��� Ű�� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

�̸��� 20�� �����̴�.
*/
