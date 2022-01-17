#include <stdio.h>
#include <math.h>

int GetRectWidth(x1, x2);
int GetRectHeight(y1, y2);
int GetRectArea(x1, x2, y1, y2);
int GetRectPerimeter(x1, x2, y1, y2);
double GetLength (x1, x2, y1, y2);

int main ()
{
	int x1, x2, y1, y2;
	printf("차례대로 x1, y1 값을 입력하시오 : ");
	scanf(" %d %d", &x1, &y1);
	printf("차례대로 x2, y2 값을 입력하시오 : ");
	scanf(" %d %d", &x2, &y2);
	
	printf("직사각형의 폭    = %d\n",GetRectWidth(x1,x2));
	printf("직사각형의 높이  = %d\n",GetRectHeight(y1,y2));
	printf("직사각형의 면적  = %d\n",GetRectArea(x1,x2,y1,y2));
	printf("직사각형의 둘레  = %d\n",GetRectPerimeter(x1,x2,y1,y2));
	printf("두 점사이의 거리 = %.2lf\n", GetLength(x1,x2,y1,y2));
	return 0;
}

double GetLength (x1, x2, y1, y2) {
	double length;
	length = (double)sqrt(pow(GetRectHeight(y1,y2),2) \
		+ pow(GetRectWidth(x1,x2),2));
	return length;
}

int GetRectWidth (x1, x2) {
	int width;
	width = x2 - x1;
	if (width < 0) {
		return -width;
	}
	else {
	return width; }
}

int GetRectHeight (y1, y2) {
	int height;
	height = y2 - y1;
	if (height < 0) {
		return -height;
	}
	else {
	return height; }
}

int GetRectArea (x1,x2,y1,y2) {
	int area;
	area = GetRectWidth(x1,x2) * GetRectHeight(y1,y2);
	return area;
}

int GetRectPerimeter (x1, x2, y1, y2) {
	int peri;
	peri = (GetRectWidth(x1,x2) + GetRectHeight(y1,y2) )*2;
	return peri;
}

/*
정수형 좌표를 사용하는 2차원 평면에서
(x1, y1)와 (x2, y2)이 이루는 직사각형에 대하여
직사각형의 폭을 구하는 GetRectWidth 함수
직사각형의 높이를 구하는 GetRectHeight 함수
면적을 구하는 GetRectArea 함수
둘레를 구하는 GetRectPerimeter 함수를 정 

*/
