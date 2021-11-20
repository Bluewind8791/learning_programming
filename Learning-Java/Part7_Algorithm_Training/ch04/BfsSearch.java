package ch04;

import java.util.ArrayList;

public class BfsSearch {
  
  int count;
  boolean[] visited;
  ArrayList<Integer> queue;
  int[][] matrix;

  public BfsSearch(int count) {
    this.count = count;
    visited = new boolean[count];
    queue = new ArrayList<>();
  }

  public void bfsTraversal() {

    queue.add(0);
    visited[0] = true;

    // queue 가 empty 아닐때까지
    while (queue.size() != 0) {

      int node = queue.remove(0); // 하나 꺼내기
      System.out.print(node + " ");

      for (int j=0; j<count; j++) {
        if (matrix[node][j] != 0 && !visited[j]) {
          queue.add(j);
          visited[j] = true;
        }
      }
    }
  }


}
