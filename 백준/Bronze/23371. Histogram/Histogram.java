import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            int a = Integer.parseInt(st.nextToken());
            arr[(a - 1) / s]++;
        }
        int maxH = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxH) {
                maxH = arr[i];
            }
        }

        for (int i = maxH; i >= 1; i--) {
            for (int j = 0; j < n; j++) {
                if (arr[j] >= i) {
                    bw.write("#");
                } else {
                    bw.write(".");
                }
            }
            maxH--;
            bw.write("\n");
        }
        for (int i = 0; i < n; i++) {
            bw.write("-");
        }
        bw.flush();
        bw.close();
    }
}
