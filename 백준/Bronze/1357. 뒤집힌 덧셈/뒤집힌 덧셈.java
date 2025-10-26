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

        String a = st.nextToken();
        String b = st.nextToken();

        StringBuffer sb = new StringBuffer(a);
        int reverseA = Integer.parseInt(sb.reverse().toString());
        sb = new StringBuffer(b);
        int reverseB = Integer.parseInt(sb.reverse().toString());

        String c = (reverseA + reverseB)+"";

        sb = new StringBuffer(c);
        int reverseC = Integer.parseInt(sb.reverse().toString());

        bw.write(reverseC+"");
        bw.flush();
        bw.close();
    }
}
