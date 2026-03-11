import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Problem {
    String s;
    int i;
    int d;

    Problem(String s, int i, int d) {
        this.s = s;
        this.i = i;
        this.d = d;
    }

    public int getI() {
        return i;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Problem[] prob = new Problem[n];

        for (int a = 0; a < n; a++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int i = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            prob[a] = new Problem(s, i, d);
        }

        Arrays.sort(prob, new Comparator<Problem>() {
            @Override
            public int compare(Problem p1, Problem p2) {
                return Integer.compare(p1.i, p2.i);
            }
        });

        String result = "";
        for (int a = 0; a < n; a++) {
            int num = prob[a].d;
            String word = prob[a].s;

            result += word.charAt(num - 1);
        }

        bw.write(result.toUpperCase());
        bw.flush();
        bw.close();
    }
}
