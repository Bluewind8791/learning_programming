#include <stdio.h>

/* RGB ������ ����Ʈ���� �� ����Ʈ���� R G B ������ */

int main(int argc, char *argv[]) 

{

unsigned int R,G,B;
unsigned int BGR = 0;
//ó�� BGR ���� ���η� 4����Ʈ ä������. 

printf("RGB �� �� RED ���� �Է��Ͻÿ�(0~255): ");
scanf(" %d", &R);

printf("RGB �� �� GREEN ���� �Է��Ͻÿ�(0~255): ");
scanf(" %d", &G);

printf("RGB �� �� BLUE ���� �Է��Ͻÿ�(0~255): ");
scanf(" %d", &B);

printf("\n");

//�Է°��� 1����Ʈ�� �츮�� ���ؼ��� mask�� �������Ѵ�

R &= 0xFF;
G &= 0xFF;
B &= 0xFF;

BGR = (B<<16) | (G<<8) | R;
//G�� 8��Ʈ ������ ��ܼ� �ְ�
//B���� 16��Ʈ ������ ��ܼ� �ִ´� 

printf("RGB���� : ");
printf("0x%x [R : 0x%02x] [G : 0x%02x] [B : 0x%02x]", BGR, R, G, B);

	return 0;
}
