#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num1, num2, sum;
	
	scanf(" %d %d", &num1, &num2);
	
	--num2, sum = num1 * num2, num1++;
	//�ι��� ���� ���ҽ�Ű�� �� ���� ���� ���� �� ù���� ���� ������Ų��. 
	
	printf("%d %d %d", num1, num2, sum);	
	
	return 0;
}
