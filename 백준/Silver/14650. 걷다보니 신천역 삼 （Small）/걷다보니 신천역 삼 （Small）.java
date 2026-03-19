import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static int n;
    static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        dfs(1, 1);
        dfs(1, 2);

        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }

    static void dfs(int depth, int sum) {
        if (depth == n) {
            if (sum % 3 == 0) {
                result++;
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            dfs(depth + 1, sum + i);
        }
    }
}
