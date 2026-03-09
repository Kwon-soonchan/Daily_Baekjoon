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

        long n = Long.parseLong(st.nextToken());
        long l = Long.parseLong(st.nextToken());
        boolean check = false;

        // n = (x * l) + (l(l-1))/2
        for(long i = l;i<=100;i++) {
            long sum = (i*(i-1))/2;
            
            // 음수 X, 정수 O
            if(n-sum >= 0 && (n-sum) % i == 0) {
                long x = (n-sum)/i;
                
                for(long j = 0;j<i;j++) {
                    bw.write((x+j) + " ");
                }
                
                check = true;
                break;
            }
        }
        
        if(!check) {
            bw.write(-1+"");
        }
        
        bw.flush();
        bw.close();
    }
}
