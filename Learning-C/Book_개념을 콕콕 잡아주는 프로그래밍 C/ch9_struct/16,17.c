#include <stdio.h>
#include <math.h>

struct point {
	int x, y;
}; 
typedef struct point POINT;

typedef struct line {
	POINT start;
	POINT end;
}LINE;

void PrintLine( start_x, start_y, end_x, end_y) {
	double length;
	int dx, dy;
	dx = abs(start_x - end_x);
	dy = abs(start_y - end_y);
	length = sqrt((pow(dx,2)+pow(dy,2)));
	printf("������ ���̴� : %.2lf\n",length);
}

int main()
{
	LINE line;
	int move_x, move_y;
	
	printf("������ ������ ��ǥ�� �Է��ϼ���(x,y) : 10, 20\n");
//	scanf("%d %d", &line.start.x, &line.start.y);
	line.start.x = 10;
	line.start.y = 20;
	printf("������ ���� ��ǥ�� �Է��ϼ���(x,y) : 50, 60\n\n");
//	scanf("%d %d", &line.end.x, &line.end.y);
	line.end.x = 50;
	line.end.y = 60;
	
	PrintLine(line.start.x, line.start.y, line.end.x, line.end.y);

	printf("���� �� ���� ���� : ������=(%d,%d), ����=(%d,%d)\n\n"
		,line.start.x, line.start.y, line.end.x, line.end.y);
			
			
	printf("x������ �̵��� �Ÿ��� �Է��ϼ��� : 5\n");
//	scanf("%d",&move_x);
	move_x = 5;
	printf("y������ �̵��� �Ÿ��� �Է��ϼ��� : -3\n");
//	scanf("%d",&move_y);
	move_y = -3;
	
	line.start.x += move_x;
	line.end.x += move_x;
	line.start.y += move_y;
	line.end.y += move_y;
	
	printf("���� �� ���� ���� : ������=(%d,%d), ����=(%d,%d)\n"
		,line.start.x, line.start.y, line.end.x, line.end.y);
	
	return 0;
}
/*
17�� 
������ ������ ����ϴ� PrintLine �Լ��� �����Ͻÿ�. 
�̋� line ����ü�� �Լ��� ���ڷ� �����Ѵ�. 
(�ʿ��ϸ� point ����ü�� ���Ͽ� ���� ��ǥ�� ����ϴ� 
PrintPoint�� �����ص� ��.)

����, Ư�� ������ �ʱ�ȭ�� 
line ����ü ������ ���Ͽ� 
���� ������ ����� �� 

x������ �̵��� �Ÿ��� y������ �̵��� �Ÿ��� �Է¹޾Ƽ� 
������ ��ǥ�� �̵��ϰ� 
�̵� ���� ���� ������ �ٽ� ����ϴ� ���α׷� 
*/



/*
16��  
������ ���ǵ� point ����ü�� �̿��ؼ� 
������ �������� ������ ����� ���� 
line ����ü�� typedef�� �����Ͻÿ�.

line ����ü ������ �̿��ؼ� 
������ ������, ���� ��ǥ�� �Է¹��� ����  
������ ���̸� ���ؼ� ����ϴ� ���α׷�  
*/
