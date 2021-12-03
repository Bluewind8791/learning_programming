#include <stdio.h>

int main(void)
{
	int num[] = {15, 23, 7, 78, 34, 67, 45, 36, 90, 71};
	int delta;
	int *p = num;
	int i;
	
	printf("[ 원본   배열 ] ");
	for(i=0; i<sizeof(num)/sizeof(num[0]); i++) {
		printf("%4d",  *(p+i));
	}
	
	printf("\n증가량을 입력하세요 : ");
	scanf("%d", &delta);
	
	for(i=0; i<sizeof(num)/sizeof(num[0]); i++) {
		*(p+i) += delta;
	} 
	
	printf("[ 증가후 배열 ] ");
	for(i=0; i<sizeof(num)/sizeof(num[0]); i++) {
		printf("%4d",  *(p+i));
	}
	
	return 0;
}
