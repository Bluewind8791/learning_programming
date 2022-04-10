package Implementation;

import java.util.ArrayList;
import java.util.List;

/**
HackerLand University에는 다음과 같은 채점 정책이 있습니다.
 * 모든 학생은 0~100 까지의 grade 를 받습니다.
 * 40 이하 grade 는 낙제등급입니다.
대학교수 Sam은 다음 규칙에 따라 각 학생의 grade를 반올림하는 것을 좋아합니다.
- 등급과 다음 5의 배수의 차이가 3보다 작으면 다음 5의 배수로 반올림합니다.
- 등급 값이 38보다 작으면 결과가 여전히 낙제 등급이 되므로 반올림이 발생하지 않습니다.
ex) 84점 (85-84 < 3) -> 85점
29점 (40점 이하 반올림 안함)
57점 (60-57 >= 3) 반올림 안함
 */
public class GradingStudents {
    
    public static List<Integer> gradingStudents(List<Integer> grades) {
        List<Integer> newGrades = new ArrayList<>();
        for (Integer grade : grades) {
            if (grade < 38) {
                newGrades.add(grade);
            } else {
                int fiveMultiple = (grade - (grade % 5)) + 5;
                if (fiveMultiple - grade < 3) {
                    newGrades.add(fiveMultiple);
                } else {
                    newGrades.add(grade);
                }
            }
        }
        return newGrades;
    }


    public static void main(String[] args) {

        List<Integer> grades = List.of(73, 67, 38, 33);
        System.out.println(gradingStudents(grades));
    }

}
