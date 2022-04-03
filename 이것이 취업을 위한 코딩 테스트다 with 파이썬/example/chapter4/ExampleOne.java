package chapter4;

/**
 * 여행자 A는 N * N 크기의 정사각형 공간 위에 서있다.
 * 가장 왼쪽 위 좌표는 1,1
 * 가장 오른쪽 좌표는 N, N에 해당한다
 * 계획서가 주어졌을때 여행자가 최종적으로 도착할 지점의 좌표는?
 */
public class ExampleOne {

    public static void main(String[] args) {
        // 공간의 크기를 나타내는 n
        int n = 5;
        // 여행자가 이동할 계획서
        String[] plan = {"R","R","R","U","D","D"};
        solution(n, plan);
    }

    private static void solution(int n, String[] plan) {
        // 초기 상태
        int x = 1;
        int y = 1;
        // Left, Right, Up, Down
        String[] moveType = {"L","R","U","D"};
        int[] moveX = {0, 0, -1, 1};
        int[] moveY = {-1, 1, 0, 0};

        for (String move : plan) {
            for (int i=0; i<moveType.length; i++) {
                if (move == moveType[i]) {
                    // 맵을 벗어나면 무시
                    if (x + moveX[i] < 1 || x + moveX[i] > n || y + moveY[i] < 1 || y + moveY[i] > n) {
                        continue;
                    }
                    // 이동 수행
                    x += moveX[i];
                    y += moveY[i];
                }
            }
        }
        System.out.println(x +" "+ y);
    }

}