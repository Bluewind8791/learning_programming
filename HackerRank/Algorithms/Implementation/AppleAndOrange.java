package Implementation;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Sam의 집에는 과일이 많이 나오는 사과나무와 오렌지나무가 있습니다.
 * 아래 그림에서 빨간색 영역은 집을 나타내며 집의 시작점은 s, 끝점은 t입니다.

 * 사과 나무(point a)는 집의 왼쪽에 있고, 오렌지 나무(point b)는 집 오른쪽에 있습니다.
 * 과일이 떨어질 때, d 는 distance 를 의미하며 - 인 경우, 오른쪽에 떨어진 것을 의미합니다.
 * 거리 d 와 사과의 수 m 과 오렌지 n 이 주어집니다.
 * Sam의 집에 떨어지는 사과와 오렌지의 수가 몇개인지 계산하세요
 * 
 * ex) house s = 7, t = 10 -> {7, 10}
 * apple tree a = 4 / orage tree b = 12
 * m = 3 apples and n = 3 orages
 * apples = {2, 3, -4} / oranges = {3, -2, -4}
 * 각 나무의 위치와 각 열매의 거리를 추가합니다.
 * apples = {2+4, 3+4, -4+4}={6, 7, 0} / oranges = {3+12, -2+12, -4+12}={15, 10, 8}
 * {7, 10} 사이에는 사과 1개와 오렌지 2개가 있습니다.
 */
public class AppleAndOrange {

    public static void countApplesAndOranges(
            int houseStart, int houseEnd, int appleTree, int orangeTree,
            List<Integer> apples,
            List<Integer> oranges
    ) {
        apples = apples.stream().map(apple -> apple += appleTree).collect(Collectors.toList());
        oranges = oranges.stream().map(orange -> orange += orangeTree).collect(Collectors.toList());
        System.out.println(
            apples.stream().filter(apple -> apple >= houseStart && apple <= houseEnd).collect(Collectors.toList()).size()
        );
        System.out.println(
            oranges.stream().filter(orange -> orange >= houseStart && orange <= houseEnd).collect(Collectors.toList()).size()
        );
    }


    public static void main(String[] args) {
        int s = 7;
        int t = 10;
        int a = 4;
        int b = 12;
        List<Integer> apples = Arrays.asList(2, 3, -4);
        List<Integer> oranges = Arrays.asList(3, -2, -4);
        countApplesAndOranges(s, t, a, b, apples, oranges);
    }

}
