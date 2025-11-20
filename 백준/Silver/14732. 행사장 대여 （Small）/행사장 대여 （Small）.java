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
        int[][] board = new int[500][500];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            for (int j = x1; j < x2; j++) {
                for (int k = y1; k < y2; k++) {
                    if (board[j][k] == 0) {
                        board[j][k] = 1;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                if (board[i][j] == 1) {
                    cnt++;
                }
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}
