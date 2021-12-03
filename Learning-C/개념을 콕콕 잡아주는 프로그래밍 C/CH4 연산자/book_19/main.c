#include <stdio.h>

/* 면적을 제곱미터로 입력받아서
합계와 평균, 최대값과 최소값을 구해서
출력하는 프로그램*/
 
int main(int argc, char *argv[]) 
{

	int ping, meter;
	
	printf("제곱미터 단위의 면적을 입력해주십시오 :");
	scanf(" %d", &meter);
	
	ping = meter / 3.3058;
	
	printf("입력하신 면적의 평수는 %d평 입니다.", ping);


	return 0;
}
