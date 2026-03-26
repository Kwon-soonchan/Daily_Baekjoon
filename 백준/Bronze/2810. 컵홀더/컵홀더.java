import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String seat = br.readLine();
        int total = seat.length();
        int L_cnt = 0;

        for (int i = 0; i < n; i++) {
            if (seat.charAt(i) == 'L') {
                L_cnt++;
            }
        }
        L_cnt /= 2;

        if (L_cnt == 0) {
            bw.write(total + "");
        } else {
            bw.write((total - (L_cnt - 1)) + "");
        }
        bw.flush();
        bw.close();
    }
}
