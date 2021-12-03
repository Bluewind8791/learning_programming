#include <stdio.h>

int OnetoNum (int num) {
	int x;
	int sum = 0;
	for (x=1; x<=num; x++) {
		sum = x + sum;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	int num;
	scanf(" %d", &num);
	printf("%d", OnetoNum(num));
	return 0;
}

/*
 171 : 함수1 - 형성평가2

1부터 전달받은 수까지의 합을 출력하는 함수를 작성하고 
1000 이하의 자연수를 입력받아 
작성한 함수로 전달하여 출력하는 
프로그램을 작성하시오.

*/
