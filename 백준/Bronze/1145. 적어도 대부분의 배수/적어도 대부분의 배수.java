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
        
        int[] numberList = new int[5];
        
        for(int i=0;i<5;i++) {
            numberList[i] = Integer.parseInt(st.nextToken());
        }
        
        int result = 1;
        while(true) {
            int count = 0;
            
            for(int i=0;i<5;i++) {
                if(result % numberList[i] == 0) {
                    count++;
                }
            }
            
            if(count >= 3) {
                bw.write(result+"");
                bw.flush();
                bw.close();
                break;
            }
            
            result++;
        }
    }
}
