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
        StringTokenizer NL = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(NL.nextToken());
        int l = Integer.parseInt(NL.nextToken());

        List<Integer> numList = new ArrayList<Integer>();
        StringTokenizer nums = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            numList.add(Integer.parseInt(nums.nextToken()));
        }
        Collections.sort(numList);

        int cnt = 0;
        double range = 0;
        for (int i = 0; i < n; i++) {
            if (numList.get(i) > range) {
                cnt++;
                range = numList.get(i) - 0.5 + l;
            }
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}
