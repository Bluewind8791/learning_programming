#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	int arr[10] = {0};
	int i;
	
	printf("[���� �迭] ");
	for(i=0; i<10; i++)
	{
		arr[i] = rand() % 100+1;
		printf("%3d", arr[i]);
	}
	printf("\n");
		
	int n;
	printf("�������� �Է��ϼ��� : ");
	scanf("%d", &n);
	
	int *p = arr;
	for(i=0; i<10; i++)
	{
		p[i] = p[i] + n;
	}
	
	printf("[���� �� �迭] ");
	for(i=0; i<10; i++)
	{
		printf("%3d", arr[i]);
	}
	
	return 0;
}

/*
���� ���� �ϳ� �Է� �޾Ƽ�
������ �迭�� ��� ���Ҹ� Ư�� ����ŭ
������Ű�� ���α׷��� �ۼ��Ͻÿ�

�� ������ �迭�� ���Ҹ� ������ų ��
�����͸� �̿��Ͻÿ� 
*/
