#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int i,count;
	
	count = 0;
	
	for (i = 10; ;)
	{
		printf("%d ", i);
		i++;
		count++;
		
		if (count > 10)
			break;
		
	}


	return 0;
}

/*10���� 20������ ���ڸ� 
���ʴ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
for���� ����ϼ���.
*/
