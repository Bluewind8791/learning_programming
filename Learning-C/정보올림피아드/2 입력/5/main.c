#include <stdio.h>
int main(void) 
{

float yard;
float inch;
	scanf("%f", &yard);
	yard = 2.1;
	printf("%4.1fyd = %5.1fcm\n", yard, yard*91.44);
	scanf("%f", &inch);
	inch = 10.5;
	printf("%4.1fin = %5.1fcm\n", inch, inch*2.54);


int height;
printf("height = ");
scanf("%d", &height);
printf("Your height is %dcm.", height);



int insert1, insert2;

scanf("%d", &insert1);
scanf("%d", &insert2);

printf("%d * %d = %d\n", insert1, insert2, insert1*insert2);
printf("%d / %d = %d\n", insert1, insert2, insert1/insert2);


	return 0;
}
