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
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[] akbo = new int[n];
        for (int i = 0; i < n; i++) {
            akbo[i] = Integer.parseInt(br.readLine());
        }

        List<Integer> time = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < akbo[i]; j++) {
                time.add(i + 1);
            }
        }

        for (int i = 0; i < q; i++) {
            int question = Integer.parseInt(br.readLine());
            bw.write(time.get(question) + "\n");
        }
        bw.flush();
        bw.close();
    }
}
