#include <stdio.h>

int main()
{
	int x;
	int *p;
	p = &x;
	//x의 주소를 p에 대입 
	
	scanf("%d",&*p);
	//p가 가르키는 주소(x)에 입력 
	
	printf("%d...%d", x/10, x%10);
	
	
	return 0;
}
/*
정수형 포인터를 이용하여 
값을 입력받고 

입력받은 값을 10으로 나눈 몫과 
나머지를 출력하는 프로그램을 작성하시오.
*/

