import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int a1 = Integer.parseInt(br.readLine());
        int a2 = Integer.parseInt(br.readLine());
        int a3 = Integer.parseInt(br.readLine());
        int b1 = Integer.parseInt(br.readLine());
        int b2 = Integer.parseInt(br.readLine());
        int b3 = Integer.parseInt(br.readLine());

        int sum_a = a1*3 + a2*2 + a3*1;
        int sum_b = b1*3 + b2*2 + b3*1;

        if (sum_a > sum_b) {
            bw.write("A");
        } else if (sum_a < sum_b) {
            bw.write("B");
        } else {
            bw.write("T");
        }

        bw.flush();
        bw.close();
    }
}
