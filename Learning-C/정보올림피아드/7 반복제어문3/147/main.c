#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, x, y;
	int num = 1;
	scanf("%d",&n);
	for(y=0; y<n; y++) {
		for (x=0; x<y; x++) {
			printf("  ");
		}
		for (x=0; x<n-y; x++) {
			printf("%d ", num++);
		}
		printf("\n");
	}
	return 0;
}

/*

�ڿ��� n�� �Է¹޾� "��� ��"�� ���� 
�������� �����Ͽ� ��µǴ� ���α׷��� �ۼ��Ͻÿ�.

1 2 3
  4 5
    6  
    
*/
