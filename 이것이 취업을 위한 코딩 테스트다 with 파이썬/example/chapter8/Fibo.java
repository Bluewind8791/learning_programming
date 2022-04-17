package chapter8;

public class Fibo {

    static long fibonacci(int n) {
        // DP 테이블 초기화
        long d[] = new long[100];
        
        // 첫번째 두번째 피보나치 수는 1로 고정
        d[1] = 1l;
        d[2] = 1l;
        
        // 피보나치 함수를 bottom-up dp로 구현 (반복문)
        for (int i=3; i<=n; i++) {
            d[i] = d[i-1] + d[i-2];
        }
        return d[n];
    }

    public static void main(String[] args) {
        System.out.println(
            fibonacci(10)
        );
    }
}