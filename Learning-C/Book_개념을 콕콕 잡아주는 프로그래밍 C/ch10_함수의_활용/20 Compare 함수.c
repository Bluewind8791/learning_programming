#include <stdio.h>
#include <string.h>
#include <ctype.h>		//tolower 포함 라이브러리 함수  
#define DIV 1				//대소문자 구분  
#define NODIV 0			//대소문자 구분 안함  

int Compare(char *str1, char *str2, int judge)
{
	//대소문자 구분 안할 때, 두 문자열 소문자로 변경  
	if (judge == NODIV) {
		for(int i=0; ; i++) {
			str1[i] = tolower(str1[i]);
			str2[i] = tolower(str2[i]);
			if (str1[i]=='\0' && str2[i]=='\0') {
				break;
			}
		}
	}
	
	//for문을 사용하여 문자 하나하나 비교  
	for(int i=0; ; i++) {
		//모두 끝에 다 닿았을 경우  
		if (str1[i]=='\0' && str2[i]=='\0') {
			return 0;	//문자열이 같음  
			break;
		}
		//i번째 문자가 다를 경우   
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];	//i번째 문자 비교  
		}
	}
}

int main()
{
	char str1[] = "hello worldssss";
	char str2[] = "hello world";
	
	char judge;
	int DIVorNOT = 0;
	
	printf("첫번째 문자열 : %s\n", str1);
	printf("두번째 문자열 : %s\n", str2);
	
	printf("대소문자를 구분 할까요? (Y/N) : ");
	scanf(" %c", &judge);
	
	if(judge == 'Y' || judge == 'y') {
		DIVorNOT = 1;
	}
	
	if(Compare(str1, str2, DIVorNOT) == 0) {
		printf("두 문자열이 같습니다.\n");
	}
	else if(Compare(str1, str2, DIVorNOT) > 0) {
		printf("두 문자열이 다르며, 첫번째 문자열이 두번째 문자열보다 큽니다.\n");
	}
	else if(Compare(str1, str2, DIVorNOT) < 0) {
		printf("두 문자열이 다르며, 첫번째 문자열이 두번째 문자열보다 작습니다.\n");
	}
	
	return 0;
}

/*
두개의 문자열을 인자로 받아 비교하는 Compare 함수 

두 문자열이 같으면 0
첫번째 문자열이 두번째 문자열보다 크면 0보다 큰값 
그렇지않으면 0보다 작은값을 리턴 

또한 대소문자 구분 여부를 인자로 받고 
0이면 대소문자 구분안하고 
1이면 대소문자 구분 
*/ 
