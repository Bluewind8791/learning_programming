package ch06;

import java.util.Stack;

public class Robot {
  
  public static int N_DIRECTIONS = 4; // 4방향
  public static int WIDTH = 8;        // 맵 가로
  public static int HEIGHT = 8;       // 맵 세로

  Stack<Move> stack = new Stack<>();  // 스택 만들기
  Move Move;
  Maze maze = new Maze();

  public int[][] DIRECTION_OFFSETS = {
    {0, -1},		// 위쪽으로 이동.
		{1, 0},			// 오른쪽으로 이동.
		{0, 1},			// 아래쪽으로 이동.
		{-1, 0}			// 왼쪽으로 이동.
  };

  public static int NOT_VISITED = 0;
  public static int WALL = 1;
  public static int VISITED = 2;
  int[][] markArray = new int[8][8];  // visited mark array



  // 길 찾기 함수
  public void findPath(int startX, int startY, int endX, int endY) {
  
    // 초기화
    boolean isEmpty = false;
    boolean isFound = false;
  
    Move start = new Move(startX, startY);
    start.direction = 0;
    stack.push(start); // 초기값 저장
  
    // 스택이 비거나 출구를 찾을때까지 반복
    while (isEmpty == false && isFound == false) {
  
      Move curPos = stack.pop();  // 스택에서 하나씩 꺼냄 갈만한대가 생길때 까지
      int x = curPos.x;           // 현재 위치 x에 대입
      int y = curPos.y;           // 현재 위치 y에 대입
      int direction = curPos.direction;   // 현재 방향 direction에 대입
  
      // 출구 못찾았고, 4방향 다 돌때까지 반복
      while (isFound == false && direction < N_DIRECTIONS) {
  
        int newX = x + DIRECTION_OFFSETS[direction][0]; // new x, y 대입
        int newY = y + DIRECTION_OFFSETS[direction][1];
  
        if (newX >= 0 && newX < WIDTH // X 범위 안에 있는지
        && newY >= 0 && newY < HEIGHT // Y 범위 안에 있는지
        && maze.myMaze[newY][newX] == NOT_VISITED   //  if not visited
        && markArray[newY][newX] == NOT_VISITED) {

          Move newPosition = new Move(newX, newY); // 그러면 new position으로 이동
          newPosition.direction = direction + 1;   // 방향 전환
          stack.push(newPosition);   // 스택에 다시 넣음
          markArray[y][x] = VISITED; // visited 처리
  
          x = newX;
          y = newY;
          direction = 0;
  
          if (newX == endX && newY == endY) { // 출구 도착
            isFound = true; // 출구 flag 처리
            newPosition.x = newX; // 스택에서 빼서 x, y에 대입
            newPosition.y = newY;
            newPosition.direction = 0;
            stack.push(newPosition);  // 스택에 위치 저장
            markArray[newY][newX] = VISITED; // visited 처리
          }
        }
  
        else direction++;
      } // end of while
  
      isEmpty = stack.isEmpty();
  
    } // end of while
  } // end of findPath method


  public void showPath() {

    int[][] resultArray = new int[8][8];
    boolean isEmpty = false;

    for (int i=0; i<HEIGHT; i++) {
      for (int j=0; j<WIDTH; j++) {
        resultArray[i][j] = maze.myMaze[i][j];
      }
    }

    for (int i=0; i<HEIGHT; i++) {
      for (int j=0; j<WIDTH; j++) {
        if (maze.myMaze[i][j] == WALL) {
          System.out.print("■");
        }
        else if (markArray[i][j] == VISITED) {
          System.out.print("□");
        }
        else {
          System.out.print("　");
        }
      }
      System.out.println();
    }

    int i = 0;
    while (isEmpty == false) {
      Move move = stack.pop();
      int x = move.x;
      int y = move.y;
      resultArray[y][x] = VISITED;

      if (i > 0) {
        System.out.print("<-");
      }
      System.out.print("(" + x + "," + y + ")");
      i++;
      isEmpty = stack.isEmpty();
    }
    System.out.println();


  } // end of showPath method


} // end of class

