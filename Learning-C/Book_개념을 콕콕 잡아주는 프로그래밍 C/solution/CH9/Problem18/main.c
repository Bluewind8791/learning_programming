#include <stdio.h>

typedef union color {
	unsigned char rgb[4];
	unsigned int dword;
} COLOR;


int main(void)
{
	COLOR color1;
	
	printf("red를 입력하세요 (0~255)	: ");
	scanf("%d", &color1.rgb[0]);
	printf("green을 입력하세요 (0~255)	: ");
	scanf("%d", &color1.rgb[1]);
	printf("blue를 입력하세요 (0~255)	: ");
	scanf("%d", &color1.rgb[2]); 
	
	printf("color1.dword = %X\n", color1.dword);

	return 0;
}
