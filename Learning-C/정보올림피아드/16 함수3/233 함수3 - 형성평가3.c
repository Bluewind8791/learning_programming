#include <stdio.h>

int array[10];      // 주사위 눈금을 담을 배열
int index = 1;      // 배열의 인덱스

void Dice(int level, int sum)
{
    int temp = 0;

    for(int i=1; i<=6; i++){
        array[index] = i;                       // 1번 인덱스를 i로 초기화
        if(index == level) {                    // 현재 인덱스가 전달받은 level 이라면
            for(int j=1; j<=level; j++)         // 1 ~ level 번째 항목을 검사하여
                temp += array[j];               // temp에 각 항목을 더함

            if(temp == sum) {                   // 각 항목의 합이 sum과 같다면
                for(int k=1; k<=level; k++)
                    printf("%d ", array[k]);    // 각 항목을 출력
                printf("\n");
            }
            temp = 0;                           // 연산 마친 temp 변수 초기화
        }
        else {                                  // 현재 인덱스가 전달받은 level이 아니라면
            index++;                            // 다음 인덱스 값을 위한 인덱스 증가 
            Dice(level, sum);                   // 재귀 호출 
            array[level + 1] = 1;               // 이전 항목의 연산을 마친 후 초기화
            index--;                            // 6번 다 돌고 나왔다면 
                                                // 이전 인덱스값 증가를 위한 인덱스 감소
        }
    }
}

int main()
{
    // level : 주사위를 던지는 횟수
    // sum : 던진 주사위 눈금의 합계
    int level, sum;

    scanf("%d %d", &level, &sum);
    // level=5, sum=20;

    Dice(level, sum);

    return 0;
}