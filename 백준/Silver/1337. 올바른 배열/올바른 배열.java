import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] numList = new int[n];

        for (int i = 0; i < n; i++) {
            numList[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(numList);

        int maxCnt = 0;
        for (int i = 0; i < n; i++) {
            int curCnt = 0;
            for (int j = i; j < n; j++) {
                if (numList[j] < numList[i] + 5) {
                    curCnt++;
                } else {
                    break;
                }
            }
            maxCnt = Math.max(maxCnt, curCnt);
        }

        bw.write((5 - maxCnt) + "");
        bw.flush();
        bw.close();
    }
}