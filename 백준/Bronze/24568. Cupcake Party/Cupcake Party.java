import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int regular = Integer.parseInt(br.readLine());
        int small = Integer.parseInt(br.readLine());

        int result = 28 - (regular * 8) - (small * 3);

        if (result >= 0) {
            bw.write(0 + "");
        } else {
            bw.write(Math.abs(result) + "");
        }

        bw.flush();
        bw.close();
    }
}
