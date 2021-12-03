#include <stdio.h>
#include <math.h>

struct point {
	int x, y;
};
typedef struct point POINT;

struct line {
	POINT start;
	POINT end;
};
typedef struct line LINE;


int main(void)
{
	LINE segment;
	double length;
	int dx, dy;
	
	printf("Input start point coordinate: ");
	scanf("%d %d", &segment.start.x, &segment.start.y);
	printf("Input end point coordinate: ");
	scanf("%d %d", &segment.end.x, &segment.end.y);
	
	dx = segment.end.x - segment.start.x;
	dy = segment.end.y - segment.start.y;
	
	length = sqrt(dx*dx + dy*dy);
	
	printf("Length : %.3f\n", length);

	return 0;
}
