package Warmup;

import java.util.*;
import java.util.stream.*;


/*
Alice와 Bob은 각각 HackerRank에 대해 하나의 문제를 만들었습니다.
검토자는 문제 명확성, 독창성 및 난이도의 세 가지 범주에 대해 1에서 100까지의 점수를 부여하여 두 가지 과제를 평가합니다.

Alice의 챌린지에 대한 등급은 a = (a[0], a[1], a[2]) 3중항이고
Bob의 챌린지 등급은 3중항 b = (b[0], b[1], b)입니다. [2]).

과제는 a[0]과 b[0], a[1]과 b[1], a[2]와 b[2]를 비교하여 비교점을 찾는 것입니다.
- a[i] > b[i]인 경우 Alice는 1점을 얻습니다.
- a[i] < b[i]이면 Bob에게 1점이 부여됩니다.
- a[i] = b[i]이면 어느 누구도 포인트를 받지 못합니다.

Return
- int[2]: Alice's score is in the first position, and Bob's score is in the second.
*/
public class CompareTheTriplets {

    public static void main(String[] args) {
        List<Integer> a = List.of(1, 2, 3);
        List<Integer> b = List.of(3, 2, 1);
        List<Integer> result = compareTriplets(a, b);
        System.out.println(result);
    }

    public static List<Integer> compareTriplets(List<Integer> a, List<Integer> b) {
        int[] result = {0,0};
        // List<Integer> result = List.of(0, 0);
        for (int i=0; i<3; i++) {
            if (a.get(i) > b.get(i)) {
                result[0] += 1;
            } else if (a.get(i) < b.get(i)) {
                result[1] += 1;
            }
        }
        return Arrays.stream(result).boxed().collect(Collectors.toList());
    }

}
