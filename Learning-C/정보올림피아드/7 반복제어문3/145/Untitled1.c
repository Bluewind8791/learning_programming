# include <stdio.h>

int main ()
{
	
	int n, x, y;
	int num = 1;
	scanf(" %d", &n);
	
	for (y=0; y<n; y++) {

		for (x=0; x<2*n-2-2*y; x++) {
			printf(" ");
		}
		num = 1;
		for (x=0; x<1+y; x++) {
			printf("%d ", num+x);
		}
		printf("\n");
	}
	return 0;
}

/*
자연수 n을 입력받아 "출력 예"와 같이 
공백으로 구분하여 출력하는 프로그램을 작성하시오.
주의! 숫자를 공백으로 구분하되 줄사이에 빈줄은 없다.

    1 공백4 
  1 2 공백2 / 1 
1 2 3 공백0 / 1 / 1 

*/
