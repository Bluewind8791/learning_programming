package DynamicProgramming;

import java.math.BigInteger;

public class FibonacciModified {
    /**
    다음 정의를 사용하여 수정된 피보나치 수열을 구현합니다.
    Given terms t[i] and t[i+1] where i ∈ (1,∞), term t[i+2] is computed as:
    t i+2 = t i + (t i+1)²
    */
    public static BigInteger fibonacciModified(int t1, int t2, int n) {
        BigInteger[] array = new BigInteger[n];
        array[0] = BigInteger.valueOf(t1);
        array[1] = BigInteger.valueOf(t2);
        for (int i=2; i<n; i++) {
            array[i] = array[i-2].add( array[i-1].pow(2) );
        }
        return array[n-1];
    }

    public static void main(String[] args) {
        String[] firstMultipleInput = "0 1 10".replaceAll("\\s+$", "").split(" ");

        int t1 = Integer.parseInt(firstMultipleInput[0]);
        int t2 = Integer.parseInt(firstMultipleInput[1]);
        int n = Integer.parseInt(firstMultipleInput[2]);
        BigInteger result = fibonacciModified(t1, t2, n);
        System.out.println(result);
    }
}
