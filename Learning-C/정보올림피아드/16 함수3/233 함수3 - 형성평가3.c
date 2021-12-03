#include <stdio.h>

int array[10];      // �ֻ��� ������ ���� �迭
int index = 1;      // �迭�� �ε���

void Dice(int level, int sum)
{
    int temp = 0;

    for(int i=1; i<=6; i++){
        array[index] = i;                       // 1�� �ε����� i�� �ʱ�ȭ
        if(index == level) {                    // ���� �ε����� ���޹��� level �̶��
            for(int j=1; j<=level; j++)         // 1 ~ level ��° �׸��� �˻��Ͽ�
                temp += array[j];               // temp�� �� �׸��� ����

            if(temp == sum) {                   // �� �׸��� ���� sum�� ���ٸ�
                for(int k=1; k<=level; k++)
                    printf("%d ", array[k]);    // �� �׸��� ���
                printf("\n");
            }
            temp = 0;                           // ���� ��ģ temp ���� �ʱ�ȭ
        }
        else {                                  // ���� �ε����� ���޹��� level�� �ƴ϶��
            index++;                            // ���� �ε��� ���� ���� �ε��� ���� 
            Dice(level, sum);                   // ��� ȣ�� 
            array[level + 1] = 1;               // ���� �׸��� ������ ��ģ �� �ʱ�ȭ
            index--;                            // 6�� �� ���� ���Դٸ� 
                                                // ���� �ε����� ������ ���� �ε��� ����
        }
    }
}

int main()
{
    // level : �ֻ����� ������ Ƚ��
    // sum : ���� �ֻ��� ������ �հ�
    int level, sum;

    scanf("%d %d", &level, &sum);
    // level=5, sum=20;

    Dice(level, sum);

    return 0;
}