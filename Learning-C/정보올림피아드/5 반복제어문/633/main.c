#include <stdio.h>
int main(int argc, char *argv[]) 
{
int base, height;
char cont;
float width;

while(1)
{
	
	printf("Base = ");
	scanf(" %d", &base);
	
	printf("Height = ");
	scanf(" %d", &height);
	
	width = (float)( base * height ) / 2;
	
	printf("Triangle width = %.1f\n", width);
	
	printf("Continue? ");
	scanf(" %c", &cont);
	
	if (!( cont == 'Y' || cont == 'y' ))
		break;

}
	return 0;
}


/*
�ﰢ���� �غ��� ���̿� ���̸� �Է¹޾� ���̸� ����ϰ�, 
"Continue? "���� �ϳ��� ���ڸ� �Է¹޾� 
�� ���ڰ� 'Y' �� 'y' �̸� �۾��� �ݺ��ϰ� 
�ٸ� �����̸� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
(���̴� �ݿø��Ͽ� �Ҽ� ù°�ڸ����� ����Ѵ�.)?
*/
