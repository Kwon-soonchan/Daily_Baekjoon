import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        List<Integer> numList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            numList.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(numList);

        int result = 0;
        boolean check = true;
        for (int i = n - 1; i >= 2; i--) {
            if (numList.get(i) < numList.get(i - 1) + numList.get(i - 2)) {
                result = numList.get(i) + numList.get(i - 1) + numList.get(i - 2);
                check = false;
                bw.write(result + "");
                bw.flush();
                bw.close();
                System.exit(0);
            }
        }
        if (check) {
            bw.write(-1 + "");
            bw.flush();
            bw.close();
        }
    }
}
