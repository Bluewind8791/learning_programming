#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[20];

    scanf("%s", string);

    int intnum = atoi(string);
    printf("%d\n", intnum*2);
    
    double doublenum = atof(string);
    printf("%.2lf\n", doublenum);

    return 0;
}

// 20�� ������ �� ���� ���ڿ��� �Է¹޾Ƽ� 
// ù �ٿ��� ������ ��ȯ�Ͽ� 2���� ���� ����ϰ�, 
// ���� �ٿ��� �Ǽ��� ��ȯ�� ���� �ݿø��Ͽ� 
// �Ҽ� ��°�ڸ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.