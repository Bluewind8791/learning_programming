
package ch01;

/**
 * MinMaxProblem
 * 1. 나열된 수에서 최솟값과 최댓값 구하기
여러개의 수가 배열에 있을때 그중 가장 큰값과 가장 작은 값을 찾는다
배열의 몇번째에 있는지 index 찾기
반복문 한번만 사용
[10, 55, 23, 2, 79, 101, 16, 82, 30, 45]
 */

public class MinMaxProblem {

  public static void main(String[] args) {
    
    int[] arrayList = {10, 55, 23, 2, 79, 101, 16, 82, 30, 45};
    
    int min = arrayList[0];
    int max = arrayList[0];
    int minIndex = 0;
    int maxIndex = 0;

    for(int i=0; i<arrayList.length; i++) {
      if (arrayList[i] > max) {
        max = arrayList[i];
        maxIndex = i;
      }
      if (arrayList[i] < min) {
        min = arrayList[i];
        minIndex = i;
      }
    }

    System.out.println("Min value : " + min);
    System.out.println("Min index : " + minIndex + 1);
    System.out.println("Max value : " + max);
    System.out.println("Max index : " + maxIndex + 1);
  }
}