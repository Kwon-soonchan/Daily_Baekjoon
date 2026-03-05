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

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[n + 1];
        int[] dp = new int[n + 1];

        for (int i = 0; i < n; i++) {
            String s = st.nextToken();
            arr[i] = Integer.parseInt(s);
        }

        for (int i = n-1; i >= 0; i--) {
            int jump = arr[i];
            if (i + jump + 1 > n) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i + jump + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            bw.write(dp[i] + " ");
        }
        bw.flush();
        bw.close();
    }
}
