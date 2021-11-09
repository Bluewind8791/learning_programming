package ch07;

public class Fibonacci {

  int value[];
  int number;

  public Fibonacci(int number) {
    this.number = number;
    value = new int[number];
  }
  

  // use recursive
  public int fiboRecursive(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fiboRecursive(n - 1) + fiboRecursive(n - 2);
  }


  // use Iteration (for)
  public int fiboIteration(int n) {

    int ppre = 0;
    int pre = 1;
    int current = 0; // 초기화

    if (n == 0) return 0;
    if (n == 1) return 1;

    for (int i=2; i<=n; i++) {
      current = ppre + pre;
      ppre = pre;
      pre = current;
    }

    return current;
  }


  // use memoization
  public int fiboMemoization(int n) {
    
    int result = 0;

    value[0] = 0;
    value[1] = 1;

    if (n == 0) {
      return value[0];
    }
    if (n == 1) {
      return value[1];
    }

    for (int i=2; i<=n; i++) {
      value[i] = value[i - 1] + value[i - 2];
      result = value[i];
    }

    return result;
  }

  public static void main(String[] args) {
    
    Fibonacci fibo = new Fibonacci(100);

    int recurResult = fibo.fiboRecursive(10);
    System.out.println(recurResult);

    int iterResult = fibo.fiboIteration(10);
    System.out.println(iterResult);

    int memoiResult = fibo.fiboMemoization(10);
    System.out.println(memoiResult);
  }


}
