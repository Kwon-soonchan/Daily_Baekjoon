import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int[] alphabet = new int[26];

        for (int i = 0; i < s.length(); i++) {
            if (n % 2 != 0 && i == n / 2) {
                continue;
            }
            alphabet[s.charAt(i) - 97]++;
        }

        boolean check = true;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 != 0) {
                check = false;
                break;
            }
        }

        if (check) {
            bw.write("Yes");
        } else {
            bw.write("No");
        }

        bw.flush();
        bw.close();
    }
}
