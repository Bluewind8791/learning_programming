#include <stdio.h>

int main(int argc, char *argv[]) {
	
	
int num;

while(1)
{
	scanf(" %d", &num);	
	
	if ( num % 3 == 0)
		printf("%d\n", num/3);	
		
	if ( num == -1)
		break;
}

	
	return 0;
}

/*������ �Է¹޾Ƽ� 3�� ����� �ƴ� ��쿡�� �ƹ� �۾��� ���� �ʰ� 
3�� ����� ��쿡�� 3���� �������� ����ϴ� �۾��� �ݺ��ϴٰ�
-1�� �ԷµǸ� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.*/
