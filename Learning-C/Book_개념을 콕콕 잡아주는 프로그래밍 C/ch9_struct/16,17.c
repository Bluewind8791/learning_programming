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
	printf("직선의 길이는 : %.2lf\n",length);
}

int main()
{
	LINE line;
	int move_x, move_y;
	
	printf("직선의 시작점 좌표를 입력하세요(x,y) : 10, 20\n");
//	scanf("%d %d", &line.start.x, &line.start.y);
	line.start.x = 10;
	line.start.y = 20;
	printf("직선의 끝점 좌표를 입력하세요(x,y) : 50, 60\n\n");
//	scanf("%d %d", &line.end.x, &line.end.y);
	line.end.x = 50;
	line.end.y = 60;
	
	PrintLine(line.start.x, line.start.y, line.end.x, line.end.y);

	printf("변경 전 직선 정보 : 시작점=(%d,%d), 끝점=(%d,%d)\n\n"
		,line.start.x, line.start.y, line.end.x, line.end.y);
			
			
	printf("x축으로 이동할 거리를 입력하세요 : 5\n");
//	scanf("%d",&move_x);
	move_x = 5;
	printf("y축으로 이동할 거리를 입력하세요 : -3\n");
//	scanf("%d",&move_y);
	move_y = -3;
	
	line.start.x += move_x;
	line.end.x += move_x;
	line.start.y += move_y;
	line.end.y += move_y;
	
	printf("변경 후 직선 정보 : 시작점=(%d,%d), 끝점=(%d,%d)\n"
		,line.start.x, line.start.y, line.end.x, line.end.y);
	
	return 0;
}
/*
17번 
직선의 정보를 출력하는 PrintLine 함수를 정의하시오. 
이떄 line 구조체를 함수의 인자로 전달한다. 
(필요하면 point 구조체에 대하여 점의 좌표를 출력하는 
PrintPoint를 정의해도 됨.)

또한, 특정 값으로 초기화된 
line 구조체 변수에 대하여 
직선 정보를 출력한 후 

x축으로 이동할 거리와 y축으로 이동할 거리를 입력받아서 
직선의 좌표를 이동하고 
이동 후의 직선 정보를 다시 출력하는 프로그램 
*/



/*
16번  
다음에 정의된 point 구조체를 이용해서 
직선의 시작점과 끝점을 멤버로 갖는 
line 구조체와 typedef를 정의하시오.

line 구조체 변수를 이용해서 
직선의 시작점, 끝점 좌표를 입력받은 다음  
직선의 길이를 구해서 출력하는 프로그램  
*/
