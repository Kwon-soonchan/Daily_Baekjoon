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

        while (true) {
            String s = br.readLine();

            if (s.equals("0")) {
                break;
            }

            int result = 2;
            int size = s.length();
            result += size - 1;
            for (int i = 0; i < size; i++) {
                if (s.charAt(i) == '0') {
                    result += 4;
                } else if (s.charAt(i) == '1') {
                    result += 2;
                } else {
                    result += 3;
                }
            }

            bw.write(result + "\n");
        }

        bw.flush();
        bw.close();
    }
}
