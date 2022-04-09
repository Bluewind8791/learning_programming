package Warmup;


/**
 * 12시간 AM/PM 형식의 시간이 주어지면 24시간제 시간으로 변환합니다.
 * 참고:
 * - 12시간제 기준 12:00:00 AM은 24시간제 기준 00:00:00입니다.
 * - 12시간제 기준 12:00:00 PM은 24시간제 기준 12:00:00입니다.
 */
public class TimeConversion {

    public static String solution(String s) {
        String[] timeList = s.split(":");
        int intHour = 0;
        intHour = Integer.parseUnsignedInt(timeList[0]);
        String hour = "";
        String minute = timeList[1];
        String second = timeList[2].replace("AM", "").replace("PM", "");
        // am 의 경우
        if (s.contains("AM")) {
            // 12시간제 기준 12:00:00 AM은 24시간제 기준 00:00:00입니다.
            if (intHour == 12) {
                hour = "00";
            } else {
                if (intHour < 10) {
                    hour = "0" + String.valueOf(intHour);
                } else {
                    hour = String.valueOf(intHour);
                }
            }
        } else if (s.contains("PM")) {
            // 12시간제 기준 12:00:00 PM은 24시간제 기준 12:00:00입니다.
            if (intHour == 12) {
                hour = "12";
            } else {
                intHour += 12;
                if (intHour >= 24) {
                    intHour -= 24;
                }
                if (intHour < 10) {
                    hour = "0" + String.valueOf(intHour);
                } else {
                    hour = String.valueOf(intHour);
                }
            }
        }
        return hour + ":" + minute + ":" + second;
    }


    public static void main(String[] args) {
        String s = "12:00:00PM";
        System.out.println(solution(s));
    }

}