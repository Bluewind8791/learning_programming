#include <stdio.h>

void Print () {
	printf("@@@@@@@@@@\n");
}

int main(int argc, char *argv[]) {
	
	printf("first\n");
	Print ();
	printf("second\n");
	Print ();
	printf("third\n");
	Print ();
	
	return 0;
}

/* 
 170 : 함수1 - 형성평가1

‘@’문자를 10개 출력하는 함수를 작성 한 후 
함수를 세 번 호출하여 
아래와 같이 출력하는 프로그램을 작성하시오.

first
@@@@@@@@@@
second
@@@@@@@@@@
third
@@@@@@@@@@

*/

