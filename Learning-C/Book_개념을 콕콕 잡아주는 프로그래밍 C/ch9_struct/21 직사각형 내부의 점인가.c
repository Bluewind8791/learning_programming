#include <stdio.h>

typedef struct Rectangle {
	int left, right, top, bottom;	
}rect;

typedef struct dot {
	int x, y;
}dot;

int main()
{
	rect r;
	dot p;
	int temp = 0;
	
	printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
	scanf("%d %d %d %d", &r.left, &r.top, &r.right, &r.bottom);
	
	printf("�Էµ� ���簢��: �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
		r.left, r.top, r.right, r.bottom);
		
	if (r.left > r.right) {
		temp = r.left;
		r.left = r.right;
		r.right = temp;
	}
	
	if (r.top > r.bottom) {
		temp = r.top;
		r.top = r.bottom;
		r.bottom = temp;
	}
	
	printf("������ ���簢��: �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
		r.left, r.top, r.right, r.bottom);
	
	printf("������ ��ǥ�� �Է��ϼ���(x, y) :");
	scanf("%d %d", &p.x, &p.y);
	
	if ((p.x >= r.left && p.x <= r.right) && (p.y <= r.bottom && p.y >= r.top))
	{
		printf("(%d, %d)�� ���簢�� ���ο� �ֽ��ϴ�", p.x, p.y);
	}
	else
	{
		printf("(%d, %d)�� ���簢�� �ܺο� �ֽ��ϴ�", p.x, p.y);
	}

	return 0;
}

/*
���� ������ rect ����ü�� ����Ʈ ����ü�� �̿��ؼ�
���簢���� ��ǥ�� ������ ��ǥ�� �Է¹޾Ƽ�

������ ���簢�� ������ ������ �˻��ϴ� ���α׷�

���簢���� left�� right���� ũ�ų�
top�� bottom ���� ũ��

���� �ΰ��� �±�ȯ�ؼ�
�׻� left�� right���� �۰ų� ���ƾ��ϰ�

top�� bottom���� �۰ų� ���� ���� ������
���簢�� ������ ������ �˻��ϵ��� �Ѵ�

--������ 
�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)
(�Է� 50 60 10 20) 
�Էµ� ���簢��: �»����=(50,60), ���ϴ���=(10,20)
������ ���簢�� : �»����=(10,20), ���ϴ���=(50,60)
������ ��ǥ�� �Է��ϼ���(x, y) : 30 40
(30, 40)�� ���簢�� ���ο� �ֽ��ϴ� 

*/
