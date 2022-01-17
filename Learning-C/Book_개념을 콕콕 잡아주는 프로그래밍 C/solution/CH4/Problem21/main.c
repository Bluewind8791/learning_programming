

#include <stdio.h>

int main(void)
{
	unsigned int r, g, b;
	unsigned int abgr = 0;
	
	printf("Input Red, Green, Blue value [decimal : 0 ~ 255] : ");
	scanf("%d %d %d", &r, &g, &b);
	
	r &= 0xFF;
	g &= 0xFF;
	b &= 0xFF;
		
	abgr = (b<<16) | (g<<8) | r;
	
	printf("RGB value : %#0.8x [R:%#02x] [G:%#02x] [B:%#02x]\n", abgr, r, g, b);
	
	return 0;
}
