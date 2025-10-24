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

        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        int cnt = 1;
        int result = 0;

        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= i; j++) {
                if (cnt >= start && cnt <= end) {
                    result += i;
                }
                
                if(cnt > end) {
                    break;
                }

                cnt++;
            }
            
            if(cnt > end) {
                 break;
            }
        }

        bw.write(result + "");
        bw.flush();
        bw.close();
    }
}
