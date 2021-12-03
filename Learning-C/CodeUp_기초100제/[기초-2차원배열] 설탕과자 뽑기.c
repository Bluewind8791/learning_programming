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
		
		//길이가 1일 때  
		if(st[i].length == 1) {
			pan[st[i].x-1][st[i].y-1] = 1;
		}
		
		//길이가 1보다 클 때  
		else if(st[i].length != 1) {
			//방향이 1일 때, 밑으로 (세로)  
			if(st[i].dir == 0) {
				for(j=0; j<st[i].length; j++) {
					pan[st[i].x-1][st[i].y-1+j] = 1;
				}
			}
			//방향이 0일때 오른쪽으로(가로) 
			else if(st[i].dir == 1) {
				for(j=0; j<st[i].length; j++) {
					pan[st[i].x-1+j][st[i].y-1] = 1;
				}
			}
		}
	}

	//바둑판 출력  
	for(i=0; i<height; i++) {
		for(j=0; j<width; j++) {
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}

	return 0;
}


