import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] numList = new int[n];
        for (int i = 0; i < n; i++) {
            numList[i] = Integer.parseInt(st.nextToken());
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt++;

            int lastDir = 0;
            for (int j = i + 1; j < n; j++) {
                long diff = numList[j] - numList[j - 1];

                if (diff == 0) {
                    break;
                }

                int curDir = (diff > 0) ? 1 : -1;

                if (lastDir == 0) {
                    lastDir = curDir;
                    cnt++;
                } else if (lastDir != curDir) {
                    lastDir = curDir;
                    cnt++;
                } else {
                    break;
                }
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}
