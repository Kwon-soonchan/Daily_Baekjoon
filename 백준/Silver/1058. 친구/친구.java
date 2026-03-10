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
        char[][] arr = new char[n][n];

        int max_cnt = 0;

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            int Y_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                if (arr[i][j] == 'Y') {
                    Y_cnt++;
                } else {
                    for (int k = 0; k < n; k++) {
                        if (arr[i][k] == 'Y' && arr[k][j] == 'Y') {
                            Y_cnt++;
                            break;
                        }
                    }
                }
            }

            max_cnt = Math.max(max_cnt, Y_cnt);
        }
        bw.write(max_cnt + "");
        bw.flush();
        bw.close();
    }
}
