package ch05;


class MyGraph {
  private int count;
  private int[][] vertexMatrix;
  private int[] distance;       // 가장 가까운거리
  private boolean[] visited;
  private static int UNLIMIT = 99999999;

  public MyGraph(int count) {
    this.count = count;
    vertexMatrix = new int[count][count];
    distance = new int[count];
    visited = new boolean[count];
  }

  public void addEdges(int from, int to, int weight) {
    vertexMatrix[from][to] = weight;
    vertexMatrix[to][from] = weight;
  }

  public void calcShortPath(int from) {

    // 처음에는 거리 다 무한대로 설정
    for (int i=0; i<count; i++) {
      distance[i] = UNLIMIT;
    }

    // 시작
    visited[from] = true;
    distance[from] = 0; // 본인이 본인에게 가는 거리

    for (int i=0; i<count; i++) {
      if (visited[from] && vertexMatrix[from][i] != 0) {
        distance[i] = vertexMatrix[from][i];
      }
    }

    for (int k=0; k<count-1; k++) {
      int min = UNLIMIT;
      int minIndex = -1;

      for (int i=0; i<count; i++) {
        if (!visited[i] && distance[i] != UNLIMIT) {
          if (distance[i] < min) {
            min = distance[i];
            minIndex = i;
          }
        }
      }

      visited[minIndex] = true;
      for (int i=0; i<count; i++) {
        if (!visited[i] && vertexMatrix[minIndex][i] != 0) {
          if (distance[i] > distance[minIndex] + vertexMatrix[minIndex][i]) {
            distance[i] = distance[minIndex] + vertexMatrix[minIndex][i];
          }
        }
      }
    }
  }

  public void showDistance(int from) {
    for (int i=0; i<count; i++) {
      System.out.println("from "+ from +" node to "+ i +" node shorten distance is "+ distance[i]);
    }
  }

}


public class ShortenPath {
  public static void main(String[] args) {
    
    MyGraph graph = new MyGraph(6);
    graph.addEdges(0, 1, 1);
    graph.addEdges(0, 2, 4);
    graph.addEdges(1, 2, 2);
    graph.addEdges(2, 3, 1);
    graph.addEdges(3, 4, 8);
    graph.addEdges(3, 5, 3);
    graph.addEdges(4, 5, 4);

    graph.calcShortPath(0);
    graph.showDistance(0);
  }
}
