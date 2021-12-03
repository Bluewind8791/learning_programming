#include <stdio.h>

int TotalSum (n1, n2, n3) {
	int total;
	total = n1 + n2 + n3;
	return total;
}

int main() {
	
	int x, score1, score2, score3;
	int a = 0, b = 0, c = 0;
	for (x=0; x<3; x++) {
		scanf("%d %d %d", &score1, &score2, &score3);
		printf("%d %d %d ", score1, score2, score3);
		printf("%d\n",TotalSum (score1, score2, score3));	
		a += score1;
		b += score2;
		c += score3;	
	}
	printf("%d %d %d %d", a, b, c, a+b+c);
	return 0;
}
