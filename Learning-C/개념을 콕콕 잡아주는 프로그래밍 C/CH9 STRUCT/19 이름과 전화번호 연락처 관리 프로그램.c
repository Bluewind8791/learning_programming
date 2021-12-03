#include <stdio.h>

typedef struct Contact {
	char name[20];
	char tel[20];
}contact;

int main()
{
	contact ct[5];
	int i;
	
	for(i=0; i<5; i++){
		printf("이    름 : ");
		gets(ct[i].name);
		printf("전화번호 : ");
		gets(ct[i].tel);
	}
	
	printf("--- 전체 연락처 목록 ---\n");
	for(i=0; i<5; i++){
		printf("%s ", ct[i].name);
		printf("%30s\n", ct[i].tel);
	}
	
	return 0;
}

/*
이름과 전화번호를 저장하는 간단한 연락처 관리 프로그램

이름과 전화번호를 멤버로 갖는 contact 구조체 정의

이름과 전화번호는 각각 문자열로 저장
그 다음 크기가 5인 contact 구조체 배열을 이용하여
이름과 전화번호를 입력받아 출력하는 프로그램 
*/
