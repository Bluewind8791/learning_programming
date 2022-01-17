#include <stdio.h>

#define SIZE_STR 256
#define SIZE_ARRY 5

typedef struct contact {
	char name[SIZE_STR];
	char tel[SIZE_STR];
} CONTACT;

int main(void)
{
	CONTACT contactArry[SIZE_ARRY];
	int i;
	
	for(i=0; i<SIZE_ARRY; i++) {
		printf("이    름 : ");
		scanf("%s", contactArry[i].name);
		printf("전화번호 : ");
		scanf("%s", contactArry[i].tel); 
	}

	printf("--- 전체 연락처 목록 ---\n");
	for(i=0; i<SIZE_ARRY; i++) {
		printf("%s	%s\n", contactArry[i].name, contactArry[i].tel);
	} 

	return 0;
}
