
#include <stdio.h>

int Get_Round(float num);

int main(void)
{
	float floatVal;
	
	printf("Input real number : ");
	scanf("%f", &floatVal);
	
	printf("Rounded Value : %d\n", Get_Round(floatVal));
	
	return 0;
}


int Get_Round(float num)
{
	if(num < 0) {
		num -= 0.5;
	}
	else {
		num += 0.5;
	}
	
	return ((int)num);
}
