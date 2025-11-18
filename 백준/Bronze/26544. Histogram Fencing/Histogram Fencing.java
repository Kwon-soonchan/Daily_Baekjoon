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

        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());
            int result = 0;

            StringTokenizer w = new StringTokenizer(br.readLine());
            int[] widths = new int[x];
            for (int j = 0; j < x; j++) {
                widths[j] = Integer.parseInt(w.nextToken());
                result += widths[j] * 2;
            }

            StringTokenizer h = new StringTokenizer(br.readLine());
            int[] heights = new int[x];
            for (int j = 0; j < x; j++) {
                heights[j] = Integer.parseInt(h.nextToken());
            }

            result += heights[0];
            result += heights[x - 1];

            for (int j = 1; j < x; j++) {
                result += Math.abs(heights[j] - heights[j - 1]);
            }

            bw.write(result + "\n");
        }
        bw.flush();
        bw.close();
    }
}
