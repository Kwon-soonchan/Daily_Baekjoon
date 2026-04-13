import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] clauses = new int[m][2];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            clauses[i][0] = Integer.parseInt(st.nextToken());
            clauses[i][1] = Integer.parseInt(st.nextToken());
        }

        boolean check = false;

        for (int i = 0; i < (1 << n); i++) {
            boolean flag = true;

            for (int j = 0; j < m; j++) {
                int a = clauses[j][0];
                int b = clauses[j][1];

                boolean valA = checkTrue(i, a);
                boolean valB = checkTrue(i, b);

                if (!valA && !valB) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                check = true;
                break;
            }
        }

        bw.write(check ? "1\n" : "0\n");
        bw.flush();
        bw.close();
    }

    static boolean checkTrue(int state, int x) {
        if (x < 0) {
            int target = -x - 1;
            return (state & (1 << target)) == 0;
        } else {
            int target = x - 1;
            return (state & (1 << target)) != 0;
        }
    }
}
