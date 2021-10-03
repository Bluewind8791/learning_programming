package chapter20;

public class array {
  public static void main(String[] args) {
    
    int[] arr = new int[10];
    int total = 0;
  
    for (int i=0, num=1; i<arr.length; i++) {
      arr[i] = num;
      num++;
      System.out.println(arr[i]);
    }

    // 향상된 for문 - 처음부터 끝까지 돌 때
    for (int num : arr) {
      total += num;
    }

    System.out.println(total);
  }
}
