
/* Lab06.c */

#include <stdio.h>

unsigned int Make_RGB(unsigned int red, unsigned int green, unsigned int blue);
unsigned int Get_Red(unsigned int rgb);
unsigned int Get_Green(unsigned int rgb);
unsigned int Get_Blue(unsigned int rgb);

int main(void)
{
	unsigned int r, g, b;
	unsigned int rgb;
	
	////////////////// Compose RGB /////////////////////////
	printf("red를 입력하세요(0~255) : ");
	scanf("%d", &r); 

	printf("green을 입력하세요(0~255) : ");
	scanf("%d", &g); 

	printf("blue를 입력하세요(0~255) : ");
	scanf("%d", &b); 

	rgb = Make_RGB(r, g, b);
	printf("RGB값: %06x\n\n", rgb);
	
	///////////////// Decompose R, G, B /////////////////////
	printf("RGB 값을 16진수로 입력하세요 : ");
	scanf("%x", &rgb);
	
	printf("RGB 값 %06x중 red	: %3d\n", rgb, Get_Red(rgb));
	printf("RGB 값 %06x중 green	: %3d\n", rgb, Get_Green(rgb));
	printf("RGB 값 %06x중 blue	: %3d\n", rgb, Get_Blue(rgb)); 
	
	return 0;
}


unsigned int Make_RGB(unsigned int red, unsigned int green, unsigned int blue)
{
	return (red | (green<<8) | (blue<<16));
}


unsigned int Get_Red(unsigned int rgb)
{
	return (rgb & 0x000000FF);
}


unsigned int Get_Green(unsigned int rgb)
{
	return ((rgb & 0x0000FF00) >> 8);
}


unsigned int Get_Blue(unsigned int rgb)
{
	return ((rgb & 0x00FF0000) >> 16);
}






