

#include <stdio.h>

int  main(void)
{
	float area;
	float pyeung;
	
	printf("Input area [square meter] : ");
	scanf("%f", &area);
	
	pyeung = area / 3.3058;
	
	printf("%.4f [square meter] is %.2f [pyeung]\n", area, pyeung);
	
	return 0;
}
