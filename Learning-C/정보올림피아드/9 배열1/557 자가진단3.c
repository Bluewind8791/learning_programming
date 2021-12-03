#include <stdio.h>

int main() {
	
	char ch[10];
	int i;
	
	for(i=0;i<10;i++) {
		scanf(" %c", &ch[i]);
	}
	
	printf("%c %c %c",ch[0],ch[3],ch[6]);
	
	return 0;
}

