import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String monthStr = st.nextToken();
        String dayStr = st.nextToken(); // "DD," 형태
        int year = Integer.parseInt(st.nextToken());
        String timeStr = st.nextToken(); // "HH:MM" 형태

        boolean isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

        int totalMinutesInYear = isLeap ? (366 * 24 * 60) : (365 * 24 * 60);

        int[] daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap) {
            daysInMonth[2] = 29; // 윤년이면 2월은 29일
        }

        int month = getMonthIndex(monthStr);
        int day = Integer.parseInt(dayStr.substring(0, 2)); // "DD" 부분만 추출
        String[] times = timeStr.split(":");
        int hour = Integer.parseInt(times[0]);
        int minute = Integer.parseInt(times[1]);

        double currentTotalMinutes = 0;

        for (int i = 1; i < month; i++) { // 1월부터 (현재월 - 1)월까지
            currentTotalMinutes += daysInMonth[i] * 24 * 60; // 일 -> 분
        }

        currentTotalMinutes += (day - 1) * 24 * 60; // (day - 1)일 * 24 * 60
        currentTotalMinutes += hour * 60;
        currentTotalMinutes += minute;

        double result = (currentTotalMinutes / totalMinutesInYear) * 100.0;

        bw.write(result + "");
        bw.flush();
        bw.close();
    }

    private static int getMonthIndex(String month) {
        switch (month) {
            case "January": return 1;
            case "February": return 2;
            case "March": return 3;
            case "April": return 4;
            case "May": return 5;
            case "June": return 6;
            case "July": return 7;
            case "August": return 8;
            case "September": return 9;
            case "October": return 10;
            case "November": return 11;
            case "December": return 12;
            default: return -1; // 오류
        }
    }
}