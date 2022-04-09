package Warmup;

import java.util.ArrayList;
import java.util.List;

/**
 * 정사각형의 행렬이 주어지면 두 대각선의 합을 구하고
 * 두 합 사이의 차이를 계산하여 리턴하시오.
 */
public class DiagonalDifference {

    public static int diagonalDifference(List<List<Integer>> arr) {
        int cross1 = 0;
        int cross2 = 0;
        int size = arr.size();
        for (int i=0; i<size; i++) {
            // 대각선의 합을 구하기
            cross1 += arr.get(i).get(i);
            // 반대편 대각선의 합을 구하기
            cross2 += arr.get(i).get(size - 1 - i);
        }
        return Math.abs(cross1 - cross2);
    }

    public static void main(String[] args) {
        List<List<Integer>> arr = new ArrayList<>();
        arr.add(List.of(11, 2, 4));
        arr.add(List.of(4, 5, 6));
        arr.add(List.of(10, 8, -12));
        System.out.println(diagonalDifference(arr));
    }
}
