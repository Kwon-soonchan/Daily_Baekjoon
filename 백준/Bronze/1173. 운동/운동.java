import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int time = 0;
        int pulse = m;

        if(M-m < T) {
            bw.write(String.valueOf(-1));
            bw.flush();
            bw.close();
            System.exit(0);
        }
        
        while(n != 0) {
            if(pulse <= M-T) {
                n--;
                pulse += T;
                time++;
            }
            else {
                if(pulse - R < m) {
                    pulse = m;
                }
                else {
                    pulse -= R;
                }
                time++;
            }
        }

        bw.write(String.valueOf(time));
        bw.flush();
        bw.close();
    }
}
