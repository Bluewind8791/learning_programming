#include <stdio.h>

struct point {
	int x, y;
};

int main()
{
	struct point t[3] = {0};
	int i;
	double x_wc, y_wc;
	
	for(i=0; i<3; i++)
	{
		scanf("%d %d", &t[i].x, &t[i].y);
		x_wc += t[i].x;
		y_wc += t[i].y;
	}
	
	printf("(%.1lf, %.1lf)", x_wc/3, y_wc/3);
		
	return 0;
}


/*
�ﰢ���� �� �������� 
���� ��ǥ�� �Է¹޾� 
�ﰢ���� �����߽��� �Ǽ� ��ǥ�� ���Ͽ� 

�Ҽ� ù°�ڸ����� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
