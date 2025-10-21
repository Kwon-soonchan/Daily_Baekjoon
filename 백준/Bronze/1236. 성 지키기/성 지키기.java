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

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] castle_x = new int[n];
        int[] castle_y = new int[m];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == 'X') {
                    castle_x[i] = 1;
                    castle_y[j] = 1;
                }
            }
        }

        int cnt_x = 0;
        int cnt_y = 0;

        for (int i = 0; i < n; i++) {
            if (castle_x[i] == 0) {
                cnt_x++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (castle_y[i] == 0) {
                cnt_y++;
            }
        }

        if (cnt_x == 0 && cnt_y == 0) {
            bw.write(String.valueOf(0));
        } else if (cnt_x > cnt_y) {
            bw.write(String.valueOf(cnt_x));
        } else if (cnt_x < cnt_y) {
            bw.write(String.valueOf(cnt_y));
        } else {
            bw.write(String.valueOf(cnt_x));
        }

        bw.flush();
        bw.close();
    }
}
