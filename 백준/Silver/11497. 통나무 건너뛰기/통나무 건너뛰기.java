import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> numList = new ArrayList<Integer>();
            for (int j = 0; j < n; j++) {
                numList.add(Integer.parseInt(st.nextToken()));
            }
            Collections.sort(numList);

            int maxDiff = 0;
            for (int j = 2; j < n; j++) {
                int diff = numList.get(j) - numList.get(j - 2);
                maxDiff = Math.max(maxDiff, diff);
            }
            bw.write(maxDiff + "\n");
        }
        bw.flush();
        bw.close();
    }
}
