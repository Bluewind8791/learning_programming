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
		printf("��    �� : ");
		scanf("%s", contactArry[i].name);
		printf("��ȭ��ȣ : ");
		scanf("%s", contactArry[i].tel); 
	}

	printf("--- ��ü ����ó ��� ---\n");
	for(i=0; i<SIZE_ARRY; i++) {
		printf("%s	%s\n", contactArry[i].name, contactArry[i].tel);
	} 

	return 0;
}
