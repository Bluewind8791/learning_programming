package Implementation;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class SalesByMatch {

    /**
    색깔별로 짝을 지어야 하는 큰 양말 더미가 있습니다.
    각 양말의 색상을 나타내는 정수 배열이 주어지면
    색상이 일치하는 양말이 몇 켤레가 있는지 확인하십시오.
    */
    public static int sockMerchant(int n, List<Integer> ar) {
        int pairs = 0;
        Collections.sort(ar);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (ar.get(i) == ar.get(j)) {
                    pairs++;
                    ar.set(j, 0);
                    break;
                }
            }
        }
        return pairs;
    }

    public static void main(String[] args) {
        int n = Integer.parseInt("9".trim());
        List<Integer> ar = Stream.of("10 20 20 10 10 30 50 10 20".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(Collectors.toList());

        int result = sockMerchant(n, ar);
        System.out.println(result);
    }
}
