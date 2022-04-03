package chapter4;

/**
 * 정수 n이 입력되면 0시 0분 0초부터 n시 59분 59초까지의 모든 시각 중에서
 * 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램
 */
public class ExampleTwo {

    public static void main(String[] args) {
        int n = 5;
        System.out.println(solution(n));
    }

    private static int solution(int n) {
        int count = 0;
        for (int hour=0; hour<=n; hour++) {
            for (int minute=0; minute<60; minute++) {
                for (int second=0; second<60; second++) {
                    // 시간안에 3이 포함되어있다면
                    if (String.format("%d", hour).contains("3")
                        || String.format("%d", minute).contains("3")
                        || String.format("%d", second).contains("3")
                    ) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
}
