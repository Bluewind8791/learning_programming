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
���ڿ� �Ǽ��� ���� �����ϰ�
�� �ּҸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ� 
*/
