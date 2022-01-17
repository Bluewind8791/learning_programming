#include <stdio.h>

typedef struct point {
	int x, y;
}POINT;

typedef struct line {
	POINT start;
	POINT end;
}LINE;

void PrintLine(LINE l);

int main(void)
{
	LINE segment;
	int dx, dy;
	
	printf("Input start point coordinate: ");
	scanf("%d %d", &segment.start.x, &segment.start.y);
	printf("Input end point coordinate: ");
	scanf("%d %d", &segment.end.x, &segment.end.y);

	printf("변경 전 직선 정보 : ");
	PrintLine(segment);
	
	printf("x축으로 이동할 거리를 입력하세요 : ");
	scanf("%d", &dx);
	printf("y축으로 이동할 거리를 입력하세요 : ");
	scanf("%d", &dy);
		
	segment.start.x += dx;
	segment.start.y += dy;
	segment.end.x += dx;
	segment.end.y += dy;	
		
	printf("변경 후 직선 정보 : ");
	PrintLine(segment);
	
	return 0;
}

void PrintLine(LINE l)
{
	printf("시작점=(%d, %d), 끝점=(%d, %d)\n", l.start.x, l.start.y, l.end.x, l.end.y); 
}










