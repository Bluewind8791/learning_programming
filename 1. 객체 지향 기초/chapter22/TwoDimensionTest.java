package chapter22;

// 2차원 배열을 Java로 구현해보자

public class TwoDimensionTest {
  public static void main(String[] args) {
    
    int[][] arr = {{1,2,3}, {1,2,3,4}};

    for(int i=0; i<arr.length; i++) {
      for (int j=0; j<arr[i].length; j++) {
        System.out.print(arr[i][j] + ", ");
      }
      System.out.println("\t" + arr[i].length);
    }
  }
}
