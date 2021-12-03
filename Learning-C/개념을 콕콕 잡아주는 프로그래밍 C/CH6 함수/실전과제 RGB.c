#include <stdio.h>

/* RGB 최하위 바이트부터 각 바이트마다 R G B 순서로 */

 RGB (Rd, Gn, Bl) {
	unsigned int BGR;
	
	//입력값의 1바이트만 살리기 위해서는 mask를 씌워야한다
	Rd &= 0xFF;
	Gn &= 0xFF;
	Bl &= 0xFF;
	
	BGR = (Bl<<16) | (Gn<<8) | Rd;
	//G를 8비트 앞으로 당겨서 넣고
	//B값은 16비트 앞으로 당겨서 넣는다 

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
	
	//처음 BGR 값을 제로로 4바이트 채워놓음. 
	printf("RED 값을 입력하시오(0~255): ");
	scanf(" %d", &R);
	printf("GREEN 값을 입력하시오(0~255): ");
	scanf(" %d", &G);
	printf("BLUE 값을 입력하시오(0~255): ");
	scanf(" %d", &B);
	
	printf("RGB 값 : %x\n", RGB (R,G,B) );
	
	printf("RGB 값을 16진수로 입력하세요 : ");
	scanf("%x", &rgb);
	
	printf("RGB 값 %06x 중 RED   : %3d\n", rgb, RedColor (rgb) );
	printf("RGB 값 %06x 중 GREEN : %3d\n", rgb, GreenColor (rgb) );
	printf("RGB 값 %06x 중 BLUE  : %3d\n", rgb, BlueColor (rgb) );


	return 0;
}
