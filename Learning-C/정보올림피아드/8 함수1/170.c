#include <stdio.h>

void Print () {
	printf("@@@@@@@@@@\n");
}

int main(int argc, char *argv[]) {
	
	printf("first\n");
	Print ();
	printf("second\n");
	Print ();
	printf("third\n");
	Print ();
	
	return 0;
}

/* 
 170 : �Լ�1 - ������1

��@�����ڸ� 10�� ����ϴ� �Լ��� �ۼ� �� �� 
�Լ��� �� �� ȣ���Ͽ� 
�Ʒ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

first
@@@@@@@@@@
second
@@@@@@@@@@
third
@@@@@@@@@@

*/

