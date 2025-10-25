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
        int l = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int totalTime = 0;
        int bellTime = 0;

        for (int i = 0; i < n; i++) {
            totalTime += l;

            while (bellTime < totalTime) {
                bellTime += d;
            }

            if (bellTime < totalTime + 5) {
                bw.write(bellTime + "");
                bw.flush();
                bw.close();
                return;
            }

            totalTime += 5;
        }

        while (bellTime < totalTime) {
            bellTime += d;
        }

        bw.write(bellTime + "");
        bw.flush();
        bw.close();
    }
}