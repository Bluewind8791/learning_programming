#include <stdio.h>

/* RGB 최하위 바이트부터 각 바이트마다 R G B 순서로 */

int main(int argc, char *argv[]) 

{

unsigned int R,G,B;
unsigned int BGR = 0;
//처음 BGR 값을 제로로 4바이트 채워놓음. 

printf("RGB 값 중 RED 값을 입력하시오(0~255): ");
scanf(" %d", &R);

printf("RGB 값 중 GREEN 값을 입력하시오(0~255): ");
scanf(" %d", &G);

printf("RGB 값 중 BLUE 값을 입력하시오(0~255): ");
scanf(" %d", &B);

printf("\n");

//입력값의 1바이트만 살리기 위해서는 mask를 씌워야한다

R &= 0xFF;
G &= 0xFF;
B &= 0xFF;

BGR = (B<<16) | (G<<8) | R;
//G를 8비트 앞으로 당겨서 넣고
//B값은 16비트 앞으로 당겨서 넣는다 

printf("RGB값은 : ");
printf("0x%x [R : 0x%02x] [G : 0x%02x] [B : 0x%02x]", BGR, R, G, B);

	return 0;
}
