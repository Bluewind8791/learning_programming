package Implementation;

public class DayOfTheProgrammer {
    /*
    1700년에서 2700년 사이의 1년 중 프로그래머 의 날(256번째 날)에 러시아를 방문하기 위해 시간 여행을 하여 테스트하려고 합니다.

    그레고리력에서 윤년은 다음 중 하나입니다
    * 400으로 나눌 수 있습니다.
    * 4의 배수이고 100의 배수가 아닙니다.

    y = year
    해당 연도의 공식 러시아 달력에 따라 해당 연도의 256일 날짜를 찾으십시오.
    그리고 dd.mm.yyyy 포맷으로 출력합니다.
    */
    public static String dayOfProgrammer(int year) {
        if (year == 1918) return "26.09.1918";
        
        if (isLeapYear(year)) {
            return "12.09." + year; // if leaf year
        } else {
            return "13.09." + year; // if not leaf year
        }
    }

    private static boolean isLeapYear(int year) {
        if (year % 4 != 0) return false;
        if (year > 1918 && year % 100 == 0 && year % 400 != 0) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int year = Integer.parseInt("2016".trim());
        String result = dayOfProgrammer(year);
        System.out.println(result);
    }

}
