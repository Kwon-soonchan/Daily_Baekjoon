import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String prev = br.readLine();
            if (prev.equals("#")) {
                break;
            }
            boolean check = true;

            while (true) {
                String cur = br.readLine();
                int wrongCnt = 0;

                if (cur.equals("#")) {
                    break;
                }

                if (cur.length() != prev.length()) {
                    check = false;
                } else {
                    for (int i = 0; i < cur.length(); i++) {
                        if (cur.charAt(i) != prev.charAt(i)) {
                            wrongCnt++;
                        }
                    }
                    if (wrongCnt != 1) {
                        check = false;
                    }
                }
                prev = cur;
            }

            if (check) {
                bw.write("Correct\n");
            } else {
                bw.write("Incorrect\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
