package chapter8;

/**
정수 x 가 주어질 때 정수 x에 사용할 수 있는 연산은 다음과 같습니다.
1. if (x % 5 == 0) x / 5
2. if (x % 3 == 0) x / 3
3. if (x % 2 == 0) x / 2
4. x -= 1

정수 x가 주어졌을 때, 연산 4개를 적절히 사용하여 1을 만듭니다.
연산을 사용하는 횟수의 최솟값을 출력하세요.
*/
public class QuestionTwo {

    public static void main(String[] args) {
        int x = 26;
        System.out.println(
            makeOne(x)
        );
    }

    private static Integer makeOne(int x) {
        // dp table 초기화
        int[] dpt = new int[30001];

        // dp bottom-up
        for (int i=2; i<=x; i++) {
            // x -= 1
            dpt[i] = dpt[i - 1] + 1;
            // if (x % 2 == 0) x / 2
            if (i % 2 == 0) {
                dpt[i] = Math.min(dpt[i], dpt[i / 2] + 1);
            }
            if (i % 3 == 0) {
                dpt[i] = Math.min(dpt[i], dpt[i / 3] + 1);
            }
            if (i % 5 == 0) {
                dpt[i] = Math.min(dpt[i], dpt[i / 5] + 1);
            }
        }
        return dpt[x];
    }
}