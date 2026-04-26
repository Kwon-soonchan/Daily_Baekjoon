import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[m];

        if (m > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }

        int maxValue = 1;
        for (int i = 0; i < n; i++) {
            maxValue *= 10;
        }

        int result = 0;
        boolean[] check = new boolean[10];

        for (int i = 0; i < maxValue; i++) {
            for (int j = 0; j < 10; j++) {
                check[j] = false;
            }

            int temp = i;

            for (int j = 0; j < n; j++) {
                int digit = temp % 10;
                check[digit] = true;
                temp /= 10;
            }

            boolean flag = true;
            for (int j = 0; j < m; j++) {
                if (!check[arr[j]]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                result++;
            }
        }

        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }
}
