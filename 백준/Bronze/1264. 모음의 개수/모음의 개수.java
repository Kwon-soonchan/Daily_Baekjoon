import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true) {
            String s = br.readLine();
            int cnt = 0;

            if(s.equals("#")) {
                break;
            }

            for(int i=0;i<s.length();i++) {
                if(s.charAt(i) == 'a' || s.charAt(i) == 'i' || s.charAt(i) == 'u' || s.charAt(i) == 'e' || s.charAt(i) == 'o'
                || s.charAt(i) == 'A' || s.charAt(i) == 'I' || s.charAt(i) == 'U' || s.charAt(i) == 'E' || s.charAt(i) == 'O') {
                    cnt++;
                }
            }

            bw.write(cnt+"\n");
            bw.flush();
        }
        bw.close();
    }
}
