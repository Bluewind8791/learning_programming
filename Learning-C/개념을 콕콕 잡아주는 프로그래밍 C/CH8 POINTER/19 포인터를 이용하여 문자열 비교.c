#include <stdio.h>
#include <string.h>

/*
���ڿ��� 2�� �Է� �޾Ƽ�
�� ���ڿ��� ��ҹ��� ���������ʰ�
���ؼ� ������ 
���θ� ����ϴ� ���α׷��� �ۼ��Ͻÿ� 

�� ���ڿ��� ���Ҷ���
���ڿ� ������ ������ �̿� 
*/

/*----------------------- Using Library Fuction: ---------------------------*/
/****************************************************************************

int main()
{
	char str1_src[100], str1_dst[100];
	char str2_src[100], str2_dst[100];
	char *p1 = str1_dst;
	char *p2 = str2_dst;
	
	printf("ù��° ���ڿ��� �Է��ϼ��� : ");
	gets(str1_src);
	printf("�ι�° ���ڿ��� �Է��ϼ��� : ");
	gets(str2_src);
	
	strcpy(str1_dst, str1_src);
	strcpy(str2_dst, str2_src);

	strlwr(p1);
	strlwr(p2);
	//��� �ҹ��ڷ� ���� 
	
	if( strcmp(p2, p1) == 0) {
		printf("%s��(��) %s��(��)�����ϴ�.\n", str1_src, str2_src);
	}
	else	{
		printf("%s��(��) %s��(��)�ٸ��ϴ�.\n", str1_src, str2_src);
	}
	
	return 0;
}

/*----------------------------- Not Use Library: ---------------------------*/
/****************************************************************************/
char GetStringLower (char str[100]);

int main() {
	char str1[100]={0};
	char str2[100]={0};
	char *p1 = str1;
	char *p2 = str2;
	int i;
		
	printf("ù��° ���ڿ��� �Է��ϼ��� : ");
	gets(p1);
	printf("�ι�° ���ڿ��� �Է��ϼ��� : ");
	gets(p2);
	
	//�ҹ��ڷ� ���� 
	GetStringLower (str1);
	GetStringLower (str2);

	//���Ͽ� ���  
	for(i=0; ; i++) {
		if (p1[i] != p2[i]) {
			printf("%s��(��) %s��(��)�ٸ��ϴ�.\n", p1, p2);
			break;
		}
		else if (p1[i]=='\0' && p2[i]=='\0') {
			printf("%s��(��) %s��(��)�����ϴ�.\n", p1, p2);
			break;
		}
	}
	
	return 0;
}

char GetStringLower (char str[100]) {
	int i;
	for (i=0; ; i++) {
		if (str[i] == '\0') {
			break;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
	return str;
}
