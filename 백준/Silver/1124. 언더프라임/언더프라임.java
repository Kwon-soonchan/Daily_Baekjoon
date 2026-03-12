import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int realPrime = 0;

    public static void underPrime(int n) {
        int primeCnt = 0;

        for (int i = 2; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                primeCnt++;
                n /= i;
            }
        }

        if (n != 1) {
            primeCnt++;
        }

        boolean check = true;

        for (int i = 2; i <= Math.sqrt(primeCnt); i++) {
            if (primeCnt % i == 0) {
                check = false;
            }
        }

        if (check && primeCnt > 1) {
            realPrime++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        for (int i = a; i <= b; i++) {
            underPrime(i);
        }

        bw.write(realPrime + "");
        bw.flush();
        bw.close();
    }
}
