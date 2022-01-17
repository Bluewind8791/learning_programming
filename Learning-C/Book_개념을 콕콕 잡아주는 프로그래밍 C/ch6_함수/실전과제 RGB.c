#include <stdio.h>

/* RGB ������ ����Ʈ���� �� ����Ʈ���� R G B ������ */

 RGB (Rd, Gn, Bl) {
	unsigned int BGR;
	
	//�Է°��� 1����Ʈ�� �츮�� ���ؼ��� mask�� �������Ѵ�
	Rd &= 0xFF;
	Gn &= 0xFF;
	Bl &= 0xFF;
	
	BGR = (Bl<<16) | (Gn<<8) | Rd;
	//G�� 8��Ʈ ������ ��ܼ� �ְ�
	//B���� 16��Ʈ ������ ��ܼ� �ִ´� 

	return BGR;	
}

unsigned char RedColor (rgb) {
	return (rgb & 0x0000ff);
}

unsigned char GreenColor (rgb) {
	return (rgb & 0x00ff00) >> 8;
}

unsigned char BlueColor (rgb) {
	return (rgb & 0xff0000) >> 16;
}


int main() {
	unsigned int R,G,B;
	unsigned int rgb;
	
	//ó�� BGR ���� ���η� 4����Ʈ ä������. 
	printf("RED ���� �Է��Ͻÿ�(0~255): ");
	scanf(" %d", &R);
	printf("GREEN ���� �Է��Ͻÿ�(0~255): ");
	scanf(" %d", &G);
	printf("BLUE ���� �Է��Ͻÿ�(0~255): ");
	scanf(" %d", &B);
	
	printf("RGB �� : %x\n", RGB (R,G,B) );
	
	printf("RGB ���� 16������ �Է��ϼ��� : ");
	scanf("%x", &rgb);
	
	printf("RGB �� %06x �� RED   : %3d\n", rgb, RedColor (rgb) );
	printf("RGB �� %06x �� GREEN : %3d\n", rgb, GreenColor (rgb) );
	printf("RGB �� %06x �� BLUE  : %3d\n", rgb, BlueColor (rgb) );


	return 0;
}
