import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int j = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            int cnt = 0;
            for (int k = 0; k < s.length(); k++) {
                if (s.charAt(k) >= 'A' && s.charAt(k) <= 'Z') {
                    cnt += 4;
                } else if (s.charAt(k) >= 'a' && s.charAt(k) <= 'z') {
                    cnt += 2;
                } else if (s.charAt(k) >= '0' && s.charAt(k) <= '9') {
                    cnt += 2;
                } else if (s.charAt(k) == ' ') {
                    cnt += 1;
                }
            }
            arr[i] = cnt;
        }
        
        for (int i = 0; i < n; i++) {
            if (arr[i] <= j) {
                result++;
            }
        }
        
        bw.write(result + "");
        bw.flush();
        bw.close();
    }
}
