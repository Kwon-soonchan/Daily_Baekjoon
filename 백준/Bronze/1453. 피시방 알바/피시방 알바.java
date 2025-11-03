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
        
        int[] sit = new int[101];
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i=0;i<n;i++) {
            int want = Integer.parseInt(st.nextToken());
            if(sit[want] == 0) {
                sit[want] = 1;
            }
            else {
                cnt++;
            }
        }
        
        bw.write(cnt+"");
        bw.flush();
        bw.close();
    }
}
