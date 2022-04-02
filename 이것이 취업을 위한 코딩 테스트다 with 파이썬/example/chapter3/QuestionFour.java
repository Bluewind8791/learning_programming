package chapter3;


/*
어떠한 수 N이 1이 될 때 까지
다음의 두 과정 중 하나를 반복적으로 선택하여 수행
단 두번쨰 연산은 n이 k로 나누어 떨어질때만 사용 가능
1. n =- 1
2. n / k
과정을 수행하는 최소 횟수는?
logic : 나누기를 최대한 많이 해야 함
*/
public class QuestionFour {

    public static void main(String[] args) {
        int n = 25;
        int k = 5;
        int n1 = 17;
        int k1 = 4;
        System.out.println(solution(n, k));
        System.out.println(solution(n1, k1));
    }

    private static Integer solution(int number, int k) {
        int count = 0;
        while (true) {
            if (number <= 1) break;
            if (number % k == 0) {
                number /= k;
                count += 1;
            } else {
                number -= 1;
                count += 1;
            }
        }
        return count;
    }
}
