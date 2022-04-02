package chapter3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 1. 숫자가 쓰인 카드들이 N x M 형태로 놓여있다. 이때 N은 행의 개수를 의미하며, M은 열의 개수를 의미
 * 2. 먼저 뽑고자 하는 카드가 포함되어있는 행을 선택.
 * 3. 그 다음 선택된 행에 포함된 카드들 중 가장 숫자가 낮은 카드를 뽑는다
 * 가장 높은 카드를 뽑는 사람이 이긴다.
 */
public class QuestionThree {

    public static void main(String[] args) {
        int n = 3; // 행의 개수
        int m = 3; // 열의 개수
        int[][] cards = {
            {3,1,2},
            {4,1,4},
            {2,2,2}
        };
        int n2 = 2; // 행의 개수
        int m2 = 4; // 열의 개수
        int[][] cards2 = {
            {7,3,1,8},
            {3,3,3,4}
        };
        System.out.println(solution(n, m, cards));
        System.out.println(solution(n2, m2, cards2));
    }

    private static Integer solution(int n, int m, int[][] cards) {
        List<Integer> minList = new ArrayList<>();
        for (int[] column : cards) {
            Arrays.sort(column);
            minList.add(column[0]);
        }
        Collections.sort(minList);
        return minList.get(minList.size()-1);
    }
}
