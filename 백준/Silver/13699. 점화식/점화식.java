import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long[] arr = new long[36];

        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 5;

        for (int i = 4; i <= 35; i++) {
            for (int j = 0; j < i; j++) {
                arr[i] += arr[j] * arr[i - 1 - j];
            }
        }

        int n = Integer.parseInt(br.readLine());

        bw.write(arr[n] + "");
        bw.flush();
        bw.close();
    }
}
