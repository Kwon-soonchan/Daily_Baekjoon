import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] arr = new int[x+1][y+1];

        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int xll = Integer.parseInt(st.nextToken());
            int yll = Integer.parseInt(st.nextToken());
            int xur = Integer.parseInt(st.nextToken());
            int yur = Integer.parseInt(st.nextToken());

            for (int j = xll-1; j < xur; j++) {
                for (int k = yll-1; k < yur; k++) {
                    arr[j][k] = 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (arr[i][j] == 1) {
                    cnt++;
                }
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}
