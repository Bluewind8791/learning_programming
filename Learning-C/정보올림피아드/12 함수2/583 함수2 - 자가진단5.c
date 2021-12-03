#include <stdio.h>
#include <math.h>

int MyCeil(double fnum);
int MyFloor(double fnum);
int MyRound(double fnum);

int main()
{
//	double fnum[3] = {0,};
	double fnum[3] = {3.45, 51.48, -100.1};
	
	int i;
	int max, min, remain;
	
	for(i=0, max=0, min=0; i<3; i++) {
		//scanf("%lf", &fnum[i]);
		if (fnum[max] < fnum[i]) {
			max = i;
		}
		if (fnum[min] > fnum[i]) {
			min = i;
		}
	}
	
	for(i=0; i<3; i++) {
		if (i != max && i != min) {
			remain = i;
		}
	}
	
	printf("My Ceil : %d\n", MyCeil(fnum[max]));
	printf("My Floor : %d\n", MyFloor(fnum[min]));
	printf("My Round : %d\n", MyRound(fnum[remain]));
//	printf("%.0lf ", ceil(fnum[max]));
//	printf("%.0lf ", floor(fnum[min]));
//	printf("%.0lf ", round(fnum[remain]));
	
	return 0;
}

int MyCeil(double fnum)		//�ø� �Լ�  
{
	int result;
	if( (fnum - (int)fnum) != 0 ) {
		if(fnum > 0) {
			result = (int)fnum + 1;
		}
		if(fnum < 0) {
			result = (int)fnum - 1;
		}
	}
	else if (fnum - (int)fnum == 0) {
		result = (int)fnum;
	}
	return result;
}

int MyFloor(double fnum)	//���� �Լ�  
{
	int result;
	if (fnum > 0) {
		result = (int)fnum;
	}
	if (fnum < 0) {
		result = (int)fnum - 1;
	}
	return result;
}

int MyRound(double fnum)
{
	int result;
	if( abs(fnum - (int)fnum)>=0.5 ) {
		result = MyCeil(fnum);
	}
	else {
		result = MyFloor(fnum);
	}
	return result;
}

/*
�� ���� �Ǽ��� �Է¹޾�,

���� ū ���� �ø��� ������ ����ϰ�,

���� ���� ���� ������ ������ ����� ��,

���� ���� �ݿø��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ԷµǴ� �Ǽ��� -1000�̻� 1000�����̴�.
*/
