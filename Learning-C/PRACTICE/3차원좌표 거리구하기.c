#include <stdio.h>
#include <math.h>

typedef struct POINT {
	int x, y, z;
}Pt;

int main()
{
	Pt p1, p2;
	int i, dx, dy, dz;
	int length=0;
	
	printf("ù��° ���� ��ǥ�� �Է��ϼ���(x,y,z) : ");
	scanf("%d %d %d", &p1.x, &p1.y, &p1.z);
	printf("�ι�° ���� ��ǥ�� �Է��ϼ���(x,y,z) : ");
	scanf("%d %d %d", &p2.x, &p2.y, &p2.z);
	
	dx = abs(p1.x - p2.x);
	dy = abs(p1.y - p2.y);
	dz = abs(p1.z - p2.z);
	
	length = sqrt(pow(dx,2) + pow(dy,2) + pow(dz,2) );
	
	printf("�� �� ������ �Ÿ��� : %d", length);
	
	
	
	
	return 0;
}
