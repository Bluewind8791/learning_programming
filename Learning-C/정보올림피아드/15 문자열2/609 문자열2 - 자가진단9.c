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
5개의 문자열을 입력받아 문자열 크기(아스키코드) 역순으로 
정렬하여 출력하는 프로그램을 작성하시오.

주어지는 문자열의 길이는 20자 미만이다.
*/