import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                int num = (i * n) + j;
                int cnt = 0;
                for (int k = 1; k <= num; k++) {
                    if (num % k == 0) {
                        cnt++;
                    }
                    if (cnt > m) {
                        bw.write(".");
                        break;
                    }
                }
                if (cnt <= m) {
                    bw.write("*");
                }
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
