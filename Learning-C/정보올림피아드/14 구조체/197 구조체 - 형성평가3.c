#include <stdio.h>

struct point {
	int x, y;
	int x2, y2;
};

int main()
{
	struct point p[2];
	int i, j;
	int triangle[2][2]={0};
	
	for(i=0; i<2; i++)	{
		scanf("%d %d", &p[i].x, &p[i].y);
		scanf("%d %d", &p[i].x2, &p[i].y2);
	}
	
	//compare p[0].x, p[1].x - small one
	if(p[0].x > p[1].x) {
		triangle[0][0] = p[1].x;
	}
	else {
		triangle[0][0] = p[0].x;
	}
	
	//compare p[0].y, p[1].y - small one
	if(p[0].y > p[1].y) {
		triangle[0][1] = p[1].y;
	}
	else {
		triangle[0][1] = p[0].y;
	}
	
	//compare p[0].x2, p[1].x2 - bigger one
	if(p[0].x2 > p[1].x2) {
		triangle[1][0] = p[0].x2;
	}
	else {
		triangle[1][0] = p[1].x2;
	}
	
	//compare p[0].y2, p[1].y2 - bigger one
	if(p[0].y2 > p[1].y2) {
		triangle[1][1] = p[0].y2;
	}
	else {
		triangle[1][1] = p[1].y2;
	}
	
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++) {
			printf("%d ", triangle[i][j]);
		}
	}

	return 0;
 } 
 
/*
���簢���� ���� �Ʒ��� ��ǥ(x, y)�� 
������ ���� ��ǥ(x2, y2)�� ������ �� �ִ� 
����ü �ڷ����� �����, 

�� ���� ���簢�� �ڷḦ �Է¹޾� 

�� ���簢���� �����ϴ� 
�ּ��� ���簢�� �ڷḦ ���Ͽ� 
����ü ������ �����ϰ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

��, ��� �Է°��� 100�� ���� �ʴ´�. 
*/
