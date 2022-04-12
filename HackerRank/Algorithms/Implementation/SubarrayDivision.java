package Implementation;

import java.util.List;
import java.util.stream.Stream;

import static java.util.stream.Collectors.toList;

import java.util.ArrayList;

public class SubarrayDivision {
    /*
    릴리와 론은 초콜릿 바를 공유하고 싶어합니다. 각 사각형에는 정수가 있습니다.
    Lily는 다음과 같이 선택된 막대의 연속적인 부분을 공유하기로 결정합니다.
    그녀가 초콜릿 바를 나눌 수 있는 방법의 수를 결정하십시오.
    
    int s[n]: 초콜릿의 각 사각형에 있는 숫자
    int d: Ron's birth day = m개 만큼의 모든 정수의 합
    int m: Ron's birth month
    */

    public static int birthday(List<Integer> s, int d, int m) {
        int count = 0;
        for (int i=0; i<=s.size()-m; i++) {
            List<Integer> subList = new ArrayList<>(s.subList(i, i + m));
            int seg = subList.stream().mapToInt(Integer::intValue).sum();
            if (seg == d) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        List<Integer> s = Stream.of("4".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        String[] firstMultipleInput = "4 1".replaceAll("\\s+$", "").split(" ");

        int d = Integer.parseInt(firstMultipleInput[0]);
        int m = Integer.parseInt(firstMultipleInput[1]);

        int result = birthday(s, d, m);
        System.out.println(result);
    }

}
