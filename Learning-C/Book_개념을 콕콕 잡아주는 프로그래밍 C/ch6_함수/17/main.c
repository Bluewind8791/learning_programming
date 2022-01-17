#include <stdio.h>

int IsPrime (int n);

int main() {
	int num, x;
	
	printf("1 부터 100 까지의 소수는...\n");
	for (x=1; x<=100; x++) {
		IsPrime(x) ? printf("%d ", x) : printf(""); ;
	}printf("\n\n");
		
	while (1) {	
		printf("정수를 입력하세요 (0 입력 시 종료) : ");
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		else if (IsPrime(num)==1) {
			printf("'%d'는 소수입니다.\n",num);
		}
		else if (IsPrime(num)==0){
			printf("'%d'는 소수가 아닙니다.\n", num);
		}
	}
	return 0;
}

int IsPrime (int n) {
	/*
	1. Description : 입력받은 인자가 소수인지 아닌지 판단하는 함수. 
	2. Function : int n (인자), x(증가변수)
	3. Return : 1 or 0 (소수라면 1, 아니면 0) 
	*/
	int x;
	for (x=2;x<=n-1;x++) {
	//x를 2부터 n-1까지 하나씩 올려가면서 나머지가 없으면 소수가 아니다 
		if (n % x == 0) {
			return 0;	}
	}
	return 1;
}


/*
정수값을 인자로 받아서
소수인지 판단하는 IsPrime 함수 정의.

함수를 이용해서 1부터 100사이의
소수를 모두 구해서 출력하는 프로그램 
*/

