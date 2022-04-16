package Implementation;

import static java.util.stream.Collectors.toList;

import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class MigratoryBirds {
    /**
     * 모든 요소가 새 유형 ID를 나타내는 새 관찰의 배열이 주어지면 가장 자주 목격되는 유형의 ID를 결정하십시오.
     * 1개 이상의 유형이 최대 금액으로 발견되면 가장 작은 ID를 반환합니다.
     */
    public static int migratoryBirds(List<Integer> arr) {
        int maxNum = 0;
        Integer result = null;
        Set<Integer> set = arr.stream().collect(Collectors.toSet());
        for (Integer num : set) {
            Integer numSize = arr.stream().filter(n -> n == num).collect(toList()).size();
            if (numSize > maxNum) {
                maxNum = numSize;
                result = num;
            }
        }
        return result;
    }


    public static void main(String[] args) {

        List<Integer> arr = Stream.of("1 4 4 4 5 3".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = migratoryBirds(arr);
        System.out.println(result);
    }
}
