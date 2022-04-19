package Search;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Watson은 Sherlock에게 정수 배열을 제공합니다.
 * 그의 과제는 왼쪽에 있는 모든 요소의 합이 오른쪽에 있는 모든 요소의 합과 같도록 배열의 요소를 찾는 것입니다.
 * 정수 배열이 주어지고 기준을 충족하는 요소가 있는지 확인해야 합니다.
 * 있는 경우 YES를 반환합니다. 그렇지 않으면 NO를 반환합니다.
 */
public class SherlockAndArray {

    public static String balancedSums(List<Integer> arr) {
        if (arr.size() == 1) {
            return "YES";
        }
        int sum = arr.stream().mapToInt(Integer::intValue).sum();
        int leftY = 0;

        for (int i=0; i<arr.size(); i++) {
            int current = arr.get(i);
            sum -= current;
            if (leftY == sum) {
                return "YES";
            }
            leftY += current;
        }
        return "NO";
    }

    public static void main(String[] args) {
        List<Integer> arr = Stream.of("1 1 4 1 1".replaceAll("\\s+$", "").split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
        String result = balancedSums(arr);
        System.out.println(result);
    }
}