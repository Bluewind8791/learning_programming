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
	printf("���ʴ�� x1, y1 ���� �Է��Ͻÿ� : ");
	scanf(" %d %d", &x1, &y1);
	printf("���ʴ�� x2, y2 ���� �Է��Ͻÿ� : ");
	scanf(" %d %d", &x2, &y2);
	
	printf("���簢���� ��    = %d\n",GetRectWidth(x1,x2));
	printf("���簢���� ����  = %d\n",GetRectHeight(y1,y2));
	printf("���簢���� ����  = %d\n",GetRectArea(x1,x2,y1,y2));
	printf("���簢���� �ѷ�  = %d\n",GetRectPerimeter(x1,x2,y1,y2));
	printf("�� �������� �Ÿ� = %.2lf\n", GetLength(x1,x2,y1,y2));
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
������ ��ǥ�� ����ϴ� 2���� ��鿡��
(x1, y1)�� (x2, y2)�� �̷�� ���簢���� ���Ͽ�
���簢���� ���� ���ϴ� GetRectWidth �Լ�
���簢���� ���̸� ���ϴ� GetRectHeight �Լ�
������ ���ϴ� GetRectArea �Լ�
�ѷ��� ���ϴ� GetRectPerimeter �Լ��� �� 

*/
