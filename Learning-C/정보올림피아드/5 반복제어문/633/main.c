#include <stdio.h>
int main(int argc, char *argv[]) 
{
int base, height;
char cont;
float width;

while(1)
{
	
	printf("Base = ");
	scanf(" %d", &base);
	
	printf("Height = ");
	scanf(" %d", &height);
	
	width = (float)( base * height ) / 2;
	
	printf("Triangle width = %.1f\n", width);
	
	printf("Continue? ");
	scanf(" %c", &cont);
	
	if (!( cont == 'Y' || cont == 'y' ))
		break;

}
	return 0;
}


/*
삼각형의 밑변의 길이와 높이를 입력받아 넓이를 출력하고, 
"Continue? "에서 하나의 문자를 입력받아 
그 문자가 'Y' 나 'y' 이면 작업을 반복하고 
다른 문자이면 종료하는 프로그램을 작성하시오.
(넓이는 반올림하여 소수 첫째자리까지 출력한다.)?
*/
