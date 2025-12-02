import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
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
        int prev = 0;
        int cur = 0;
        int[] checkList = new int[n];

        for (int i = 0; i < n; i++) {
            int size = 0;
            prev = numList[i];
            cnt++;
            if (i != n - 1) {
                for (int j = i + 1; j < n; j++) {
                    cur = numList[j];
                    // increase
                    if ((cur - prev) > 0) {
                        checkList[size] = 1;
                        size++;
                    }
                    // decrease
                    else if ((cur - prev) < 0) {
                        checkList[size] = 0;
                        size++;
                    }
                    // same
                    else {
                        break;
                    }

                    if (size == 1) {
                        cnt++;
                    } else if (checkList[size - 1] != checkList[size - 2]) {
                        cnt++;
                    } else {
                        break;
                    }

                    prev = cur;
                }
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}