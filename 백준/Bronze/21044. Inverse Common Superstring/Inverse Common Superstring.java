import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String r = br.readLine();
        int cnt = 0;
        int maxLength = 0;

        for (int i = 0; i < r.length(); i++) {
            if (r.charAt(i) == 'a') {
                cnt++;
                maxLength = Math.max(maxLength, cnt);
            } else {
                cnt = 0;
            }
        }

        String s = "";
        for (int i = 0; i < maxLength + 1; i++) {
            s += 'a';
        }

        bw.write(s);
        bw.flush();
        bw.close();
    }
}
