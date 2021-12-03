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
		printf("\n검색할 이름 : ");
		scanf("%s", search_name);
		
		//'.'이 입력되면 종료 
		if( strcmp(search_name, ".") == 0 ) {
			break;
		} 	
		
		//저장된 연락처인지 검색 
		for(i=0; i<=tel_cnt; i++) {
			if (strcmp(ct[i].name, search_name) == 0) {
				printf("찾은 전화번호 : %s\n", ct[i].tel);
				break;
			}
			else {
				if (i==tel_cnt) {
					printf("저장되지 않은 연락처입니다. 저장하시겠습니까? (Y/N) :");
					scanf(" %c", &answer);
					if (answer == 'y' || answer == 'Y')	{
						strcpy(ct[tel_cnt].name, search_name);
						fputs(ct[tel_cnt].name, fp);
						printf("전화번호 입력 : ");
						scanf("%s", input_tel);
						strcpy(ct[tel_cnt].tel, input_tel);
						fputs(ct[tel_cnt].tel, fp);
						printf("저장된 번호는 %d 입니다.\n", tel_cnt);
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
19번의 contact 구조체를 이용해서 이름으로 전화번호를 검색하는 프로그램

contact 구조체 배열을 이용해서
연락처는 최대 100개까지 저장

먼저 이름을 입력받아서 기존의 저장된 연락처에서
해당 이름을 찾을수 있으면
해당 연락처의 전화번호를 출력하고

찾을 수 없으면 전화번호를 입력받아서
새로운 연락처로 저장

이 프로그램은 반복수행하다가
.이 입력되면 종료 
*/
