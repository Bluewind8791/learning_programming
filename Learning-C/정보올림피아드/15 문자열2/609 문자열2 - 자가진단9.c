#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int StrCompare(const void *a, const void *b) {
    return strcmp(a, b);
}

int main() {

    char string[5][100];

    for(int i=0; i<5; i++) {
        scanf("%s", string[i]);
    }

    qsort(string, 5, sizeof(string[0]), StrCompare);

    for(int i=4; i>=0; i--) {
        printf("%s\n", string[i]);
    }

    return 0;
}

/*
5���� ���ڿ��� �Է¹޾� ���ڿ� ũ��(�ƽ�Ű�ڵ�) �������� 
�����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�־����� ���ڿ��� ���̴� 20�� �̸��̴�.
*/