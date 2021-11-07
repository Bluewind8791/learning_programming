package ch03;

/*
- 삽입정렬
이미 정렬된 상태의 요소에 새로운 요소를 추가할때 정렬하여 추가
두번째 요소부터 이전 요소들과 비교하면서 insert 될 위치를 찾아가며 정렬하는 알고리즘
*/

public class InsertionSort {
  
  public static void insertionSort(int[] arr, int count) {


    for (int i=1; i<count; i++) { // i = target index

      int target = arr[i]; // target number
      int j = i - 1;

      // target이 앞 원소보다 크기 전까지 반복 -> target이 앞보다 크면 (순서대로면) 멈춤
      while (j>=0 && target < arr[j]) {
        arr[j+1] = arr[j]; // 앞으로 한칸씩 땡긴다
        j--;
      }

      // 위 반복문에서 탈출하는 경우 앞의 원소가 타겟보다 작다는 의미이므로
      // 타겟 원소는 j 뒤에와야한다
      // 그러므로 타겟은 j+1에 위치
      arr[j+1] = target;

      printSort(arr);
    }
  }

  public static void printSort(int[] arr) {
    for (int i=0; i<arr.length; i++) {
      System.out.print(arr[i] + "\t");
    }
    System.out.println();
  }


  public static void main(String[] args) {
    
    int[] arr = {80, 50, 70, 10, 60, 20, 40, 30 };
    insertionSort(arr, arr.length);
  }
}
