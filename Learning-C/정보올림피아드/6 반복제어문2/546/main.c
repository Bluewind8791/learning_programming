#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int n;
	int point, count, sum;
	float avg;
	
	scanf(" %d", &n);

	count = 1;
	sum = 0;
	
	while(1)
	{
		scanf(" %d", &point);	
		
		sum = point + sum;		
		
		count++;
		if(count > n)
			break;
	}
	
	avg = (float)sum / n;
	printf("avg : %.1f\n", avg);
	
	if ( avg >= 80 && avg <= 100 )
		printf("pass");
	
	else
		printf("fail");	
	
	return 0;
}

//10 ������ ����� n�� �־�����.

//������ �־��� n�� ������ ������ �Է¹޾Ƽ� 
//�Ǽ� ����� ���Ͽ� ����ϰ� 

//����� 80���̻��̸� "pass", 
//80�� �̸��̸� "fail"�̶�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//����� �ݿø��Ͽ� �Ҽ� ù°�ڸ����� ����Ѵ�.
