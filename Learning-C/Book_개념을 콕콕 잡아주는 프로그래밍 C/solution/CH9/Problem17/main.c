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

	printf("���� �� ���� ���� : ");
	PrintLine(segment);
	
	printf("x������ �̵��� �Ÿ��� �Է��ϼ��� : ");
	scanf("%d", &dx);
	printf("y������ �̵��� �Ÿ��� �Է��ϼ��� : ");
	scanf("%d", &dy);
		
	segment.start.x += dx;
	segment.start.y += dy;
	segment.end.x += dx;
	segment.end.y += dy;	
		
	printf("���� �� ���� ���� : ");
	PrintLine(segment);
	
	return 0;
}

void PrintLine(LINE l)
{
	printf("������=(%d, %d), ����=(%d, %d)\n", l.start.x, l.start.y, l.end.x, l.end.y); 
}










