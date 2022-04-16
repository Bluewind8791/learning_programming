package Implementation;

import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.toList;


public class DivisibleSumPairs {
    /*
    정수 배열 ar 과 정수 k 가 주어집니다.
    아래의 조건을 따르는 숫자 (i, j) 쌍이 몇개가 있는지 계산하시오.
    - i < j
    - ar[i] + ar[j] % k = 0
    */
    public static int divisibleSumPairs(int n, int k, List<Integer> ar) {
        int count = 0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                if (i < j && (ar.get(i) + ar.get(j)) % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        String[] firstMultipleInput = "6 3".replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);
        int k = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> ar = Stream.of("1 3 2 6 1 2".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = divisibleSumPairs(n, k, ar);
        System.out.println(result);
    }
}
