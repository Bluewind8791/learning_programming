#include <stdio.h>

/* ������ �������ͷ� �Է¹޾Ƽ�
�հ�� ���, �ִ밪�� �ּҰ��� ���ؼ�
����ϴ� ���α׷�*/
 
int main(int argc, char *argv[]) 
{

	int ping, meter;
	
	printf("�������� ������ ������ �Է����ֽʽÿ� :");
	scanf(" %d", &meter);
	
	ping = meter / 3.3058;
	
	printf("�Է��Ͻ� ������ ����� %d�� �Դϴ�.", ping);


	return 0;
}
