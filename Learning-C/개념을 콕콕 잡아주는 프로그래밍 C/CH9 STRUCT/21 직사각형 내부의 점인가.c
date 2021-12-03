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
	
	printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
	scanf("%d %d %d %d", &r.left, &r.top, &r.right, &r.bottom);
	
	printf("입력된 직사각형: 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
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
	
	printf("수정된 직사각형: 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
		r.left, r.top, r.right, r.bottom);
	
	printf("한점의 좌표를 입력하세요(x, y) :");
	scanf("%d %d", &p.x, &p.y);
	
	if ((p.x >= r.left && p.x <= r.right) && (p.y <= r.bottom && p.y >= r.top))
	{
		printf("(%d, %d)은 직사각형 내부에 있습니다", p.x, p.y);
	}
	else
	{
		printf("(%d, %d)은 직사각형 외부에 있습니다", p.x, p.y);
	}

	return 0;
}

/*
실전 과제의 rect 구조체와 포인트 구조체를 이용해서
직사각형의 좌표와 한점의 좌표를 입력받아서

그점이 직사각형 내부의 점인지 검사하는 프로그램

직사각형의 left가 right보다 크거나
top이 bottom 보다 크면

각각 두값을 맞교환해서
항상 left는 right보다 작거나 같아야하고

top은 bottom보다 작거나 같게 만든 다음에
직사각형 내부의 점인지 검사하도록 한다

--실행결과 
좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)
(입력 50 60 10 20) 
입력된 직사각형: 좌상단점=(50,60), 우하단점=(10,20)
수정된 직사각형 : 좌상단점=(10,20), 우하단점=(50,60)
한점의 좌표를 입력하세요(x, y) : 30 40
(30, 40)은 직사각형 내부에 있습니다 

*/
