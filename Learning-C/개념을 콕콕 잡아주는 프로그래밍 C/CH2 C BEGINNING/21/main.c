#include <stdio.h>
#include <limits.h>


int main(int argc, char *argv[]) 
{

signed char max = CHAR_MAX;
signed char min = CHAR_MIN;

printf("char���� �ִ밪 : %d\n", max);

signed char max1 = CHAR_MAX+1;

printf("char���� �ִ밪+1 : %d\n", max1);

printf("char���� �ּҰ� : %d\n", min);

signed char min1 = CHAR_MIN-1;

printf("char���� �ּҰ�-1 : %d\n", min1);




	return 0;
}
