#include <stdio.h>

int Power (int base, int sq) {
	int i, power = 1;
	for (i=0; i<sq; i++) {
		power = base * power;
	}
	return power;
}

int main() {
	int n1, n2;
	scanf(" %d %d", &n1, &n2);
	
	printf("%d", Power(n1,n2));

	return 0;
}




