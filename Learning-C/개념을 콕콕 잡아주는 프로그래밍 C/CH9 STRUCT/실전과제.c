#include <stdio.h>
#include <math.h>
#define COUNT 5

typedef struct Rectangle {
	int left, right, top, bottom;	
}RECT;

void InputArray(RECT *arr);

int main()
{
	RECT d[COUNT] = {0,};
	
	int i;
	InputArray(&d);
	
	for(i=0; i<COUNT; i++) {
		printf("%d��° ���簢��: �»����=(%2d,%2d) ���ϴ���=(%2d,%2d)\
		��=%2d ����=%2d\n",i+1,d[i].left, d[i].top, d[i].right, d[i].bottom,
		abs(d[i].left-d[i].right), abs(d[i].top-d[i].bottom));
	}
	
	return 0;
}

void InputArray(RECT *arr) {
	int i;
	for(i=0; i<COUNT; i++) {
		printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ��� : ");
		scanf("%d %d %d %d",
			&arr[i].left, &arr[i].top, &arr[i].right, &arr[i].bottom);
	}
}
