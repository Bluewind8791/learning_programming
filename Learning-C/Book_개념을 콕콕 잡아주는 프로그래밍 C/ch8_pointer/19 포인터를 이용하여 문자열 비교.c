#include <stdio.h>
#include <string.h>

/*
문자열을 2개 입력 받아서
두 문자열을 대소문자 구분하지않고
비교해서 같은지 
여부를 출력하는 프로그램을 작성하시오 

두 문자열을 비교할때는
문자열 포인터 변수를 이용 
*/

/*----------------------- Using Library Fuction: ---------------------------*/
/****************************************************************************

int main()
{
	char str1_src[100], str1_dst[100];
	char str2_src[100], str2_dst[100];
	char *p1 = str1_dst;
	char *p2 = str2_dst;
	
	printf("첫번째 문자열을 입력하세요 : ");
	gets(str1_src);
	printf("두번째 문자열을 입력하세요 : ");
	gets(str2_src);
	
	strcpy(str1_dst, str1_src);
	strcpy(str2_dst, str2_src);

	strlwr(p1);
	strlwr(p2);
	//모두 소문자로 변경 
	
	if( strcmp(p2, p1) == 0) {
		printf("%s와(과) %s는(은)같습니다.\n", str1_src, str2_src);
	}
	else	{
		printf("%s와(과) %s는(은)다릅니다.\n", str1_src, str2_src);
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
		
	printf("첫번째 문자열을 입력하세요 : ");
	gets(p1);
	printf("두번째 문자열을 입력하세요 : ");
	gets(p2);
	
	//소문자로 변경 
	GetStringLower (str1);
	GetStringLower (str2);

	//비교하여 출력  
	for(i=0; ; i++) {
		if (p1[i] != p2[i]) {
			printf("%s와(과) %s는(은)다릅니다.\n", p1, p2);
			break;
		}
		else if (p1[i]=='\0' && p2[i]=='\0') {
			printf("%s와(과) %s는(은)같습니다.\n", p1, p2);
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
