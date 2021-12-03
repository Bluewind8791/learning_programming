#include <stdio.h>

int main(void)
{
	int num[10];
	int i, cntPlus = 0, cntMinus = 0, cntZero = 0;
	
	printf("Input 10 numbers : ");
	for(i=0; i<10; i++) {
		scanf("%d", &num[i]);
	}
		
	for(i=0; i<10; i++) {
		if(num[i] == 0) {
			cntZero++;
		}
		else if(num[i] > 0) {
			cntPlus++;
		}
		else {
			cntMinus++;
		}
	}
	
	printf("Count [+] : %d\n", cntPlus);
	printf("Count [-] : %d\n", cntMinus);
	printf("Count [0] : %d\n", cntZero);
	
	return 0;
}
