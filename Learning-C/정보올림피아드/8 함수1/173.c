#include <stdio.h>

int Result (int n1, int n2) {
	int result;
	if (n1 > n2) {
		result = (n1 * n1) - (n2 * n2) ;
	}
	else if (n2 > n1) {
		result = (n2 * n2) - (n1 * n1);		
	}
	return result;
}


int main() {
	
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("%d",Result (num1, num2));
	
	return 0;
}
