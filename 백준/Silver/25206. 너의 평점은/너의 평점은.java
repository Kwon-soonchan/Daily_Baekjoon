import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        double sum_my_grade = 0;
        double sum_major_grade = 0;

        for (int i = 0; i < 20; i++) {
            String course = br.readLine();
            String[] course_split = new String[3];
            course_split = course.split(" ");

            double my_grade = Double.parseDouble(course_split[1]);
            double major_grade = 0;

            // '=='가 아니라 equals를 사용해야 인식이 되더라..
            if (course_split[2].equals("A+")) {
                major_grade = 4.5;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("A0")) {
                major_grade = 4.0;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("B+")) {
                major_grade = 3.5;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("B0")) {
                major_grade = 3.0;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("C+")) {
                major_grade = 2.5;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("C0")) {
                major_grade = 2.0;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("D+")) {
                major_grade = 1.5;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("D0")) {
                major_grade = 1.0;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("F")) {
                major_grade = 0.0;
                sum_my_grade += my_grade;
                sum_major_grade += my_grade * major_grade;
            } else if (course_split[2].equals("P")) {
                continue;
            }
        }

        double result = sum_major_grade / sum_my_grade;
        String resultS = String.format("%.6f", result);
        // BufferedReader는 Double 타입의 직접 쓰기를 지원하지 않는다.
        bw.write(resultS);
        bw.flush();
        bw.close();
    }
}
