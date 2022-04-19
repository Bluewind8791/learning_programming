package Search;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Knight L 은 L자 모양으로 움직이는 체스 말입니다.
 * Knight L (a,b)은 움직일 수 있는 위치는 다음의 조건을 충족합니다.
 * x2 = x1 +- a && y2 = y1 +- b ||
 * x2 = x1 +- b && y2 = y1 +- a
 * (a,b)와 (b,a)는 동일한 움직임을 허용합니다.
 * 1 <= a,b < n
 * 
 * n * n 의 체스 보드가 주어집니다.
 * KnightL 가 (0,0) 에서 (n-1, n-1) 까지의 최소 이동 횟수는 얼마인지 계산하시오.
 * 만약 그 위치에 도달할 수 없다면 -1 을 리턴하세요.
 * 
 * 예를 들어 n이 5일때 5x5의 체스판이 주어집니다.
 * output 은 아래와 같습니다
 * 4 4  2  8 -> row 1 (a = 1, b = 1,2,3,4 일 때)
 * 4 2  4  4 -> row 2 (a = 2, b = 1,2,3,4 일 때)
 * 2 4 -1 -1 -> row 3 (a = 3, b = 1,2,3,4 일 때)
 * 8 4 -1  1 -> row 4 (a = 4, b = 1,2,3,4 일 때)
 */
public class KnightLOnAChessboard {

    public static List<List<Integer>> knightlOnAChessboard(int n) {
        List<List<Integer>> resultList = new ArrayList<>();

        // 이동 가능한 범위 a b
        for (int a=1; a<n; a++) {
            List<Integer> list = new ArrayList<>();
            for (int b=1; b<n; b++) {
                // 체스판 초기화
                int[][] chess = new int[n][n];
                // bfs
                int result = bfs(n, chess, a, b);
                list.add(result);
            }
            resultList.add(list);
        }
        return resultList;
    }

    private static int bfs(int n, int[][] chess, int a, int b) {
        // 큐 생성
        Queue<Location> queue = new LinkedList<>();
        // 시작 지점 큐 추가
        queue.add(new Location(0, 0));

        // 이동 가능한 방향 정의
        // dx = x1 +- a && dy = y1 +- b || dx = x1 +- b && dy = y1 +- a
        int[] dx = new int[]{ a, a, -a, -a, b, b, -b, -b};
        int[] dy = new int[]{-b, b, -b,  b, -a, a, a, -a,};

        // 큐가 빌때 까지 진행
        while (!queue.isEmpty()) {
            // 큐에서 꺼내옴
            Location location = queue.poll();
            int x = location.x;
            int y = location.y;
            // 현재 위치에서 이동 가능한 위치 확인
            for (int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // 범위 체크
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                    continue;
                }
                // 방문하지 않은 곳이라면
                if (chess[nx][ny] == 0) {
                    // 최단 거리 기록
                    chess[nx][ny] = chess[x][y] + 1;
                    // 큐에 추가하여 해당방향으로 진행
                    queue.add(new Location(nx, ny));
                }
            }
        }
        if (chess[n - 1][n - 1] == 0) {
            return -1;
        }
        return chess[n - 1][n - 1];
    }

    public static void main(String[] args) {
        int n = Integer.parseInt("5".trim());
        List<List<Integer>> result = knightlOnAChessboard(n);
        System.out.println(result);
    }

}

class Location {
    int x, y;
    public Location(int x, int y) {
        this.x = x;
        this.y = y;
    }
}