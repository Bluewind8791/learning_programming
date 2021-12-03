#include <stdio.h>
int main(int argc, char *argv[]) {
	
	long num; 
	int times_3, times_5, count;
	
	times_3 = 0;
	times_5 = 0;
	count = 1;
	
	while(1)
	{
	
		scanf(" %d", &num);
		
			
		if (num % 3 == 0)
			times_3++;	
		
		if (num % 5 == 0) 
			times_5++; 
			
		count++;
		
		if (count > 10)
			break;
		
	}
	
	printf("Multiples of 3 : %d\n", times_3);
	printf("Multiples of 5 : %d", times_5);
	
	return 0;
}

//10개의 정수를 입력받아 
//3의 배수의 개수와 
//5의 배수의 개수를 
//각각 출력하는 프로그램을 작성하시오.


