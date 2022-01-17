
#include <stdio.h>

int main(void)
{
	float inch, cm;
	
	printf("Input Lenth in inch : ");
	scanf("%f", &inch);
	
	cm = inch * 2.54f;
	
	printf("%.2f[inch] = %.2f[cm]\n", inch, cm);
	
	return 0;
}
