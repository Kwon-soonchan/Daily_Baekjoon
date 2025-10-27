import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();

        int oneCnt = 0;
        int zeroCnt = 0;

        for(int i=0;i<s.length()-1;i++) {
            if(s.charAt(i) == '0') {
                if(s.charAt(i+1) == '0') {
                    continue;
                }
                else {
                    zeroCnt++;
                }
            }
            else if(s.charAt(i) == '1') {
                if(s.charAt(i+1) == '1') {
                    continue;
                }
                else {
                    oneCnt++;
                }
            }
        }
        // 마지막 구간도 체크해주기
        if(s.charAt(s.length()-1) == '0') {
            zeroCnt++;
        }
        else {
            oneCnt++;
        }

        if(zeroCnt > oneCnt) {
            bw.write(oneCnt+"");
        }
        else {
            bw.write(zeroCnt+"");
        }
        bw.flush();
        bw.close();
    }
}
