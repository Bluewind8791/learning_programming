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
	char *MsgResult = "�� �� ������ �Ÿ��� : %d";
	
//	printf("ù��° ���� ��ǥ�� �Է��ϼ���(x,y) : ");
//	scanf("%d %d", ptr1->x, ptr1->y);
//	printf("�ι�° ���� ��ǥ�� �Է��ϼ���(x,y) : ");
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
1. ���� ��ǥ�� ǥ���� �� �ִ� ����ü ���� 
2. ���ǵ� ����ü �̿�. ���� 2��(�� 2�� ����) ����.
3. �� ���� ��ǥ�� ǥ���Է���ġ�κ��� �Է� �޾�,
4. �̵� ���� ������ �Ÿ��� ���.  
*/
