#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Stick {
	int length, dir, x, y;
}Stick;


int main()
{
	int height, width, n, i, j;
		
	scanf("%d %d", &height, &width);
	scanf("%d", &n);
	
	Stick st[n];
	int pan[100][100] = {0,};
	
	
	for(i=0; i<n; i++) {
		//Input struct stick 
		scanf("%d %d %d %d",&st[i].length, &st[i].dir, &st[i].x, &st[i].y);
		
		//���̰� 1�� ��  
		if(st[i].length == 1) {
			pan[st[i].x-1][st[i].y-1] = 1;
		}
		
		//���̰� 1���� Ŭ ��  
		else if(st[i].length != 1) {
			//������ 1�� ��, ������ (����)  
			if(st[i].dir == 0) {
				for(j=0; j<st[i].length; j++) {
					pan[st[i].x-1][st[i].y-1+j] = 1;
				}
			}
			//������ 0�϶� ����������(����) 
			else if(st[i].dir == 1) {
				for(j=0; j<st[i].length; j++) {
					pan[st[i].x-1+j][st[i].y-1] = 1;
				}
			}
		}
	}

	//�ٵ��� ���  
	for(i=0; i<height; i++) {
		for(j=0; j<width; j++) {
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}

	return 0;
}


