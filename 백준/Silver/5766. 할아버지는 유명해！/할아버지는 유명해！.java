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
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0) {
                break;
            }

            int[] num = new int[10001];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    num[Integer.parseInt(st.nextToken())]++;
                }
            }

            int maxScore = 0;
            for (int i = 0; i <= 10000; i++) {
                maxScore = Math.max(maxScore, num[i]);
            }

            int secondScore = 0;
            for (int i = 0; i <= 10000; i++) {
                if (num[i] != maxScore) {
                    secondScore = Math.max(secondScore, num[i]);
                }
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= 10000; i++) {
                if (num[i] == secondScore) {
                    sb.append(i).append(" ");
                }
            }

            bw.write(sb.toString() + "\n");
        }

        bw.flush();
        bw.close();
    }
}
