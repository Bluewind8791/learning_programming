package chapter3;

import java.util.Arrays;

/**
 * 다양한 수로 이루어진 배열이 있을 때
 * 주어진 수들을 M번 더하여
 * 가장 큰 수를 만드는 법칙
 * 단 배열의 특정한 인덱스에 해당하는 수가
 * 연속해서 K번을 초과하여 더해질 수 없다는 것이 특징
 */
public class QuestionTwo {

    private static int bestSolution(int n, int m, int k, int[] array) {
        int sum = 0;
        Arrays.sort(array);
        int bigOne = array[n - 1];
        int bigTwo = array[n - 2];
        // 가장 큰 수가 더해지는 횟수 계산
        int count;
        count = (int)(m / (k+1)) * k;
        count += m % (k + 1);

        sum += (count) * bigOne;
        sum += (m - count) * bigTwo;
        return sum;
    }

    private static int solution(int n, int m, int k, int[] array) {
        int sum = 0;
        Arrays.sort(array);
        int bigOne = array[n - 1];
        int bigTwo = array[n - 2];
        while (true) {
            for (int i=0; i<k; i++) {
                if (m == 0) break;
                sum += bigOne;
                m -= 1;
            }
            if (m == 0) break;
            sum += bigTwo;
            m -= 1;
        }
        return sum;
    }

    public static void main(String[] args) {
        // 배열의 크기 N
        int n = 5;
        // 숫자가 더해지는 횟수 m
        int m = 8;
        // 한 숫자를 사용할 수 있는 횟수 k
        int k = 3;
        int[] array = {2,4,5,4,6};
        System.out.println(solution(n, m, k, array));
        System.out.println(bestSolution(n, m, k, array));
    }
}
