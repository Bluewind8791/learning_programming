#include <stdio.h>

typedef struct Data {
	char name[20];
	int score1, score2, score3;
	int total_score;
}data;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	data d[n];
	data temp;

	
	for(i=0; i<n; i++)	//������ �Է¹ޱ� 
	{
		scanf("%s %d %d %d", &d[i].name, 
			&d[i].score1, &d[i].score2, &d[i].score3);
		d[i].total_score = d[i].score1+d[i].score2+d[i].score3;
	}
	
	//�������� ���� 
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if (d[j].total_score < d[j+1].total_score) {
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}
	
	for(i=0; i<n; i++) {
		printf("%s %d %d %d %d\n", d[i].name, d[i].score1, 
			d[i].score2, d[i].score3, d[i].total_score);
	}
	
	return 0;
}

/*
10 ������ ���� n�� �Է¹��� �� 

n���� �̸�(������ 20�� ����)�� 
�� ������ ������ �Է¹޾� 

������ ���� ������ �����Ͽ� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
