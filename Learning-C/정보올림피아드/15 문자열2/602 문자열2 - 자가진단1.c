#include <stdio.h>
#include <string.h>

int main()
{
	char str[5][30];
	int i;
	char temp[30];
	
	for(i=0; i<5; i++) {
		scanf("%s", &str[i]);
	}
	
	//���� ����  
	for(i=5-1; i>2; i--) {
		strcpy(temp, str[i]);
		strcpy(str[i], str[4-i]);
		strcpy(str[4-i], temp);
	}
	
	for(i=0; i<5; i++) {
		printf("%s\n", str[i]);
	}
	
	return 0;
}

/*
5���� �ܾ �Է¹޾� 
��� �ܾ �Է¹��� 
�������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�� �ܾ��� ���̴� 30�����̴�.
*/
