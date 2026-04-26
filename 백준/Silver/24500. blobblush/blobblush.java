import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long n = Long.parseLong(br.readLine());
        long temp = n;
        long length = 0;

        while (temp > 0) {
            temp = temp >> 1;
            length++;
        }

        long maxN = (1L << length) - 1;

        if (n == maxN) {
            bw.write("1\n");
            bw.write(n + "");
        } else {
            bw.write("2\n");
            bw.write((maxN - n) + "\n");
            bw.write(n + "");
        }
        bw.flush();
        bw.close();
    }
}
