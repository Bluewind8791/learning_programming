package chapter5;

public class factorial {

    public static void main(String[] args) {
        int n = 5;
        // 1*2*3*4*5
        System.out.println(ExampleFactorial(n));
    }

    private static int ExampleFactorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return  n * ExampleFactorial(n - 1);
    }


}
