import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] A;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());

            A = new int[q + 2];
            A[0] = 0;
            A[q + 1] = p + 1;

            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= q; j++) {
                A[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(A);

            dp = new int[A.length][A.length];
            for (int j = 0; j < A.length; j++) {
                Arrays.fill(dp[j], -1);
            }

            int ans = solve(0, q + 1);

            bw.write("Case #" + (i + 1) + ": " + ans + "\n");
        }
        bw.flush();
        bw.close();
    }

    static int solve(int left, int right) {
        if (left + 1 == right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int minCost = Integer.MAX_VALUE;

        for (int mid = left + 1; mid < right; mid++) {
            int curCost = A[right] - A[left] - 2;

            int totalCost = curCost + solve(left, mid) + solve(mid, right);

            minCost = Math.min(minCost, totalCost);
        }
        return dp[left][right] = minCost;
    }
}
