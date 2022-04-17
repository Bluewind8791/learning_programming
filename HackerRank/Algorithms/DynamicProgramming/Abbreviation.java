package DynamicProgramming;

import java.io.IOException;


public class Abbreviation {
    /*
    문자열 a 에 대한 아래의 작업을 수행합니다.
    1. 문자열 a 에서 0개 이상의 소문자를 대문자로 바꿉니다.
    2. 문자열 a 에서 나머지 소문자를 모두 삭제합니다.
    a, b 문자열이 주어집니다. 위에서 설명한 조건으로 
    a 를 b와 동일하게 만들 수 있다면 YES 라고 출력하고
    아니라면 NO 라고 출력하세요.
    */
    public static String abbreviation(String a, String b) {
        // dp(dynamic programming) 배열 초기화
        boolean[][] dp = new boolean[b.length() + 1][a.length() + 1];
        dp[0][0] = true;

        // index 1 부터 a[i]가 소문자라면
        for (int i=1; i<dp[0].length; i++) {
            if ( Character.isLowerCase(a.charAt(i - 1)) )
                // dp
                dp[0][i] = dp[0][i - 1];
        }

        for (int i=1; i<dp.length; i++) {
            for (int j=1; j<dp[0].length; j++) {
                char ca = a.charAt(j - 1);
                char cb = b.charAt(i - 1);
                if (Character.isUpperCase(ca)) { // 대문자라면
                    if (ca == cb) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else { // 대문자가 아니라면
                    ca = Character.toUpperCase(ca); // 대문자로 변환
                    if (ca == cb)
                        dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1];
                    else
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[b.length()][a.length()] ? "YES" : "NO";
    }

    public static void main(String[] args) throws IOException {
        String a = "Pi";
        String b = "P";
        String result = abbreviation(a, b);
        System.out.println(result);
    }

}
