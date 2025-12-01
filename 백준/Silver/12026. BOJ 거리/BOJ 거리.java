import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String word = br.readLine();
        List<Character> BOJ = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            BOJ.add(word.charAt(i));
        }

        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == Integer.MAX_VALUE) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (BOJ.get(i) == 'B' && BOJ.get(j) == 'O') {
                    dp[j] = Math.min(dp[j], dp[i] + (j - i) * (j - i));
                } else if (BOJ.get(i) == 'O' && BOJ.get(j) == 'J') {
                    dp[j] = Math.min(dp[j], dp[i] + (j - i) * (j - i));
                } else if (BOJ.get(i) == 'J' && BOJ.get(j) == 'B') {
                    dp[j] = Math.min(dp[j], dp[i] + (j - i) * (j - i));
                }
            }
        }
        
        if (dp[n - 1] == Integer.MAX_VALUE) {
            bw.write(-1 + "");
        } else {
            bw.write(dp[n - 1] + "");
        }
        bw.flush();
        bw.close();
    }
}
