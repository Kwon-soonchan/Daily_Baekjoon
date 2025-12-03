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
        String[] nameList = new String[n];

        for (int i = 0; i < n; i++) {
            nameList[i] = br.readLine();
        }

        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                String s1 = nameList[i];
                String s2 = nameList[j];
                int len1 = s1.length();
                int len2 = s2.length();

                int maxLen = Math.min(len1, len2);
                boolean connected = false;

                for (int k = 1; k <= maxLen; k++) {
                    if (s1.substring(len1 - k).equals(s2.substring(0, k))) {
                        connected = true;
                        break;
                    }

                    if (s2.substring(len2 - k).equals(s1.substring(0, k))) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    cnt++;
                }
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}
