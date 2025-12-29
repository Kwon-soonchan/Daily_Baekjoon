import static java.lang.Character.isDigit;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        long x = 0;
        long y = 0;

        for (int i = 0; i < s.length(); i++) {
            String num = "";
            if (s.charAt(i) == 'n') {
                while (true) {
                    if (i + 1 < s.length() && isDigit(s.charAt(i + 1))) {
                        num += s.charAt(i + 1);
                        i++;
                    } else {
                        break;
                    }
                }
                y += Integer.parseInt(num);
            } else if (s.charAt(i) == 's') {
                while (true) {
                    if (i + 1 < s.length() && isDigit(s.charAt(i + 1))) {
                        num += s.charAt(i + 1);
                        i++;
                    } else {
                        break;
                    }
                }
                y -= Integer.parseInt(num);
            } else if (s.charAt(i) == 'e') {
                while (true) {
                    if (i + 1 < s.length() && isDigit(s.charAt(i + 1))) {
                        num += s.charAt(i + 1);
                        i++;
                    } else {
                        break;
                    }
                }
                x += Integer.parseInt(num);
            } else if (s.charAt(i) == 'w') {
                while (true) {
                    if (i + 1 < s.length() && isDigit(s.charAt(i + 1))) {
                        num += s.charAt(i + 1);
                        i++;
                    } else {
                        break;
                    }
                }
                x -= Integer.parseInt(num);
            }
        }

        double result = Math.sqrt(x * x + y * y);
        bw.write(String.format("%.2f", result));
        bw.flush();
        bw.close();
    }
}
