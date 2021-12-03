#include <stdio.h>

int arr[100];
int n;

void Print() {
	int i;
	for(i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Dice(int level) {
	int i;
	if(level > n) {
		Print();
		return;
	}
	
	for(i=arr[level-1]; i<=6; i++) {
		arr[level] = i;
		Dice(level + 1);
	}
}


int main()
{
	scanf("%d", &n);
	arr[0] = 1;

	Dice(1);
	
	return 0;
}
/*
10 ������ �ڿ��� N�� �Է¹޾� 

�ֻ����� N�� ������ ���� �� �ִ� 
��� ��츦 ����ϵ� 

�ߺ��Ǵ� ��쿡�� �տ������� ���� ������ 
1���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
