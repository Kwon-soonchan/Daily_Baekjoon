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

        long x = Integer.parseInt(st.nextToken());
        long y = Integer.parseInt(st.nextToken());
        long z = (y * 100) / x;

        if (z == 99 || z == 100) {
            bw.write(-1 + "");
        } 
        else {
            long left = 1;
            long right = 2000000000;
            long ans = -1;

            while (left <= right) {
                long mid = (left + right) / 2;
                long new_z = ((y + mid) * 100) / (x + mid);
                
                if (new_z > z) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            bw.write(ans + "");
        }

        bw.flush();
        bw.close();
    }
}
