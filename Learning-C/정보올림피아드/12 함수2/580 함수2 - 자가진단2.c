#include <stdio.h>

int LeapYear (int year)
{
	if (year % 400 == 0)
	{
		return 1;
	}
	else if ( year % 4 == 0 && year % 100 != 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Date (int month, int day)
{
	int LastDay[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	if (LeapYear(2016))
	{
		LastDay[1] = 29;
	}
	else
	{
		LastDay[1] = 28;
	}
	
	if (month > 0 && month <= 12)
	{
		if (day>0 && day<=LastDay[month-1])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int month, day;
	scanf("%d %d", &month, &day);
	
	if ( Date(month,day) )
	{
		printf("OK!");
	}
	else
	{
		printf("BAD!");
	}
	
	return 0;
}


/*
2016���� ��¥�� 
�� ���� ���� �� �Ϸ� �Է¹޾Ƽ� 

�Էµ� ��¥�� �����ϸ� "OK!" 
�׷��� ������ "BAD!"��� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/
