package Warmup;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * 당신은 아이의 생일 케이크를 담당하고 있습니다.
 * 당신은 케이크에 그들의 총 연령의 해마다 하나의 양초가 있을 것이라고 결정했습니다.
 * 그들은 가장 높은 양초만 끌 수 있을 것입니다.
 * 얼마나 많은 양초가 가장 높은지 세십시오.
 */
public class BirthdayCakeCandles {

    public static int solution(List<Integer> candles) {
        Collections.sort(candles);
        int tallest = candles.get(candles.size()-1);
        return candles.stream().filter(c -> c == tallest).collect(Collectors.toList()).size();
    }


    public static void main(String[] args) {
        List<Integer> candles = Stream.of(4, 4, 1, 3).collect(Collectors.toList());
        System.out.println(solution(candles));
    }

}
