#include <stdio.h>
#include <string.h>

int main() {

    char word1[100];
    char word2[100];
    char word3[100];
    char firstword[100] = {0,};

    
    scanf("%s %s %s", word1, word2, word3);

    
    if(strcmp(word1, word2) <= 0) {          // if word1 < word2
        if(strcmp(word1, word3) <= 0) {      // word1 < word2 and if word1 < word3
            strcpy(firstword, word1);        // word 1 most small
        }
        else {										   // word1 < word2 and word3 < word1
      		strcpy(firstword, word3);
		  }
    }
    else {                                  // word2 < word1
        if(strcmp(word2, word3) <= 0) {      // if word2 < word3
            strcpy(firstword, word2);       // word2 most small
        }
        else {                              // word2 < word1 and word3 < word2
            strcpy(firstword, word3);       // word3 most small
        }
    }

    printf("%s", firstword);

    return 0;
}

/*
세 개의 단어를 입력받아 아스키코드(사전) 순으로 
가장 먼저 나오는 단어를 출력하는 프로그램을 작성하시오.

각 단어의 길이는 1이상 10 이하이다.
*/