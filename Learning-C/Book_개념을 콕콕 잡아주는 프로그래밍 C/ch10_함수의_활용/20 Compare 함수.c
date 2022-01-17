#include <stdio.h>
#include <string.h>
#include <ctype.h>		//tolower ���� ���̺귯�� �Լ�  
#define DIV 1				//��ҹ��� ����  
#define NODIV 0			//��ҹ��� ���� ����  

int Compare(char *str1, char *str2, int judge)
{
	//��ҹ��� ���� ���� ��, �� ���ڿ� �ҹ��ڷ� ����  
	if (judge == NODIV) {
		for(int i=0; ; i++) {
			str1[i] = tolower(str1[i]);
			str2[i] = tolower(str2[i]);
			if (str1[i]=='\0' && str2[i]=='\0') {
				break;
			}
		}
	}
	
	//for���� ����Ͽ� ���� �ϳ��ϳ� ��  
	for(int i=0; ; i++) {
		//��� ���� �� ����� ���  
		if (str1[i]=='\0' && str2[i]=='\0') {
			return 0;	//���ڿ��� ����  
			break;
		}
		//i��° ���ڰ� �ٸ� ���   
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];	//i��° ���� ��  
		}
	}
}

int main()
{
	char str1[] = "hello worldssss";
	char str2[] = "hello world";
	
	char judge;
	int DIVorNOT = 0;
	
	printf("ù��° ���ڿ� : %s\n", str1);
	printf("�ι�° ���ڿ� : %s\n", str2);
	
	printf("��ҹ��ڸ� ���� �ұ��? (Y/N) : ");
	scanf(" %c", &judge);
	
	if(judge == 'Y' || judge == 'y') {
		DIVorNOT = 1;
	}
	
	if(Compare(str1, str2, DIVorNOT) == 0) {
		printf("�� ���ڿ��� �����ϴ�.\n");
	}
	else if(Compare(str1, str2, DIVorNOT) > 0) {
		printf("�� ���ڿ��� �ٸ���, ù��° ���ڿ��� �ι�° ���ڿ����� Ů�ϴ�.\n");
	}
	else if(Compare(str1, str2, DIVorNOT) < 0) {
		printf("�� ���ڿ��� �ٸ���, ù��° ���ڿ��� �ι�° ���ڿ����� �۽��ϴ�.\n");
	}
	
	return 0;
}

/*
�ΰ��� ���ڿ��� ���ڷ� �޾� ���ϴ� Compare �Լ� 

�� ���ڿ��� ������ 0
ù��° ���ڿ��� �ι�° ���ڿ����� ũ�� 0���� ū�� 
�׷��������� 0���� �������� ���� 

���� ��ҹ��� ���� ���θ� ���ڷ� �ް� 
0�̸� ��ҹ��� ���о��ϰ� 
1�̸� ��ҹ��� ���� 
*/ 
