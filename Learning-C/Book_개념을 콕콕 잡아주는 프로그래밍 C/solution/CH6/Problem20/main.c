
#include <stdio.h>

int GetRectWidth(int x1, int x2);
int GetRectHeight(int y1, int y2);
int GetRectArea(int x1, int y1, int x2, int y2);
int GetRectPerimeter(int x1, int y1, int x2, int y2);

int main(void)
{
	int x1, y1, x2, y2;
	
	printf("Input 1st point (x y) : ");
	scanf("%d %d", &x1, &y1);
	printf("Input 2nd point (x y) : ");
	scanf("%d %d", &x2, &y2);
	
	printf("Width     of rectangle : %d\n", GetRectWidth(x1, x2));
	printf("Height    of rectangle : %d\n", GetRectHeight(y1, y2));
	printf("Area      of rectangle : %d\n", GetRectArea(x1, y1, x2, y2));
	printf("Perimeter of rectangle : %d\n", GetRectPerimeter(x1, y1, x2, y2)); 
	
	return 0;
}

int GetRectWidth(int x1, int x2)
{
	int dx = x2 - x1;
	if(dx < 0) {
		return -dx;
	}
	else {
		return dx;
	}
}


int GetRectHeight(int y1, int y2)
{
	int dy = y2 - y1;
	if(dy < 0) {
		return -dy;
	}
	else {
		return dy;
	}
}


int GetRectArea(int x1, int y1, int x2, int y2)
{
	return (GetRectWidth(x1, x2) * GetRectHeight(y1, y2));
}



int GetRectPerimeter(int x1, int y1, int x2, int y2)
{
	return (2 * (GetRectWidth(x1, x2) + GetRectHeight(y1, y2)));
}










