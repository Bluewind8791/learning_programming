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

	
	for(i=0; i<n; i++)	//데이터 입력받기 
	{
		scanf("%s %d %d %d", &d[i].name, 
			&d[i].score1, &d[i].score2, &d[i].score3);
		d[i].total_score = d[i].score1+d[i].score2+d[i].score3;
	}
	
	//내림차순 정렬 
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
10 이하의 정수 n을 입력받은 후 

n명의 이름(영문자 20자 이하)과 
세 과목의 점수를 입력받아 

총점이 높은 순으로 정렬하여 
출력하는 프로그램을 작성하시오.
*/
