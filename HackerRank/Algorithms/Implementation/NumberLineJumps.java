package Implementation;


/**
 * 당신은 다양한 동물들과 함께 서커스 쇼를 안무하고 있습니다.
 * 점프할 준비가 된 두 마리의 캥거루가 숫자 줄에 표시됩니다.

 * 첫번쨰 캥거루가 x1 에서 시작하여 v1 미터까지 점프하여 이동합니다.
 * 두번째 캥거루는 x2 에서 시작하여 v2 미터만큼 점프하여 이동합니다.
 * 두 캥거루가 같은 위치에 서있는 위치가 존재한다면 YES를 반환하고, 그렇지 않으면 NO를 반환합니다.
 */
public class NumberLineJumps {

    public static String kangaroo(int x1, int v1, int x2, int v2) {
        // 앞에 서있는 캥거루가 다른 캥거루 보다 속도가 빠르거나 같다면 절대 따라잡을 수 없다.
        if (x1 > x2 && v1 >= v2) {
            return "NO";
        } else if (x2 > x1 && v2 >= v1) {
            return "NO";
        }
        /*
         * 해설
         * if (x1 + (jump * v1) == x2 + (jump * v2) ) 일 때, 두 캥거루는 만납니다.
         * 위의 식을 간단하게 풀면 아래의 식이 됩니다.
         * (x1 - x2) / (v1 - v2) == jump
         * 이때 jump 는 양의 무한대 수이기 때문에
         * (x1 - x2) % (v1 - v2) == 0 일 때 두 캥거루는 만납니다.
        */
        if ((x1 - x2) % (v1 - v2) == 0) {
            return "YES";
        } else {
            return "NO";
        }
    }


    public static void main(String[] args) {
        String[] firstMultipleInput = "0 3 4 2".replaceAll("\\s+$", "").split(" ");
        int x1 = Integer.parseInt(firstMultipleInput[0]);
        int v1 = Integer.parseInt(firstMultipleInput[1]);
        int x2 = Integer.parseInt(firstMultipleInput[2]);
        int v2 = Integer.parseInt(firstMultipleInput[3]);
        System.out.println(
            kangaroo(x1, v1, x2, v2)
        );
    }

}
