#include <stdio.h>

union color {
	unsigned char rgb[4];
	unsigned int dword;
};

int main()
{
	union color color1 = {0};
	
	/*
	<13�� ����> 
	color1.dword = 0x00CC00FF;
	printf("red = %2X, green = %2X, blue = %2X\n",
		color1.rgb[0], color1.rgb[1], color1.rgb[2]);
	*/
	
	printf("red�� �Է��ϼ���(0~255)   : ");
	scanf("%d", &color1.rgb[0]);
	printf("green�� �Է��ϼ���(0~255) : ");
	scanf("%d", &color1.rgb[1]);
	printf("blue�� �Է��ϼ���(0~255)  : ");
	scanf("%d", &color1.rgb[2]);
	
	//�Է°��� 1����Ʈ�� �츮�� ���ؼ��� mask�� �������Ѵ�
	color1.rgb[0] &= 0xFF;
	color1.rgb[1] &= 0xFF;
	color1.rgb[2] &= 0xFF;
	
	color1.dword = (color1.rgb[2]<<16) | (color1.rgb[1]<<8) | color1.rgb[0];
	//G�� 8��Ʈ ������ ��ܼ� �ְ�
	//B���� 16��Ʈ ������ ��ܼ� �ִ´� 
	
	printf("color1.dword = %X\n", color1.dword);
	
	return 0;
}

/*
13���� ���ǵ� color ����ü�� �̿��ؼ� 
����ڷκ��� red, green, blue���� 
���� 0~255������ ������ �Է¹��� �� 
double word ������ 16���� ����ϴ� ���α׷� �ۼ�  

red�� �Է��ϼ���(0~255)   :  
green�� �Է��ϼ���(0~255) : 
blue�� �Է��ϼ���(0~255)  : 
color1.dword = 4080FF
*/
