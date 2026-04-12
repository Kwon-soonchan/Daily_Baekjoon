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

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[] rowSums = new int[n];
            int[] colSums = new int[n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    int value = Integer.parseInt(st.nextToken());
                    rowSums[i] += value;
                    colSums[j] += value;
                }
            }

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int r1 = Integer.parseInt(st.nextToken()) - 1;
                int c1 = Integer.parseInt(st.nextToken()) - 1;
                int r2 = Integer.parseInt(st.nextToken()) - 1;
                int c2 = Integer.parseInt(st.nextToken()) - 1;
                int v = Integer.parseInt(st.nextToken());

                int rowCnt = r2 - r1 + 1;
                int colCnt = c2 - c1 + 1;

                for (int r = r1; r <= r2; r++) {
                    rowSums[r] += v * colCnt;
                }
                for (int c = c1; c <= c2; c++) {
                    colSums[c] += v * rowCnt;
                }
            }

            for (int i = 0; i < n; i++) {
                bw.write(rowSums[i] + " ");
            }
            bw.write("\n");
            for (int i = 0; i < n; i++) {
                bw.write(colSums[i] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
