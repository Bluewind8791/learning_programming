#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{

//후치증가 연산자를 사용하여 출력한 후
//전치 증가 연산자를 사용하여 
//출력하는프로그램을 작성하시오.

int num1;

scanf(" %d", &num1);

printf("%d\n", num1++);
printf("%d", ++num1);


	return 0;
}
