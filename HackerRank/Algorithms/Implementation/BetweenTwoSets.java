package Implementation;

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
    두 개의 정수 배열이 있습니다. 다음 두 조건을 만족하는 모든 정수를 구하세요.
    1. The elements of the first array are all factors of the integer being considered
    2. The integer being considered is a factor of all elements of the second array
    Example)
    a = {2, 6} / b = {24, 36}
    두 배열 사이에 두 조건을 만족하는 숫자는 6과 12가 있습니다.
    첫번째 조건으로 6%2(a[0])=0 / 6%6(a[1])=0 / 24(b[0])%6=0 / 36(b[1])%6=0
    두번째 조건으로 12%2=0 / 12%6=0 / 24%12=0 / 36%12=0
    그러므로 2를 리턴합니다.

    array a 의 최소공배수를 구합니다: 4 (최소공배수 = 두 자연수의 곱 / 최대공약수)
    array b 의 최대공약수를 구합니다: 16
    최소공배수의 배수 중 최대공약수에 최대한 가깝게 구합니다 (4,8,12,16,...)
    만약 최소공배수 16 % (4의 배수) == 0 가 된다면 count += 1 을 합니다.
    */
    public static int getTotalX(List<Integer> a, List<Integer> b) {
        int count = 0;
        Collections.sort(a);
        Collections.sort(b);
        int lcm = lcm(a);
        int gcd = gcd(b);
        // for (int i=1; ; i++) {
        //     lcm *= i;
        //     if (lcm > gcd) break;
        //     if (gcd % lcm == 0) {
        //         count += 1;
        //     }
        // }
        for (int i=lcm; i<=gcd; i+=lcm) {
            if (gcd % i == 0) {
                count++;
            }
        }
        return count;
    }

    private static int gcd(List<Integer> array) {
        int result = array.get(0);
        for (int i=1; i<array.size(); i++) {
            result = getGCD(result, array.get(i));
        }
        return result;
    }

    private static int getGCD(int smallN, int bigN) {
        if (smallN == 0) {
            return bigN;
        }
        if (bigN % smallN == 0) {
            return smallN;
        }
        return getGCD(bigN % smallN, smallN);
    }

    private static int lcm(List<Integer> array) {
        int result = array.get(0);
        for (int i=1; i<array.size(); i++) {
            result = getLCM(result, array.get(i));
        }
        return result;
    }

    private static int getLCM(int small, int big) {
        return (small * big) / getGCD(big, small);
    }

}

public class BetweenTwoSets {

    public static void main(String[] args) throws IOException {
        List<Integer> arrayA = Stream.of("2 4".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> arrayB = Stream.of("16 32 96".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int total = Result.getTotalX(arrayA, arrayB);
        System.out.println(total);
    }
}

