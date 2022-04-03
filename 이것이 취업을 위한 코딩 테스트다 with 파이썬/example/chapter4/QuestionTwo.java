package chapter4;

/*
왕실 정원은 8 * 8 좌표 평면이다. 왕실 정원의 특정한 칸에 나이트가 서있다. 
나이트는 L자 형태로만 이동할 수 있으며 정원 밖으로는 나갈 수 없다 
나이트는 특정한 위치에서 두가지 경우로 이동할 수 있다 
1. 수평으로 두칸 이동한 뒤에 수직으로 한칸 이동 
2. 수직으로 두칸 이동한 뒤에 수평으로 한칸 이동

왕실 정원의 나이트의 위치가 주어졌을 때, 나이트가 이동할 수 있는 경우의 수를 출력하시오
행은 1 ~ 8 / 열은 a ~ h 로 표현
*/

public class QuestionTwo {

    public static void main(String[] args) {
        String knight = "a1";
        System.out.println(solution(knight));
    }

    private static int solution(String start) {
        int count = 0;
        int startX = 0;
        int startY = 0;
        
        // start posistion x, y
        String[] column = {"a","b","c","d","e","f","g","h"};
        for (int i=0; i<column.length; i++) {
            if (start.substring(0) == column[i]) {
                startX = i;
            }
        }
        startY = Integer.parseInt(start.substring(1)) - 1;

        // L자형태 이동 - 수평으로 두칸 이동 후 수직으로 한칸 이동
        // 수직으로 두칸 이동 후 수평으로 한칸 이동
        int[][] knightMove = {
            {-2, -1},
            {-1, -2},
            {-2, 1},
            {-1, 2},
            {2, -1},
            {1, -2},
            {2, 1},
            {1, 2}
        };
        for (int[] move : knightMove) {
            int movedX = startX + move[0];
            int movedY = startY + move[1];

            // 이동하여 맵을 벗어나지 않으면 count 추가
            if (movedX >= 0 && movedX <= 7 && movedY >= 0 && movedY <= 7) {
                count += 1;
            }
        }
        return count;
    }

}
