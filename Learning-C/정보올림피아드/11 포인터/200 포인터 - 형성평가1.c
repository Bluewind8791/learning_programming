# include <stdio.h>

int main ()
{
	char ch;
	double fnum;
	
	char *pch = &ch;			//pointer of ch
	double *pfn = &fnum;		//pointer of f_num
	
	printf("%#p ", *pch);
	printf("%#p", *pfn);
	
	return 0;
}

/*
문자와 실수를 각각 선언하고
그 주소를 출력하는 프로그램을 작성하시오 
*/
