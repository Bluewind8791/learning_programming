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
10 이하의 자연수 N을 입력받아 

주사위를 N번 던져서 나올 수 있는 
모든 경우를 출력하되 

중복되는 경우에는 앞에서부터 작은 순으로 
1개만 출력하는 프로그램을 작성하시오.
*/
