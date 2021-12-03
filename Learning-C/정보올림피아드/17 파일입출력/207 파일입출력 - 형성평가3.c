#include <stdio.h>

int main()
{
    int num1, num2;
    char ch;
    int result;

    fscanf(stdin, "%d %d %c", &num1, &num2, &ch);
    
    switch (ch)
    {
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    case '%':
        result = num1 % num2;
        break;
    }

    fprintf(stdout, "%d %c %d = %d", num1, ch, num2, result);

    return 0;
}