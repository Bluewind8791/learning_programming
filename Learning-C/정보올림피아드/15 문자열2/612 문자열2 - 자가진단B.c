#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int array[5];
    char mergestr[100];

    for(int i=0; i<5; i++) {
        scanf("%d", &array[i]);
    }

    sprintf(mergestr, "%d%d%d%d%d", array[0],array[1],array[2],array[3],array[4]);

    for(int i=0; i<strlen(mergestr); i++) {
        printf("%c", mergestr[i]);
        if( ((i+1)%3)==0 ) {
            printf("\n");
        }
    }

    return 0;
}

// 5���� ������ �Է¹޾� 
// ��� �ٿ��� ���ڿ��� ������ �� 

// �� �ھ� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
