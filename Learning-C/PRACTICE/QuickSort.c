#include <stdio.h>
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

int data[100] = {34,50,5,17,82,66,73,1,48,29};
int cnt;

void QuickSort(int *data, int start, int end)
{
	//������ ������ 2�� �̻��� ������ 
	if (start >= end) {
		return;
	}
	
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j) {	//������������ �ݺ� 
	  
		//key ������ ū ���� ���� �� ���� 
		while(data[key] >= data[i]) {	
			i++;
		}
		
		//key ������ ���� ���� ���� �� ����  
		while(data[key] <= data[j] && j > start) {	
			j--;
		}
		
		//�����Ͱ� ������ ���¸� Ű ���� ��ü  
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
	
	//Quick sort (�迭�ǽ���:0) (�迭�ǳ�:cnt-1) 
	QuickSort(data, 0, cnt-1);
	
	printf("\n\n<After Quick Sorting>\n");
	for(i=0; i<cnt; i++){
		printf("%d ",data[i]);
	}
	
	return 0;
}
