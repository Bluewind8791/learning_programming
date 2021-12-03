#include <stdio.h>
#include <math.h>

int main () {
	
	double avg[6] = {85.6, 79.5, 83.1, 80.0, 78.2, 75.0};
	int i, j;
	
	scanf("%d %d",&i, &j);
	printf("%.1lf", (round(10*(avg[i-1]+avg[j-1]))/10) );
	
	return 0;
}

