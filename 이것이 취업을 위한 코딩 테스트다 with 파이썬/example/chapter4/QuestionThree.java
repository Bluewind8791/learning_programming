package chapter4;

/*
N * M 의 맵으로 육지 또는 바다.
캐릭터는 동서남북 중 한 곳을 바라본다.
맵의 각 칸은 (A, B)로 나타내며 
A는 북쪽으로부터 떨어진 칸의 개수
B는 서쪽으로부터 떨어진 칸의 개수

1. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 갈 곳을 정한다.
2. 캐릭터의 바로 왼쪽에 가보지않은 칸이 존재한다면 왼쪽으로 회전 후 한칸 전진,
    왼쪽방향에 가보지않은 칸이 없다면 왼쪽 방향으로 회전만 수행하고 1단계로 돌아감
3. 만약 네 방향이 모두 이미 가본 칸이거나 바다이면, 
    바라보는 방향을 유지한 채로 한칸 뒤로 가서 1단계로 돌아간다.
    이때 뒷칸이 바다이면 멈춘다.

캐릭터가 방문한 칸의 수를 출력하는 프로그램
*/
public class QuestionThree {

    static final int VISITED = 2;
    static final int SEA = 1;
    static final int NON_VISITED = 0;

    public static void main(String[] args) {
        int[] mapSize = {4, 4};
        int[] position = {1, 1};
        // 방향의 값으로는 0 북 1 동 2 남 3 서
        int direction = 0;
        int[][] map = {
            {1,1,1,1},
            {1,0,0,1},
            {1,1,0,1},
            {1,1,1,1}
        };
        System.out.println(solution(mapSize, position, direction, map));
    }


    private static int solution(int[] mapSize, int[] position, int direction, int[][] map) {
        int count = 0;
        // 현재 위치
        int x = position[0];
        int y = position[1];
        // 현재위치 방문 처리
        map[x][y] = VISITED;
        count += 1;
        // 북 동 남 서 방향 정의
        int[] moveX = {-1, 0, 1, 0};
        int[] moveY = {0, 1, 0, -1};
        // 4방향이 모두 바다인지 체크
        int checkCount = 0;
        //
        int checkX;
        int checkY;

        while (true) {
            // 왼쪽으로 회전 후
            direction = turnLeft(direction);
            // 캐릭터의 바로 왼쪽에 가보지않은 칸이 존재한다면
            checkX = x + moveX[direction];
            checkY = y + moveY[direction];
            if (map[checkX][checkY] == NON_VISITED) {
                // 한칸 전진
                x = checkX;
                y = checkY;
                // 방문 처리
                map[checkX][checkY] = VISITED;
                count += 1;
                checkCount = 0;
                continue;
            } else {
                // 갈 수 없는 칸이라면 처음으로 돌아가서 회전 수행
                checkCount += 1;
            }
            // 만약 네 방향이 모두 이미 가본 칸이거나 바다이면, 
            if (checkCount >= 4) {
                // 바라보는 방향을 유지한 채로 한칸 뒤로 가서 1단계로 돌아간다.
                checkX = x - moveX[direction];
                checkY = y - moveY[direction];
                // 뒷칸이 바다라면 멈춘다
                if (map[checkX][checkY] == SEA) {
                    break;
                } else {
                    // 바다가 아니라면 뒤로 이동
                    x = checkX;
                    y = checkY;
                }
            }
        }
        return count;
    }


    private static int turnLeft(int direction) {
        direction -= 1;
        if (direction == -1) {
            direction = 3;
        }
        return direction;
    }

}
/**
 * 방향을 설정해서 이동하는 문제 유형에서는 dx dy 라는 별도의 리스트를 만들어 방향을 정하는것이 효과적.
 */
