package Warmup;

import java.util.List;
import java.util.Arrays;

import static java.util.stream.Collectors.toList;

/**
 * 이 과제에서는 일부 정수가 상당히 클 수 있다는 점을 염두에 두고 배열에 있는 요소의 합을 계산하고 인쇄해야 합니다.
 * 아래 편집기에서 매우 큰 합계 기능을 완료하십시오. 모든 배열 요소의 합계를 반환해야 합니다.
 */
public class AVeryBigSum {
    
    public static void main(String[] args) {
        long[] arr = {1000000001, 1000000002, 1000000003, 1000000004, 1000000005};
        List<Long> ar = Arrays.stream(arr).boxed().collect(toList());
        System.out.println(aVeryBigSum(ar));
    }

    public static long aVeryBigSum(List<Long> ar) {
        long result = 0;
        for (Long l : ar) {
            result += l;
        }
        return result;
    }
}
