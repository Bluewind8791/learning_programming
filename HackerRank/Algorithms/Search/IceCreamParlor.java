package Search;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * 두 친구는 돈을 모아 아이스크림 가게에 가는 것을 좋아합니다.
 * 그들은 항상 두 가지 독특한 맛을 선택하고 모든 돈을 씁니다.
 * 아이스크림 맛에 대한 가격 목록이 주어지면 그들이 가진 모든 돈을 들일 두 가지를 선택하십시오.
 * 
 * int m: 지출해야 하는 총 금액
 * int cost[n]: 아이스크림 각 맛 별 금액
 * return: int[2]: 구매한 두 가지 맛의 가격 인덱스, 오름차순 정렬
 */
public class IceCreamParlor {

    public static void main(String[] args) {
        int m = Integer.parseInt("4".trim());

        List<Integer> arr = Stream.of("2 2 4 3".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(Collectors.toList());

        List<Integer> result = icecreamParlor(m, arr);
        System.out.println(result);
    }


    public static List<Integer> icecreamParlor(int m, List<Integer> arr) {
        Integer[] result = new Integer[2];
        // HashMap 생성
        Map<Integer, Integer> map = new HashMap<>();

        // 모든 아이스크림을 확인
        for (int i=0; i<arr.size(); i++) {
            int x = arr.get(i); // x 는 i 번째 아이스크림의 가격
            int y = m - x; // x + y = m -> y = m - x

            Integer j = map.get(y);
            if (j != null) { // hashmap 에서 y 의 값이 존재한다면
                // result에 값을 넣어서 return 합니다
                result[0] = j + 1;
                result[1] = i + 1;
                break;
            }
            // hashmap 에 y 값이 없다면 map에 추가합니다.
            map.put(x, i);
        }
        return Arrays.asList(result);
    }


}
