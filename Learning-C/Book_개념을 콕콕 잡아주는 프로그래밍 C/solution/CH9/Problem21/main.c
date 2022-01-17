#include <stdio.h>

typedef struct rect {
	int left, top;
	int right, bottom;
} RECT;

typedef struct point {
	int x, y;
} POINT;

int main(void)
{
	RECT rect1;
	POINT p1;
	int tempX, tempY; 
	
	printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
	scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);
	
	printf("�Էµ� ���簢�� : �»����=(%d,%d), ���ϴ���=(%d,%d)\n", 
							rect1.left, rect1.top, rect1.right, rect1.bottom);
	
	if(rect1.left > rect1.right) {
		tempX = rect1.left;
		rect1.left = rect1.right;
		rect1.right = tempX;
	}

	if(rect1.top > rect1.bottom) {
		tempY = rect1.top;
		rect1.top = rect1.bottom;
		rect1.bottom = tempY;
	}
	
	printf("������ ���簢�� : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
							rect1.left, rect1.top, rect1.right, rect1.bottom);
							
	printf("������ ��ǥ�� �Է��ϼ���(x, y) : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	if((p1.x>rect1.left) && (p1.x<rect1.right) && (p1.y>rect1.top) && (p1.y<rect1.bottom)) {
		printf("(%d, %d)�� ���簢�� ���ο� �ֽ��ϴ�.\n", p1.x, p1.y); 
	}  
	else {
		printf("(%d, %d)�� ���簢�� ���ο� ���� �ʽ��ϴ�.\n", p1.x, p1.y);
	} 

	return 0;
}










