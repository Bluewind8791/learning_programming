package Warmup;

import java.util.List;


/**
 * 정수 배열이 주어지면 양수, 음수, 0인 요소의 비율을 계산합니다.
 * 소수점 이하 6자리가 있는 새 줄에 각 분수의 소수점 값을 인쇄합니다.
 * 
 */
public class PlusMinus {

    public static void main(String[] args) {
        List<Integer> arr = List.of(1, 1, 0, -1, -1);
        plusMinus(arr);
    }

    public static void plusMinus(List<Integer> arr) {
        double total = arr.size();
        double plus = arr.stream().filter(n -> n > 0).count();
        double minus = arr.stream().filter(n -> n < 0).count();
        double zero = total - plus - minus;
        System.out.println( String.format("%.6f", (plus  / total)) );
        System.out.println( String.format("%.6f", (minus / total)) );
        System.out.println( String.format("%.6f", (zero  / total)) );
    }
}
