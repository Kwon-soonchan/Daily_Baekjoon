import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int k = Integer.parseInt(br.readLine());

        for (int i = 1; i <= k; i++) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            int cnt = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);

            for (int j = 0; j < n; j++) {
                if (arr[j] <= cnt) {
                    cnt++;
                } else {
                    break;
                }
            }
            bw.write("Data Set " + i + ":\n" + cnt + "\n\n");
        }
        bw.flush();
        bw.close();
    }
}
