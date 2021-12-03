#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Contact {
	char name[20];
	char tel[20];
}contact;

int main()
{
	contact ct[100];
	char search_name[20];
	char answer;
	char input_tel[20] = {0};
	int tel_cnt = 0;
	int i;
	
	FILE *fp = fopen("Contact.txt", "a");
	int fsync(fp);
	
	while(1)
	{
		printf("\n�˻��� �̸� : ");
		scanf("%s", search_name);
		
		//'.'�� �ԷµǸ� ���� 
		if( strcmp(search_name, ".") == 0 ) {
			break;
		} 	
		
		//����� ����ó���� �˻� 
		for(i=0; i<=tel_cnt; i++) {
			if (strcmp(ct[i].name, search_name) == 0) {
				printf("ã�� ��ȭ��ȣ : %s\n", ct[i].tel);
				break;
			}
			else {
				if (i==tel_cnt) {
					printf("������� ���� ����ó�Դϴ�. �����Ͻðڽ��ϱ�? (Y/N) :");
					scanf(" %c", &answer);
					if (answer == 'y' || answer == 'Y')	{
						strcpy(ct[tel_cnt].name, search_name);
						fputs(ct[tel_cnt].name, fp);
						printf("��ȭ��ȣ �Է� : ");
						scanf("%s", input_tel);
						strcpy(ct[tel_cnt].tel, input_tel);
						fputs(ct[tel_cnt].tel, fp);
						printf("����� ��ȣ�� %d �Դϴ�.\n", tel_cnt);
						tel_cnt++;
						break;
					}
					else { break;
					}
				}
			}
		}
	}
	
	fclose(fp);
	
	return 0;
}


/*
19���� contact ����ü�� �̿��ؼ� �̸����� ��ȭ��ȣ�� �˻��ϴ� ���α׷�

contact ����ü �迭�� �̿��ؼ�
����ó�� �ִ� 100������ ����

���� �̸��� �Է¹޾Ƽ� ������ ����� ����ó����
�ش� �̸��� ã���� ������
�ش� ����ó�� ��ȭ��ȣ�� ����ϰ�

ã�� �� ������ ��ȭ��ȣ�� �Է¹޾Ƽ�
���ο� ����ó�� ����

�� ���α׷��� �ݺ������ϴٰ�
.�� �ԷµǸ� ���� 
*/
