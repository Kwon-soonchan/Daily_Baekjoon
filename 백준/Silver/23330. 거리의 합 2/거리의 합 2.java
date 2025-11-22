import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        long[] numArray = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            numArray[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(numArray);

        long result = 0;
        long prefix = 0;

        for (int i = 0; i < n; i++) {
            result += (numArray[i] * i) - prefix;
            prefix += numArray[i];
        }

        bw.write((result * 2) + "");
        bw.flush();
        bw.close();
    }
}
