package chapter5;

import java.util.LinkedList;
import java.util.Queue;

/*
n * m 크기의 미로를 탈출
시작 위치 (1, 1)
출구 (n, m)
괴물이 있는 부분은 0 없는 부분은 1
탈출을 위하여 움직어야 하는 최소 칸의 개수를 구하시오 (첫번째 칸과 마지막 칸 포함)
*/
public class QuestionFour {

    static int n = 5;
    static int m = 6;
    static int[][] maze = {
        {1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1}, 
        {0, 0, 0, 0, 0, 1}, 
        {1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1}
    };
    // 이동할 네 방향 정의 (상하좌우)
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        /*
        logic
        BFS는 시작 지점에서 가까운 노드부터 차례대로 그래프의 모든 노드를 탐색한다.
        그러므로 1,1 지점에서 부터 BFS를 수행하여 모든 노드의 값을 거리 정보로 넣으면 된다.
        */
        System.out.println(
            // 시작지점 0, 0
            bfs(0, 0)
        );
    }


    static int bfs(int startX, int startY) {
        // Queue 구현
        Queue<Location> queue = new LinkedList<>();
        // 큐에 x, y 삽입
        queue.add(new Location(startX, startY));

        // 큐가 빌때 까지 반복
        while (!queue.isEmpty()) {
            // 큐를 꺼낸다
            Location location = queue.poll();
            int x = location.x;
            int y = location.y;
            // 현재 위치에서 4방향으로의 위치 확인
            for (int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                // 맵을 벗어난다면
                if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
                    continue;
                }
                // 괴물인 경우
                if (maze[newX][newY] == 0) {
                    continue;
                }
                // 방문하지 않은 곳이라면
                if (maze[newX][newY] == 1) {
                    // 최단 거리 기록
                    maze[newX][newY] = maze[x][y] + 1;
                    // 큐에 추가하여 해당 방향으로 진행
                    queue.add(new Location(newX, newY));
                }
            }
        }
        return maze[n - 1][m - 1];
    }

}


class Location {
    int x, y;
    public Location(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
