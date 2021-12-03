#include <stdio.h>
#define ASCEND 1
#define DESCEND 0
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

void QuickSort(int *arr, int start, int end, int dir)
{
	int key = start;
	int i = start+1;
	int j = end;
	int temp;
	
	if (start >= end) {
		return;
	}
	
	while(i <= j) {
		if(dir == ASCEND) {
			while(arr[key] >= arr[i]) {
			i++;}
			while(arr[key] <= arr[j] && j > start) {
			j--;}
		}
		else if (dir == DESCEND) {
			while(arr[key] <= arr[i]) {
			i++;}
			while(arr[key] >= arr[j] && j > start) {
			j--;}
		}
		
		if(i > j) {
			SWAP(arr[key], arr[j], temp);			
		}
		else {
			SWAP(arr[i], arr[j], temp);
		}
	}
	
	QuickSort(arr, start, j-1, dir);
	QuickSort(arr, j+1, end, dir);
}

int main()
{
	int i;
	int cnt;
	int arr[100] = {34,50,5,17,82,66,73,1,48,29};
	
	for(i=0, cnt=0; ; i++) {
		if (arr[i] == 0) {
			break;
		}
		else {
			cnt++;
		}
	}
	
	printf("\n<Before Sorting>\n");
	for(i=0; i<cnt; i++){
		printf("%d ",arr[i]);
	}
	
	QuickSort(arr, 0, cnt-1, ASCEND);
	
	printf("\n\n<After Quick Sorting>\n");
	for(i=0; i<cnt; i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
