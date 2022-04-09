package Warmup;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * 5개의 양의 정수가 주어졌을 때
 * 5개의 정수 중 4개를 골라서 더한 최소값과 최대값을 찾으십시오.
 * 그런 다음 각각의 최소값과 최대값을 공백으로 구분된 두 개의 긴 정수로 구성된 한 줄로 인쇄합니다.
 */
public class MiniMaxSum {

    public static void miniMaxSum(List<Integer> arr) {
        Long small = 0l;
        Long big = 0l;

        Collections.sort(arr);
        List<Integer> smallList = arr.stream().limit(4).collect(Collectors.toList());
        for (Integer num : smallList) {
            small += num;
        }

        Collections.reverse(arr);
        List<Integer> bigList = arr.stream().limit(4).collect(Collectors.toList());
        for (Integer num : bigList) {
            big += num;
        }
        System.out.println(small+" "+big);
    }

    public static void main(String[] args) {
        // List<Integer> arr = Stream.of(1,3,5,7,9).collect(Collectors.toList());
        List<Integer> arr = Stream.of(256741038, 623958417, 467905213, 714532089, 938071625).collect(Collectors.toList());
        miniMaxSum(arr);
    }

}
