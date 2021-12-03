/* Lab09.c */
#include <stdio.h>
#define COUNT 5

struct rect {
	int left;
	int top;
	int right;
	int bottom;
};

typedef struct rect RECT;

int main(void) 
{
	RECT rects[COUNT] = {0};
	int i;
	
	for(i=0; i<COUNT; i++) {
		printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom순)\n");
		scanf("%d %d %d %d", &rects[i].left, &rects[i].top,
							 &rects[i].right, &rects[i].bottom);
	}
	
	for(i=0; i<COUNT; i++) {
		int width = rects[i].right - rects[i].left;
		int height = rects[i].bottom - rects[i].top;
		
		width = (width>0)? width : -width;
		height = (height>0)? height : -height;
		
		printf("%d 번째 직사각형 : ", i+1);
		printf("좌상단점=(%3d,%3d) 우하단점=(%3d,%3d) 폭=%d 높이=%d\n",
				rects[i].left, rects[i].top, rects[i].right, rects[i].bottom,
				width, height);
	}

	return 0;
}















