#include <stdio.h>

union color {
	unsigned char rgb[4];
	unsigned int dword;
};

int main()
{
	union color color1 = {0};
	
	/*
	<13번 문제> 
	color1.dword = 0x00CC00FF;
	printf("red = %2X, green = %2X, blue = %2X\n",
		color1.rgb[0], color1.rgb[1], color1.rgb[2]);
	*/
	
	printf("red를 입력하세요(0~255)   : ");
	scanf("%d", &color1.rgb[0]);
	printf("green을 입력하세요(0~255) : ");
	scanf("%d", &color1.rgb[1]);
	printf("blue를 입력하세요(0~255)  : ");
	scanf("%d", &color1.rgb[2]);
	
	//입력값의 1바이트만 살리기 위해서는 mask를 씌워야한다
	color1.rgb[0] &= 0xFF;
	color1.rgb[1] &= 0xFF;
	color1.rgb[2] &= 0xFF;
	
	color1.dword = (color1.rgb[2]<<16) | (color1.rgb[1]<<8) | color1.rgb[0];
	//G를 8비트 앞으로 당겨서 넣고
	//B값은 16비트 앞으로 당겨서 넣는다 
	
	printf("color1.dword = %X\n", color1.dword);
	
	return 0;
}

/*
13번에 정의된 color 공용체를 이용해서 
사용자로부터 red, green, blue값을 
각각 0~255사이의 정수로 입력받은 후 
double word 값으로 16진수 출력하는 프로그램 작성  

red를 입력하세요(0~255)   :  
green을 입력하세요(0~255) : 
blue를 입력하세요(0~255)  : 
color1.dword = 4080FF
*/
