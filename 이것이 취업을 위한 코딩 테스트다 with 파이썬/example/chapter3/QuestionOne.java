package chapter3;

/**
 * 카운터에는 거스름돈으로 사용할 
 * 500원 100원 50원 10원 동전이 무한히 존재한다고 가정
 * 손님에게 거슬러 줘야할 돈이 N원일 때, 
 * 거슬러 줘야할 동전의 최소 갯수를 구하라
 * -> 가장 큰 화폐부터 돈을 거슬러준다
 */
public class QuestionOne {

    public static void main(String[] args) {
        System.out.println(solution(1260));
        System.out.println(bestSolution(1260));
    }

    private static int bestSolution(int money) {
        int count = 0;
        int[] coinTypes = {500, 100, 50, 10};
        for (int coin : coinTypes) {
            count += money / coin;
            money %= coin;
        }
        return count;
    }

    private static Integer solution(int money) {
        int numberOfCoin = 0;
        if (money >= 500) {
            numberOfCoin += (Integer)(money / 500);
            money = money % 500;
        }
        if (money >= 100) {
            numberOfCoin += (Integer)(money / 100);
            money = money % 100;
        }
        if (money >= 50) {
            numberOfCoin += (Integer)(money / 50);
            money = money % 50;
        }
        if (money >= 10) {
            numberOfCoin += (Integer)(money / 10);
            money = money % 10;
        }
        
        return numberOfCoin;
    }

}