import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static final int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        for (int t = 1; t <= N; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            long X = Integer.parseInt(st.nextToken());
            long Y = Integer.parseInt(st.nextToken());
            long Z = Integer.parseInt(st.nextToken());

            long[] A = new long[m];
            for (int i = 0; i < m; i++) {
                A[i] = Integer.parseInt(br.readLine());
            }

            long[] S = new long[n];
            for (int i = 0; i < n; i++) {
                S[i] = A[i % m];
                long nextValue = (X * A[i % m] + Y * (i + 1)) % Z;
                A[i % m] = nextValue;
            }

            long[] dp = new long[n];
            long totalResult = 0;

            for (int i = 0; i < n; i++) {
                dp[i] = 1;

                for (int j = 0; j < i; j++) {
                    if (S[j] < S[i]) {
                        dp[i] = (dp[i] + dp[j]) % MOD;
                    }
                }

                totalResult = (totalResult + dp[i]) % MOD;
            }
            bw.write("Case #" + t + ": " + totalResult + "\n");
        }
        bw.flush();
        bw.close();
    }
}
