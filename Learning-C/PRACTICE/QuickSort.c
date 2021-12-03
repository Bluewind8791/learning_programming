#include <stdio.h>
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

int data[100] = {34,50,5,17,82,66,73,1,48,29};
int cnt;

void QuickSort(int *data, int start, int end)
{
	//정렬할 범위가 2개 이상의 데이터 
	if (start >= end) {
		return;
	}
	
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j) {	//엇갈릴때까지 반복 
	  
		//key 값보다 큰 값을 만날 때 까지 
		while(data[key] >= data[i]) {	
			i++;
		}
		
		//key 값보다 작은 값을 만날 때 까지  
		while(data[key] <= data[j] && j > start) {	
			j--;
		}
		
		//데이터가 엇갈린 상태면 키 값과 교체  
		if (i > j) {
			SWAP(data[j], data[key], temp);
		}
		else {
			SWAP(data[j], data[i], temp);
		}
	}
	
	QuickSort(data, start, j-1);
	QuickSort(data, j+1, end);

}

int main()
{
	int i;
	
	for(i=0, cnt=0; ; i++) {
		if (data[i] == 0) {
			break;
		}
		else {
			cnt++;
		}
	}
	
	printf("\n<Before Sorting>\n");
	for(i=0; i<cnt; i++){
		printf("%d ",data[i]);
	}
	
	//Quick sort (배열의시작:0) (배열의끝:cnt-1) 
	QuickSort(data, 0, cnt-1);
	
	printf("\n\n<After Quick Sorting>\n");
	for(i=0; i<cnt; i++){
		printf("%d ",data[i]);
	}
	
	return 0;
}
