#include <stdio.h>
#include <string.h>

#define SIZE_STR 256
#define SIZE_ARRY 100

typedef struct contact {
	char name[SIZE_STR];
	char tel[SIZE_STR];
} CONTACT;

int main(void)
{
	CONTACT contactArry[SIZE_ARRY] = {0};
	char nameCurrent[SIZE_STR] = "";
	char yesOrNo[SIZE_STR] = "N";
	int contactCount = 0, i;
	
	while(1) {
		printf("\n�˻��� �̸� : ");
		scanf("%s", nameCurrent);
		
		if(strcmp(nameCurrent, ".") == 0) {
			break;
		}
		
		for(i=0; i<contactCount; i++) {
			if(strcmp(nameCurrent, contactArry[i].name) == 0) {
				printf("ã�� ��ȭ��ȣ : %s\n", contactArry[i].tel);
				break; 
			}
		} 
		
		if(i == contactCount) {
			printf("������� ���� ����ó�Դϴ�. �����Ͻðڽ��ϱ�? (Y/N) : ");
			scanf("%s", &yesOrNo); 
			if((strcmp(yesOrNo, "Y")==0) || (strcmp(yesOrNo, "y")==0)) {
				
				strcpy(contactArry[contactCount].name, nameCurrent);
				printf("��ȭ��ȣ �Է� : ");
				scanf("%s", contactArry[contactCount].tel);
				contactCount++;
			} // end if(yesOrNo~~)
		} // end if(i== contactCount)
	} // end while(1)

	return 0;
}
















