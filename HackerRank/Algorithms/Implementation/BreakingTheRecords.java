package Implementation;

import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.toList;


public class BreakingTheRecords {
    /*
     * Maria는 대학 농구를 하고 프로가 되고 싶어합니다.
     * 그녀는 한 경기에서 최대 득점과 최소 득점에 대한 자신의 시즌 기록을 깨뜨린 횟수를 표로 작성합니다.
     * 첫 번째 게임에서 득점한 득점은 시즌 기록을 세우며 그녀는 거기부터 계산을 시작합니다.
     * 최대 득점 기록을 깨뜨린 횟수와 최소 득점 기록을 깬 횟수를 리턴하시오
     */
    public static List<Integer> breakingRecords(List<Integer> scores) {
        List<Integer> result = new ArrayList<>();
        int worstRecord = scores.get(0);
        int bestRecord = scores.get(0);
        int bestRecordCount = 0;
        int worstRecordCount = 0;
        for ( Integer score : scores ) {
            if (score > bestRecord) {
                bestRecord = score;
                bestRecordCount++;
            } else if (score < worstRecord) {
                worstRecord = score;
                worstRecordCount++;
            }
        }
        result.add(bestRecordCount);
        result.add(worstRecordCount);
        return result;
    }

    public static void main(String[] args) {

        List<Integer> scores = Stream.of("10 5 20 20 4 5 2 25 1".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = breakingRecords(scores);
        System.out.println(result);
    }
}
