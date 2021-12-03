#include <stdio.h>

int main(void) 

{


int inum = 50;
float fnum = 100.12;

printf("%.2f * %d = %.0f\n\n", fnum, inum, inum * fnum);



int ins1, ins2, ins3;

scanf(" %d %d %d", &ins1, &ins2, &ins3);

printf("sum = %d\navg = %d\n", ins1+ins2+ins3, (ins1+ins2+ins3)/3);



	return 0;
}
