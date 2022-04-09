package Warmup;

import java.io.*;
import java.util.*;


public class SimpleArraySum {

    public static void main(String[] args) throws IOException {
        List<Integer> ar = List.of(1, 2, 3);
        int result = simpleArraySum(ar);
        System.out.println(result);
    }

    public static int simpleArraySum(List<Integer> ar) {
        int result = 0;
        for (int i : ar) {
            result += i;
        }
        return result;
    }

}
