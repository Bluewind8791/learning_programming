#include <stdio.h>

int Round ();
	
int main(int argc, char *argv[]) {
	double n;
	while(1) {
		scanf("%lf", &n);
		if (n == 0) {
			return;
		}
		printf("Round value = %d\n", Round(n) );
	}
	return 0;
}

int Round (double num) {
	int round;		//return value
	if (num > 0) {
		if ( (num - (int)num) + 0.5 >= 1 ) {	
			round = num + 1;
		} 
		else {
			round = (int)num;
		} 
	}
	else if (num < 0) {
		if ( (num + (int)num) - 0.5 >= -1 ) {	
			round = num - 1;
		}
		else {
			round = (unsigned int)num;
		}
	}
	return round;
}


/* �Ǽ� ���� ���ڷ� �޾Ƽ�
�Ҽ� ù° �ڸ����� �ݿø��� �������� �����ϴ�
Round �Լ��� �����϶�.

�ݿø��Լ� Round�� ����϶��� �����϶� ��� ����

�������
1.2�� 1��
1.7�� 2�� ����

-1.2�� -1��
-1.7�� -2�� ����
*/ 
