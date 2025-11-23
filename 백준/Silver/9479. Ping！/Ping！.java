import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String pingStr = br.readLine();
            if (pingStr.equals("0")) {
                break;
            }

            int n = pingStr.length();
            int[] signals = new int[n];
            for (int i = 0; i < n; i++) {
                signals[i] = pingStr.charAt(i) - '0';
            }

            List<Integer> result = new ArrayList<>();

            for (int k = 1; k < n; k++) {
                if (signals[k] == 1) {
                    result.add(k);

                    for (int j = k; j < n; j += k) {
                        signals[j] = 1 - signals[j]; 
                    }
                }
            }

            for (int i = 0; i < result.size(); i++) {
                bw.write(result.get(i) + (i == result.size() - 1 ? "" : " "));
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}