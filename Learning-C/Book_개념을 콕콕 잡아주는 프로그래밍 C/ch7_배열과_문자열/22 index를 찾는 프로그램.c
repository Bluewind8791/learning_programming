#include <stdio.h>

int main()
{
	int i;
	int a[10]={0,};
	
	//배열 초기화
	for(i=0;i<10;i++)
	{
		a[i]=(i+1)*5;
	}
	
	//배열 확인
	printf("배열 정보는 아래와 같습니다.\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	
	int index=0;
	int find=0;
	
	printf("배열에서 검색할 값을 입력하시오 : ");
	scanf("%d",&find);
	
	for(i=0;i<10;i++)
	{
		if (a[i]==find)
		{
			index = i+1;
		}
	}

	printf("검색한 값은 %d 번째에 있습니다.",index);	 
	
	return 0;
}
/*
크기가 10인 int형 배열에 대하여
특정 값을 갖는 원소를 찾아서
그 위치(인덱스)를 알려주는 프로그램을 작성

특정 값을 갖는 원소를 찾으면
찾은 원소의 인덱스를 출력하고
찾지 못하면 에러메세지를 출력

배열은 미리 초기화해두고 사용하고
배열에서 검색할 값은 사용자로부터 입력을 받는다. 
*/
