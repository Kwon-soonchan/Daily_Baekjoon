import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] tasks = new int[n];
        int[] quiets = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            tasks[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            quiets[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(tasks);
        Arrays.sort(quiets);

        int taskIdx = 0;
        int quietIdx = 0;
        int cnt = 0;

        while (taskIdx < n && quietIdx < m) {
            if (tasks[taskIdx] <= quiets[quietIdx]) {
                cnt++;
                taskIdx++;
                quietIdx++;
            } else {
                quietIdx++;
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}
