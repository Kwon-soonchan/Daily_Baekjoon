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

        int s1 = Integer.parseInt(st.nextToken());
        int s2 = Integer.parseInt(st.nextToken());
        int s3 = Integer.parseInt(st.nextToken());
        int[] sum_list = new int[81];
        
        for(int i=0;i<=80;i++) {
            sum_list[i] = 0;
        }

        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                for (int k = 1; k <= s3; k++) {
                    sum_list[i + j + k]++;
                }
            }
        }

        int max_sum = 0;
        for (int i = 3; i <= 80; i++) {
            if (max_sum < sum_list[i]) {
                max_sum = sum_list[i];
            }
        }
        for (int i = 3; i <= 80; i++) {
            if (max_sum == sum_list[i]) {
                bw.write(String.valueOf(i));
                bw.flush();
                bw.close();
                break;
            }
        }
    }
}
