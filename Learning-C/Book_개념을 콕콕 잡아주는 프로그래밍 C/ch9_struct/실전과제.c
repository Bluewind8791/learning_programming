#include <stdio.h>
#include <math.h>
#define COUNT 5

typedef struct Rectangle {
	int left, right, top, bottom;	
}RECT;

void InputArray(RECT *arr);

int main()
{
	RECT d[COUNT] = {0,};
	
	int i;
	InputArray(&d);
	
	for(i=0; i<COUNT; i++) {
		printf("%d번째 직사각형: 좌상단점=(%2d,%2d) 우하단점=(%2d,%2d)\
		폭=%2d 높이=%2d\n",i+1,d[i].left, d[i].top, d[i].right, d[i].bottom,
		abs(d[i].left-d[i].right), abs(d[i].top-d[i].bottom));
	}
	
	return 0;
}

void InputArray(RECT *arr) {
	int i;
	for(i=0; i<COUNT; i++) {
		printf("좌상단점/우하단점의 좌표를 입력하세요 : ");
		scanf("%d %d %d %d",
			&arr[i].left, &arr[i].top, &arr[i].right, &arr[i].bottom);
	}
}
