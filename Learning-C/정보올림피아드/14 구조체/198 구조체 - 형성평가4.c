#include <stdio.h>

typedef struct Data {
	int tall;
	double weight;
}data;

int main()
{
	data d[2];
	
	
	scanf("%d %lf", &d[0].tall, &d[0].weight);
	scanf("%d %lf", &d[1].tall, &d[1].weight);
	
	data std;
	std.tall = 5 + (d[0].tall+d[1].tall)/2;
	std.weight = ((d[0].weight+d[1].weight)/2) - 4.5;
	
	printf("height : %dcm\n", std.tall);
	printf("weight : %.1lfkg\n", std.weight);
	
	return 0;
}

/*
� �л��� Ű�� 
�ƹ����� ��Ӵ��� Ű�� ��պ��� 5cm ũ�� 
�����Դ� �ƹ����� ��Ӵ��� 
�������� ��պ��� 4.5kg �����ٰ� �Ѵ�. 

Ű�� �����Ը� ��������� ���� ����ü�� �����ϰ� 
�ƹ����� ��Ӵ��� Ű�� �����Ը� �Է¹޾� 
�л��� Ű�� �����Ը� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

Ű�� �����̸� �����ϰ� 
�����Դ� �ݿø��Ͽ� �Ҽ� ù°�ڸ����� ��Ÿ����.
*/
