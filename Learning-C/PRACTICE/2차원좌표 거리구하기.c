#include <stdio.h>
#include <math.h>

typedef struct POINT
{
	int x, y;
}Pt;

double GetDistance(int dx, int dy);
int GetLength(int x1, int x2);
void PrintResult (char *msg, int value);

int main()
{
	Pt p1 = {10,10};
	Pt p2 = {30,30};
	Pt *ptr1 = &p1;
	Pt *ptr2 = &p2;
	int i, dx, dy;
	int length=0;
	char *MsgResult = "두 점 사이의 거리는 : %d";
	
//	printf("첫번째 점의 좌표를 입력하세요(x,y) : ");
//	scanf("%d %d", ptr1->x, ptr1->y);
//	printf("두번째 점의 좌표를 입력하세요(x,y) : ");
//	scanf("%d %d", ptr2->x, ptr2->y);
	
	dx = GetLength(ptr1->x, ptr2->x);
	dy = GetLength(ptr1->y, ptr2->y);
	
	length = GetDistance(dx, dy);
	
	PrintResult (MsgResult, length);
		
	return 0;
}

double GetDistance(int dx, int dy)
{
	double length;
	length = sqrt(pow(dx,2) + pow(dy,2) );
	return length;
}

int GetLength(int x1, int x2)
{
	int dx;
	dx = abs(x1 - x2);
	return dx;
}

void PrintResult (char *msg, int value)
{
	printf(msg,value);
}

/*
1. 점의 좌표를 표현할 수 있는 구조체 정의 
2. 정의된 구조체 이용. 변수 2개(점 2개 선언) 선언.
3. 두 점의 좌표를 표준입력장치로부터 입력 받아,
4. 이들 두점 사이의 거리를 출력.  
*/
