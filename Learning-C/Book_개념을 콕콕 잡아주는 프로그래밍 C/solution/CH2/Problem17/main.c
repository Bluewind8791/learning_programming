

#include <stdio.h>

int main(void)
{
	// Methode 1 : Severial printf statements
	printf("-- Methode 1 : Several statements --\n");
	printf("안녕하세요?\n");
	printf("반갑습니다.\n");
	printf("또 만나요.\n\n\n");
	
	// Methode 2  : One printf statement
	printf("-- Methode 2 : One statement --\n");
	printf("안녕하세요?\n반갑습니다.\n또만나요.\n\n\n"); 
	
	// Methode 3 : One printf statement
		printf("-- Methode 3  : One statement --\n");
	printf("안녕하세요?\n" "반갑습니다.\n" "또 만나요.\n"); 
	
	return 0; 
}
