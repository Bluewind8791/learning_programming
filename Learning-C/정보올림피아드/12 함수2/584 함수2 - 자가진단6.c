#include <stdio.h>
#define first 1
#define second 2
#define third 3

int main()
{
	int array[3]={first,second,third};
	int i, j;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d + %d = %d\n", array[i], array[j], array[i]+array[j]);
		}
	}
	
	return 0;
}

/*
main() �Լ� ������ 
���ڸ� ������� ���� 

��, #define �� �̿��Ͽ� 
1, 2, 3 �� ���� ���ڸ� �����Ͽ� 
������ �� ��� ���� ����ϴ� 
���α׷��� �ۼ��Ͻÿ�.

��¿��� ���� ����Ͻÿ�.

1 + 1 = 2
1 + 2 = 3
1 + 3 = 4
2 + 1 = 3
2 + 2 = 4
2 + 3 = 5
3 + 1 = 4
3 + 2 = 5
3 + 3 = 6

*/
