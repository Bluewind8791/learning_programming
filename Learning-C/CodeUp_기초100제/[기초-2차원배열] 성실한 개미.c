#include <stdio.h>
#define ANTHOUSE maze[1][1]
#define FOOD 2
#define WALL 1
#define ROAD 0
#define WALK 9

int main()
{
	int maze[10][10]={0,};
	int i, j;
	
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++) {
			scanf("%d",&maze[i][j]);
		}
	}
	if (ANTHOUSE == 2) {
		ANTHOUSE = 9;
		goto EXIT;
	}
	ANTHOUSE = 9;
	
	int k = 1;
	for(i=1; i<10; i++) {
		if(maze[i][k] == FOOD) {
			maze[i][k] = WALK;
			break;
		}
		else if(maze[i][j] == ROAD) {
			maze[i][j] = WALK;
		}
		
		for(j=k; j<10; j++) {
			if (maze[i][j] == FOOD) {
				maze[i][j] = WALK;
				goto EXIT;
			}
			else if(maze[i][j] == ROAD) {
				maze[i][j] = WALK;
			}
			else if (maze[i][j] == WALL) {
				k = j-1;
				break;
			}
		}
	}
	
	EXIT:

	for(i=0; i<10; i++) {
		for(j=0; j<10; j++) {
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
