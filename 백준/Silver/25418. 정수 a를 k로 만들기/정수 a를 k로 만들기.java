import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] dp = new int[1000001];

        Queue<Integer> q = new LinkedList<>();
        q.add(a);
        dp[a] = 1;

        while (!q.isEmpty()) {
            int now = q.poll();

            if (now == k) {
                bw.write(dp[now] - 1 + "");
                bw.flush();
                bw.close();
                return;
            }

            if (now + 1 <= 1000000 && dp[now + 1] == 0) {
                dp[now + 1] = dp[now] + 1;
                q.add(now + 1);
            }

            if (now * 2 <= 1000000 && dp[now * 2] == 0) {
                dp[now * 2] = dp[now] + 1;
                q.add(now * 2);
            }
        }
    }
}
