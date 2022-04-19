package Search;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/*
 * Lauren은 향후 몇 년 동안 주택에 대한 뚜렷한 예상 가격 차트를 가지고 있습니다.
 * 그녀는 1년 안에 집을 사서 다른 년에 팔아야 하고, 그렇게 해서 손실을 봐야 합니다.
 * 그녀는 재정적 손실을 최소화하기를 원합니다.

 * price = {20,15,8,2,12} 일 때
 * 그녀의 최소 손실은 price[1]=15 때 구입하고, price[4]=12 일때 팔아야 합니다. (15-12=3)
 * int형의 가능한 최소 손실을 리턴하세요.
 */
public class MinimumLoss {

    public static void main(String[] args) {
        List<Long> price = Stream.of("20 7 8 2 5".replaceAll("\\s+$", "").split(" "))
            .map(Long::parseLong)
            .collect(Collectors.toList());
        Long result = minimumLoss(price);
        System.out.println(result);
    }


    public static Long minimumLoss(List<Long> price) {
        // using hashmap
        Map<Long, Integer> map = new HashMap<>();
        for (int i=0; i<price.size(); i++) {
            map.put(price.get(i), i);
        }
        // sorting
        Collections.sort(price);

        long minValue = Long.MAX_VALUE;
        int size = price.size();

        for (int i=size-1; i>0; i--) {
            if ( map.get(price.get(i)) < map.get(price.get(i-1)) ) {
                minValue = Math.min(price.get(i) - price.get(i-1), minValue);
            }
        }
        return minValue;
    }


}
