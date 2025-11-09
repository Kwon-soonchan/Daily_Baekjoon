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
        int[][] board = new int[n][m];

        for (int i = 0; i < n; i++) {
            String numList = br.readLine();
            for (int j = 0; j < m; j++) {
                board[i][j] = numList.charAt(j) - '0';
            }
        }

        int minNum = Math.min(n, m);
        while (minNum > 0) {
            for (int i = 0; i <= n - minNum; i++) {
                for (int j = 0; j <= m - minNum; j++) {
                    if (board[i][j] == board[i][j + minNum - 1] &&
                            board[i][j] == board[i + minNum - 1][j] &&
                            board[i][j] == board[i + minNum - 1][j + minNum - 1]) {
                        bw.write((int)Math.pow(minNum, 2) + "");
                        bw.flush();
                        bw.close();
                        System.exit(0);
                    }
                }
            }
            minNum--;
        }
    }
}
