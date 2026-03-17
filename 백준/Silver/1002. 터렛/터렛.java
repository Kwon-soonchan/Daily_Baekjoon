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
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int r1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());
            int distance = (int) (Math.pow(Math.abs(x2 - x1), 2) + Math.pow(Math.abs(y2 - y1), 2));
            int sum = (int) Math.pow(r1 + r2, 2);
            int diff = (int) Math.pow(r1 - r2, 2);

            if (x1 == x2 && y1 == y2 && r1 == r2) {
                bw.write(-1 + "\n");
            } else if (distance > sum || distance < diff || distance == 0) {
                bw.write(0 + "\n");
            } else if (distance == diff || distance == sum) {
                bw.write(1 + "\n");
            } else {
                bw.write(2 + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
