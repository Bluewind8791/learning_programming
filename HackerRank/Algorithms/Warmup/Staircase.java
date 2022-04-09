package Warmup;

/*
아래는 n=4 인 staircase 입니다.
   #
  ##
 ###
####
밑변과 높이는 모두 n과 같습니다.
# 기호와 공백을 사용하여 그립니다.
마지막 줄은 공백이 앞에 오지 않습니다.
*/
public class Staircase {

    public static void main(String[] args) {
        int n = 10;
        staircase(n);
    }

    public static void staircase(int n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (j < n - i - 1) {
                    System.out.print(" ");
                } else {
                    System.out.print("#");
                }
            }
            System.out.println();
        }
    }

}
