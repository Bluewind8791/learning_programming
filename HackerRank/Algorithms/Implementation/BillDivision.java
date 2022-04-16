package Implementation;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class BillDivision {
    /*
    청구서에 다음 가격이 있다고 가정합니다 bill = {2,4,6}
    Anna는 k를 먹지않았습니다. k = bill[2] cost 6
    그렇다면 Anna의 bill 은 (2+4)/2 = 3 입니다.
    Brian의 코스트는 (2+4+6)/2 = 6 이며 차액의 6-3=3을 Anna에게 돌려줍니다.

    bill: 주문한 각 항목의 비용을 나타내는 정수 배열
    k: Anna가 먹지 않는 항목의 0부터 시작하는 인덱스를 나타내는 정수
    b: Anna가 청구서에 기부한 금액
    */
    public static void bonAppetit(List<Integer> bill, int k, int b) {
        int totalBill = bill.stream().mapToInt(Integer::intValue).sum();
        int annaPaid = (totalBill - bill.get(k)) / 2;
        if (b == annaPaid) {
            System.out.println("Bon Appetit");
        } else {
            System.out.println(b - annaPaid);
        }
    
    }

    public static void main(String[] args) {
        String[] firstMultipleInput = "4 1".replaceAll("\\s+$", "").split(" ");

        // int n = Integer.parseInt(firstMultipleInput[0]);
        int k = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> bill = Stream.of("3 10 2 9".replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(Collectors.toList());

        int b = Integer.parseInt("7".trim());

        bonAppetit(bill, k, b);
    }

}
