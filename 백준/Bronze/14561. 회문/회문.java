import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long l = Long.parseLong(st.nextToken());
            int n = Integer.parseInt(st.nextToken());

            StringBuilder sb = new StringBuilder();

            long temp = l;

            while (temp > 0) {
                long remainder = temp % n;

                if (remainder >= 10) {
                    sb.append((char) ('A' + (remainder - 10)));
                } else {
                    sb.append(remainder);
                }
                temp /= n;
            }

            String convert = sb.toString();
            boolean check = true;
            int len = convert.length();

            for (int i = 0; i < len / 2; i++) {
                if (convert.charAt(i) != convert.charAt(len - 1 - i)) {
                    check = false;
                    break;
                }
            }
            if (check) {
                bw.write(1 + "\n");
            } else {
                bw.write(0 + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
