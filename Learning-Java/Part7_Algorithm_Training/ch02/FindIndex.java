package ch02;

/*
* 여러개의 수가 정렬된 순서로 있을떄 특정한 수를 찾는 방법
* 단분 반복문을 이용하면 수의 개수에 따라 비교 횟수가 증가하는 O(n)의 수행
* 수가 정렬된 상태에서는 이진탐색을 활용하면 매번 비교되는 요소의 수가
절반 이상으로 감소될 수 있으므로 O(logN)의 수행으로 원하는 수 찾기
{12, 25, 31, 48, 54, 66, 70, 83, 95, 108}
*/

public class FindIndex {
  
  public static void main(String[] args) {
    
    int[] array = {12, 25, 31, 48, 54, 66, 70, 83, 95, 108};

    int target = 83;
    
    int mid = array.length / 2;
    int rightIndex = array.length - 1;
    int leftIndex = 0;
    
    int temp = array[mid];
    boolean findFlag = false;

    while (leftIndex <= rightIndex) {

      if (target == temp) { // find target
        findFlag = true;
        break;
      }
      else if (target > temp) { // target at right side
        leftIndex = mid + 1;
      }
      else { // target at left side
        rightIndex = mid - 1;
      }
      mid = (leftIndex + rightIndex) / 2;
      temp = array[mid];
    }

    if (findFlag == true) {

      System.out.println("Target number position : " + (mid+1));
    }
    else {
      System.out.println("Can not find the target number.");
    }

  }
}
